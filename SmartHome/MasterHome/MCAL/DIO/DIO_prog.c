
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorStates.h"

#include "DIO_priv.h"
#include "DIO_config.h"

ES_t DIO_enuInit(void)
{
	ES_t Local_enuerrorStates = ES_NOK;

	DDRA=CONC(DIO_u8PA7_DIR,DIO_u8PA6_DIR,DIO_u8PA5_DIR,DIO_u8PA4_DIR,DIO_u8PA3_DIR,DIO_u8PA2_DIR,DIO_u8PA1_DIR,DIO_u8PA0_DIR);

	PORTA=CONC(DIO_u8PA7_VALUE,DIO_u8PA6_VALUE,DIO_u8PA5_VALUE,DIO_u8PA4_VALUE,DIO_u8PA3_VALUE,DIO_u8PA2_VALUE,DIO_u8PA1_VALUE,DIO_u8PA0_VALUE);

	return Local_enuerrorStates;
}

ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Direction)
{
	ES_t Local_enuerrorStates = ES_NOK;

	if (Copy_u8PortID <= DIO_u8GROUP_D
			&& Copy_u8PinID <= DIO_u8PIN7
			&& Copy_u8Direction <= DIO_u8OUTPUT)
	{
		switch (Copy_u8PortID)
		{
		case DIO_u8GROUP_A:

			DDRA &=~(DIO_MASK_BIT<<Copy_u8PinID);
			DDRA |= (Copy_u8Direction<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_B:

			DDRB &=~(DIO_MASK_BIT<<Copy_u8PinID);
			DDRB |= (Copy_u8Direction<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_C:

			DDRC &=~(DIO_MASK_BIT<<Copy_u8PinID);
			DDRC |= (Copy_u8Direction<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_D:

			DDRD &=~(DIO_MASK_BIT<<Copy_u8PinID);
			DDRD |= (Copy_u8Direction<<Copy_u8PinID);

			break;
		}
		Local_enuerrorStates = ES_OK;
	}
	else
	{
		Local_enuerrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuerrorStates;
}

ES_t DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
	ES_t Local_enuerrorStates = ES_NOK;

	if (Copy_u8PortID <= DIO_u8GROUP_D
			&& Copy_u8PinID <= DIO_u8PIN7
			&& (Copy_u8Value <= DIO_u8HIGH || Copy_u8Value <= DIO_u8PULL_UP ))
	{
		switch (Copy_u8PortID)
		{
		case DIO_u8GROUP_A:

			PORTA &=~(DIO_MASK_BIT<<Copy_u8PinID);
			PORTA |= (Copy_u8Value<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_B:

			PORTB &=~(DIO_MASK_BIT<<Copy_u8PinID);
			PORTB |= (Copy_u8Value<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_C:

			PORTC &=~(DIO_MASK_BIT<<Copy_u8PinID);
			PORTC |= (Copy_u8Value<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_D:

			PORTD &=~(DIO_MASK_BIT<<Copy_u8PinID);
			PORTD |= (Copy_u8Value<<Copy_u8PinID);

			break;
		}
		Local_enuerrorStates = ES_OK;
	}
	else
	{
		Local_enuerrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuerrorStates;
}

ES_t DIO_enuTogPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	ES_t Local_enuerrorStates = ES_NOK;

	if (Copy_u8PortID <= DIO_u8GROUP_D
			&& Copy_u8PinID <= DIO_u8PIN7)
	{
		switch (Copy_u8PortID)
		{
		case DIO_u8GROUP_A:

			PORTA ^= (DIO_MASK_BIT<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_B:

			PORTB ^= (DIO_MASK_BIT<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_C:

			PORTC ^= (DIO_MASK_BIT<<Copy_u8PinID);

			break;
		case DIO_u8GROUP_D:

			PORTD ^= (DIO_MASK_BIT<<Copy_u8PinID);

			break;
		}
		Local_enuerrorStates = ES_OK;
	}
	else
	{
		Local_enuerrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuerrorStates;
}
ES_t DIO_enuGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_pu8Value)
{
	ES_t Local_enuerrorStates = ES_NOK;

	if (Copy_pu8Value != NULL)
	{
		if(Copy_u8PortID <= DIO_u8GROUP_D
				&& Copy_u8PinID <= DIO_u8PIN7)
		{
			switch (Copy_u8PortID)
			{
			case DIO_u8GROUP_A:

				*Copy_pu8Value = ( (PINA >> Copy_u8PinID ) & DIO_MASK_BIT);

				break;
			case DIO_u8GROUP_B:

				*Copy_pu8Value = ( (PINB >> Copy_u8PinID ) & DIO_MASK_BIT);

				break;
			case DIO_u8GROUP_C:

				*Copy_pu8Value = ( (PINC >> Copy_u8PinID ) & DIO_MASK_BIT);

				break;
			case DIO_u8GROUP_D:

				*Copy_pu8Value = ( (PIND >> Copy_u8PinID ) & DIO_MASK_BIT);

				break;
			}
			Local_enuerrorStates = ES_OK;
		}
		else
		{
			Local_enuerrorStates = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuerrorStates = ES_NULL_POINTER;
	}

	return Local_enuerrorStates;
}
