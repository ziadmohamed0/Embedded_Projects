/*
 * BCD_Config.h
 *
 *  Created on: May 27, 2024
 *      Author: ziad
 */

#ifndef HALL_BCD_BCD_CONFIG_H_
#define HALL_BCD_BCD_CONFIG_H_

/*********** INCLUDES ***********/
#include "../../MCAL/DIO/DIO_Init.h"

/*********** PIN INIT ***********/
typedef struct
{
	uint_8 ENABLE_PIN;
	uint_8 PIN1;
	uint_8 PIN2;
	uint_8 PIN3;
	uint_8 PIN4;
}_BCD_PINS_;

/*********** 7-SEGMENT TYPE ***********/
#define COMMON_CATHOD	0
#define COMMON_ANODE	1
#define	_7SEG_TYPE	 COMMON_ANODE

/*********** BCD ***********/
_BCD_PINS_	_7_SEGMENT;

#endif /* HALL_BCD_BCD_CONFIG_H_ */
