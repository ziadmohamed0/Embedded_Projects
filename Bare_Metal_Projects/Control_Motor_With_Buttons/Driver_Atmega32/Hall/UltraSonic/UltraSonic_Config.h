/*
 * UltraSonic_Config.h
 *
 *  Created on: Apr 9, 2024
 *      Author: ziad
 */

#ifndef HALL_ULTRASONIC_ULTRASONIC_CONFIG_H_
#define HALL_ULTRASONIC_ULTRASONIC_CONFIG_H_

/********** SECTION : Includes **********/
#include "../../Mcal/DIO/dio_Init.h"

/********** SECTION : MACROS **********/
typedef struct{
	u8 Triger;
	u8 Echo;
}UltraSonic;

/********** SECTION : VARIABLES **********/
UltraSonic UltraSonic_1;

#endif /* HALL_ULTRASONIC_ULTRASONIC_CONFIG_H_ */
