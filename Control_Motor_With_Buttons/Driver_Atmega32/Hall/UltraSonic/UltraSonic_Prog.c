/*
 * UltraSonic_Prog.c
 *
 *  Created on: Apr 9, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "UltraSonic_Init.h"

/********** SECTION : Functions Definitions **********/
void UltraSonic_Init(UltraSonic CopyUltraSonic)
{
	Dio_setPinDir(CopyUltraSonic.Triger,Direction_Pin_Output);
	Dio_setPinDir(CopyUltraSonic.Echo,Direction_Pin_Input);
}
void UltraSonic_ReadDistance(UltraSonic CopyUltraSonic , u8 CopyDistance)
{
	Dio_setPinVal(CopyUltraSonic.Triger,Status_Pin_Low);
	_delay_ms(2);
	Dio_setPinVal(CopyUltraSonic.Triger,Status_Pin_High);
	_delay_ms(10);
	Dio_setPinVal(CopyUltraSonic.Triger,Status_Pin_Low);

//	Dio_setPinVal(CopyUltraSonic.Echo, Status_Pin_High);


}
