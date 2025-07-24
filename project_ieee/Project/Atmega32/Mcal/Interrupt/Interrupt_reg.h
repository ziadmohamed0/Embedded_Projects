/*
 * Interrupt_reg.h
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_REG_H_
#define MCAL_INTERRUPT_INTERRUPT_REG_H_

/* -------------------- Include Start -------------------- */
#include "../GPIO/GPIO_init.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define ISR(vector)            \
    void vector (void)  __attribute__ ((signal,used, externally_visible)); \
    void vector (void)

#define SREG									(*((volatile uint8*)(0x5F)))
#define MCUCR									(*((volatile uint8*)(0x55)))
#define MCUCSR									(*((volatile uint8*)(0x54)))
#define GICR									(*((volatile uint8*)(0x5B)))
#define GIFR									(*((volatile uint8*)(0x5A)))
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
	ISC00,
	ISC01,
	ISC10,
	ISC11
}MCUCR_t;

typedef enum {
	ISC2 = 6,
}MCUCSR_t;

typedef enum {
	INT2= 5,
	INT0,
	INT1
}GICR_t;

typedef enum {
	INTF2= 5,
	INTF0,
	INTF1
}GIFR_t;

typedef enum {
	GIE = 7,
}SREG_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_INTERRUPT_INTERRUPT_REG_H_ */
