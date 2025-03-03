
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Keypad_config.h"
#include "Keypad_priv.h"

#include <util/delay.h>

ES_t Keypad_enuInit(void)
{
	ES_t Local_enuerrorStates = ES_NOK;

	DIO_enuSetPinDirection(C1_PORT , C1_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C2_PORT , C2_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C3_PORT , C3_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C4_PORT , C4_PIN , DIO_u8OUTPUT);

	DIO_enuSetPinDirection(R1_PORT , R1_PIN , DIO_u8INPUT);
	DIO_enuSetPinDirection(R2_PORT , R2_PIN , DIO_u8INPUT);
	DIO_enuSetPinDirection(R3_PORT , R3_PIN , DIO_u8INPUT);
	DIO_enuSetPinDirection(R4_PORT , R4_PIN , DIO_u8INPUT);

	DIO_enuSetPinValue(C1_PORT , C1_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(C2_PORT , C2_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(C3_PORT , C3_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(C4_PORT , C4_PIN , DIO_u8HIGH);

	DIO_enuSetPinValue(R1_PORT , R1_PIN , DIO_u8PULL_UP);
	DIO_enuSetPinValue(R2_PORT , R2_PIN , DIO_u8PULL_UP);
	DIO_enuSetPinValue(R3_PORT , R3_PIN , DIO_u8PULL_UP);
	DIO_enuSetPinValue(R4_PORT , R4_PIN , DIO_u8PULL_UP);

	return Local_enuerrorStates;
}

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue)
{
	ES_t Local_enuerrorStates = ES_NOK;

	u8 Local_Au8ColPorts [COL_NUM] = {C1_PORT,C2_PORT,C3_PORT,C4_PORT};
	u8 Local_Au8ColPins  [COL_NUM] = {C1_PIN, C2_PIN, C3_PIN, C4_PIN};

	u8 Local_Au8RowPorts [ROW_NUM] = {R1_PORT,R2_PORT,R3_PORT,R4_PORT};
	u8 Local_Au8RowPins  [ROW_NUM] = {R1_PIN, R2_PIN, R3_PIN, R4_PIN};

	u8 Local_u8ColIter , Local_u8RowIter , Local_u8PinValue;
	*Copy_pu8KeyValue = KEYPAD_NOT_PRESSED;
	while (*Copy_pu8KeyValue == KEYPAD_NOT_PRESSED)
	{
	for (Local_u8ColIter=0; Local_u8ColIter < COL_NUM ; Local_u8ColIter++ )
	{
		DIO_enuSetPinValue(Local_Au8ColPorts[Local_u8ColIter], Local_Au8ColPins[Local_u8ColIter], DIO_u8LOW);
		for (Local_u8RowIter=0; Local_u8RowIter < ROW_NUM ; Local_u8RowIter++)
		{
			DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);
			if (! Local_u8PinValue)
			{
				_delay_ms(10);
				DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);
				if (! Local_u8PinValue)
				{
					while (! Local_u8PinValue)
						DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);

					u8 Local_Au8Values[ROW_NUM][COL_NUM] = KEYPAD_VALUES;
					*Copy_pu8KeyValue = Local_Au8Values[Local_u8RowIter][Local_u8ColIter];
					return ES_OK;
				}
			}
		}
		DIO_enuSetPinValue(Local_Au8ColPorts[Local_u8ColIter], Local_Au8ColPins[Local_u8ColIter], DIO_u8HIGH);
	}
	}
	return Local_enuerrorStates;
}
