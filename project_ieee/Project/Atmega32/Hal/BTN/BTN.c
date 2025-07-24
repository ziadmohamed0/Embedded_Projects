/*
 * BTN.c
 *
 *  Created on: Jul 9, 2025
 *      Author: ziad
 */

#include "BTN.h"

void BUTTON_init() {
	GPIO_vSetPinDirection(btn_Port, btn_Pin, Port_Output);
}

uint8 BUTTON_read() {
	return GPIO_u8GetPinValue(btn_Port, btn_Pin);
}
