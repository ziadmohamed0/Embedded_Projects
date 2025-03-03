/*
 * Dc_Motor_Config.h
 *
 *  Created on: Mar 22, 2024
 *      Author: ziad
 */

#ifndef HALL_DC_MOTOR_DC_MOTOR_CONFIG_H_
#define HALL_DC_MOTOR_DC_MOTOR_CONFIG_H_

/********** SECTION : Includes **********/
#include "../../Mcal/DIO/dio_Init.h"
/********** SECTION : STRUCTS **********/
typedef struct{
	u8 IN1;
	u8 IN2;
	u8 ENA;
}motor1;

typedef struct{
	u8 IN3;
	u8 IN4;
	u8 ENB;
}motor2;

/********** SECTION : VARIABLES **********/
motor1 m1;
motor2 m2;


#endif /* HALL_DC_MOTOR_DC_MOTOR_CONFIG_H_ */
