/*
 * L298_DC_MOTOR_init.h
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

#ifndef HALL_L298_DC_MOTOR_L298_DC_MOTOR_INIT_H_
#define HALL_L298_DC_MOTOR_L298_DC_MOTOR_INIT_H_

/*********** INCLUDES ***********/
#include "L298_DC_MOTOR_config.h"

/*********** FUNCTIONS DECLER ***********/
/**
  * @brief   : Motors Initialization H-bridge l298 by Configure all pin IN0 ~ IN4 output.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_init(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2);

/**
  * @brief   : Motors move forward by configure pin high & next pin low.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorForward(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2);

/**
  * @brief   : Motors move forward by configure pin low & next pin high.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorReverse(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2);

/**
  * @brief   : Motors move forward by configure all pins high but right motor in4 low.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorRight(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2);

/**
  * @brief   : Motors move forward by configure all pins high but left motor in2 low.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorLeft(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2);

/**
  * @brief   : Motors move forward by configure all pins low.
  * @param1  : copyMotor1
  * @param1  : copyMotor2
  */
void DCMOTOR_motorStop(PINS_MOTORS copyMotor1 , PINS_MOTORS copyMotor2);

#endif /* HALL_L298_DC_MOTOR_L298_DC_MOTOR_INIT_H_ */
