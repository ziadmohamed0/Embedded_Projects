/*
 * BUZZ.c
 *
 *  Created on: Jul 9, 2025
 *      Author: ziad
 */

#include "BUZZ.h"

void Buzzer_init() {
	GPIO_vSetPinDirection(Buzzr_port, Buzzr_pin, Pin_Output);
}

void Buzzer_ON() {
	GPIO_vSetPinValue(Buzzr_port, Buzzr_pin, Pin_High);
}

void Buzzer_OFF() {
	GPIO_vSetPinValue(Buzzr_port, Buzzr_pin, Pin_High);
}
