/*
 * INTERRUPT_reg.h
 *
 *  Created on: Jun 14, 2024
 *      Author: ziad
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_REG_H_
#define MCAL_INTERRUPT_INTERRUPT_REG_H_

/*********** INCLUDES ***********/
#include "INTERRUPT_vec.h"

/*********** REGISTERS ***********/
#define MCUCR	*((volatile uint_8 *) 0x55)
#define MCUCSR	*((volatile uint_8 *) 0x54)
#define GICR	*((volatile uint_8 *) 0x5B)
#define GIFR	*((volatile uint_8 *) 0x5A)
#define SREG	*((volatile uint_8 *) 0x5F)

/*********** BITS ***********/
	/* ----- MCUCR BITS ----- */
typedef enum
{
	ISC00,
	ISC01,
	ISC10,
	ISC11
}BITS_MCUCR;

	/* ----- MCUCSR BITS ----- */
#define ISC2 (uint_8)6

	/* ----- GICR BITS ----- */
typedef enum
{
	_INT2 = 5,
	_INT0,
	_INT1
}BITS_GICR;

	/* ----- GIFR BITS ----- */
typedef enum
{
	INTF2 = 5,
	INTF0,
	INTF1
}BITS_GIFR;

	/* ----- SREG BITS ----- */
#define GIE	(uint_8)7

#endif /* MCAL_INTERRUPT_INTERRUPT_REG_H_ */
