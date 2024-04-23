/*
 * Lcd_Config.h
 *
 *  Created on: Mar 24, 2024
 *      Author: ziad
 */

#ifndef HALL_LCD_LCD_CONFIG_H_
#define HALL_LCD_LCD_CONFIG_H_

/********** SECTION : Includes **********/
#include "../../Mcal/DIO/dio_Init.h"

/********** SECTION : Macros **********/

#define _LCD_8_Bit_Mood	0
#define _LCD_4_Bit_Mood	1

#define _LCD_Mood	_LCD_4_Bit_Mood

/********** SECTION : STRUCTS **********/

#if _LCD_Mood ==  _LCD_8_Bit_Mood
typedef struct {
	u8	RS;
	u8	E;
	u8 port[8];
}LCD_8_MODE;

#elif _LCD_Mood == _LCD_4_Bit_Mood
typedef struct {
	u8	RS;
	u8	E;
	u8	Port[4];
}LCD_4_MODE;

#endif

/********** SECTION : VARIABLES **********/
#if _LCD_Mood ==  _LCD_8_Bit_Mood
LCD_8_MODE LCD_1;

#elif _LCD_Mood == _LCD_4_Bit_Mood
LCD_4_MODE LCD_2;

#endif
#endif /* HALL_LCD_LCD_CONFIG_H_ */
