/*
 * DIO_Config.h
 *
 *  Created on: Jun 12, 2024
 *      Author: ziad
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

/*********** INCLUDES ***********/
#include "DIO_Reg.h"

/*********** PINS CONFIG***********/
	/* ----- STATUS PINS ----- */
typedef enum
{
	_STATUS_PIN_LOW,
	_STATUS_PIN_HIGH,
	_STATUS_PIN_TOGGLE
}_STATUS_PINS;

	/* ----- DIRECTION PINS ----- */
typedef enum
{
	_DIRECTION_PIN_INPUT,
	_DIRECTION_PIN_OUTPUT
}_DIRECTION_PINS;

/*********** PORTS CONFIG***********/
	/* ----- STATUS PORTS ----- */
typedef enum
{
	_STATUS_PORT_LOW = 0x00,
	_STATUS_PORT_HIGH = 0xFF
}_STATUS_PORTS;

	/* ----- DIRECTION PORTS ----- */
typedef enum
{
	_DIRECTION_PORT_INPUT = 0x00,
	_DIRECTION_PORT_OUTPUT = 0xFF
}_DIRECTION_PORTS;

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
