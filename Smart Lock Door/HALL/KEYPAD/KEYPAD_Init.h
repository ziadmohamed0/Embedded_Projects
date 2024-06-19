/*
 * KEYPAD_Init.h
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */

#ifndef HALL_KEYPAD_KEYPAD_INIT_H_
#define HALL_KEYPAD_KEYPAD_INIT_H_

/*********** INCLUDES ***********/
#include "KEYPAD_Config.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : keypad initialization function by initialization ROW PINS Directions
 *           keypad is DIRECTION_PIN_INPUTS & COLUMN PINS Directions DIRECTION_PIN_OUTPUT.
 * @param1 : copyKEYPAD
 * @retVal : void
 */
void KEYPAD_init(PINS_KEYPAD copyKEYPAD);

/**
 * @brief  : Keypad function to get data from column & row pins .
 * @param1 : copyKEYPAD
 * @retVal : void
 */
Return_Value KEYPAD_getData(PINS_KEYPAD copyKEYPAD, uint_8 *copyKeypadValue);

#endif /* HALL_KEYPAD_KEYPAD_INIT_H_ */
