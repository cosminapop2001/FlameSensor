#include "MKL25Z4.h"

#define RED_PIN (18) //PORT B 
#define GREEN_PIN (19) //PORT B 
#define BLUE_PIN (1) //PORT D
#define SWITCH_PIN (12) //PORT A



void RGBLedInit(void);
void LED_Sequence(int n);
void delay(long int n);

void RED_SET(void);
void GREEN_SET(void);
void BLUE_SET(void);

