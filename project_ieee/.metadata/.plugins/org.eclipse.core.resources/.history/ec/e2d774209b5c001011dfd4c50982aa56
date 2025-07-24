/*
 * KEYPAD_prog.c
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */
#include "KEYPAD_init.h"

extern uint8 Pattern[NO_ROW][NO_COL];
extern uint8 Row_Pin[NO_ROW];
extern uint8 Col_Pin[NO_COL];

void keypad_vidInit(){
	for(int i = 0; i < NO_ROW; i++) {
		GPIO_vSetPinDirection(KEYPAD_Port, Row_Pin[i], Pin_Input);
		GPIO_vSetPinValue(KEYPAD_Port, Row_Pin[i], Pin_High);
	}

	for(int i = 0; i < NO_COL; i++) {
		GPIO_vSetPinDirection(KEYPAD_Port, Col_Pin[i], Pin_Output);
		GPIO_vSetPinValue(KEYPAD_Port, Col_Pin[i],Pin_High);
	}
}


uint8 keypad_u8Stat(uint8 *ptr){
	uint8 i, j;
	uint8 flag = 0;
	for(i = 0 ; i < 4 ; i++){
		GPIO_vSetPinValue(KEYPAD_Port, Col_Pin[i], Pin_Low);
		for(j = 0 ; j < 4 ; j++){
			if(GPIO_u8GetPinValue(KEYPAD_Port, Row_Pin[j]) == 0){

				*ptr = Pattern[j][i];
				flag = 1;
				while(GPIO_u8GetPinValue(KEYPAD_Port, Row_Pin[j])==0);
				_delay_ms(20);
				GPIO_vSetPinValue(KEYPAD_Port, Col_Pin[i],Pin_High);
				return flag;
			}
		}
		GPIO_vSetPinValue(KEYPAD_Port, Col_Pin[i],Pin_High);
	}
	return flag;
}
