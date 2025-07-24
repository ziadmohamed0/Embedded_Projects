/*
 * DC_MOTOR.c
 *
 *  Created on: Jul 9, 2025
 *      Author: ziad
 */

#include "DC_MOTOR.h"

void DcMotor_Init(void) {
	GPIO_vSetPinDirection(DcMotorIN1_port, DcMotorIN1_pin, Pin_Output);
	GPIO_vSetPinDirection(DcMotorIN2_port, DcMotorIN2_pin, Pin_Output);
	GPIO_vSetPinDirection(DcMotorEN_port, DcMotorEN_pin, Pin_Output);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed) {
	switch(state){
		case forward:
			GPIO_vSetPinValue(DcMotorIN1_port, DcMotorIN1_pin, Pin_High);
			GPIO_vSetPinValue(DcMotorIN2_port, DcMotorIN2_pin, Pin_Low);
			break;
		case reverse:
			GPIO_vSetPinValue(DcMotorIN1_port, DcMotorIN1_pin, Pin_Low);
			GPIO_vSetPinValue(DcMotorIN2_port, DcMotorIN2_pin, Pin_High);
			break;
		case stop:
			GPIO_vSetPinValue(DcMotorIN1_port, DcMotorIN1_pin, Pin_Low);
			GPIO_vSetPinValue(DcMotorIN2_port, DcMotorIN2_pin, Pin_Low);
			break;
	}
	PWM_Timer0_Start(speed);
}



