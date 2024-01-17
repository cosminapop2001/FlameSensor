#include "MKL25Z4.h"

#define RED_PIN (18) //PORT B 
#define GREEN_PIN (19) //PORT B 
#define BLUE_PIN (1) //PORT D


void GPIO_Init(void);
void afisare_BCD(int x);


//void RGBLedInit(void);
void LED_Sequence(int n);
void delay_ms(unsigned long int n);

