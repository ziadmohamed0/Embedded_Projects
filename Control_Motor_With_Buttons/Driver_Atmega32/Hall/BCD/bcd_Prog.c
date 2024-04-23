/*
 * bcd_Prog.c
 *
 *  Created on: Mar 17, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "bcd_Init.h"

/********** SECTION : Functions Definitions **********/
void Bcd_7segInit(BCD Copy7seg)
{
	Dio_setPinDir(Copy7seg.Pin_1, Direction_Pin_Output);
	Dio_setPinDir(Copy7seg.Pin_2, Direction_Pin_Output);
	Dio_setPinDir(Copy7seg.Pin_3, Direction_Pin_Output);
	Dio_setPinDir(Copy7seg.Pin_4, Direction_Pin_Output);
}

void Bcd_7segWriteNum(BCD Copy7segNum , u8 CopyNumber)
{
	switch (CopyNumber) {
		case 0:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_Low);	// A = 0
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_Low);	// B = 0
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_Low);	// C = 0
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_Low);	// D = 0
			break;
		case 1:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_High);	// A = 1
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_Low);	// B = 0
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_Low);	// C = 0
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_Low);	// D = 0
			break;
		case 2:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_Low);	// A = 0
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_High);	// B = 1
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_Low);	// C = 0
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_Low);	// D = 0
			break;
		case 3:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_High);	// A = 1
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_High);	// B = 1
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_Low);	// C = 0
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_Low);	// D = 0
			break;
		case 4:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_Low);	// A = 0
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_Low);	// B = 0
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_High);	// C = 1
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_Low);	// D = 0
			break;
		case 5:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_High);	// A = 1
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_Low);	// B = 0
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_High);	// C = 1
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_Low);	// D = 0
			break;
		case 6:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_Low);	// A = 0
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_High);	// B = 1
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_High);	// C = 1
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_Low);	// D = 0
			break;
		case 7:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_High);	// A = 1
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_High);	// B = 1
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_High);	// C = 1
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_Low);	// D = 0
			break;
		case 8:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_Low);	// A = 0
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_Low);	// B = 0
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_Low);	// C = 0
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_High);	// D = 1
			break;
		case 9:
				Dio_setPinVal(Copy7segNum.Pin_1, Status_Pin_High);	// A = 1
				Dio_setPinVal(Copy7segNum.Pin_2, Status_Pin_Low);	// B = 0
				Dio_setPinVal(Copy7segNum.Pin_3, Status_Pin_Low);	// C = 0
				Dio_setPinVal(Copy7segNum.Pin_4, Status_Pin_High);	// D = 1
			break;
		default:
			break;
	}
}

void Bcd_MPX_2Enable(MPX_2_Enables CopyPinsEnable, u8 CopyCommonType, u8 CopyStatus)
{
	if(CopyStatus == Enable){
		switch (CopyCommonType) {
			case Common_Anode :

				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_High);
				break;
			case Common_Cathod :
				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_Low);
				break;
			default:
				break;
		}
	}
	else if (CopyStatus == Disable){
		switch (CopyCommonType) {
			case Common_Anode :

				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_Low);
				break;
			case Common_Cathod :
				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_High);
				break;
			default:
				break;
		}
	}
	else{}
}
void Bcd_MPX_4Enable(MPX_4_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus)
{
	if(CopyStatus == Enable){
		switch (CopyCommonType) {
			case Common_Anode :

				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_High);
				break;
			case Common_Cathod :
				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_Low);
				break;
			default:
				break;
		}
	}
	else if (CopyStatus == Disable)
	{
		switch (CopyCommonType) {
			case Common_Anode :

				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_Low);
				break;
			case Common_Cathod :
				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_High);
				break;
			default:
				break;
		}
	}
	else{}
}
void Bcd_MPX_6Enable(MPX_6_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus)
{
	if(CopyStatus == Enable){
		switch (CopyCommonType) {
			case Common_Anode :

				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_5, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_6, Status_Pin_High);
				break;
			case Common_Cathod :
				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_5, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_6, Status_Pin_Low);
				break;
			default:
				break;
		}
	}
	else if (CopyStatus == Disable)
	{
		switch (CopyCommonType) {
			case Common_Anode :

				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_5, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_6, Status_Pin_Low);
				break;
			case Common_Cathod :
				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_5, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_6, Status_Pin_High);
				break;
			default:
				break;
		}
	}
	else{}
}
void Bcd_MPX_8Enable(MPX_8_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus)
{
	if(CopyStatus == Enable){
		switch (CopyCommonType) {
			case Common_Anode :

				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_5, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_6, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_7, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_8, Status_Pin_High);
				break;
			case Common_Cathod :
				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_5, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_6, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_7, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_8, Status_Pin_Low);
				break;
			default:
				break;
		}
	}
	else if (CopyStatus == Disable)
	{
		switch (CopyCommonType) {
			case Common_Anode :

				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_5, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_6, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_7, Status_Pin_Low);
				Dio_setPinVal(CopyPinsEnable.EN_8, Status_Pin_Low);
				break;
			case Common_Cathod :
				Dio_setPinVal(CopyPinsEnable.EN_1, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_2, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_3, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_4, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_5, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_6, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_7, Status_Pin_High);
				Dio_setPinVal(CopyPinsEnable.EN_8, Status_Pin_High);
				break;
			default:
				break;
		}
	}
	else{}
}



