#include "uart.h"
uint8_t i=0;
uint8_t array[4];

uint8_t out[128];
uint8_t write_index=0;
uint8_t read_index=0;


void UART0_Transmit(uint8_t data) { // transmite de pe placuta
	while(!(UART0->S1 & UART_S1_TDRE_MASK)) {}
	UART0->D = data;
}

uint8_t UART0_Receive(void) { //receive pe placuta 
	while(!(UART0->S1 & UART_S1_RDRF_MASK)) {}
	return UART0->D;
}

void UART0_Initialize(uint32_t baud_rate) {
	uint16_t osr = 16;//din cerinta
	uint16_t sbr;
	
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;

	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	UART0->C2 &= ~((UART0_C2_RE_MASK) | (UART0_C2_TE_MASK)); 
	
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(01);
	
	PORTA->PCR[1] = ~PORT_PCR_MUX_MASK;
	PORTA->PCR[1] = PORT_PCR_ISF_MASK | PORT_PCR_MUX(2);
	PORTA->PCR[2] = ~PORT_PCR_MUX_MASK;
	PORTA->PCR[2] = PORT_PCR_ISF_MASK | PORT_PCR_MUX(2);
	
	sbr = (uint16_t)((DEFAULT_SYSTEM_CLOCK)/(baud_rate * (osr)));
	UART0->BDH &= UART0_BDH_SBR_MASK;
	UART0->BDH |= UART0_BDH_SBR(sbr>>8);
	UART0->BDL = UART_BDL_SBR(sbr);
	UART0->C4 |= UART0_C4_OSR(osr - 1);
			
	UART0->C1 = UART0_C1_M(0) | UART0_C1_PE(0);
	
	UART0->S2 |= UART0_S2_MSBF(1);//din cerinta
	
	UART0->C2 = 0x2C;
	UART0->C3 |= UART0_C3_TXINV(1);// din cerinta
	
	UART0->C2 |= ((UART_C2_RE_MASK) | (UART_C2_TE_MASK));
	
	NVIC_ClearPendingIRQ(UART0_IRQn);
	NVIC_EnableIRQ(UART0_IRQn);
	
	__enable_irq();
	
}

void UART0_IRQHandler(void) {
	//se trateaza evenimentul de receptie
	if(UART0->S1 & UART0_S1_RDRF_MASK) {
			uint8_t data = UART0->D; //practic e receive pe placuta
			if(data==0x0D){
				out[write_index++]=0X0D;
				out[write_index++]=0X0A;	
		}
		else {
			out[write_index++]=data;
		}	
	}	
	//se trateaza evenimentul de transmisie
	if(UART0->S1 & UART0_S1_TDRE_MASK){
		UART0_Transmit(out[read_index++]);
	}
}
