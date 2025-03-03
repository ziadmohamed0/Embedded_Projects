/*
 * INTERRUPT_prog.c
 *
 *  Created on: Jun 14, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "INTERRUPT_init.h"

/*********** STATIC FUNCTIONS DECLER ***********/
/**
  * @brief  : Static Function Control Direction of External Interrupt {0}
  * @param1 : copySense
  * @retVal : void
  */
static void EXINTER_controlINT0(_SENSE_SELECT copySense);

/**
  * @brief  : Static Function Control Direction of External Interrupt {1}
  * @param1 : copySense
  * @retVal : void
  */
static void EXINTER_controlINT1(_SENSE_SELECT copySense);

/**
  * @brief  : Static Function Control Direction of External Interrupt {2}
  * @param1 : copySense
  * @retVal : void
  */
static void EXINTER_controlINT2(_SENSE_SELECT copySense);


/*********** FUNCTIONS DEFIN ***********/
/**
  * @brief  : Initialization External Interrupt
  * 		  put number of external interrupt &
  * 		  put status or sense of signal.
  * @param1  : copyNumInt
  * @param2  : copySense
  */
void EXINTER_init(_NUM_EX_INTERRUPT copyNumInt,_SENSE_SELECT copySense)
{
	SET_BIT(SREG,GIE);	// set general interrupt bit

	switch(copyNumInt)
	{
		case INT0:
			EXINTER_controlINT0(copySense);
			SET_BIT(GICR,_INT0);
			DIO_setPinDIR(PIND2, _DIRECTION_PIN_INPUT);
			break;
		case INT1:
			EXINTER_controlINT1(copySense);
			SET_BIT(GICR,_INT1);
			DIO_setPinDIR(PIND3, _DIRECTION_PIN_INPUT);
			break;
		case INT2:
			EXINTER_controlINT2(copySense);
			SET_BIT(GICR,_INT2);
			DIO_setPinDIR(PINB2, _DIRECTION_PIN_INPUT);
			break;
	}
}

/*********** STATIC FUNCTIONS DEFIN ***********/
/**
  * @brief  : Static Function Control Direction of External Interrupt {0}
  * @param1 : copySense
  * @retVal : void
  */
static void EXINTER_controlINT0(_SENSE_SELECT copySense)
{
	switch (copySense)
	{
		case LOW:
			CLR_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
			break;
		case ANY:
			CLR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
		case FALLING:
			SET_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
			break;
		case RISING:
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
	}
}

/**
  * @brief  : Static Function Control Direction of External Interrupt {1}
  * @param1 : copySense
  * @retVal : void
  */
static void EXINTER_controlINT1(_SENSE_SELECT copySense)
{
	switch (copySense)
	{
		case LOW:
			CLR_BIT(MCUCR,ISC11);
			CLR_BIT(MCUCR,ISC10);
			break;
		case ANY:
			CLR_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break;
		case FALLING:
			SET_BIT(MCUCR,ISC11);
			CLR_BIT(MCUCR,ISC10);
			break;
		case RISING:
			SET_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break;
	}
}


/**
  * @brief  : Static Function Control Direction of External Interrupt {2}
  * @param1 : copySense
  * @retVal : void
  */
static void EXINTER_controlINT2(_SENSE_SELECT copySense)
{
	switch (copySense)
	{
		case FALLING:
			CLR_BIT(MCUCR,ISC2);
			break;
		case RISING:
			SET_BIT(MCUCR,ISC2);
			break;
		default:
			CLR_BIT(MCUCSR,ISC2);
			break;
	}
}

