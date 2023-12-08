#include "gpio.h"


void GPIO_Init(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK |SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK ;
	
	//leds
	PORTB->PCR[RED_PIN] = ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_PIN] |= PORT_PCR_MUX(1);
	PTB->PDDR |= (1 << RED_PIN);
	PTB->PSOR = (1 << RED_PIN);
	PORTB->PCR[GREEN_PIN] = ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_PIN] |= PORT_PCR_MUX(1);
	PTB->PDDR |= (1 << GREEN_PIN);
	PTB->PSOR = (1 << GREEN_PIN);
	PORTD->PCR[BLUE_PIN] = ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_PIN] |= PORT_PCR_MUX(1);
	PTD->PDDR |= (1 << BLUE_PIN);
	PTD->PSOR = (1 << BLUE_PIN);
	
	//d0-7 ports for bcd
	//D0_PORT->PCR[D0_PIN] |= ~PORT_PCR_MUX_MASK;
	//D1_PORT->PCR[D1_PIN] |= ~PORT_PCR_MUX_MASK;
	D2_PORT->PCR[D2_PIN] |= ~PORT_PCR_MUX_MASK;	
	D3_PORT->PCR[D3_PIN] |= ~PORT_PCR_MUX_MASK;	
	//D4_PORT->PCR[D4_PIN] |= ~PORT_PCR_MUX_MASK;
	D5_PORT->PCR[D5_PIN] |= ~PORT_PCR_MUX_MASK;	
	D6_PORT->PCR[D6_PIN] |= ~PORT_PCR_MUX_MASK;	
	D7_PORT->PCR[D7_PIN] |= ~PORT_PCR_MUX_MASK;
	//D0_PORT->PCR[D0_PIN] |= PORT_PCR_MUX(1);
	//D1_PORT->PCR[D1_PIN] |= PORT_PCR_MUX(1);	
	D2_PORT->PCR[D2_PIN] |= PORT_PCR_MUX(1);	
	D3_PORT->PCR[D3_PIN] |= PORT_PCR_MUX(1);	
	//D4_PORT->PCR[D4_PIN] |= PORT_PCR_MUX(1);	
	D5_PORT->PCR[D5_PIN] |= PORT_PCR_MUX(1);
	D6_PORT->PCR[D6_PIN] |= PORT_PCR_MUX(1);
	D7_PORT->PCR[D7_PIN] |= PORT_PCR_MUX(1);
	//D0_PT->PDDR|=(1<<D0_PIN);
	//D1_PT->PDDR|=(1<<D1_PIN);
	D2_PT->PDDR|=(1<<D2_PIN);
	D3_PT->PDDR|=(1<<D3_PIN);
	//D4_PT->PDDR|=(1<<D4_PIN);
	D5_PT->PDDR|=(1<<D5_PIN);
	D6_PT->PDDR|=(1<<D6_PIN);
	D7_PT->PDDR|=(1<<D7_PIN);
	D0_PT->PSOR=(1<<D0_PIN);
	D1_PT->PSOR=(1<<D1_PIN);
	D2_PT->PSOR=(1<<D2_PIN);
	D3_PT->PSOR=(1<<D3_PIN);
	D4_PT->PSOR=(1<<D4_PIN);
	D5_PT->PSOR=(1<<D5_PIN);
	D6_PT->PSOR=(1<<D6_PIN);
	D7_PT->PSOR=(1<<D7_PIN);

	
	
}

void LED_Sequence(int n)
{
	switch(n)
	{
		case 0: 
			PTB->PCOR = (1 << RED_PIN); 
			PTB->PCOR = (1 << GREEN_PIN);
			PTD->PCOR = (1 << BLUE_PIN);	
			break;
		case 1: 
			PTB->PCOR = (1 << RED_PIN); 
			PTB->PSOR = (1 << GREEN_PIN);
			PTD->PSOR = (1 << BLUE_PIN);	
			break;
		case 2: 
			PTB->PCOR = (1 << RED_PIN); 
			PTB->PSOR = (1 << GREEN_PIN);
			PTD->PCOR = (1 << BLUE_PIN);	
			break;
		case 3: 
			PTB->PSOR = (1 << RED_PIN); 
			PTB->PCOR = (1 << GREEN_PIN);
			PTD->PCOR = (1 << BLUE_PIN);	
			break;
		default:
			PTB->PSOR = (1 << RED_PIN); 
			PTB->PSOR = (1 << GREEN_PIN);
			PTD->PSOR = (1 << BLUE_PIN);
	}
}


void delay(long int n) {
    volatile long int i;
    for (i = 0; i < n; i++);
}

void DX_SET(int x)
{
	switch(x)
	{
		case 0:
			D0_PT->PSOR=(1<<D0_PIN);
		break;
		case 1:
			D1_PT->PSOR=(1<<D1_PIN);
			break;
		case 2:
			D2_PT->PSOR=(1<<D2_PIN);
			break;
		case 3:
			D3_PT->PSOR=(1<<D3_PIN);
			break;
		case 4:
			D4_PT->PSOR=(1<<D4_PIN);
			break;
		case 5:
			D5_PT->PSOR=(1<<D5_PIN);
			break;
		case 6:
			D6_PT->PSOR=(1<<D6_PIN);
			break;
		case 7:
			D7_PT->PSOR=(1<<D7_PIN);
	}
}

void DX_CLR(int x)
{
	switch(x)
	{
		case 0:
			D0_PT->PCOR=(1<<D0_PIN);
		break;
		case 1:
			D1_PT->PCOR=(1<<D1_PIN);
			break;
		case 2:
			D2_PT->PCOR=(1<<D2_PIN);
			break;
		case 3:
			D3_PT->PCOR=(1<<D3_PIN);
			break;
		case 4:
			D4_PT->PCOR=(1<<D4_PIN);
			break;
		case 5:
			D5_PT->PCOR=(1<<D5_PIN);
			break;
		case 6:
			D6_PT->PCOR=(1<<D6_PIN);
			break;
		case 7:
			D7_PT->PCOR=(1<<D7_PIN);
	}
}


