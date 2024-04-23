/*
 * bcd_Init.h
 *
 *  Created on: Mar 17, 2024
 *      Author: ziad
 */

#ifndef HALL_BCD_BCD_INIT_H_
#define HALL_BCD_BCD_INIT_H_

/* -------------------- Section : Includes -------------------- */
#include "../../Mcal/DIO/dio_Init.h"
#include "bcd_Config.h"
#include "../../Mcal/External_Interrupt/External_Interrupts_Init.h"

/* -------------------- Section : Function Declarations -------------------- */
void Bcd_7segInit(BCD Copy7seg);
void Bcd_7segWriteNum(BCD Copy7segNum , u8 CopyNumber);
void Bcd_MPX_2Enable(MPX_2_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus);
void Bcd_MPX_4Enable(MPX_4_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus);
void Bcd_MPX_6Enable(MPX_6_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus);
void Bcd_MPX_8Enable(MPX_8_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus);

#endif /* HALL_BCD_BCD_INIT_H_ */
