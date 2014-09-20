#ifndef ADC_H
#define ADC_H
#include <avr/io.h>
#ifdef ADSC
//		divider 32 (1<<ADPS2) | (0<<ADPS1) | (1<<ADPS0)

#define ADC_DIVIDER_1 0
#define ADC_DIVIDER_2 1
#define ADC_DIVIDER_4 2
#define ADC_DIVIDER_8 3
#define ADC_DIVIDER_16 4
#define ADC_DIVIDER_32 5
#define ADC_DIVIDER_64 6
#define ADC_DIVIDER_128 7

#ifdef REFS1
#define ADC_REFVALUE_MODE_EXTERNAL_AREF (0<<REFS1) | (0<<REFS0)
#define ADC_REFVALUE_MODE_VCC (0<<REFS1) | (1<<REFS0)
#define ADC_REFVALUE_MODE_INTERNAL_2_5 (1<<REFS1) | (1<<REFS0)
#else
#define ADC_REFVALUE_MODE_DEFAULT_INTERNAL 0
#endif

uint8_t simpleAdcInit(uint8_t adcDivider, uint8_t adcRefValueMode);
uint8_t simpleAdcStart(uint8_t channel);
uint8_t simpleAdcIsBusy(void);
int simpleAdcRead();

#endif
#endif
