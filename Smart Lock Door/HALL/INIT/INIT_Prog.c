/*
 * INIT_Prog.c
 *
 *  Created on: Jun 12, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "INIT_Init.h"

/*********** MACROS ***********/

/*********** GLOBAL AREA ***********/


/*********** ISR FUNCTION ***********/
ISR(INT0_VEC)
{

	DCMOTOR_motorReverse(MOTOR1, MOTOR2);
	_delay_ms(2000);
	DCMOTOR_motorStop(MOTOR1, MOTOR2);
}
/*********** FUNCTIONS DEFIN ***********/
/**
 * @brief  : standard function setup all initializations & directions of all modules.
 * @param1 : void
 * @RetVal : void
 */
void setUp(void)
{
	EXINTER_init(INT0, RISING);
	DCMOTOR_init(MOTOR1, MOTOR2);
	LCD_init(LCD);
	KEYPAD_init(KEYPAD);
	smartDoorLock_START();

}
/**
 * @brief  : standard function loop your Program.
 * @param1 : void
 * @RetVal : void
 */
void Loop(void)
{
	uint_8 ir = Zero_INIT;
	uint_8 val = Zero_INIT;
	KEYPAD_getData(KEYPAD, &val);
	if(val == '#')
	{
		LCD_writeCMD(LCD, _LCD_DISPLAY_ON);
		uint_8 alarm2 = Zero_INIT;
		alarm2 = smartDoorLock_Three_attempts();
		if(alarm2 == 1)
		{
			LCD_GoTo(LCD, ROW2,1);
			LCD_writeSTR(LCD, "door can't be opened");
			DCMOTOR_motorStop(MOTOR1, MOTOR2);
			_delay_ms(2000);
		}
		else
		{
			DCMOTOR_motorForward(MOTOR1, MOTOR2);
			_delay_ms(2000);
			DCMOTOR_motorStop(MOTOR1, MOTOR2);
			_delay_ms(2000);
		}
		LCD_writeCMD(LCD, _LCD_DISPLAY_OFF);
	}
	else
	{
		LCD_writeCMD(LCD, _LCD_DISPLAY_OFF);
	}
}


