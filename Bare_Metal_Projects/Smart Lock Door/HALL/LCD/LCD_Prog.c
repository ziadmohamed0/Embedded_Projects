/*
 * LCD_Prog.h
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "LCD_Init.h"

/*********** STATIC FUNCTIONS DECLER ***********/
/**
 * @brief  : function get data for LCD 4 Bit Mode
 * @param1 : copyLCDNum
 * @retVal : void
 */
static void LCD_getData(PINS_LCD copyLCDNum, _LCD_COMMANDS copyCMD);

/**
 * @brief  : LCD enable signal static function
 * @param1 : copyLCDNum
 * @retVal : void
 */
static void LCD_enableSignal(PINS_LCD copyLCDNum);

/*
* @brief  : function to set cursor & display in any row & column.
* @param1 : copyLCDNum
* @param2 : copyRow
* @param3 : copyColumn
* @retVal : void
*/
static void LCD_setCursorPosition(PINS_LCD copyLCDNum , ROW_NUM copyRow , uint_8 copyColumn);
/*
* @brief  : function Convert from Number to String Size 8 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u8(uint_8 copyNum , uint_8 *copySTR);
/*
* @brief  : function Convert from Number to String Size 16 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u16(uint_16 copyNum , uint_8 *copySTR);
/*
* @brief  : function Convert from Number to String Size 32 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u32(uint_32 copyNum , uint_8 *copySTR);


/*********** FUNCTIONS DEFIN ***********/
/**
 * @brief  : LCD initialization function by initialization all Directions of
 *           pins LCD is DIRECTION_PIN_OUTPUT.
 *           if _LCD_MODE is _8_BIT_MODE_LCD then EN , RS , D0 ~ D7 is output pins.
 *           if _LCD_MODE is _4_BIT_MODE_LCD then EN , RS , D4 ~ D7 is output pins.
 * @param1 : copyLCDNum
 * @retVal : void
 */
void LCD_init(PINS_LCD copyLCDNum)
{
#if (_LCD_MODE == _8_BIT_MODE_LCD)
	DIO_setPinDIR(copyLCDNum.EN, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyLCDNum.RS, _DIRECTION_PIN_OUTPUT);
	for(uint_8 count = Zero_INIT ; count < 8 ; count++)
	{
		DIO_setPinDIR(copyLCDNum.D[count],_DIRECTION_PIN_OUTPUT);
	}
	_delay_ms(20);
	LCD_writeCMD(copyLCDNum,_LCD_8_BIT_MODE);
	_delay_ms(5);
	LCD_writeCMD(copyLCDNum,_LCD_8_BIT_MODE);
	_delay_ms(150);
	LCD_writeCMD(copyLCDNum,_LCD_8_BIT_MODE);
	LCD_writeCMD(copyLCDNum,_LCD_CLEAR_DIS);
	LCD_writeCMD(copyLCDNum,_LCD_RETURN_HOME);
	LCD_writeCMD(copyLCDNum,_LCD_ENTERY_INC);
	LCD_writeCMD(copyLCDNum,_LCD_DISPLAY_ON);
	LCD_writeCMD(copyLCDNum,_LCD_8_BIT_MODE);
	LCD_writeCMD(copyLCDNum,0x80);
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
	DIO_setPinDIR(copyLCDNum.EN, _DIRECTION_PIN_OUTPUT);
	DIO_setPinDIR(copyLCDNum.RS, _DIRECTION_PIN_OUTPUT);
	for(uint_8 count = Zero_INIT ; count < 4 ; count++)
	{
		DIO_setPinDIR(copyLCDNum.D[count],_DIRECTION_PIN_OUTPUT);
	}
	_delay_ms(20);
	LCD_writeCMD(copyLCDNum,_LCD_8_BIT_MODE);
	_delay_ms(5);
	LCD_writeCMD(copyLCDNum,_LCD_8_BIT_MODE);
	_delay_ms(150);
	LCD_writeCMD(copyLCDNum,_LCD_8_BIT_MODE);
	LCD_writeCMD(copyLCDNum,_LCD_CLEAR_DIS);
	LCD_writeCMD(copyLCDNum,_LCD_RETURN_HOME);
	LCD_writeCMD(copyLCDNum,_LCD_ENTERY_INC);
	LCD_writeCMD(copyLCDNum,_LCD_DISPLAY_ON);
	LCD_writeCMD(copyLCDNum,_LCD_4_BIT_MODE);
	LCD_writeCMD(copyLCDNum,0x80);
	#endif
}

/**
 * @brief  : LCD write command function
 *           if Command is _LCD_CLEAR_DIS Clear all the display data.
 *           if Command is _LCD_RETURN_HOME Return display to its original position.
 *           if Command is _LCD_ENTERY_INC Sets the move direction of cursor and display Right.
 *           if Command is _LCD_ENTERY_DEC Sets the move direction of cursor and display Left.
 *           if Command is _LCD_DISPLAY_ON Sets the LCD is ON.
 *           if Command is _LCD_DISPLAY_OFF Sets the LCD is OFF.
 *           if Command is _LCD_CURSOR_ON Sets the LCD is ON.
 *           if Command is _LCD_CURSOR_BLINK Sets the LCD is ON.
 *           if Command is _LCD_SHIFT_RIGHT Shifts the entire display to the Right.
 *           if Command is _LCD_SHIFT_LEFT Shifts the entire display to the Left.
 *           if Command is _LCD_8_BIT_MODE length (DB7 ~ DB0).
 *           if Command is _LCD_4_BIT_MODE length (DB7 ~ DB4).
 *           if Command is _LCD_CG_RAM_SET Sets the CG RAM address to the address counter.
 *           if Command is _LCD_DD_RAM_SET Sets the DD RAM address to the address counter.
 * @param1 : copyLCDNum
 * @param2 : copyCMD
 * @retVal : void
 */
void LCD_writeCMD(PINS_LCD copyLCDNum, _LCD_COMMANDS copyCMD)
{
#if (_LCD_MODE == _8_BIT_MODE_LCD)
	DIO_setPinVAL(copyLCDNum.RS , _STATUS_PIN_LOW);
	DIO_setPortVAL(copyLCDNum.PORT_DATA_PIN_NUM, copyCMD);
	LCD_enableSignal(LCD);
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
	DIO_setPinVAL(copyLCDNum.RS , _STATUS_PIN_LOW);
	LCD_getData(copyLCDNum , copyCMD >> 4);
	LCD_enableSignal(LCD);
	LCD_getData(copyLCDNum,copyCMD);
	LCD_enableSignal(LCD);
#endif
}

/**
 * @brief  : LCD write Character function
 * @param1 : copyLCDNum
 * @param2 : copyChar
 * @retVal : void
 */
void LCD_writeChar(PINS_LCD copyLCDNum, uint_8 copyChar)
{
#if (_LCD_MODE == _8_BIT_MODE_LCD)
	DIO_setPinVAL(copyLCDNum.RS , _STATUS_PIN_HIGH);
	DIO_setPortVAL(copyLCDNum.PORT_DATA_PIN_NUM, copyChar);
	LCD_enableSignal(LCD);
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
	DIO_setPinVAL(copyLCDNum.RS , _STATUS_PIN_HIGH);
	LCD_getData(copyLCDNum , copyChar >> 4);
	LCD_enableSignal(LCD);
	LCD_getData(copyLCDNum,copyChar);
	LCD_enableSignal(LCD);
#endif
}

/**
 * @brief  : LCD write String function
 * @param1 : copyLCDNum
 * @param2 : copySTR
 * @retVal : void
 */
void LCD_writeSTR(PINS_LCD copyLCDNum, uint_8 *copySTR)
{
	while(*copySTR)
	{
		LCD_writeChar(copyLCDNum, *copySTR++);
	}
}
/**
 * @brief  : LCD write Number function
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u8(PINS_LCD copyLCDNum, uint_8 *copyNum)
{
	uint_8 Ret[5];
	LCD_convertNum_u8(copyNum, &Ret);
	LCD_writeSTR(copyLCDNum, Ret);
}

/**
 * @brief  : LCD write Number function size 16 Bits.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u16(PINS_LCD copyLCDNum, uint_16 *copyNum)
{
	uint_16 Ret[5];
	LCD_convertNum_u16(copyNum, &Ret);
	LCD_writeSTR(copyLCDNum, Ret);
}
/**
 * @brief  : LCD write Number function size 32 Bits.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u32(PINS_LCD copyLCDNum, uint_32 *copyNum)
{
	uint_32 Ret[5];
	LCD_convertNum_u32(copyNum, &Ret);
	LCD_writeSTR(copyLCDNum, Ret);
}

/**
 * @brief  : LCD write Character function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyRow
 * @param3 : copyColumn
 * @param4 : copyChar
 * @retVal : void
 */
void LCD_writeCharPosition(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn, uint_8 copyChar)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeChar(copyLCDNum, copyChar);
}

/**
 * @brief  : LCD write String function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyRow
 * @param3 : copyColumn
 * @param4 : copySTR
 * @retVal : void
 */
void LCD_writeSTRPosition(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn,uint_8 *copySTR)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeSTR(copyLCDNum, copySTR);
}

/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u8Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn,uint_8 *copyNum)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeNum_u8(copyLCDNum, copyNum);
}

/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u16Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn,uint_16 *copyNum)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeNum_u16(copyLCDNum, copyNum);
}

/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u32Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn,uint_32 *copyNum)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeNum_u32(copyLCDNum, copyNum);
}

/**
 * @brief  : LCD function go to any where in LCD .
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_GoTo(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
}
/*********** STATIC FUNCTIONS DEFIN ***********/
#if (_LCD_MODE == _4_BIT_MODE_LCD)
/**
 * @brief  : function get data for LCD 4 Bit Mode
 * @param1 : copyLCDNum
 * @param2 : copyCMD
 * @retVal : void
 */
static void LCD_getData(PINS_LCD copyLCDNum, _LCD_COMMANDS copyCMD)
{
	DIO_setPinVAL(copyLCDNum.D[0], (copyCMD >> 0) & (uint_8)0x01);
	DIO_setPinVAL(copyLCDNum.D[1], (copyCMD >> 1) & (uint_8)0x01);
	DIO_setPinVAL(copyLCDNum.D[2], (copyCMD >> 2) & (uint_8)0x01);
	DIO_setPinVAL(copyLCDNum.D[3], (copyCMD >> 3) & (uint_8)0x01);
}
#endif

/**
 * @brief  : LCD enable signal static function
 * @param1 : copyLCDNum
 * @retVal : void
 */
static void LCD_enableSignal(PINS_LCD copyLCDNum)
{
#if (_LCD_MODE == _4_BIT_MODE_LCD)
	DIO_setPinVAL(copyLCDNum.EN, _STATUS_PIN_HIGH);
	_delay_us(5);
	DIO_setPinVAL(copyLCDNum.EN, _STATUS_PIN_LOW);
#elif (_LCD_MODE == _8_BIT_MODE_LCD)
	DIO_setPinVAL(copyLCDNum.EN, _STATUS_PIN_HIGH);
	_delay_ms(5);
	DIO_setPinVAL(copyLCDNum.EN, _STATUS_PIN_LOW);
#endif
}

/*
* @brief  : function to set cursor & display in any row & column.
* @param1 : copyLCDNum
* @param2 : copyRow
* @param3 : copyColumn
* @retVal : void
*/
static void LCD_setCursorPosition(PINS_LCD copyLCDNum , ROW_NUM copyRow , uint_8 copyColumn)
{
	copyColumn--;
#if ((_Rows_LCD_TYPE == LM044_LCD) || (_Rows_LCD_TYPE == LM04L_LCD))
	switch (copyRow)
	{
		case ROW1:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_1 + copyColumn)); break;
		case ROW2:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_2 + copyColumn)); break;
		case ROW3:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_3 + copyColumn)); break;
		case ROW4:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_4 + copyColumn)); break;
	}
#elif 	(_Rows_LCD_TYPE == LM32L_LCD)
	switch (copyRow)
	{
		case ROW1:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_1 + copyColumn)); break;
		case ROW2:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_2 + copyColumn)); break;
	}
#endif
}


/*
* @brief  : function Convert from Number to String Size 8 Bits
* @param1 : copyLCDNum
* @param2 : copySTR
* @retVal : void
*/
static void LCD_convertNum_u8(uint_8 copyNum , uint_8 *copySTR)
{
	memset(copySTR , '\0' , 4);
	sprintf(copySTR , "%i", copyNum);
}


/*
* @brief  : function Convert from Number to String Size 16 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u16(uint_16 copyNum , uint_8 *copySTR)
{
	memset(copySTR , '\0' , 6);
	sprintf(copySTR , "%i", copyNum);
}


/*
* @brief  : function Convert from Number to String Size 32 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u32(uint_32 copyNum , uint_8 *copySTR)
{
	memset(copySTR , '\0' , 11);
	sprintf(copySTR , "%i", copyNum);
}
