/*
 * KEYPAD_Config.h
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */

#ifndef HALL_KEYPAD_KEYPAD_CONFIG_H_
#define HALL_KEYPAD_KEYPAD_CONFIG_H_

/*********** INCLUDES ***********/
#include "../../MCAL/DIO/DIO_Init.h"

/*********** KEYPAD TYPES ***********/
#define _COLUMN_3	0
#define _COLUMN_4	1
#define _COLUMN_6	2

#define TYPE_KEYPAD _COLUMN_4

/*********** KEYPAD PINS ***********/
#if (TYPE_KEYPAD == _COLUMN_4)
typedef struct
{
	uint_8 ROWS[4];
	uint_8 COLUMNS[4];
}PINS_KEYPAD;

#define MAX_ROWS	(uint_8)4
#define MAX_COLUMN	(uint_8)4

uint_8 PATTIRN_KEYPAD[4][4];
#elif (TYPE_KEYPAD == _COLUMN_3)
typedef struct
{
	uint_8 ROWS[4];
	uint_8 COLUMNS[3];
}PINS_KEYPAD;

#define MAX_ROWS	(uint_8)4
#define MAX_COLUMN	(uint_8)3

uint_8 PATTIRN_KEYPAD[4][3];
#elif (TYPE_KEYPAD == _COLUMN_6)
typedef struct
{
	uint_8 ROWS[4];
	uint_8 COLUMNS[6];
}PINS_KEYPAD;

#define MAX_ROWS	(uint_8)4
#define MAX_COLUMN	(uint_8)6

uint_8 PATTIRN_KEYPAD[4][6];
#endif

/*********** KEYPAD PINS ***********/
PINS_KEYPAD KEYPAD;

#endif /* HALL_KEYPAD_KEYPAD_CONFIG_H_ */
