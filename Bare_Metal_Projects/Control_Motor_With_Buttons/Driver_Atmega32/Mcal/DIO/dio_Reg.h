/*
 * dio_Reg.h
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */

#ifndef MCAL_DIO_DIO_REG_H_
#define MCAL_DIO_DIO_REG_H_

/* -------------------- Section : DDrS -------------------- */
#define DDRA_REG       ( (volatile u8 *)   0x3A)
#define DDRB_REG       ( (volatile u8 *)   0x37)
#define DDRC_REG       ( (volatile u8 *)   0x34)
#define DDRD_REG       ( (volatile u8 *)   0x31)

/* -------------------- Section : PortS -------------------- */
#define PORTA_REG      ( (volatile u8 *)   0x3B)
#define PORTB_REG      ( (volatile u8 *)   0x38)
#define PORTC_REG      ( (volatile u8 *)   0x35)
#define PORTD_REG      ( (volatile u8 *)   0x32)

/* -------------------- Section : PinS -------------------- */
#define PINA_REG       ( (volatile u8 *)   0x39)
#define PINB_REG       ( (volatile u8 *)   0x36)
#define PINC_REG       ( (volatile u8 *)   0x33)
#define PIND_REG       ( (volatile u8 *)   0x30)

#endif /* MCAL_DIO_DIO_REG_H_ */
