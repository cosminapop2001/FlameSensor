#include "gpio.h"
#include "adc.h"
#include "uart.h"
#include "pit.h"

uint16_t sensor_read;
uint16_t i;


int main(void) {
	UART0_Init(14400);
	GPIO_Init();
	PIT_INIT();
	ADC0_Init();
	
	while(1)
		{ 
			sensor_read = ADC0_ReadChannel(15);
			//Transmit the adcValue for debugging
			for( i =10000;i>=1;i/=10)
			{
				UART0_Transmit('0'+(sensor_read/i%10));
			}
			UART0_Transmit(0x0a);
			UART0_Transmit(0x0d);
			
				
			if (sensor_read >= 64800 && sensor_read <= 64910) {
            afisare_BCD(2); 
        } else if (sensor_read >= 64911 && sensor_read <= 64960) {
            afisare_BCD(5); // Display "5" on BCD
        } else if (sensor_read >= 64961) {
            afisare_BCD(8); // Display "8" on BCD
        }
			delay_ms(1000);
	}
}
