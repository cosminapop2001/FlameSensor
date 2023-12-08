#include "pit.h"
#include "gpio.h"
#include "uart.h"
uint16_t LEDstate = 3;
void PIT_INIT(void)
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT_MCR &= ~PIT_MCR_MDIS_MASK; // mdis=0 Clock for standard PIT timers is enabled
	PIT->MCR |= PIT_MCR_FRZ_MASK; //frz=1 Timers are stopped in Debug mode.
	
	//Load Value = Nr. sec. * BUS CLOCK Freq. - 1
	//10.485.760Hz bcf
	//0x9FFFFF = 1sec
	//8336179.2 = 0.795  sec
	//-> 
	PIT->CHANNEL[0].LDVAL =0x7F3333;
	// Interrupt will be requested whenever TIF is set
	//	Timer n is enabled.
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK; 
	
	NVIC_ClearPendingIRQ(PIT_IRQn);
	NVIC_SetPriority(PIT_IRQn,5);
	NVIC_EnableIRQ(PIT_IRQn);
}

void PIT_IRQHandler(void) {
	if(PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK) {
		LEDstate ++;
		LED_Sequence(LEDstate%4);
		int i;
		if(LEDstate%2){
			for(i =0 ;i<8;i++)
				DX_CLR(i);
		}
		else{
			for(i =0 ;i<8;i++)
				DX_SET(i);
		}
		//Sets to 1 at the end of the timer period. Writing 1 to this flag clears it. Writing 0 has no effect. If enabled,
		//or, when TCTRLn[TIE] = 1, TIF causes an interrupt request.
		PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
	}
}
