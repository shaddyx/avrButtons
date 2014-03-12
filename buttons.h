/*
 * buttons.h
 *
 *  Created on: Feb 25, 2014
 *      Author: shaddy
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_
#ifndef BUTTON_PRESS_DELAY
	#define BUTTON_PRESS_DELAY 20
#endif

#define initButton(portName,pin) _initButton(&DDR##portName, &PORT##portName, pin)
#define buttonPressed(portName,pin) _buttonPressed(&PIN##portName, pin)
#define buttonDown(portName,pin) _buttonDown(&PIN##portName, pin)
#define buttonUp(portName,pin) _buttonUp(&PIN##portName, pin)
#define waitButton(portName,pin) _waitButton(&PIN##portName, pin)

int _buttonPressed (volatile uint8_t * port_in, uint8_t pin);
int _buttonDown (volatile uint8_t * port_in, uint8_t pin);
int _buttonUp (volatile uint8_t * port_in, uint8_t pin);

void _waitButton (volatile uint8_t * port_in, uint8_t pin);

void _initButton(volatile uint8_t * port_ddr,
                              volatile uint8_t * port,
                              uint8_t pin);


#endif /* BUTTONS_H_ */
