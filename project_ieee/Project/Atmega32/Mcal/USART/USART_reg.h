/*
 * USART_reg.h
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#ifndef MCAL_USART_USART_REG_H_
#define MCAL_USART_USART_REG_H_

/* -------------------- Include Start -------------------- */
#include "../Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#define UDR        			*((volatile uint8 *) 0x2C)
#define UCSRA      			*((volatile uint8 *) 0x2B)
#define UCSRB      			*((volatile uint8 *) 0x2A)
#define UCSRC      			*((volatile uint8 *) 0x40)
#define UBRRH      			*((volatile uint8 *) 0x40)
#define UBRRL      			*((volatile uint8 *) 0x29)


/*------ UCSRA -------*/
#define UDRE     			(uint8)5
#define TXC      			(uint8)6
#define RXC      			(uint8)7

/*------ UCSRB --------*/

#define RXEN  				(uint8)4
#define TXEN  				(uint8)3
#define UCSZ2 				(uint8)2

/*------ UCSRC --------*/

#define URSEL  				(uint8)7
#define UMSEL  				(uint8)6
#define UPM1   				(uint8)5
#define UPM0   				(uint8)4
#define USBS   				(uint8)3
#define UCSZ1  				(uint8)2
#define UCSZ0  				(uint8)1
#define UCPOL  				(uint8)0
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_USART_USART_REG_H_ */
