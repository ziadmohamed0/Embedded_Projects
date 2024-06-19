/*
 * ADC_reg.h
 *
 *  Created on: Jun 15, 2024
 *      Author: ziad
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

/*********** INCLUDES ***********/
#include "../INTERRUPT/INTERRUPT_init.h"

/*********** REGISTERS ***********/
#define SFIOR	*((volatile uint_8 *) 0x50)
#define ACSR	*((volatile uint_8 *) 0x28)
#define ADMUX	*((volatile uint_8 *) 0x27)
#define ADCSRA	*((volatile uint_8 *) 0x26)
#define ADCH	*((volatile uint_8 *) 0x25)
#define ADCL	*((volatile uint_8 *) 0x24)

/*********** BITS ***********/

	/* ----- ADMUX BITS ----- */
typedef enum
{
	MUX0,
	MUX1,
	MUX2,
	MUX3,
	MUX4,
	ADLAR,
	REFS0,
	REFS1
}BITS_ADMUX;

	/* ----- ADCSRA BITS ----- */
typedef enum
{
	ADPS0,
	ADPS1,
	ADPS2,
	ADIE,
	ADIF,
	ADATE,
	ADSC,
	ADEN
}BITS_ADCSRA;

	/* ----- SFIOR BITS ----- */
typedef enum
{
	ADTS0 = 5,
	ADTS1,
	ADTS2
}BITS_SFIOR;

#endif /* MCAL_ADC_ADC_REG_H_ */
