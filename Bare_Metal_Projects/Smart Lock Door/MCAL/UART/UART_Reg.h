/*
 * UART_Reg.h
 *
 *  Created on: Jun 8, 2024
 *      Author: ziad
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_

/*********** INCLUDES ***********/
#include "../INTERRUPT/INTERRUPT_init.h"

/*********** REGISTERS ***********/
#define UBRRH *((volatile uint_8 *) 0x40)
#define UCSRC *((volatile uint_8 *) 0x40)
#define UCSRB *((volatile uint_8 *) 0x2A)
#define UBRRL *((volatile uint_8 *) 0x29)
#define UDR   *((volatile uint_8 *) 0x2C)
#define UCSRA *((volatile uint_8 *) 0x2B)

/*********** BITS REGISTER ***********/
typedef enum
{
	MPCM,
	U2X,
	PE,
	DOR,
	FE,
	UDRE,
	TXC,
	RXC
}BITS_UCSRA;


typedef enum
{
	TXB8,
	RXB8,
	UCSZ2,
	TXEN,
	RXEN,
	UDRIE,
	TXCIE,
	RXCIE
}BITS_UCSRB;

typedef enum
{
	UCPOL,
	UCSZ0,
	UCSZ1,
	USBS,
	UPM0,
	UPM1,
	UMSEL,
	URSEL
}BITS_UCSRC;

#endif /* MCAL_UART_UART_REG_H_ */
