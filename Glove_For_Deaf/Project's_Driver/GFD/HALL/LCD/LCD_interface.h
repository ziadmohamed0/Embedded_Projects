/*
 * LCD_interface.h
 *
 *  Created: 17/2/2024 8:43:59 PM
 *  Author: Ziad
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define LCD_8_BIT_MODE          1
#define LCD_4_BIT_MODE          2

/* Macros For LCD Line Id */
#define LCD_LINE_ONE            1
#define LCD_LINE_TWO            2

/* Macros For LCD Shifting Direction */
#define LCD_SHIFT_LEFT          0
#define LCD_SHIFT_RIGHT         1

void LCD_init(void);
void LCD_sendChar(u8 data);
void LCD_sendCmnd(u8 cmnd);
void LCD_display(u8*string);
void LCD_writeNumber(u32 number);
void LCD_goToSpecificPosition(u8 LineNumber, u8 Position);
static void PRIVATE_WriteHalfPort(u8 value);
void LCD_clear(void);

#endif /* LCD_INTERFACE_H_ */