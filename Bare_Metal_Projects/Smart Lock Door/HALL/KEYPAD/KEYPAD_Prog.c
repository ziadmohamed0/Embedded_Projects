/*
 * KEYPAD_Prog.c
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "KEYPAD_Init.h"

/*********** FUNCTIONS DEFIN ***********/
/**
 * @brief  : keypad initialization function by initialization ROW PINS Directions
 *           keypad is DIRECTION_PIN_INPUTS & COLUMN PINS Directions DIRECTION_PIN_OUTPUT.
 * @param1 : copyKEYPAD
 * @retVal : void
 */
void KEYPAD_init(PINS_KEYPAD copyKEYPAD)
{
	for(uint_8 count1 = Zero_INIT ; count1 < MAX_ROWS ; count1++)
	{
		DIO_setPinDIR(copyKEYPAD.ROWS[count1], _DIRECTION_PIN_INPUT);
		DIO_setPinVAL(copyKEYPAD.ROWS[count1], _STATUS_PIN_HIGH);
	}

	for (uint_8 count2 = Zero_INIT ; count2 < MAX_COLUMN; count2++)
	{
		DIO_setPinDIR(copyKEYPAD.COLUMNS[count2], _DIRECTION_PIN_OUTPUT);
		DIO_setPinVAL(copyKEYPAD.COLUMNS[count2], _STATUS_PIN_HIGH);
	}
}

/**
 * @brief  : Keypad function to get data from column & row pins .
 * @param1 : copyKEYPAD
 * @retVal : void
 */
Return_Value KEYPAD_getData(PINS_KEYPAD copyKEYPAD , uint_8 *copyKeypadValue)
{
	uint_8 count1;
	uint_8 count2;
	uint_8 flag = 0;

	for(count1 = 0 ; count1 < 4 ; count1++)
	{
		DIO_setPinVAL(copyKEYPAD.COLUMNS[count1],_STATUS_PIN_LOW);
		for(count2 = 0 ; count2 < 4 ; count2++)
		{
			if(DIO_getPinVAL(copyKEYPAD.ROWS[count2]) == 0)
			{
				*copyKeypadValue = PATTIRN_KEYPAD[count2][count1];
				flag = 1;
				while(DIO_getPinVAL(copyKEYPAD.ROWS[count2]) == 0);
				_delay_ms(10);
				DIO_setPinVAL(copyKEYPAD.COLUMNS[count1],_STATUS_PIN_HIGH);
				return flag;
			}
		}
		DIO_setPinVAL(copyKEYPAD.COLUMNS[count1],_STATUS_PIN_HIGH);
	}
	return flag;
}
