#include "MKL25Z4.h"

#define FLAME_SENSOR_CHANNEL 15 // Adjust this according to your setup
#define ADC_MAX_CHANNEL 20

void ADC0_Init(void) {
    // Enable clock for ADC0
    SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;

    // Configure ADC for 12-bit conversion, bus/2 clock, single-ended mode
    ADC0->CFG1 = ADC_CFG1_MODE(3) | ADC_CFG1_ADIV(1);

    // Software trigger, no compare function
    ADC0->SC2 &= ~ADC_SC2_ADTRG_MASK;
}

uint16_t ADC0_ReadChannel(uint16_t channel) {
    // Configure ADC channel
    ADC0->SC1[0] = ADC_SC1_ADCH(channel);

    // Wait for conversion to complete
    while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));

    // Read conversion result
    return ADC0->R[0];
}
