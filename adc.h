#ifndef ADC_H
#define ADC_H

//		divider 32 (1<<ADPS2) | (0<<ADPS1) | (1<<ADPS0)
#define ADC_DIVIDER_1 0
#define ADC_DIVIDER_2 1
#define ADC_DIVIDER_4 2
#define ADC_DIVIDER_8 3
#define ADC_DIVIDER_16 4
#define ADC_DIVIDER_32 5
#define ADC_DIVIDER_64 6
#define ADC_DIVIDER_128 7


uint8_t adcInit(uint16_t adcClock);
uint8_t adcStart(uint8_t channel);
uint8_t adcIsBusy(void);
int adcRead();

#endif
