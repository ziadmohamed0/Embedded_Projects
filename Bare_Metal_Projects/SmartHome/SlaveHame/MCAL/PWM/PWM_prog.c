
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "../PWM/PWM_config.h"
#include "../PWM/PWM_priv.h"

extern u8 PWM_u8TimerNum;

ES_t PWM_enuInit(PWM_t * Copy_pAstrPWMConfig)
{
	ES_t Local_enuErrorState =ES_NOK;

	if(Copy_pAstrPWMConfig[0].TimerNum == 0)
	{
		if (Copy_pAstrPWMConfig[0].PWM_Type == FAST_PWM)
		{
			if (Copy_pAstrPWMConfig[0].OC_PinConfig == NON_INVERTED)
			{
				TCCR0 = 0x68;
			}
		}
		else if(Copy_pAstrPWMConfig[0].PWM_Type == 150 /*Phase_PWM*/)
		{

		}
	}

	return Local_enuErrorState;
}

ES_t PWM_enuSetFrequency(u16 Copy_u16Frequency , PWM_t * Copy_pstrPWMConfig)
{
	ES_t Local_enuErrorState =ES_NOK;

	u16 Local_Au16FreqFast []={62400,7812,976,245,61};
	u16 Local_Au16FreqPhase[]={31200,3650,467,123,30};

	u8 flag=0;

	if (Copy_pstrPWMConfig->TimerNum == 0)
	{
		if (Copy_pstrPWMConfig->PWM_Type == FAST_PWM)
		{
			for (u8 i=0 ; i<5 ; i++)
			{
				if (Copy_u16Frequency == Local_Au16FreqFast[i])
				{
					TCCR0 &=~(7<<0);
					TCCR0 |= (i+1);
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				for (u8 i=0; i<5 ; i++)
				{
					if (Copy_u16Frequency > Local_Au16FreqFast[i])
					{
						TCCR0 &=~(7<<0);
						TCCR0 |= (i+1);
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					TCCR0 &=~(7<<0);
					TCCR0 |= (5);
				}
			}
		}
	}

	return Local_enuErrorState;
}

ES_t PWM_enuSetDutyCycle(u8 Copy_u8DutyCycle, PWM_t * Copy_pstrPWMConfig)
{
	ES_t Local_enuErrorState =ES_NOK;

	if (Copy_u8DutyCycle <=100)
	{
		if (Copy_pstrPWMConfig->TimerNum == 0)
		{
			if (Copy_pstrPWMConfig->PWM_Type == FAST_PWM)
			{
				if (Copy_pstrPWMConfig->OC_PinConfig == NON_INVERTED)
				{
					u8 OCR_Value = (u8)( (Copy_u8DutyCycle * 256ul)/100ul );
					OCR0 = OCR_Value;
				}
			}
		}
	}

	return Local_enuErrorState;
}
