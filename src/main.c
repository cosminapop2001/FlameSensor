#include "gpio.h"
#include "adc.h"
#include "uart.h"
#include "pit.h"

extern uint16_t temperature_read;
int togg=0;
int i;
int main(void) {
	UART0_Init(14400);
	GPIO_Init();
	PIT_INIT();
	ADC0_Init();
	while(1){ 
		if(togg)
		{
			Flame_Read();
			togg=0;
			delay(DEFAULT_SYSTEM_CLOCK/20);
		}
		else
		{	
			for(i =0;i<9;i++)
			{
				Temperature_Read();
				delay(DEFAULT_SYSTEM_CLOCK/200);
			}
			togg=1;
		}
	}
}
