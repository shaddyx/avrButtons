#include <avr/io.h>
#ifdef ADSC
uint8_t simpleAdcInit(uint8_t adcDivider, uint8_t adcRefValueMode){
	uint8_t adcPrescaller =  adcDivider;
	ADCSRA  = (1<<ADEN) | adcPrescaller;
	ADMUX = adcRefValueMode;
}

uint8_t simpleAdcStart(uint8_t channel){
	ADMUX |= channel & 0b00000111;
	ADCSRA  |= (1<<ADSC);
}

uint8_t simpleAdcIsBusy(void){
	return ADCSRA & (1<<ADSC);
}
int simpleAdcRead(){
	unsigned int adcValue = ADCW;	//Store ADC result
	//ADCSRA |= (1<<ADIF);
	return adcValue;
}
#endif
