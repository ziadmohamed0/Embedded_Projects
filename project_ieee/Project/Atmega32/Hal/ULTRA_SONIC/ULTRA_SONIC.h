/*
 * ULTRA_SONIC.h
 *
 *  Created on: Jul 9, 2025
 *      Author: ziad
 */

#ifndef HAL_ULTRA_SONIC_ULTRA_SONIC_H_
#define HAL_ULTRA_SONIC_ULTRA_SONIC_H_

#include "../../Mcal/Mcal_dfs.h"

#define trigger_Port	Port_D
#define trigger_Pin		Pin_7

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);


#endif /* HAL_ULTRA_SONIC_ULTRA_SONIC_H_ */
