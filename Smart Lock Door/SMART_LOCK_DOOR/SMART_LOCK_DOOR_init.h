/*
 * SMART_LOCK_DOOR_init.h
 *
 *  Created on: Jun 19, 2024
 *      Author: ziad
 */

#ifndef PROJECTS_SMART_LOCK_DOOR_SMART_LOCK_DOOR_INIT_H_
#define PROJECTS_SMART_LOCK_DOOR_SMART_LOCK_DOOR_INIT_H_

/*********** INCLUDES ***********/
#include "../../MCAL/DIO/DIO_Init.h"
//#include "../../HALL/BCD/BCD_Init.h"
#include "../../HALL/KEYPAD/KEYPAD_Init.h"
#include "../../HALL/LCD/LCD_Init.h"
#include "../../HALL/L298_DC_MOTOR/L298_DC_MOTOR_init.h"

/*********** GLOBAL AREA ***********/
#define MAX_SIZE	9
/*********** GLOBAL AREA ***********/


/*********** ISR FUNCTION ***********/

/*********** FUNCTIONS DEFIN ***********/
/**
 * @brief  : smart lock door project function setup all initializations
 * 			 & directions of all modules.
 * @param1 : void
 * @RetVal : void
 */
void smartDoorLock_START(void);

/**
 * @brief  : smart lock door project function to looping if password is correct
 * 			then welcome in home else you have a three attempts then alarm is on.
 * @param1 : void
 * @RetVal : void
 */
uint_8 smartDoorLock_Three_attempts(void);

#endif /* PROJECTS_SMART_LOCK_DOOR_SMART_LOCK_DOOR_INIT_H_ */
