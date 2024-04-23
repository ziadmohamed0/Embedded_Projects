/*
 * Dc_Motor_Config.c
 *
 *  Created on: Mar 22, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "Dc_Motor_Config.h"

/********** SECTION : Variable_Definations **********/
motor1 m1 = {
		.IN1 = PortB_p0,
		.IN2 = PortB_p1,
		.ENA = PortB_p4
};

motor2 m2 = {
		.IN3 = PortB_p2,
		.IN4 = PortB_p3,
		.ENB = PortB_p5
};
