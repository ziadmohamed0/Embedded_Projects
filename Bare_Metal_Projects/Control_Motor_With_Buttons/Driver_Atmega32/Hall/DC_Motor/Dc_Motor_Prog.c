/*
 * Dc_Motor_Prog.c
 *
 *  Created on: Mar 22, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "Dc_Motor_Init.h"

/********** SECTION : Functions Definitions **********/
void Motor_2_Motors_Init(motor1 CopyMotor_1,motor2 CopyMotor_2)
{
	Dio_setPinDir(m1.IN1, Direction_Pin_Output);
	Dio_setPinDir(m1.IN2, Direction_Pin_Output);
	Dio_setPinDir(m1.ENA, Direction_Pin_Output);


	Dio_setPinDir(m2.IN3, Direction_Pin_Output);
	Dio_setPinDir(m2.IN4, Direction_Pin_Output);
	Dio_setPinDir(m2.ENB, Direction_Pin_Output);

}


void Motor_2_Motors_Forward(motor1 CopyMotor_1,motor2 CopyMotor_2)
{
	Dio_setPinVal(CopyMotor_1.IN1, Status_Pin_High);
	Dio_setPinVal(CopyMotor_1.IN2, Status_Pin_Low);
	Dio_setPinVal(CopyMotor_1.ENA, Status_Pin_High);

	Dio_setPinVal(CopyMotor_2.IN3, Status_Pin_High);
	Dio_setPinVal(CopyMotor_2.IN4, Status_Pin_Low);
	Dio_setPinVal(CopyMotor_2.ENB, Status_Pin_High);
}

void Motor_2_Motors_Reverse(motor1 CopyMotor_1,motor2 CopyMotor_2)
{
	Dio_setPinVal(CopyMotor_1.IN1, Status_Pin_Low);
	Dio_setPinVal(CopyMotor_1.IN2, Status_Pin_High);
	Dio_setPinVal(CopyMotor_1.ENA, Status_Pin_High);


	Dio_setPinVal(CopyMotor_2.IN3, Status_Pin_Low);
	Dio_setPinVal(CopyMotor_2.IN4, Status_Pin_High);
	Dio_setPinVal(CopyMotor_2.ENB, Status_Pin_High);

}

void Motor_2_Motors_Off(motor1 CopyMotor_1,motor2 CopyMotor_2)
{
	Dio_setPinVal(CopyMotor_1.IN1, Status_Pin_Low);
	Dio_setPinVal(CopyMotor_1.IN2, Status_Pin_Low);
	Dio_setPinVal(CopyMotor_1.ENA, Status_Pin_Low);


	Dio_setPinVal(CopyMotor_2.IN3, Status_Pin_Low);
	Dio_setPinVal(CopyMotor_2.IN4, Status_Pin_Low);
	Dio_setPinVal(CopyMotor_2.ENB, Status_Pin_Low);
}

