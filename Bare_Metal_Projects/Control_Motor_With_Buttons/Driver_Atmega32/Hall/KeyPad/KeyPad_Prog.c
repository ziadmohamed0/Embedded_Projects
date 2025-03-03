/*
 * KeyPad_Prog.c
 *
 *  Created on: Apr 7, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "KeyPad_Init.h"

/********** SECTION : Functions Definitions **********/
void KeyPad_Init(KeyPad CopyKeyPad)
{
	u8 Rows_Counter = Initial_Counter ;
	u8 Columns_Counter = Initial_Counter;

	for(Rows_Counter = Initial_Counter ; Rows_Counter < KeyPad_Rows; Rows_Counter++)
	{
		Dio_setPinDir(CopyKeyPad.Pins_Row[Rows_Counter],Direction_Pin_Output);
//		Dio_setPinVal(CopyKeyPad.Pins_Row[Rows_Counter], Status_Pin_Low);
	}

	for(Columns_Counter = Initial_Counter ; Columns_Counter < KeyPad_Coulmn; Columns_Counter++)
	{
		Dio_setPinDir(CopyKeyPad.Pins_Coulmn[Columns_Counter],Direction_Pin_Input);
	}
}

void KeyPad_getValue(KeyPad CopyKeyPad, u8 *CopyValue)
{
	u8 Rows_Counter = Initial_Counter ;
	u8 Columns_Counter = Initial_Counter;
	u8 Counter_1 = Initial_Counter;
	u8 Logic_Value = Initial_Counter;

	for(Rows_Counter = Initial_Counter ; Rows_Counter < KeyPad_Rows; Rows_Counter++)
	{
		for(Counter_1 = Initial_Counter ; Counter_1 < KeyPad_Rows ; Counter_1++)
		{
			Dio_setPinVal(CopyKeyPad.Pins_Row[Counter_1], Status_Pin_Low);
		}

		Dio_setPinVal(CopyKeyPad.Pins_Row[Rows_Counter], Status_Pin_High);
		_delay_ms(50);
		for(Columns_Counter = Initial_Counter ; Columns_Counter < KeyPad_Coulmn; Columns_Counter++)
		{
			Dio_getPinVal(CopyKeyPad.Pins_Coulmn[Columns_Counter]);
			_delay_ms(50);

			if(Logic_Value == Status_Pin_High)
			{
				*CopyValue = &(Keypad_Buttons[Rows_Counter][Columns_Counter]);
			}
		}
	}
}
