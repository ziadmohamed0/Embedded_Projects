
#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorStates.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIMER1/Timer1_int.h"
#include "../MCAL/ADC/ADC_int.h"



#include "main_config.h"
#include <util/delay.h>




void ServoMotor_Door(u8 Copy_u8Angle)
{

		float Local_floatDuty=0;
		Local_floatDuty = (((float)Copy_u8Angle/180.0)*5)+5;
		Timer_PWM(50,Local_floatDuty);
}



void Auto_AIR_COND_CONTROL(u8 Copy_u8LowerLimit,u8 Copy_u8UpperLimit)
{

	u16 Local_u16TempVal;
	Local_u16TempVal = ADC_Read(0);
	Local_u16TempVal = (float)Local_u16TempVal/2.0;

	if(Local_u16TempVal > Copy_u8UpperLimit)
	{
		DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN6,DIO_u8HIGH);
	}
	else if(Local_u16TempVal < Copy_u8LowerLimit)
	{
		DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN6,DIO_u8LOW);
	}
}

