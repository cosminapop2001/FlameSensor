#include "bcd.h"

void BCD_Init(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK |SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK ;
	
	/*
	D0-D7 pe nume
		PORTA->PCR[2] |= ~PORT_PCR_MUX_MASK;   
		PORTA->PCR[1] |= ~PORT_PCR_MUX_MASK;   
		PORTD->PCR[4] |= ~PORT_PCR_MUX_MASK;   
		PORTA->PCR[12]|= ~PORT_PCR_MUX_MASK;  
		PORTA->PCR[4] |= ~PORT_PCR_MUX_MASK;  
		PORTA->PCR[5] |= ~PORT_PCR_MUX_MASK;   
		PORTC->PCR[8] |= ~PORT_PCR_MUX_MASK;  
		PORTC->PCR[9] |= ~PORT_PCR_MUX_MASK;  
	
	PORTA->PCR[2] |= PORT_PCR_MUX(1);
	PORTA->PCR[1] |= PORT_PCR_MUX(1);
	PORTD->PCR[4] |= PORT_PCR_MUX(1); 
	PORTA->PCR[12] |= PORT_PCR_MUX(1);
	PORTA->PCR[4] |= PORT_PCR_MUX(1);
	PORTA->PCR[5] |= PORT_PCR_MUX(1); 
	PORTC->PCR[8] |= PORT_PCR_MUX(1); 
	PORTC->PCR[9] |= PORT_PCR_MUX(1);
	
	
	PTA->PDDR|=(1<<2);
	PTA->PDDR|=(1<<1);
	PTD->PDDR|=(1<<4);
	PTA->PDDR|=(1<<12);
	PTA->PDDR|=(1<<4);
	PTA->PDDR|=(1<<5);
	PTC->PDDR|=(1<<8);
	PTC->PDDR|=(1<<9);*/
	
	//la fel pentru toti 8 pini
	D0_PORT->PCR[D0_PIN] |= ~PORT_PCR_MUX_MASK;
	D0_PORT->PCR[D0_PIN] |= PORT_PCR_MUX(1);
	D0_PT->PDDR|=(1<<D0_PIN);

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


