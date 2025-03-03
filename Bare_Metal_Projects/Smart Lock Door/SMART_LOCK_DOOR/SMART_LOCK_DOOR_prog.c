/*
 * SMART_LOCK_DOOR_prog.c
 *
 *  Created on: Jun 19, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "SMART_LOCK_DOOR_init.h"

/*********** GLOBAL AREA ***********/
uint_8 lcd_style[20] = "====================";
uint_8 PassSet[MAX_SIZE];
uint_8 Pass[MAX_SIZE];
uint_8 PassCheck[MAX_SIZE];
uint_8 KeyVal = Zero_INIT;

/*********** ISR FUNCTION ***********/

/*********** STATIC FUNCTIONS DECLER ***********/
/**
 * @brief  : smart lock door project function setup all initializations
 * 			 & directions of all modules.
 * @param1 : void
 * @RetVal : void
 */
static void smartDoorLock_FirstStart(void);

/**
 * @brief  : smart lock door project function to get password from user.
 * @param1 : void
 * @RetVal : void
 */
static void smartDoorLock_getPass(void);

/**
 * @brief  : smart lock door project function to check password
 * 			 is correct or not if correct return 1 else return 0.
 * @param1 : void
 * @RetVal : Ret1
 */
static uint_8 smartDoorLock_checkpass(void);

/**
 * @brief  : smart lock door project function to get password.
 * @param1 : void
 * @RetVal : void
 */
static void smartDoorLock_getpass(void);

/*********** FUNCTIONS DEFIN ***********/
void smartDoorLock_START(void)
{
	KEYPAD_getData(KEYPAD,&KeyVal);
	while(KEYPAD_getData(KEYPAD,&KeyVal) == 0);

	if(KeyVal == '#')
	{
		smartDoorLock_FirstStart();
		smartDoorLock_getPass();
	}

	LCD_writeCMD(LCD, _LCD_DISPLAY_OFF);
	LCD_writeCMD(LCD, _LCD_CLEAR_DIS);
}

/**
 * @brief  : smart lock door project function to looping if password is correct
 * 			then return 0 else you have a three attempts then return 1.
 * @param1 : void
 * @RetVal : void
 */
uint_8 smartDoorLock_Three_attempts(void)
{
	uint_8 alarm1 = Zero_INIT;
	for(uint_8 count = Zero_INIT; count < 3 ; count++)
	{
		LCD_writeCMD(LCD, _LCD_CLEAR_DIS);
		smartDoorLock_getpass();
		uint_8 error = Zero_INIT;
		error = smartDoorLock_checkpass();
		if (error == 1)
		{
			LCD_GoTo(LCD, ROW2,2);
			LCD_writeSTR(LCD, "Incorrect password");
			_delay_ms(800);
			alarm1 = 1;
		}
		else
		{
			LCD_writeCMD(LCD, _LCD_DISPLAY_ON);
			LCD_GoTo(LCD, ROW2,2);
			LCD_writeSTR(LCD, "correct password");
			_delay_ms(800);
			LCD_writeCMD(LCD, _LCD_CLEAR_DIS);
			LCD_GoTo(LCD, ROW2,2);
			LCD_writeSTR(LCD, "Welcome Master <3");
			_delay_ms(800);
			LCD_writeCMD(LCD, _LCD_DISPLAY_OFF);
			alarm1 = 0;
			break;
		}
	}
	return alarm1;
}
/*********** STATIC FUNCTIONS DEFIN ***********/
/**
 * @brief  : smart lock door project function to welcome massage for user.
 * @param1 : void
 * @RetVal : void
 */
static void smartDoorLock_FirstStart(void)
{
	uint_8 welcom[20] =  "Hi Master";
	uint_8 welcom1[20] = "   Welcome in Home ";
	LCD_writeSTR(LCD, lcd_style);
	LCD_GoTo(LCD, ROW2, 7);
	LCD_writeSTR(LCD, welcom);
	LCD_GoTo(LCD, ROW3, 1);
	LCD_writeSTR(LCD, welcom1);
	LCD_GoTo(LCD, ROW4, 1);
	LCD_writeSTR(LCD, lcd_style);
	_delay_ms(1500);
	LCD_writeCMD(LCD, _LCD_CLEAR_DIS);

}

/**
 * @brief  : smart lock door project function to get password from user.
 * @param1 : void
 * @RetVal : void
 */
static void smartDoorLock_getPass(void)
{
	uint_8 Lcd_Pos = Zero_INIT;
	LCD_GoTo(LCD, ROW2,6);
	LCD_writeSTR(LCD,"SET PASSWORD");
	while(1)
	{
		LCD_writeCMD(LCD,_LCD_DISPLAY_ON);
		KEYPAD_getData(KEYPAD,&KeyVal);
		while(KEYPAD_getData(KEYPAD,&KeyVal) == 0);
		Lcd_Pos++;
		if(KeyVal == '#')
		{
			break;
		}
		LCD_writeCharPosition(LCD, ROW3, Lcd_Pos, KeyVal);
		_delay_ms(250);
		LCD_writeCharPosition(LCD, ROW3, Lcd_Pos, '*');
		PassSet[Lcd_Pos] = KeyVal;
	}
}

/**
 * @brief  : smart lock door project function to check password
 * 			 is correct or not if correct return 1 else return 0.
 * @param1 : void
 * @RetVal : Ret1
 */
static uint_8 smartDoorLock_checkpass(void)
{
	uint_8 Ret1 = Zero_INIT;
	for(uint_8 count = Zero_INIT ; count < MAX_SIZE ; count++)
	{
		if(Pass[count] != PassSet[count])
		{
			Ret1 = 1;
		}
	}
	return Ret1;
}

/**
 * @brief  : smart lock door project function to get password.
 * @param1 : void
 * @RetVal : void
 */
static void smartDoorLock_getpass(void)
{
	Pass[MAX_SIZE] = Zero_INIT;
	uint_8 Lcd_Pos = Zero_INIT;
	LCD_writeCMD(LCD,_LCD_DISPLAY_ON);
	LCD_GoTo(LCD, ROW2,4);
	LCD_writeSTR(LCD,"Enter Password");
	while(1)
	{
		KEYPAD_getData(KEYPAD,&KeyVal);
		while(KEYPAD_getData(KEYPAD,&KeyVal) == 0);
		Lcd_Pos++;
		if(KeyVal == '#')
		{
			_delay_ms(250);
			break;
		}
		LCD_writeCharPosition(LCD, ROW3, Lcd_Pos, KeyVal);
		_delay_ms(100);
		LCD_writeCharPosition(LCD, ROW3, Lcd_Pos, '*');
		Pass[Lcd_Pos] = KeyVal;
	}
	LCD_writeCMD(LCD, _LCD_CLEAR_DIS);
}
