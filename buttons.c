/*
 * buttons.c
 *
 *  Created on: Feb 25, 2014
 *      Author: shaddy
 */

#include <avr/io.h>
#include <util/delay.h>
#include "buttons.h"
#include "util.h"

int _buttonPressed (volatile uint8_t * port_in, uint8_t pin) {
  if (!ckbi(*port_in, pin)) {
	  _delay_ms (BUTTON_PRESS_DELAY);
	  while (!ckbi (*port_in, pin)) {
	      _delay_ms (BUTTON_PRESS_DELAY);
	  }
	  return 1;
  }
  return 0;
}

int _buttonDown (volatile uint8_t * port_in, uint8_t pin) {
  if (!ckbi(*port_in, pin)) {
	  return 1;
  }
  return 0;
}

int _buttonUp (volatile uint8_t * port_in, uint8_t pin) {
  if (ckbi(*port_in, pin)) {
	  return 1;
  }
  return 0;
}

void _waitButton (volatile uint8_t * port_in, uint8_t pin) {
	  while (ckbi (*port_in, pin)) {
	    _delay_ms (BUTTON_PRESS_DELAY);
	  }

	  while (!ckbi (*port_in, pin)) {
	    _delay_ms (BUTTON_PRESS_DELAY);
	  }
}


void _initButton(volatile uint8_t * port_ddr,
                              volatile uint8_t * port,
                              uint8_t pin) {
  cbi (*port_ddr, pin);
  sbi (*port, pin);
}
