/*
 * L298_DC_MOTOR_config.c
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "L298_DC_MOTOR_config.h"

PINS_MOTORS MOTOR1 =
{
		.motor[0] = PIND4,
		.motor[1] = PIND5,
};

PINS_MOTORS MOTOR2 =
{
		.motor[0] = PIND6,
		.motor[1] = PIND7,
};
