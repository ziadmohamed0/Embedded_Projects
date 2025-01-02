
#include "../LIBRARIES/interrupt.h"

#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorStates.h"
#include "../LIBRARIES/AVR_REG.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/TIMER1/Timer1_int.h"
#include "../MCAL/PWM/PWM_config.h"
#include "../MCAL/PWM/PWM_int.h"



#include "main_config.h"
#include "LoginSystem.h"
#include <util/delay.h>

extern PWM_t PWM_AstrPWMConfig[TIMER_NUM];
volatile u8 Master_Command;		//This Command is sent by The master by SPI and Read by Slave in SPI ISR

int main()
{
/*********************************************INITIALIZATION******************************************/
		SPI_vidInit ();
 	    Timer1_init();
		ADC_Init();
		PWM_enuInit(PWM_AstrPWMConfig);
/**********************************************DECLARATIONS*******************************************/
		u8 AirCond_ManualControlFlag=0;
		u8 Dimming_percent;
		u8 Local_High_temp_limit = 28 ;
		u8 Local_Low_temp_limit = 21 ;

/*****************************************DEVICES OUTPUT CONFIGURATION*********************************************************/

		DIO_enuSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN5,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN6,DIO_u8OUTPUT);

		DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN1,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN2,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN3,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN4,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN5,DIO_u8OUTPUT);

		DIO_enuSetPinDirection(DIO_u8GROUP_B, DIO_u8PIN3, DIO_u8OUTPUT);

			__asm("sei");// GIE Enable
		SPI_EnableINT();



	while (1)
	{

/******************************AIR CONDITIONER AUTOMATIC CONTROL*********************************************/

				if(AirCond_ManualControlFlag == 0)
				{
					Auto_AIR_COND_CONTROL(Local_Low_temp_limit,Local_High_temp_limit);
				}


/***************************************************************************************************************/

		switch(Master_Command)
		{
		case ROOM1_LED_TOGGLE:
			DIO_enuTogPinValue(DIO_u8GROUP_A,DIO_u8PIN1);
			Master_Command=0;
			break;

		case ROOM2_LED_TOGGLE:
			DIO_enuTogPinValue(DIO_u8GROUP_A,DIO_u8PIN2);
			Master_Command=0;
			break;

		case ROOM3_LED_TOGGLE:
			DIO_enuTogPinValue(DIO_u8GROUP_A,DIO_u8PIN3);
			Master_Command=0;
			break;

		case ROOM4_LED_TOGGLE:
			DIO_enuTogPinValue(DIO_u8GROUP_A,DIO_u8PIN4);
			Master_Command=0;
			break;

		case ROOM5_LED_TOGGLE:
			DIO_enuTogPinValue(DIO_u8GROUP_A,DIO_u8PIN5);
			Master_Command=0;
			break;

		case DIMMER:
			SPI_DisableINT();
			Dimming_percent = SPI_ui8TransmitRecive(0);
			PWM_enuSetFrequency(50,&PWM_AstrPWMConfig[0]);
			PWM_enuSetDutyCycle(Dimming_percent, &PWM_AstrPWMConfig[0]);
			Master_Command=0;
			SPI_EnableINT();
			break;
		case OPEN_DOOR_COMMAND:
			ServoMotor_Door(90);
			Master_Command=0;
			break;

		case CLOSE_DOOR_COMMAND:
			ServoMotor_Door(0);
			Master_Command=0;
			break;

		case OPEN_AirCond_COMMAND:
			DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN6,DIO_u8HIGH);
			AirCond_ManualControlFlag =1;
			Master_Command=0;
			break;

		case CLOSE_AirCond_COMMAND:
			DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN6,DIO_u8LOW);
			AirCond_ManualControlFlag =1;
			Master_Command=0;
			break;
		case AUTO_AirCond_COMMAND:
			AirCond_ManualControlFlag =0;
			Master_Command=0;
			break;
		default:

			break;
		}



	}//end of the while (1)
}

ISR (SPI_VECT)
{
	Master_Command = SPDR;
}
