
#include <MKL25Z4.h>
#include "bcd.h"
#include "gpio.h"
#include "uart.h"
#include "pit.h"

int main(void) {
	UART0_Initialize(14400);//din cerinta
	RGBLedInit();
	PIT_INIT();
	//RED_SET();
	//int i;
	//BCD_Init();
	
    while (1) {
				//for(i = 0 ;i<3;i++)
					//DX_CLR(i);
				//LED_Sequence(0);
				//delay(DEFAULT_SYSTEM_CLOCK/200);
			//DX_SET(2);
				//LED_Sequence(1);
        //delay(DEFAULT_SYSTEM_CLOCK/200);
			//DX_SET(1);
				//LED_Sequence(2);
				//delay(DEFAULT_SYSTEM_CLOCK/200);
			//DX_SET(0);
				//LED_Sequence(3);
        //delay(DEFAULT_SYSTEM_CLOCK/200);
			//UART0_Transmit(0x23);
    }
		
		
		
}

