/*
 * LCD_Privet.h
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */

#ifndef HALL_LCD_LCD_PRIVET_H_
#define HALL_LCD_LCD_PRIVET_H_

/*********** INCLUDES ***********/
#include "../../MCAL/DIO/DIO_Init.h"
/*********** DISPLAY CONTROL INSTRUCTION ***********/
typedef enum
{
	_LCD_CLEAR_DIS    = 0x01,
	_LCD_RETURN_HOME  = 0x02,
	_LCD_ENTERY_INC   = 0x06,
	_LCD_ENTERY_DEC   = 0x04,
	_LCD_DISPLAY_ON   = 0x0C,
	_LCD_DISPLAY_OFF  = 0x08,
	_LCD_CURSOR_ON    = 0x0E,
	_LCD_CURSOR_BLINK = 0x0F,
	_LCD_SHIFT_RIGHT  = 0x1C,
	_LCD_SHIFT_LEFT   = 0x18,
	_LCD_8_BIT_MODE   = 0x38,
	_LCD_4_BIT_MODE   = 0x28,
	_LCD_CG_RAM_SET   = 0x40,
	_LCD_DD_RAM_SET   = 0x80
}_LCD_COMMANDS;

/*********** LCD ROWS ***********/
#define LM044_LCD	0
#define LM04L_LCD	1
#define LM32L_LCD	2

#define _Rows_LCD_TYPE LM044_LCD

#if (_Rows_LCD_TYPE == LM044_LCD)
typedef enum
{
	ADDREES_ROW_1 = 0x80,
	ADDREES_ROW_2 = 0xC0,
	ADDREES_ROW_3 = 0x94,
	ADDREES_ROW_4 = 0xD4
}ROWS;
#elif 	(_Rows_LCD_TYPE == LM04L_LCD)
typedef enum
{
	ADDREES_ROW_1 = 0x80,
	ADDREES_ROW_2 = 0xC0,
	ADDREES_ROW_3 = 0x90,
	ADDREES_ROW_4 = 0xD0
}ROWS;
#elif 	(_Rows_LCD_TYPE == LM32L_LCD)
typedef enum
{
	ADDREES_ROW_1 = 0x00,
	ADDREES_ROW_2 = 0x40
}ROWS;
#endif



#endif /* HALL_LCD_LCD_PRIVET_H_ */
