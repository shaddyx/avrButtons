#include <avr/io.h>
uint8_t adcInit(uint16_t adcDivider){
	// Set ADCSRA Register with division factor 32
	uint8_t adcPrescaller =  adcDivider;
	ADCSRA  = (1<<ADEN) | adcPrescaller;
	uint8_t adcRefValueMode = (1<<REFS1) | (1<<REFS0);
	ADMUX = adcRefValueMode;
}

uint8_t adcStart(uint8_t channel){
	ADMUX |= channel & 0b00000111;
	ADCSRA  |= (1<<ADSC);
}

uint8_t adcIsBusy(void){
	return ADCSRA & (1<<ADSC);
}
int adcRead(){
	unsigned int adcValue = ADCW;	//Store ADC result
	//ADCSRA |= (1<<ADIF);
	return adcValue;
}
