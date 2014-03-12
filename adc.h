#ifndef LIB_ADC
#define LIB_ADC

#include <avr/io.h>
#ifdef ADMUX
	void adcInit ();
	uint16_t adcRead(uint8_t ch);
#endif

#endif
