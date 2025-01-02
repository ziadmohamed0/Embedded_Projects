

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DIO_u8GROUP_A 			0
#define DIO_u8GROUP_B 			1
#define DIO_u8GROUP_C 			2
#define DIO_u8GROUP_D 			3

#define DIO_u8PIN0				0
#define DIO_u8PIN1				1
#define DIO_u8PIN2				2
#define DIO_u8PIN3				3
#define DIO_u8PIN4				4
#define DIO_u8PIN5				5
#define DIO_u8PIN6				6
#define DIO_u8PIN7				7

#define DIO_u8OUTPUT			1
#define DIO_u8INPUT				0

#define DIO_u8HIGH				1
#define DIO_u8LOW				0

#define DIO_u8PULL_UP			1
#define DIO_u8FLOAT				0




#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)			0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)				CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)




#define DIO_MASK_BIT			1

#define PORTA	*((u8*)0x3B)
#define DDRA	*((u8*)0x3A)
#define PINA	*((volatile u8*)0x39)

#define DDRB	*((u8*)0x37)
#define PORTB	*((u8*)0x38)
#define PINB	*((volatile u8*)0x36)

#define DDRC	*((u8*)0x34)
#define PORTC	*((u8*)0x35)
#define PINC	*((volatile u8*)0x33)

#define DDRD	*((u8*)0x31)
#define PORTD	*((u8*)0x32)
#define PIND	*((volatile u8*)0x30) /*read only register for processor,
										to prevent optimizer from register allocation*/


#endif /* DIO_PRIV_H_ */
