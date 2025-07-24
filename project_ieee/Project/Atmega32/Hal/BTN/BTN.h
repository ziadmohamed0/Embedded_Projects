/*
 * BTN.h
 *
 *  Created on: Jul 9, 2025
 *      Author: ziad
 */

#ifndef HAL_BTN_BTN_H_
#define HAL_BTN_BTN_H_

#include "../../Mcal/Mcal_dfs.h"

#define btn_Port	Port_D
#define btn_Pin		Pin_2

void BUTTON_init();
uint8 BUTTON_read();

#endif /* HAL_BTN_BTN_H_ */
