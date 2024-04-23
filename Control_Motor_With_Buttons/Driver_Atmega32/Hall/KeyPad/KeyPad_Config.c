/*
 * KeyPad_Config.c
 *
 *  Created on: Apr 7, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "KeyPad_Config.h"

/********** SECTION : Variables Definitions **********/
u8 Keypad_Buttons[KeyPad_Rows][KeyPad_Coulmn] = {
							 						{'7','8','9','/'},
							 						{'4','5','6','x'},
							 						{'1','2','3','-'},
							 						{'#','0','=','+'},
												};


KeyPad KeyPad_1 = {

				/* ----- Pins Rows ----- */
				.Pins_Row[0] = PortC_p4,
				.Pins_Row[1] = PortC_p5,
				.Pins_Row[2] = PortC_p6,
				.Pins_Row[3] = PortC_p7,

				/* ----- Pins Column ----- */
				.Pins_Coulmn[0] = PortC_p0,
				.Pins_Coulmn[1] = PortC_p1,
				.Pins_Coulmn[2] = PortC_p2,
				.Pins_Coulmn[3] = PortC_p3,

};
