/*
 * BUZZ.h
 *
 *  Created on: Jul 9, 2025
 *      Author: ziad
 */

#ifndef HAL_BUZZ_BUZZ_H_
#define HAL_BUZZ_BUZZ_H_

#include "../../Mcal/Mcal_dfs.h"

#define Buzzr_pin	Pin_5
#define Buzzr_port	Port_B

void Buzzer_init();
void Buzzer_ON();
void Buzzer_OFF();

#endif /* HAL_BUZZ_BUZZ_H_ */
