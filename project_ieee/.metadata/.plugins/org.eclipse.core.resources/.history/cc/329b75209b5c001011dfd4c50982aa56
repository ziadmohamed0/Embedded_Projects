/*
 * PCD_prog.c
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#include "PCD_init.h"


extern uint8 Pin_arr[4];

void BCD_vidInit(){
	for(int i = 0 ; i < 4; i++) {
		GPIO_vSetPinDirection(BCD_port, Pin_arr[i], Pin_Output);
	}
	GPIO_vSetPinDirection(BCD_port, BCD_EN, Pin_Output);
	GPIO_vSetPinValue(BCD_port, BCD_EN, Pin_High);
}



void BCD_writeNumber(uint8_t copyNumber) {
	GPIO_vSetPinValue(BCD_port, Pin_arr[0], (copyNumber & 0x01));
	GPIO_vSetPinValue(BCD_port, Pin_arr[1], ((copyNumber >> 1) & 0x01));
	GPIO_vSetPinValue(BCD_port, Pin_arr[2], ((copyNumber >> 2) & 0x01));
	GPIO_vSetPinValue(BCD_port, Pin_arr[3], ((copyNumber >> 3) & 0x01));
}
