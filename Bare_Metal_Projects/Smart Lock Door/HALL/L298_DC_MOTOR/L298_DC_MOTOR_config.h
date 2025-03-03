/*
 * L298_DC_MOTOR_config.h
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

#ifndef HALL_L298_DC_MOTOR_L298_DC_MOTOR_CONFIG_H_
#define HALL_L298_DC_MOTOR_L298_DC_MOTOR_CONFIG_H_

/*********** INCLUDES ***********/
#include "../../MCAL/DIO/DIO_Init.h"

/*********** MOTOR PINS ***********/
typedef struct
{
	uint_8 motor[2];
}PINS_MOTORS;

/*********** MOTORS ***********/
PINS_MOTORS MOTOR1;
PINS_MOTORS MOTOR2;

#endif /* HALL_L298_DC_MOTOR_L298_DC_MOTOR_CONFIG_H_ */
