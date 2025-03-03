/*
 * Initialize_Init.h
 *
 *  Created on: Apr 8, 2024
 *      Author: ziad
 */

#ifndef HALL_INITIALIZE_INITIALIZE_INIT_H_
#define HALL_INITIALIZE_INITIALIZE_INIT_H_

/********** SECTION : Includes **********/
#include "../BCD/bcd_Init.h"
#include "../DC_Motor/Dc_Motor_Init.h"
#include "../LCD/Lcd_Init.h"
#include "../KeyPad/KeyPad_Init.h"

/**********  Section : Function Declarations **********/
void App_Init(void);
void App_Loop(void);

#endif /* HALL_INITIALIZE_INITIALIZE_INIT_H_ */
