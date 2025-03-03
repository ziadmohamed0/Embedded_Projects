
#ifndef AVR_REG_H_
#define AVR_REG_H_

/*
 * NULL
 */
//#define NULL  ((void*)0)

/*
 * DIO REGISTERS
 */

#define PORTA 	*((volatile u8*) 0x3B)
#define DDRA  	*((volatile u8*) 0x3A)
#define PINA  	*((volatile u8*) 0x39)

#define PORTB 	*((volatile u8*) 0x38)
#define DDRB  	*((volatile u8*) 0x37)
#define PINB  	*((volatile u8*) 0x36)

#define PORTC_REG 	*((volatile u8*) 0x35)
#define DDRC  	*((volatile u8*) 0x34)
#define PINC  	*((volatile u8*) 0x33)

#define PORTD_REG 	*((volatile u8*) 0x32)
#define DDRD  	*((volatile u8*) 0x31)
#define PIND  	*((volatile u8*) 0x30)

/*
 * INTERRUPT REGISTERS
 */

#define MCUCR 	*((volatile u8*) 0x55)
#define MCUCSR	*((volatile u8*) 0x54)
#define GICR 	*((volatile u8*) 0x5b)
#define SREG  	*((volatile u8*) 0x5f)
#define GIFR  	*((volatile u8*) 0x5a)

/*
 * TIMER RESIGTERS
 */

/*TIMSK*/
#define TIMSK	*((volatile u8*) 0x59)

/*TIFR*/
#define TIFR	*((volatile u8*) 0x58)

/*TCCR*/
#define TCCR0	*((volatile u8*) 0x53)
#define TCCR1A	*((volatile u8*) 0x4f)
#define TCCR1B	*((volatile u8*) 0x4e)
#define TCCR2	*((volatile u8*) 0x45)

/*TCNT*/
#define TCNT0	*((volatile u8*) 0x52)

#define TCNT1H	*((volatile u8*) 0x4d)
#define TCNT1L	*((volatile u8*) 0x4c)

#define TCNT1	*((volatile u16*) 0x4c)

#define TCNT2	*((volatile u8*) 0x44)

/*OCR*/
#define OCR0	*((volatile u8*) 0x5c)
#define OCR1AH	*((volatile u8*) 0x4b)
#define OCR1AL	*((volatile u8*) 0x4a)

#define OCR1A	*((volatile u16*) 0x4a)

#define OCR1BH	*((volatile u8*) 0x49)
#define OCR1BL	*((volatile u8*) 0x48)

#define OCR1B	*((volatile u16*) 0x48)

#define OCR2	*((volatile u8*) 0x43)

/*
 * ADC REGISTERS
 */
#define ADMUX	*((volatile u8*) 0x27)
#define ADCSRA	*((volatile u8*) 0x26)
#define ADCH	*((volatile u8*) 0x25)
#define ADCL	*((volatile u8*) 0x24)

/*
 * UASRT REGISTERS
 */

#define UDR		*((volatile u8*) 0x2c)
#define UCSRA	*((volatile u8*) 0x2b)
#define UCSRB	*((volatile u8*) 0x2a)
#define UCSRC	*((volatile u8*) 0x40)
#define UBRRL	*((volatile u8*) 0x29)
#define UBRRH	*((volatile u8*) 0x40)

/*
 * SPI REGISTERS
 */

#define SPDR	*((volatile u8*) 0x2f)
#define SPSR	*((volatile u8*) 0x2e)
#define SPCR	*((volatile u8*) 0x2d)

#endif /* AVR_REG_H_ */
