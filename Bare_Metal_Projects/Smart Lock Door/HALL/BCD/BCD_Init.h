/*
 * BCD_Init.h
 *
 *  Created on: May 27, 2024
 *      Author: ziad
 */

#ifndef HALL_BCD_BCD_INIT_H_
#define HALL_BCD_BCD_INIT_H_

/*********** INCLUDES ***********/
#include "BCD_Config.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : BCD 7-SEGMENT initialization function by initialization all Directions of
 *           pins of 7-SEGMENT is DIRECTION_PIN_OUTPUT
 * @param1 : copyBCDNum
 * @retVal : void
 */
void BCD_init(_BCD_PINS_ copyBCDNum);

/**
 * @brief  : BCD 7-SEGMENT function to Write Number in 7-SEGMENT Display
 * 			 & if Number Greater Than 9 the 7-SEGMENT Display of
 * 			 else  Write Number in 7-SEGMENT Display
 * @param1 : copyBCDNum
 * @param2 : copyNumber
 * @retVal : void
 */
void BCD_displayNum(_BCD_PINS_ copyBCDNum, uint_8 copyNumber);

/**
 * @brief  : BCD 7-SEGMENT function to Set bit Enable 7-SEGMENT Display
 * 			 if 7-SEGMENT is COMMON_ANODE SET Enable bit STATUS_PIN_HIGH .
 * 			 if 7-SEGMENT is COMMON_CATHOD SET Enable bit STATUS_PIN_LOW.
 * @param1 : copyBCDNum
 * @retVal : void
 */
void BCD_displayEN(_BCD_PINS_ copyBCDNum);

/**
 * @brief  : BCD 7-SEGMENT function to Set bit Enable 7-SEGMENT Display
 * 			 if 7-SEGMENT is COMMON_ANODE SET Enable bit STATUS_PIN_LOW .
 * 			 if 7-SEGMENT is COMMON_CATHOD SET Enable bit STATUS_PIN_HIGH.
 * @param1 : copyBCDNum
 * @retVal : void
 */
void BCD_displayDIS(_BCD_PINS_ copyBCDNum);

#endif /* HALL_BCD_BCD_INIT_H_ */
