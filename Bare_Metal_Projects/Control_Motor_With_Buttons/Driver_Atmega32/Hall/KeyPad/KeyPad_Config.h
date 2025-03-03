/*
 * KeyPad_Config.h
 *
 *  Created on: Apr 7, 2024
 *      Author: ziad
 */

#ifndef HALL_KEYPAD_KEYPAD_CONFIG_H_
#define HALL_KEYPAD_KEYPAD_CONFIG_H_

/********** SECTION : Includes **********/
#include "../../Mcal/DIO/dio_Init.h"

/********** SECTION : Macros **********/
#define KeyPad_Rows		4
#define KeyPad_Coulmn	4

/********** SECTION : Structs **********/
typedef struct {
	u8 Pins_Row[KeyPad_Rows];
	u8 Pins_Coulmn[KeyPad_Coulmn];
}KeyPad;

/********** SECTION : Variables Declarations **********/
KeyPad KeyPad_1;
u8 Keypad_Buttons[KeyPad_Rows][KeyPad_Coulmn];

#endif /* HALL_KEYPAD_KEYPAD_CONFIG_H_ */
