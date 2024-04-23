/*
 * Lcd_Config.c
 *
 *  Created on: Mar 24, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "Lcd_Config.h"

/********** SECTION : Variable_Definations **********/
#if _LCD_Mood ==  _LCD_8_Bit_Mood
LCD_8_MODE LCD_1 = {

		.port[0] = PortA_p0,
		.port[1] = PortA_p1,
		.port[2] = PortA_p2,
		.port[3] = PortA_p3,
		.port[4] = PortA_p4,
		.port[5] = PortA_p5,
		.port[6] = PortA_p6,
		.port[7] = PortA_p7,
		.RS = PortB_p6,
		.E  = PortB_p7
};

#elif _LCD_Mood ==  _LCD_4_Bit_Mood

LCD_4_MODE LCD_2 = {

		.Port[0] = PortA_p0,
		.Port[1] = PortA_p1,
		.Port[2] = PortA_p2,
		.Port[3] = PortA_p3,
		.RS = PortA_p4,
		.E  = PortA_p5,
};

#endif

