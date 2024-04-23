/*
 * Initialized_Prog.c
 *
 *  Created on: Apr 8, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "Initialize_Init.h"

/********** SECTION : Globale Variable **********/
u8 KeyPad_Value = 0;
/********** SECTION : Functions setUp Definitions **********/
void App_Init(void)
{
	LCD_4_INIT(LCD_2);
	Motor_2_Motors_Init(m1,m2);

	Dio_setPinDir(PortD_p0, Direction_Pin_Input);	//foward
	Dio_setPinDir(PortD_p1, Direction_Pin_Input);	//reverse
	Dio_setPinDir(PortD_p2, Direction_Pin_Input);	//Off
	Dio_setPinDir(PortC_p0, Direction_Pin_Output);
	Dio_setPinDir(PortC_p1, Direction_Pin_Output);
	Dio_setPinDir(PortC_p2, Direction_Pin_Output);


	LCD_4_STR_Postion(LCD_2, Row_1, 1 , "================");

	LCD_4_STR_Postion(LCD_2, Row_2 , 7 , "Hello");
	LCD_4_STR_Postion(LCD_2, Row_3 , 2 , "My name is Ziad");

	LCD_4_STR_Postion(LCD_2, Row_4, 1 , "================");

	_delay_ms(1000);
	LCD_4_CMD_Write(LCD_2, _LCD_Clear_Dis);

	LCD_4_STR_Postion(LCD_2, Row_1, 1 , "================");
	LCD_4_STR_Postion(LCD_2, Row_2 , 2 , "Motors is OFF.");
	LCD_4_STR_Postion(LCD_2, Row_3, 1 , "================");
	LCD_4_STR_Postion(LCD_2, Row_4, 1 , "================");
}

/********** SECTION : Functions Loop Definitions **********/
void App_Loop(void)
{
	u8 foward 	= Dio_getPinVal(PortD_p0);
	u8 reverse 	= Dio_getPinVal(PortD_p1);
	u8 off 		= Dio_getPinVal(PortD_p2);

	if(foward == Status_Pin_High)
	{
		LCD_4_CMD_Write(LCD_2, _LCD_Clear_Dis);

		LCD_4_STR_Postion(LCD_2, Row_1, 1 , "================");

		Motor_2_Motors_Off(m1,m2);
		Dio_setPinVal(PortC_p1, Status_Pin_High);
		Dio_setPinVal(PortC_p2, Status_Pin_Low);
		Dio_setPinVal(PortC_p0, Status_Pin_Low);

		Motor_2_Motors_Forward(m1,m2);
		LCD_4_STR_Postion(LCD_2, Row_2 , 2 , "Motors Forward.");
		LCD_4_STR_Postion(LCD_2, Row_3, 1 , "================");
		LCD_4_STR_Postion(LCD_2, Row_4, 1 , "================");

	}
	if(reverse == Status_Pin_High)
	{
		LCD_4_CMD_Write(LCD_2, _LCD_Clear_Dis);

		LCD_4_STR_Postion(LCD_2, Row_1, 1 , "================");

		Motor_2_Motors_Off(m1,m2);
		Dio_setPinVal(PortC_p2, Status_Pin_High);
		Dio_setPinVal(PortC_p1, Status_Pin_Low);
		Dio_setPinVal(PortC_p0, Status_Pin_Low);


		Motor_2_Motors_Reverse(m1,m2);

		LCD_4_STR_Postion(LCD_2, Row_2 , 2 , "Motors Reverse.");
		LCD_4_STR_Postion(LCD_2, Row_3, 1 , "================");
		LCD_4_STR_Postion(LCD_2, Row_4, 1 , "================");


	}
	if(off == Status_Pin_High)
	{
		LCD_4_CMD_Write(LCD_2, _LCD_Clear_Dis);

		LCD_4_STR_Postion(LCD_2, Row_1, 1 , "================");

		Motor_2_Motors_Off(m1,m2);

		Dio_setPinVal(PortC_p0, Status_Pin_High);
		Dio_setPinVal(PortC_p1, Status_Pin_Low);
		Dio_setPinVal(PortC_p2, Status_Pin_Low);

		LCD_4_STR_Postion(LCD_2, Row_2 , 1 , "Motors turn OFF.");
		LCD_4_STR_Postion(LCD_2, Row_3, 1 , "================");
		LCD_4_STR_Postion(LCD_2, Row_4, 1 , "================");

	}


}
