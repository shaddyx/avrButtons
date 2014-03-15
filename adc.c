#include <avr/io.h>
uint8_t simpleAdcInit(uint8_t adcDivider, uint8_t adcRefValueMode){
	// Set ADCSRA Register with division factor 32
	uint8_t adcPrescaller =  adcDivider;
	ADCSRA  = (1<<ADEN) | adcPrescaller;
	//uint8_t adcRefValueMode = (1<<REFS1) | (1<<REFS0);
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
