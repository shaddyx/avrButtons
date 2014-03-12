/*
 * timer.h
 *
 *  Created on: Feb 26, 2014
 *      Author: shaddy
 */

#ifndef TIMER_H_
#define TIMER_H_

unsigned long setTimer(unsigned long ms);
char checkTimer(unsigned long* timer);
unsigned long getTime();
void pollTimer();

#endif /* TIMER_H_ */
