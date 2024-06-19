/*
 * LCD_Config.h
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */

#ifndef HALL_LCD_LCD_CONFIG_H_
#define HALL_LCD_LCD_CONFIG_H_

/*********** INCLUDES ***********/
#include "LCD_Privet.h"

/*********** LCD TYPES ***********/
typedef enum
{
	_LM044_LCD,	//4 x 20
	_LM04L_LCD,	//4 x 16
	_LM32L_LCD,	//2 x 20
	_LM16L_LCD,	//2 x 16
}TYPES_LCD;

/*********** LCD MODE ***********/
#define	_8_BIT_MODE_LCD	0	// D0 ~ D7
#define	_4_BIT_MODE_LCD	1	// D4 ~ D7

#define _LCD_MODE	_4_BIT_MODE_LCD

/*********** LCD PINS ***********/
#if (_LCD_MODE == _8_BIT_MODE_LCD)
typedef struct
{
	uint_8 PORT_DATA_PIN_NUM;
	uint_8 EN;
	uint_8 RS;
	uint_8 D[8];
}PINS_LCD;
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
typedef struct
{
	uint_8 EN;
	uint_8 RS;
	uint_8 D[4];
}PINS_LCD;
#endif

typedef enum
{
	ROW1,
	ROW2,
	ROW3,
	ROW4,
}ROW_NUM;
/*********** LCDS ***********/
PINS_LCD LCD;

#endif /* HALL_LCD_LCD_CONFIG_H_ */
