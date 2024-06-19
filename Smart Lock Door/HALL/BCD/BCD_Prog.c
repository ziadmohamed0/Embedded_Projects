/*
 * BCD_Prog.c
 *
 *  Created on: May 27, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "BCD_Init.h"

/*********** FUNCTIONS DEFIN ***********/
/**
 * @brief  : BCD 7-SEGMENT initialization function by initialization all Directions of
 *           pins of 7-SEGMENT is DIRECTION_PIN_OUTPUT
 * @param1 : copyBCDNum
 * @retVal : void
 */
void BCD_init(_BCD_PINS_ copyBCDNum)
{
#if (_7SEG_TYPE == COMMON_ANODE)
	DIO_setPinDIR(copyBCDNum.ENABLE_PIN, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyBCDNum.PIN1, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyBCDNum.PIN2, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyBCDNum.PIN3, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyBCDNum.PIN4, _DIRECTION_PIN_OUTPUT);
#elif	(_7SEG_TYPE == COMMON_CATHOD)
	DIO_setPinDIR(copyBCDNum.ENABLE_PIN, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyBCDNum.PIN1, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyBCDNum.PIN2, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyBCDNum.PIN3, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyBCDNum.PIN4, _DIRECTION_PIN_OUTPUT);
#endif
	BCD_displayEN(copyBCDNum);
}

/**
 * @brief  : BCD 7-SEGMENT function to Set bit Enable 7-SEGMENT Display
 * 			 if 7-SEGMENT is COMMON_ANODE SET Enable bit STATUS_PIN_HIGH .
 * 			 if 7-SEGMENT is COMMON_CATHOD SET Enable bit STATUS_PIN_LOW.
 * @param1 : copyBCDNum
 * @retVal : void
 */
void BCD_displayEN(_BCD_PINS_ copyBCDNum)
{
#if (_7SEG_TYPE == COMMON_ANODE)
	DIO_setPinVAL(copyBCDNum.ENABLE_PIN ,_STATUS_PIN_HIGH);
#elif (_7SEG_TYPE == COMMON_CATHOD)
	DIO_setPinVAL(copyBCDNum.ENABLE_PIN ,_STATUS_PIN_LOW);
#endif
}

/**
 * @brief  : BCD 7-SEGMENT function to Set bit Enable 7-SEGMENT Display
 * 			 if 7-SEGMENT is COMMON_ANODE SET Enable bit STATUS_PIN_LOW .
 * 			 if 7-SEGMENT is COMMON_CATHOD SET Enable bit STATUS_PIN_HIGH.
 * @param1 : copyBCDNum
 * @retVal : void
 */
void BCD_displayDIS(_BCD_PINS_ copyBCDNum)
{
#if (_7SEG_TYPE == COMMON_ANODE)
	DIO_setPinVAL(copyBCDNum.ENABLE_PIN ,_STATUS_PIN_LOW);
#elif (_7SEG_TYPE == COMMON_CATHOD)
	DIO_setPinVAL(copyBCDNum.ENABLE_PIN ,_STATUS_PIN_HIGH);
#endif
}

/**
 * @brief  : BCD 7-SEGMENT function to Write Number in 7-SEGMENT Display
 * 			 & if Number Greater Than 9 the 7-SEGMENT Display of
 * 			 else  Write Number in 7-SEGMENT Display
 * @param1 : copyBCDNum
 * @param2 : copyNumber
 * @retVal : void
 */
void BCD_displayNum(_BCD_PINS_ copyBCDNum, uint_8 copyNumber)
{
	if(copyNumber <= 9)
	{
		DIO_setPinVAL(copyBCDNum.PIN1,  copyNumber & 0x01);
		DIO_setPinVAL(copyBCDNum.PIN2, (copyNumber >> 1) & 0x01);
		DIO_setPinVAL(copyBCDNum.PIN3, (copyNumber >> 2) & 0x01);
		DIO_setPinVAL(copyBCDNum.PIN4, (copyNumber >> 3) & 0x01);
	}
	else
	{
		BCD_displayDIS(copyBCDNum);
	}
}


