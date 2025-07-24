/*
 *  GPIO_reg.h
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#ifndef MCAL_GPIO__GPIO_REG_H_
#define MCAL_GPIO__GPIO_REG_H_

/* -------------------- Include Start -------------------- */
#include "../../Lib/Std_Types.h"
#include "../../Lib/bit_math.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
	/* GPIOx Output State Registers */
#define PORTA								(*((volatile uint8*)(0x3B)))
#define PORTB								(*((volatile uint8*)(0x38)))
#define PORTC								(*((volatile uint8*)(0x35)))
#define PORTD								(*((volatile uint8*)(0x32)))

	/* GPIOx Direction Registers */
#define DDRA								(*((volatile uint8*)(0x3A)))
#define DDRB								(*((volatile uint8*)(0x37)))
#define DDRC								(*((volatile uint8*)(0x34)))
#define DDRD								(*((volatile uint8*)(0x31)))

	/* GPIOx Input State Registers */
#define PINA								(*((volatile uint8*)(0x39)))
#define PINB								(*((volatile uint8*)(0x36)))
#define PINC								(*((volatile uint8*)(0x33)))
#define PIND								(*((volatile uint8*)(0x30)))
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */

	/* GPIOx Pins Data type */
typedef enum {
	Pin_0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7,
}Pin_t;

/* GPIOx Ports Data type */
typedef enum {
	Port_A,
	Port_B,
	Port_C,
	Port_D
}Port_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_GPIO__GPIO_REG_H_ */
