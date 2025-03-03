/*
 * DIO_Reg.h
 *
 *  Created on: Jun 12, 2024
 *      Author: ziad
 */

#ifndef MCAL_DIO_DIO_REG_H_
#define MCAL_DIO_DIO_REG_H_

/*********** INCLUDES ***********/
#include "../../SERV/LIB/Includes.h"
#include "../../SERV/LIB/Std_Types.h"
#include "../../SERV/LIB/Bit_Math.h"
#include "../ADC/ADC_init.h"
#include "../TIMER0/TIMER0_init.h"
#include "../UART/UART_Init.h"
#include "../SPI/SPI_init.h"

	/* ----- DDRx REGISTERS ----- */
#define DDRA  ( (volatile uint_8 *)   0x3A)
#define DDRB  ( (volatile uint_8 *)   0x37)
#define DDRC  ( (volatile uint_8 *)   0x34)
#define DDRD  ( (volatile uint_8 *)   0x31)

	/* ----- PINx REGISTERS ----- */
#define PINA  ( (volatile uint_8 *)   0x39)
#define PINB  ( (volatile uint_8 *)   0x36)
#define PINC  ( (volatile uint_8 *)   0x33)
#define PIND  ( (volatile uint_8 *)   0x30)

	/* ----- PORTx REGISTERS ----- */
#define PORTA  ( (volatile uint_8 *)   0x3B)
#define PORTB  ( (volatile uint_8 *)   0x38)
#define PORTC  ( (volatile uint_8 *)   0x35)
#define PORTD  ( (volatile uint_8 *)   0x32)

/*********** PINS ***********/
typedef enum
{
	PINA0,PINA1,PINA2,PINA3,PINA4,PINA5,PINA6,PINA7,
	PINB0,PINB1,PINB2,PINB3,PINB4,PINB5,PINB6,PINB7,
	PINC0,PINC1,PINC2,PINC3,PINC4,PINC5,PINC6,PINC7,
	PIND0,PIND1,PIND2,PIND3,PIND4,PIND5,PIND6,PIND7
}_GPIO_PINS;

/*********** PORTS ***********/
typedef enum
{
	_PORTA,
	_PORTB,
	_PORTC,
	_PORTD
}_GPIO_PORTS;

#endif /* MCAL_DIO_DIO_REG_H_ */
