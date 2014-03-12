
#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"

#ifdef ADMUX
	void adcInit () {
	  ADMUX |= (1 << REFS0);
	  ADCSRA = (1 << ADEN) | (7 << ADPS0);
	}

	uint16_t adcRead(uint8_t ch) {
	  ADMUX |= ch;
	  ADCSRA |= (1 << ADSC);
	  while (!(ADCSRA & (1 << ADIF)));
	  ADCSRA |= (1 << ADIF);
	  return (ADC);
	}
#endif
