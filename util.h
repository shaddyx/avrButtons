/*
 * constants.h
 *
 *  Created on: Feb 26, 2014
 *      Author: shaddy
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define sbi(reg, bit) (reg |= (1<<bit))
#define cbi(reg, bit) (reg &= ~(1<<bit))
#define ckbi(reg, bit) (reg & (1<<bit))
#define xorbi(reg, bit) (reg ^ (1<<bit))

#endif /* CONSTANTS_H_ */
