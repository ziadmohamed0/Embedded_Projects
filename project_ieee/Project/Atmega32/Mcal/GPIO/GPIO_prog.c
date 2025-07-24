/*
 * GPIO_prog.c
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */
#include "GPIO_init.h"

volatile uint8 *DDR_reg[4]  = {&DDRA, &DDRB, &DDRC, &DDRD};
volatile uint8 *PORT_reg[4] = {&PORTA, &PORTB, &PORTC, &PORTD};
volatile uint8 *PIN_reg[4]  = {&PINA, &PINB, &PINC, &PIND};


	/* GPIOx Pins APIs */
void GPIO_vSetPinDirection(uint8 copyPort, uint8 copyPin, uint8 copyDirection) {
	switch(copyDirection){
		case Pin_Output:
			SET_BIT(*(DDR_reg[copyPort]), copyPin);
			break;
		case Pin_Input:
			CLR_BIT(*(DDR_reg[copyPort]), copyPin);
			break;
		default:
			/* Nothing */
			break;
	}
}

void GPIO_vSetPinValue(uint8 copyPort, uint8 copyPin, uint8 copyStatus) {
	switch(copyStatus){
		case Pin_High:
			SET_BIT(*(PORT_reg[copyPort]), copyPin);
			break;
		case Pin_Low:
			CLR_BIT(*(PORT_reg[copyPort]), copyPin);
			break;
		case Pin_Toggle:
			TOGGLE_BIT(*(PORT_reg[copyPort]), copyPin);
			break;
		default:
			/* Nothing */
			break;
	}
}

uint8 GPIO_u8GetPinValue(uint8 copyPort, uint8 copyPin) {
	uint8 retVal = 0;
	retVal = GET_BIT(*(PIN_reg[copyPort]), copyPin);
	return retVal;
}


	/* GPIOx Ports APIs */
void GPIO_vSetPortDirection(uint8 copyPort, uint8 copyDirection) {
	*DDR_reg[copyPort] = copyDirection;
}

void GPIO_vSetPortValue(uint8 copyPort, uint8 copyStatus) {
	*PORT_reg[copyPort] = copyStatus;
}

uint8 GPIO_u8GetPortValue(uint8 copyPort) {
	uint8 retVal = 0;
	retVal = *PIN_reg[copyPort];
	return retVal;
}
