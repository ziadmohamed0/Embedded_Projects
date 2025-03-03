/*
 * ADC_config.h
 *
 *  Created on: Jun 15, 2024
 *      Author: ziad
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*********** INCLUDES ***********/
#include "ADC_reg.h"

/*********** ADC CHANNELS ***********/
typedef enum
{
	CHANAL0,
	CHANAL1,
	CHANAL2,
	CHANAL3,
	CHANAL4,
	CHANAL5,
	CHANAL6,
	CHANAL7
}_ADC_CHANNELS;

/*********** ADC VOLTAGE REFERENCE ***********/
#define AREF		1
#define AVCC		2
#define INTERNAL	3

#define _ADC_VOLT	AVCC

/*********** ADC DIVISION FACTOR ***********/
#define _ADC_FACTOR_No	(uint_8)0x00
#define _ADC_FACTOR_2	(uint_8)0x01
#define _ADC_FACTOR_4	(uint_8)0x02
#define _ADC_FACTOR_8	(uint_8)0x03
#define _ADC_FACTOR_16	(uint_8)0x04
#define _ADC_FACTOR_32	(uint_8)0x05
#define _ADC_FACTOR_64	(uint_8)0x06
#define _ADC_FACTOR_128	(uint_8)0x07
#define _ADC_CLEAR_MASK (uint_8)0xE0

#define _ADC_PRESCALER_SELECT	_ADC_FACTOR_No

/*********** ADC AUTO TRIGGER ***********/
#define FREE_RUNNING_MODE			0
#define ANALOG_COMPARATOR_MODE		1
#define EXTERNAL_INTERRUPT_MODE		2
#define TIMER0_COMPARE_MODE			3
#define TIMER0_OVERFLOW_MODE		4
#define TIMER1_COMPARE_B_MODE		5
#define TIMER1_OVERFLOW_MODE		6
#define TIMER1_CAPTURE_MODE			7

#define ADC_AUTO_TRIGGER	FREE_RUNNING_MODE

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
