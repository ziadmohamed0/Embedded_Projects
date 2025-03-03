
#include "../../LIBRARY/errorStates.h"
#include "../../LIBRARY/stdTypes.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"

#include "../../LIBRARY/interrupt.h"

//static volatile void (* EXTI_pfunISR_fun[INTERRUPT_NUM]) (void) = { NULL , NULL , NULL };
static volatile void (* EXTI_pfunISR_fun) (void) =  NULL; 

ES_t EXTI_enuInit()
{
ES_t Local_enuerrorStates = ES_NOK ;
///////////////////////////////////////////////////////////////////////////////

if(Interrupt_State == ENABELED)
{
			GICR |= (1<<6);

		switch(INT_Sense_Level)
		{
		case LOW_LEVEL:

			MCUCR &= ~(3<<0);	//mask bit 0,1
			break;
		case ANY_LOGICAL:

			MCUCR |= (1<<0);	//set bit 0

			MCUCR &= ~(1<<1);	//mask bit 1

			break;
		case FALLING:

			MCUCR &= ~(1<<0);	//mask bit 0

			MCUCR |= (1<<1);	//set bit 1

			break;
		case RISING:

			MCUCR |= (3<<0);	//set bit 0,1

			break;
		default :
			Local_enuerrorStates =ES_OUT_OF_RANGE;

		}
}

	else if(Interrupt_State == DISABELED)
		{
			GICR &= ~(1<<6);
		}



return Local_enuerrorStates;
}

ES_t EXTI_enuEnableInterrupt()
{
ES_t Local_enuerrorStates = ES_NOK ;


		GICR |= (1<<6);
		Local_enuerrorStates = ES_OK;

return Local_enuerrorStates;
}

ES_t EXTI_enuDisableInterrupt(u8 Copy_u8InterruptNum)
{
ES_t Local_enuerrorStates = ES_NOK ;


		GICR &= ~(1<<6);
		Local_enuerrorStates = ES_OK;

return Local_enuerrorStates;
}

ES_t EXTI_enuCallBack(volatile void  (* pfunAppFunction)(void))//,u8 Copy_u8InterruptNum)
{
ES_t Local_enuerrorStates = ES_NOK ;

	if(pfunAppFunction != NULL)
	{
		
		
			EXTI_pfunISR_fun = pfunAppFunction;

			Local_enuerrorStates = ES_OK;
		
	}
	else
	{
		Local_enuerrorStates = ES_NULL_POINTER;
	}

	return Local_enuerrorStates;
}

ISR(VECT_INT0)
{
	if(EXTI_pfunISR_fun != NULL)
	{
		EXTI_pfunISR_fun ();
	}
}
