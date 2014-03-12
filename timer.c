/*
 * timer.c
 *
 *  Created on: Feb 26, 2014
 *      Author: shaddy
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "util.h"

#ifdef TCCR1B
#define TIMER_CONF TCCR1B
#define TIMER_COUNTER TCNT1
#else
#define TIMER_CONF TCCR0B
#define TIMER_COUNTER TCNT0
#endif


#if F_CPU == 8000000
	#define TIMER_DIVIDER 256
	#define TIMER_QUANTUM 4
	#define IMPULSES_PER_QUANTUM 125
#elif F_CPU == 4000000
	#define TIMER_DIVIDER 64
#elif F_CPU == 1000000
	#define TIMER_DIVIDER 64
#endif
#define IMPULSES_PER_QUANTUM 125

#if TIMER_DIVIDER == 64
#define TIMER_CONF_BITS (0<<CS02)|(1<<CS01)|(1<<CS00)
#elif TIMER_DIVIDER == 256
#define TIMER_CONF_BITS (1<<CS02)|(0<<CS01)|(0<<CS00)
#elif TIMER_DIVIDER == 1024
#define TIMER_CONF_BITS (1<<CS02)|(0<<CS01)|(1<<CS00)
#endif

#define IMPULSES_PER_MS (F_CPU / TIMER_DIVIDER) / 1000

unsigned long counter = 0;
unsigned int lastValue = 0;
char timerNotStarted = 1;

void initTimer() {
	TIMER_CONF = TIMER_CONF_BITS;
	TIMER_COUNTER = 0;
}

void pollTimer(){
	if (timerNotStarted){
		return;
	}
	unsigned int curValue = TIMER_COUNTER;
	unsigned int delta;
	if (curValue >= lastValue) {
		delta = curValue - lastValue;
	} else {
		delta = curValue + (65535 - lastValue);
	}

	if (delta > IMPULSES_PER_QUANTUM) {
		counter += delta / IMPULSES_PER_QUANTUM;
		lastValue = curValue - delta % IMPULSES_PER_QUANTUM;
	}
}

unsigned long getTime() {
	return counter;
}

char checkTimer(unsigned long* timer) {
	if (*timer != 0 && *timer <= counter) {
		*timer = 0;
		return 1;
	}
	return 0;
}

unsigned long setTimer(unsigned long ms){
	if (timerNotStarted){
		timerNotStarted = 0;
		initTimer();
	}
	return counter + ms /TIMER_QUANTUM;
}
