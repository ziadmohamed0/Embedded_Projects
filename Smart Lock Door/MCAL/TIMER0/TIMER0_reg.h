/*
 * TIMER0_reg.h
 *
 *  Created on: Jun 16, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER0_TIMER0_REG_H_
#define MCAL_TIMER0_TIMER0_REG_H_

/************ INCLUDE ***********/
#include "../INTERRUPT/INTERRUPT_init.h"

/************ REGISTERS ***********/
#define TCCR0   *((volatile uint_8 *) 0x53)
#define TCNT0   *((volatile uint_8 *) 0x52)
#define OCR0    *((volatile uint_8 *) 0x5C)
#define TIMSK   *((volatile uint_8 *) 0x59)
#define TIFR    *((volatile uint_8 *) 0x58)

/************ TCCR0 REGISTERS ***********/
typedef enum
{
	CS00,
	CS01,
	CS02,
	WGM01,
	COM00,
	COM01,
	WGM00,
	FOC0
}_BIT_TCCR0;

/************ TIMSK REGISTERS ***********/
typedef enum
{
	TOIE0,
	OCIE0
}_BIT_TIMSK;

#endif /* MCAL_TIMER0_TIMER0_REG_H_ */
