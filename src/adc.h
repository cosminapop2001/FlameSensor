#ifndef ADC_H
#define ADC_H

#include <stdint.h>

void ADC0_Init(void);
uint16_t ADC0_ReadChannel(uint16_t channel);

#endif // ADC_H
