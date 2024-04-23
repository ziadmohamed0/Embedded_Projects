/*
 * External_Interrupts_Reg.h
 *
 *  Created on: Apr 12, 2024
 *      Author: ziad
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPTS_REG_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPTS_REG_H_

/* -------------------- Section : Addresses Of Registers -------------------- */
#define MCUCR_REG	*(	(volatile u8*)	0x55)
#define MCUCSR_REG	*(	(volatile u8*)	0x54)
#define GICR_REG	*(	(volatile u8*)	0x5B)
#define GIFR_REG	*(	(volatile u8*)	0x5A)
#define SREG_REG	*(	(volatile u8*)	0x5F)

/* -------------------- Section : Bits Of Registers -------------------- */
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

#define MCUCSR_ISC2		6

#define GICR_INT2		5
#define GICR_INT0		6
#define GICR_INT1		7

#define SREG_GIE		7

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPTS_REG_H_ */
