/*
 * LCD_Init.h
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */

#ifndef HALL_LCD_LCD_INIT_H_
#define HALL_LCD_LCD_INIT_H_

/*********** INCLUDES ***********/
#include "LCD_Config.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : LCD initialization function by initialization all Directions of
 *           pins LCD is DIRECTION_PIN_OUTPUT.
 *           if _LCD_MODE is _8_BIT_MODE_LCD then EN , RS , D0 ~ D7 is output pins.
 *           if _LCD_MODE is _4_BIT_MODE_LCD then EN , RS , D4 ~ D7 is output pins.
 * @param1 : copyLCDNum
 * @retVal : void
 */
void LCD_init(PINS_LCD copyLCDNum);

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
void LCD_writeCMD(PINS_LCD copyLCDNum, _LCD_COMMANDS copyCMD);

/**
 * @brief  : LCD write Character function
 * @param1 : copyLCDNum
 * @param2 : copyChar
 * @retVal : void
 */
void LCD_writeChar(PINS_LCD copyLCDNum, uint_8 copyChar);

/**
 * @brief  : LCD write String function
 * @param1 : copyLCDNum
 * @param2 : copySTR
 * @retVal : void
 */
void LCD_writeSTR(PINS_LCD copyLCDNum, uint_8 *copySTR);

/**
 * @brief  : LCD write Number function size 8 Bits.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u8(PINS_LCD copyLCDNum, uint_8 *copyNum);

/**
 * @brief  : LCD write Number function size 16 Bits.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u16(PINS_LCD copyLCDNum, uint_16 *copyNum);

/**
 * @brief  : LCD write Number function size 32 Bits.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u32(PINS_LCD copyLCDNum, uint_32 *copyNum);

/**
 * @brief  : LCD write Character function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyRow
 * @param3 : copyColumn
 * @param4 : copyChar
 * @retVal : void
 */
void LCD_writeCharPosition(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn, uint_8 copyChar);

/**
 * @brief  : LCD write String function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyRow
 * @param3 : copyColumn
 * @param4 : copySTR
 * @retVal : void
 */
void LCD_writeSTRPosition(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn,uint_8 *copySTR);


/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u32Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn,uint_32 *copyNum);

/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u16Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn,uint_16 *copyNum);


/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u8Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn,uint_8 *copyNum);

/**
 * @brief  : LCD function go to any where in LCD .
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_GoTo(PINS_LCD copyLCDNum, ROW_NUM copyRow, uint_8 copyColumn);

#endif /* HALL_LCD_LCD_INIT_H_ */
