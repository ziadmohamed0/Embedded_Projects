/*
 * KeyPad_Init.h
 *
 *  Created on: Apr 7, 2024
 *      Author: ziad
 */

#ifndef HALL_KEYPAD_KEYPAD_INIT_H_
#define HALL_KEYPAD_KEYPAD_INIT_H_

/********** SECTION : Includes **********/
#include "KeyPad_Config.h"
#include "../../Mcal/External_Interrupt/External_Interrupts_Init.h"

/********** SECTION : Functions Declarations **********/
void KeyPad_Init(KeyPad CopyKeyPad);
void KeyPad_getValue(KeyPad CopyKeyPad, u8 *CopyValue);

#endif /* HALL_KEYPAD_KEYPAD_INIT_H_ */
