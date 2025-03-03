/*
 * bcd_Config.h
 *
 *  Created on: Mar 17, 2024
 *      Author: ziad
 */

#ifndef HALL_BCD_BCD_CONFIG_H_
#define HALL_BCD_BCD_CONFIG_H_

/* -------------------- Section : Includes -------------------- */
#include "../../Mcal/DIO/dio_Init.h"

/* -------------------- Section : Macros -------------------- */
#define Common_Cathod	(u8)0
#define Common_Anode	(u8)1

#define Disable			(u8)0
#define Enable			(u8)1

/* -------------------- Section : Struct -------------------- */
typedef struct {
	u8 Pin_1;
	u8 Pin_2;
	u8 Pin_3;
	u8 Pin_4;
}BCD;


typedef enum{
	MPX_2,MPX_4,MPX_6,MPX_8
}MPX;

typedef struct {
	u8 EN_1;
	u8 EN_2;
}MPX_2_Enables;

typedef struct {
	u8 EN_1;
	u8 EN_2;
	u8 EN_3;
	u8 EN_4;
}MPX_4_Enables;

typedef struct {
	u8 EN_1;
	u8 EN_2;
	u8 EN_3;
	u8 EN_4;
	u8 EN_5;
	u8 EN_6;
}MPX_6_Enables;

typedef struct {
	u8 EN_1;
	u8 EN_2;
	u8 EN_3;
	u8 EN_4;
	u8 EN_5;
	u8 EN_6;
	u8 EN_7;
	u8 EN_8;
}MPX_8_Enables;

/* -------------------- Section : Declarations -------------------- */
BCD Seg_1;
MPX_4_Enables MX_1;

#endif /* HALL_BCD_BCD_CONFIG_H_ */
