/*
 * UltraSonic_Init.h
 *
 *  Created on: Apr 9, 2024
 *      Author: ziad
 */

#ifndef HALL_ULTRASONIC_ULTRASONIC_INIT_H_
#define HALL_ULTRASONIC_ULTRASONIC_INIT_H_

/********** SECTION : Includes **********/
#include "UltraSonic_Config.h"
#include "../../Mcal/External_Interrupt/External_Interrupts_Init.h"

/********** SECTION : Functions Declarations **********/
void UltraSonic_Init(UltraSonic CopyUltraSonic);
void UltraSonic_ReadDistance(UltraSonic CopyUltraSonic , u8 CopyDistance);

#endif /* HALL_ULTRASONIC_ULTRASONIC_INIT_H_ */
