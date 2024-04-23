/*
 * Lcd_Prog.c
 *
 *  Created on: Mar 24, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "Lcd_Init.h"

/********** SECTION : Functions Declarations **********/
#if _LCD_Mood ==  _LCD_8_Bit_Mood

static void LCD_8_SendEnable_Signal(LCD_8_MODE CopyLCD);
static void LCD_8_SetCursor_Position(LCD_8_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn);

#elif _LCD_Mood == _LCD_4_Bit_Mood

static void LCD_4_GetData(LCD_4_MODE CopyLCD , u8 CopyCMD);
static void LCD_4_SendEnable_Signal(LCD_4_MODE CopyLCD);
static void LCD_4_SetCursor_Position(LCD_4_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn);
#endif

/************************************************************************************************************************/


/********** SECTION : Functions Definitions 8 Bit Mode **********/
#if _LCD_Mood ==  _LCD_8_Bit_Mood

void LCD_8_INIT(LCD_8_MODE CopyLCD)
{
	u8 Counter = Initial_Counter;
	Dio_setPinDir(CopyLCD.E, Direction_Pin_Output);
	Dio_setPinDir(CopyLCD.RS, Direction_Pin_Output);
	for (Counter = Initial_Counter;  Counter < 8; Counter++)
	{
		Dio_setPinDir(CopyLCD.port[Counter], Direction_Pin_Output);
	}
	_delay_ms(20);
	LCD_8_CMD_Write(CopyLCD, _LCD_8_Bit_Mode);
	_delay_ms(5);
	LCD_8_CMD_Write(CopyLCD, _LCD_8_Bit_Mode);
	_delay_us(150);
	LCD_8_CMD_Write(CopyLCD, _LCD_8_Bit_Mode);
	LCD_8_CMD_Write(CopyLCD, _LCD_Clear_Dis);
	LCD_8_CMD_Write(CopyLCD, _LCD_Return_Home);
	LCD_8_CMD_Write(CopyLCD, _LCD_Entery_INC);
	LCD_8_CMD_Write(CopyLCD, _LCD_Dis_ON);
	LCD_8_CMD_Write(CopyLCD, _LCD_8_Bit_Mode);
	LCD_8_CMD_Write(CopyLCD, 0x80);
}

void LCD_8_CMD_Write(LCD_8_MODE CopyLCD , u8 CopyCMD)
{
	u8 Counter = Initial_Counter;

	Dio_setPinVal(CopyLCD.RS , Status_Pin_Low);
	for(Counter = Initial_Counter; Counter < 8 ; Counter++)
	{
		Dio_setPinVal(CopyLCD.port[Counter], ((CopyCMD >> Counter) & (u8)0x01));
	}
	LCD_8_SendEnable_Signal(CopyLCD);
}

void LCD_8_Char_Write(LCD_8_MODE CopyLCD , u8 CopyChar)
{
	u8 Counter = Initial_Counter;

	Dio_setPinVal(CopyLCD.RS , Status_Pin_High);
	for(Counter = Initial_Counter; Counter < 8 ; Counter++)
	{
		Dio_setPinVal(CopyLCD.port[Counter], ((CopyChar >> Counter) & (u8)0x01));
	}
	LCD_8_SendEnable_Signal(CopyLCD);
}

void LCD_8_Char_Postion(LCD_8_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn , u8 CopyChar)
{
	LCD_8_SetCursor_Position(CopyLCD , CopyRow , CopyCoulmn);
	LCD_8_Char_Write(CopyLCD , CopyChar);
}

void LCD_8_String_Write(LCD_8_MODE CopyLCD , u8 *CopySTR)
{
	while(*CopySTR)
	{
		LCD_8_Char_Write(CopyLCD, *CopySTR++);
	}
}
void LCD_8_STR_Write_Postion(LCD_8_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn , u8 *CopySTR)
{
	LCD_8_SetCursor_Position(CopyLCD , CopyRow , CopyCoulmn);
	while(*CopySTR)
	{
		LCD_8_Char_Write(CopyLCD, *CopySTR++);
	}
}


/************************************************************************************************************************/


/********** SECTION : Functions Definitions 4 Bit Mode **********/
#elif _LCD_Mood == _LCD_4_Bit_Mood

void LCD_4_INIT(LCD_4_MODE CopyLCD)
{
	u8 Counter = Initial_Counter;

	Dio_setPinDir(CopyLCD.E, Direction_Pin_Output);
	Dio_setPinDir(CopyLCD.RS, Direction_Pin_Output);

	for (Counter = Initial_Counter;  Counter < 4; Counter++)
	{
		Dio_setPinDir(CopyLCD.Port[Counter], Direction_Pin_Output);
	}
	_delay_ms(20);
	LCD_4_CMD_Write(CopyLCD, _LCD_8_Bit_Mode);
	_delay_ms(5);
	LCD_4_CMD_Write(CopyLCD, _LCD_8_Bit_Mode);
	_delay_us(150);
	LCD_4_CMD_Write(CopyLCD, _LCD_8_Bit_Mode);
	LCD_4_CMD_Write(CopyLCD, _LCD_Clear_Dis);
	LCD_4_CMD_Write(CopyLCD, _LCD_Return_Home);
	LCD_4_CMD_Write(CopyLCD, _LCD_Entery_INC);
	LCD_4_CMD_Write(CopyLCD, _LCD_Dis_ON);
	LCD_4_CMD_Write(CopyLCD, _LCD_4_Bit_Mode);
	LCD_4_CMD_Write(CopyLCD, 0x80);
}

void LCD_4_CMD_Write(LCD_4_MODE CopyLCD , u8 CopyCMD)
{
	Dio_setPinVal(CopyLCD.RS , Status_Pin_Low);
	LCD_4_GetData(CopyLCD,CopyCMD >> 4);
	LCD_4_SendEnable_Signal(CopyLCD);
	LCD_4_GetData(CopyLCD,CopyCMD);
	LCD_4_SendEnable_Signal(CopyLCD);
}

void LCD_4_Char_Write(LCD_4_MODE CopyLCD , u8 CopyChar)
{
	Dio_setPinVal(CopyLCD.RS , Status_Pin_High);
	LCD_4_GetData(CopyLCD,CopyChar >> 4);
	LCD_4_SendEnable_Signal(CopyLCD);
	LCD_4_GetData(CopyLCD,CopyChar);
	LCD_4_SendEnable_Signal(CopyLCD);
}

void LCD_4_Char_Postion(LCD_4_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn , u8 CopyChar)
{
	LCD_4_SetCursor_Position(CopyLCD , CopyRow , CopyCoulmn);
	LCD_4_Char_Write(CopyLCD , CopyChar);
}

void LCD_4_Str_Write(LCD_4_MODE CopyLCD , u8 *CopySTR)
{
	while(*CopySTR)
	{
		LCD_4_Char_Write(CopyLCD, *CopySTR++);
	}
}

void LCD_4_STR_Postion(LCD_4_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn , u8 *CopySTR)
{
	LCD_4_SetCursor_Position(CopyLCD , CopyRow , CopyCoulmn);
	while(*CopySTR)
	{
		LCD_4_Char_Write(CopyLCD, *CopySTR++);
	}
}
#endif
/************************************************************************************************************************/

/********** SECTION : Functions Declarations Convert **********/

void Convert_u8_to_String(u8 CopyValueu8 , u8 *CopySTR)
{
	memset(CopySTR , '\0' , 4);
	sprintf(CopySTR , "%i", CopyValueu8);
}
void Convert_u16_to_String(u16 CopyValueu8 , u8 *CopySTR)
{
	memset(CopySTR , '\0' , 6);
	sprintf(CopySTR , "%i", CopyValueu8);
}
void Convert_u32_to_String(u32 CopyValueu8 , u8 *CopySTR)
{
	memset(CopySTR , '\0' , 11);
	sprintf(CopySTR , "%i", CopyValueu8);
}

/************************************************************************************************************************/


/********** SECTION : Static Functions **********/
#if _LCD_Mood ==  _LCD_4_Bit_Mood

static void LCD_4_GetData(LCD_4_MODE CopyLCD , u8 CopyCMD)
{
	Dio_setPinVal(CopyLCD.Port[0] , (CopyCMD >> 0) & (u8)0x01);
	Dio_setPinVal(CopyLCD.Port[1] , (CopyCMD >> 1) & (u8)0x01);
	Dio_setPinVal(CopyLCD.Port[2] , (CopyCMD >> 2) & (u8)0x01);
	Dio_setPinVal(CopyLCD.Port[3] , (CopyCMD >> 3) & (u8)0x01);
}

static void LCD_4_SendEnable_Signal(LCD_4_MODE CopyLCD)
{
	Dio_setPinVal(CopyLCD.E,Status_Pin_High);
	_delay_us(5);
	Dio_setPinVal(CopyLCD.E, Status_Pin_Low);
}

static void LCD_4_SetCursor_Position(LCD_4_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn)
{
	CopyCoulmn--;
	switch (CopyRow) {
		case Row_1 : LCD_4_CMD_Write(CopyLCD, (0x80 + CopyCoulmn)); break;
		case Row_2 : LCD_4_CMD_Write(CopyLCD, (0xc0 + CopyCoulmn)); break;
		case Row_3 : LCD_4_CMD_Write(CopyLCD, (0x90 + CopyCoulmn)); break;
		case Row_4 : LCD_4_CMD_Write(CopyLCD, (0xd0 + CopyCoulmn)); break;
		default: break;
	}
}

#elif _LCD_Mood ==  _LCD_8_Bit_Mood

static void LCD_8_SendEnable_Signal(LCD_8_MODE CopyLCD)
{
	Dio_setPinVal(CopyLCD.E,Status_Pin_High);
	_delay_ms(5);
	Dio_setPinVal(CopyLCD.E, Status_Pin_Low);
}

static void LCD_8_SetCursor_Position(LCD_8_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn)
{
	CopyCoulmn--;
	switch (CopyRow) {
		case Row_1 : LCD_8_CMD_Write(CopyLCD, (0x80 + CopyCoulmn)); break;
		case Row_2 : LCD_8_CMD_Write(CopyLCD, (0xc0 + CopyCoulmn)); break;
		case Row_3 : LCD_8_CMD_Write(CopyLCD, (0x90 + CopyCoulmn)); break;
		case Row_4 : LCD_8_CMD_Write(CopyLCD, (0xd0 + CopyCoulmn)); break;
		default: break;
	}
}
#endif
