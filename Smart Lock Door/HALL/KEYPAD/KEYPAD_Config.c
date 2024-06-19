/*
 * KEYPAD_Config.c
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "KEYPAD_Config.h"

/*********** KEYPAD PINS ***********/


#if (TYPE_KEYPAD == _COLUMN_4)
PINS_KEYPAD KEYPAD = {
					  .ROWS[0] 	  = PINA0,
					  .ROWS[1] 	  = PINA1,
					  .ROWS[2]    = PINA2,
					  .ROWS[3]    = PINA3,
					  .COLUMNS[0] = PINA4,
					  .COLUMNS[1] = PINA5,
					  .COLUMNS[2] = PINA6,
					  .COLUMNS[3] = PINA7
					 };

uint_8 PATTIRN_KEYPAD[4][4] = {{'7' , '8' , '9' , '/'},
							  {'4' , '5' , '6' , 'x'},
							  {'1' , '2' , '3' , '-'},
							  {'#', '0' , '=' , '+'}};
#elif (TYPE_KEYPAD == _COLUMN_3)
PINS_KEYPAD KEYPAD = {
					  .ROWS[0] 	  = PINA0,
					  .ROWS[1] 	  = PINA1,
					  .ROWS[2]    = PINA2,
					  .ROWS[3]    = PINA3,
					  .COLUMNS[0] = PINA4,
					  .COLUMNS[1] = PINA5,
					  .COLUMNS[2] = PINA6
					 };
uint_8 PATTIRN_KEYPAD[4][3] = {{'1', '2' , '3'},
							  {'4', '5' , '6'},
							  {'7', '8' , '9'},
							  {'*', '0' , '#'}};
#elif (TYPE_KEYPAD == _COLUMN_6)
PINS_KEYPAD KEYPAD = {
					  .ROWS[0] 	  = PINA0,
					  .ROWS[1] 	  = PINA1,
					  .ROWS[2]    = PINA2,
					  .ROWS[3]    = PINA3,
					  .COLUMNS[0] = PINA4,
					  .COLUMNS[1] = PINA5,
					  .COLUMNS[2] = PINA6,
					  .COLUMNS[3] = PINA7,
					  .COLUMNS[4] = PINB0,
					  .COLUMNS[5] = PINB1
					 };
uint_8 PATTIRN_KEYPAD[4][6] = {{'O'  , '7' , '8' , '9' , 'x' , '/'},
							  {'e' , '4' , '5' , '6' , '-' , 'M'},
							  {'%'   , '1' , '2' , '3' , '+' , 'm'},
							  {'s'   , '0' , '.' , '=' , '+' , 'v'}};
#endif
