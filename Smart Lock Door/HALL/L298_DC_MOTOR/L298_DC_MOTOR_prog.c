/*
 * L298_DC_MOTOR_prog.c
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "L298_DC_MOTOR_init.h"

/*********** FUNCTIONS DEFIN ***********/
/**
  * @brief   : Motors Initialization H-bridge l298 by Configure all pin IN0 ~ IN4 output.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_init(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2)
{
	for(uint_8 count = Zero_INIT ; count < 2 ; count++)
	{
		DIO_setPinDIR(copyMotor1.motor[count], _DIRECTION_PIN_OUTPUT);
		DIO_setPinDIR(copyMotor2.motor[count], _DIRECTION_PIN_OUTPUT);
	}
}

/**
  * @brief   : Motors move forward by configure pin high & next pin low.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorForward(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2)
{
	DIO_setPinVAL(copyMotor1.motor[0], _STATUS_PIN_HIGH);
	DIO_setPinVAL(copyMotor1.motor[1], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor2.motor[0], _STATUS_PIN_HIGH);
	DIO_setPinVAL(copyMotor2.motor[1], _STATUS_PIN_LOW);
}

/**
  * @brief   : Motors move forward by configure pin low & next pin high.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorReverse(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2)
{
	DIO_setPinVAL(copyMotor1.motor[0], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor1.motor[1], _STATUS_PIN_HIGH);
	DIO_setPinVAL(copyMotor2.motor[0], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor2.motor[1], _STATUS_PIN_HIGH);
}

/**
  * @brief   : Motors move forward by configure all pins high but right motor in4 low.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorRight(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2)
{
	DIO_setPinVAL(copyMotor1.motor[0], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor1.motor[1], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor2.motor[0], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor2.motor[1], _STATUS_PIN_HIGH);
}

/**
  * @brief   : Motors move forward by configure all pins high but left motor in2 low.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorLeft(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2)
{
	DIO_setPinVAL(copyMotor1.motor[0], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor1.motor[1], _STATUS_PIN_HIGH);
	DIO_setPinVAL(copyMotor2.motor[0], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor2.motor[1], _STATUS_PIN_LOW);
}

/**
  * @brief   : Motors move forward by configure all pins low.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorStop(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2)
{
	DIO_setPinVAL(copyMotor1.motor[0], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor1.motor[1], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor2.motor[0], _STATUS_PIN_LOW);
	DIO_setPinVAL(copyMotor2.motor[1], _STATUS_PIN_LOW);
}
