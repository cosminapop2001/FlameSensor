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
	
	//BCD
	
PORTA->PCR[13] |= ~PORT_PCR_MUX_MASK;
PORTA->PCR[13] = PORT_PCR_MUX(1);
PTA->PDDR |= (1 << 13); 

PORTD->PCR[0] |= ~PORT_PCR_MUX_MASK;
PORTD->PCR[0] = PORT_PCR_MUX(1);
PTD->PDDR |= (1 << 0);

PORTD->PCR[4] |= ~PORT_PCR_MUX_MASK;
PORTD->PCR[4] = PORT_PCR_MUX(1);
PTD->PDDR |= (1 << 4);

PORTA->PCR[12] |= ~PORT_PCR_MUX_MASK;
PORTA->PCR[12] = PORT_PCR_MUX(1);
PTA->PDDR |= (1 << 12);

PORTA->PCR[4] |= ~PORT_PCR_MUX_MASK;
PORTA->PCR[4] = PORT_PCR_MUX(1);
PTA->PDDR |= (1 << 4);

PORTA->PCR[5] |= ~PORT_PCR_MUX_MASK;
PORTA->PCR[5] = PORT_PCR_MUX(1);
PTA->PDDR |= (1 << 5);

PORTC->PCR[8] |= ~PORT_PCR_MUX_MASK;
PORTC->PCR[8] = PORT_PCR_MUX(1);
PTC->PDDR |= (1 << 8);

PORTC->PCR[9] |= ~PORT_PCR_MUX_MASK;
PORTC->PCR[9] = PORT_PCR_MUX(1);
PTC->PDDR |= (1 << 9);


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


void delay_ms(unsigned long int ms) {
    volatile unsigned long int i,n;
		n=ms*(DEFAULT_SYSTEM_CLOCK/20000);
    for (i = 0; i < n; i++);
}


void afisare_BCD(int x)
{
PTD->PSOR = (1 << 0);
PTA->PSOR = (1 << 13);
PTD->PSOR = (1 << 4);
PTA->PSOR = (1 << 12);
PTA->PSOR = (1 << 4);
PTA->PSOR = (1 << 5);
PTC->PSOR = (1 << 8);
PTC->PSOR = (1 << 9);
	

	switch(x)
	{
		case 2:
PTA->PCOR = (1 << 13);
PTD->PCOR = (1 << 0);
PTA->PCOR = (1 << 12);
PTA->PCOR = (1 << 4);
PTC->PCOR = (1 << 8);
PTC->PCOR = (1 << 9);
		break;
		case 5:
PTA->PCOR = (1 << 13);
PTD->PCOR = (1 << 4);
PTA->PCOR = (1 << 12);
PTA->PCOR = (1 << 5);
PTC->PCOR = (1 << 8);
PTC->PCOR = (1 << 9);
			break;
		case 8:
PTD->PCOR = (1 << 0);
PTA->PCOR = (1 << 13);
PTD->PCOR = (1 << 4);
PTA->PCOR = (1 << 12);
PTA->PCOR = (1 << 4);
PTA->PCOR = (1 << 5);
PTC->PCOR = (1 << 8);
PTC->PCOR = (1 << 9);
			break;
		default:
PTD->PSOR = (1 << 0);
PTA->PSOR = (1 << 13);
PTD->PSOR = (1 << 4);
PTA->PSOR = (1 << 12);
PTA->PSOR = (1 << 4);
PTA->PSOR = (1 << 5);
PTC->PSOR = (1 << 8);
PTC->PSOR = (1 << 9);
			break;
	}
}
