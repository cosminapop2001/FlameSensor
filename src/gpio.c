#include "gpio.h"


void RGBLedInit(void){
	
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;
	
	PORTB->PCR[RED_PIN] = ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_PIN] |= PORT_PCR_MUX(1);
	PORTB->PCR[GREEN_PIN] = ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_PIN] |= PORT_PCR_MUX(1);
	PORTD->PCR[BLUE_PIN] = ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_PIN] |= PORT_PCR_MUX(1);
	
	PTB->PDDR |= (1 << RED_PIN); // output
	PTB->PDDR |= (1 << GREEN_PIN);
	PTD->PDDR |= (1 << BLUE_PIN);
	
	PTB->PSOR = (1 << RED_PIN); //SET = oprire led
	PTB->PSOR = (1 << GREEN_PIN);
	PTD->PSOR = (1 << BLUE_PIN);
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

void RED_SET(void)
{
	PTB->PCOR = (1 << RED_PIN);
  delay(100000);
  PTB->PSOR = (1 << RED_PIN);
}


void GREEN_SET(void)
{
	PTB->PCOR = (1 << GREEN_PIN);
  delay(100000);
  PTB->PSOR = (1 << GREEN_PIN);
}


void BLUE_SET(void)
{
	PTD->PCOR = (1 << BLUE_PIN);
  delay(100000);
  PTD->PSOR = (1 << BLUE_PIN);
}
