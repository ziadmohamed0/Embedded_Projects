/*
 * External_Interrupts_Init.h
 *
 *  Created on: Apr 12, 2024
 *      Author: ziad
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPTS_INIT_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPTS_INIT_H_

/* -------------------- Section : Includes -------------------- */
#include "External_Interrupts_Reg.h"
#include "External_Interrupts_Config.h"
#include "../DIO/dio_Init.h"

/* -------------------- Section : Macros -------------------- */
#define INT0_PIN    (u8)0
#define INT1_PIN    (u8)1
#define INT2_PIN    (u8)2


#define FALLING   (u8)0
#define RISSING   (u8)1
#define LOW       (u8)2
#define ANY_LOG   (u8)3


#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPTS_INIT_H_ */
