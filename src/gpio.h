#include "MKL25Z4.h"

#define RED_PIN (18) //PORT B 
#define GREEN_PIN (19) //PORT B 
#define BLUE_PIN (1) //PORT D

//de modificat (uart rx tx)
#define D0_PIN (2)		
#define D1_PIN (1)
#define D0_PORT (PORTA)
#define D1_PORT (PORTA)
#define D0_PT (PTA)
#define D1_PT (PTA)

//idk why, zice de intreruperi so maybe that
#define D4_PIN (4)
#define D4_PORT (PORTA)
#define D4_PT (PTA)

#define D2_PIN (4)
#define D3_PIN (12)
#define D5_PIN (5)
#define D6_PIN (8)
#define D7_PIN (9)

#define D2_PORT (PORTD)
#define D3_PORT (PORTA)
#define D5_PORT (PORTA)
#define D6_PORT (PORTC)
#define D7_PORT (PORTC)

#define D2_PT (PTD)
#define D3_PT (PTA)
#define D5_PT (PTA)
#define D6_PT (PTC)
#define D7_PT (PTC)


void GPIO_Init(void);

void DX_SET(int x);
void DX_CLR(int x);


//void RGBLedInit(void);
void LED_Sequence(int n);
void delay(long int n);

