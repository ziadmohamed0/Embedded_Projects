
#include "../../LIBRARY/errorStates.h"
#include "../../LIBRARY/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"


#include <util/delay.h>


ES_t LCD_enuInit(void)
{
	ES_t Local_enuerrorStates = ES_NOK;

	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);

	_delay_ms(35);
#if LCD_MODE == FOUR_BIT
	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x28);

#elif LCD_MODE == EIGHT_BIT
	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x38);

	DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);



#endif

	_delay_ms(1);
	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x0f);

	_delay_ms(1);
	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x01);

	_delay_ms(2);
	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x06);

	return Local_enuerrorStates;
}

ES_t LCD_enuSendData(u8 Copy_u8Data)
{
	ES_t Local_enuerrorStates = ES_NOK;

	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
	LCD_enuWriteNLatch(Copy_u8Data);


	return Local_enuerrorStates;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuerrorStates = ES_NOK;

	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(Copy_u8Command);

	return Local_enuerrorStates;
}


static ES_t LCD_enuWriteNLatch(u8 Copy_u8Data)
{
	ES_t Local_enuerrorStates = ES_NOK;

	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);

	if (Copy_u8Data == 0x28)//'('
	{
		u8 Local_u8RS_Val;
		DIO_enuGetPinValue(RS_PORT, RS_PIN, &Local_u8RS_Val);

		if (Local_u8RS_Val == DIO_u8LOW)
		{
			DIO_enuSetPinValue(D7_PORT, D7_PIN , ((Copy_u8Data>>7)&1));
			DIO_enuSetPinValue(D6_PORT, D6_PIN , ((Copy_u8Data>>6)&1));
			DIO_enuSetPinValue(D5_PORT, D5_PIN , ((Copy_u8Data>>5)&1));
			DIO_enuSetPinValue(D4_PORT, D4_PIN , ((Copy_u8Data>>4)&1));

			DIO_enuSetPinValue(EN_PORT, EN_PIN , DIO_u8HIGH);
			_delay_ms(5);
			DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
			_delay_ms(50);  //el lcd ta5od nafas.ha
		}
	}

#if LCD_MODE == FOUR_BIT //'A' =65=0b 0100  0001

	DIO_enuSetPinValue(D7_PORT, D7_PIN , ((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN , ((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN , ((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN , ((Copy_u8Data>>4)&1));

	DIO_enuSetPinValue(EN_PORT, EN_PIN , DIO_u8HIGH);
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(50);  //el lcd ta5od nafas.ha;


	DIO_enuSetPinValue(D7_PORT, D7_PIN , ((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN , ((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN , ((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN , ((Copy_u8Data>>0)&1));

	DIO_enuSetPinValue(EN_PORT, EN_PIN , DIO_u8HIGH);
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(50);  //el lcd ta5od nafas.ha

#elif LCD_MODE == EIGHT_MODE
	//8
#else
#error"LCD mode is wrong"
#endif


	return Local_enuerrorStates;
}

/****************************************************************************************************/

ES_t LCD_enuDisplayUnsignedInteger(u16 Copy_u32Data)
{
	ES_t Local_enuerrorStates = ES_NOK;



	if (Copy_u32Data == 0)
	{
		DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
		LCD_enuWriteNLatch('0');
	}
	else
	{
		u8 Local_u8Remainder;
		u32 Local_u32Reversed = 0;
		u8 Local_u8Counter=0;
		for (;Copy_u32Data>0;)
			{
				Local_u8Remainder = Copy_u32Data%10;
				Local_u32Reversed = Local_u32Reversed*10 + Local_u8Remainder;
				Local_u8Counter++;
				Copy_u32Data/=10;
			}
			/*********in the previous step: 3malt reverse lel integer elly gayelly, 3ashan law ma3amaltelosh reverse hayetebe3 ma3koos**********/
			for (;Local_u32Reversed>0;)
			{
				DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
				Local_enuerrorStates = LCD_enuWriteNLatch(Local_u32Reversed%10 + '0');
				Local_u32Reversed/=10;
				Local_u8Counter--;
				/*********el mafrood a3mel error status check hna bs 3ashan write and latch me7taga te3mel return ES_OK fa me7taga ta3deel**********/
			}
			while (Local_u8Counter != 0)
			{
				LCD_enuWriteNLatch('0');
				Local_u8Counter--;
			}
	}


	return Local_enuerrorStates;

}
/*
ES_t LCD_enuDisplaySignedInteger(s32 Copy_s32Data)
{
	ES_t Local_enuerrorStates = ES_NOK;

	u8 Local_u8Remainder;
	u32 Local_u32Reversed = 0;

	if (Copy_s32Data < 0)
	{
		DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
		Local_enuerrorStates = LCD_enuWriteNLatch('-');
		Copy_s32Data *= -1;
	}
	for (;Copy_s32Data>0;)
	{
		Local_u8Remainder = Copy_s32Data%10;
		Local_u32Reversed = Local_u32Reversed*10 + Local_u8Remainder;
		Copy_s32Data/=10;
	}
	/*********in the previous step: 3malt reverse lel integer elly gayelly, 3ashan law ma3amaltelosh reverse hayetebe3 ma3koos**********
	for (;Local_u32Reversed>0;)
	{
		DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
		Local_enuerrorStates = LCD_enuWriteNLatch(Local_u32Reversed%10 + '0');
		Local_u32Reversed/=10;
		/*********el mafrood a3mel error status check hna bs 3ashan write and latch me7taga te3mel return ES_OK fa me7taga ta3deel**********
	}

	return Local_enuerrorStates;

}

ES_t LCD_enuDisplayFloat(f64 Copy_f64Data)
{
	ES_t Local_enuerrorStates = ES_NOK;
	u8 Local_u8Remainder;
	u32 Local_u32Reversed = 0;

	u32 Local_u32BeforeDecimalPoint;


	if (Copy_f64Data < 0)
	{
		DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
		Local_enuerrorStates = LCD_enuWriteNLatch('-');
		Copy_f64Data *= -1;
	}

	Local_u32BeforeDecimalPoint = (u32)(Copy_f64Data);
	Copy_f64Data -= Local_u32BeforeDecimalPoint;

	for (;Local_u32BeforeDecimalPoint>0;)
	{
		Local_u8Remainder = Local_u32BeforeDecimalPoint%10;
		Local_u32Reversed = Local_u32Reversed*10 + Local_u8Remainder;
		Local_u32BeforeDecimalPoint/=10;
	}
	/*********in the previous step: 3malt reverse lel integer elly gayelly, 3ashan law ma3amaltelosh reverse hayetebe3 ma3koos**********
	for (;Local_u32Reversed>0;)
	{
		DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
		Local_enuerrorStates = LCD_enuWriteNLatch(Local_u32Reversed%10 + '0');
		Local_u32Reversed/=10;
		/*********el mafrood a3mel error status check hna bs 3ashan write and latch me7taga te3mel return ES_OK fa me7taga ta3deel**********
	}


	if (Copy_f64Data != 0)
	{
		DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
		Local_enuerrorStates = LCD_enuWriteNLatch('.');
	//	for (;Copy_f64Data>0;)
		for (u8 Local_u8Iterator=0 ;Local_u8Iterator < 5; Local_u8Iterator++)
			{
				Copy_f64Data *= 10;
				DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
				Local_enuerrorStates = LCD_enuWriteNLatch((int)(Copy_f64Data) + '0');
				Copy_f64Data -= (int)(Copy_f64Data);
				/*********el mafrood a3mel error status check hna bs 3ashan write and latch me7taga te3mel return ES_OK fa me7taga ta3deel**********
			}
	}

	return Local_enuerrorStates;
}
*/
ES_t LCD_enuDisplayString(const char * Copy_pcString)
{
	ES_t Local_enuerrorStates = ES_NOK;
	if (Copy_pcString != NULL)
	{
		while (*Copy_pcString)
		{
			DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
			Local_enuerrorStates = LCD_enuWriteNLatch(*Copy_pcString++);
		}

	}
	else Local_enuerrorStates = ES_NULL_POINTER;
	return Local_enuerrorStates;
}


ES_t LCD_enuSetCursorPosition(u8 Copy_u8XDimension, u8 Copy_u8YDimension)
{

	ES_t Local_enuerrorStates = ES_NOK;
	if ((Copy_u8XDimension <= LCD_u8XDIM_1) && (Copy_u8YDimension <= LCD_u8YDIM_15))
		{
		Local_enuerrorStates = DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
		LCD_enuWriteNLatch(0x80 + (Copy_u8XDimension*64) + Copy_u8YDimension);
		}
	return Local_enuerrorStates;

}

ES_t LCD_enuClearDisplay( void )
{

	ES_t Local_enuerrorStates = ES_NOK;

		Local_enuerrorStates = DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
		LCD_enuWriteNLatch(0x01);

	return Local_enuerrorStates;

}
