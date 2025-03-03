/*
 * INTERRUPT_config.h
 *
 *  Created on: Jun 14, 2024
 *      Author: ziad
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_CONFIG_H_
#define MCAL_INTERRUPT_INTERRUPT_CONFIG_H_

/*********** INCLUDES ***********/
#include "INTERRUPT_reg.h"

/*********** EXTERNAL INTERRUPT NUMBERS ***********/
typedef enum
{
	INT0,
	INT1,
	INT2
}_NUM_EX_INTERRUPT;

/*********** SENSE SELECT ***********/
typedef enum
{
	LOW,
	ANY,
	FALLING,
	RISING
}_SENSE_SELECT;

#endif /* MCAL_INTERRUPT_INTERRUPT_CONFIG_H_ */
