/*
 * LCD_init.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef HAL_LCD_LCD_INIT_H_
#define HAL_LCD_LCD_INIT_H_

/* -------------------- Include Start -------------------- */
#include "../../Mcal/Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define _LCD_CLEAR_DIS          (uint8)0x01
#define _LCD_Return_Home        (uint8)0x02
#define _LCD_DISPLAY_ON         (uint8)0x0C
#define _LCD_DISPLAY_OFF        (uint8)0x08
#define _LCD_CURSOR_ON_BLINK    (uint8)0x0F
#define _LCD_CURSOR_OFF_BLINK   (uint8)0x0E
#define _LCD_SHIFT_DIS_R        (uint8)0x1C
#define _LCD_SHIFT_DIS_L        (uint8)0x18
#define _LCD_ENTRY_MODE_INC     (uint8)0X06
#define _LCD_ENTRY_MODE_DEC     (uint8)0X04
#define _LCD_BIT_8_MODE         (uint8)0x38
#define _LCD_BIT_4_MODE         (uint8)0x28
#define _LCD_AD_CGRAM           (uint8)0x40
#define _LCD_AD_DDRAM           (uint8)0x80
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void LCD_vidInit();
void LCD_vidWriteCmd(uint8 u8CmdCopy);
void LCD_vidWriteChar(uint8 u8CharCopy);
void LCD_vidClrDisp();
void LCD_vidShiftLeft();
void LCD_vidShiftRight();
void LCD_vidWriteInt(sint32 u32NumCopy);
void LCD_vidWriteStr(uint8 *u8StrCopy);
void LCD_vidGoto(uint8 u8RowCopy,uint8 u8ColCopy);
void LCD_vidWritePatternCGRAM(uint8 *u8Pattern,uint8 u8Loc);
/* -------------------- API End -------------------- */

#endif /* HAL_LCD_LCD_INIT_H_ */
