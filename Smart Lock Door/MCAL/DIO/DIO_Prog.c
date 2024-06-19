/*
 * DIO_Prog.c
 *
 *  Created on: Jun 12, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "DIO_Init.h"

/*********** ARRAY ***********/
volatile uint_8 *ARR_DDR[11]  = {DDRA  , DDRB  , DDRC  , DDRD };
volatile uint_8 *ARR_PORT[11] = {PORTA , PORTB , PORTC , PORTD};
volatile uint_8 *ARR_PIN[11]  = {PINA  , PINB  , PINC  , PIND};

/*********** FUNCTIONS DEFIN ***********/
	/* ----- FUNCTIONS PINS ----- */
/**
 * @brief  : This function control in the DDRx Register selects the direction of this pin.
 * 			 If DDxn is written logic DIRECTION_PIN_OUTPUT,Pin_x is configured as an output pin.
 * 			 If DDxn is written logic DIRECTION_PIN_INPUT, Pn_x is configured as an input pin.
 * @param1 : copyPortNum
 * @param2 : copyPinNum
 * @param3 : copyDir
 * @retVal : void
 */
void DIO_setPinDIR(_GPIO_PINS copyPinNum,_DIRECTION_PINS copyDir)
{
	switch (copyDir)
	{
		case _DIRECTION_PIN_INPUT  : CLR_BIT(*(ARR_DDR[copyPinNum / 8]),(copyPinNum % 8)); break;
		case _DIRECTION_PIN_OUTPUT : SET_BIT(*(ARR_DDR[copyPinNum / 8]),(copyPinNum % 8)); break;
	}
}

/**
 * @brief  : This function control in the PORTxn Register selects the Status of this pin.
 * 			 If PORTxn is written logic STATUS_PIN_LOW,Pin_x is configured as an LOW pin.
 * 			 If PORTxn is written logic STATUS_PIN_HIGH, Pn_x is configured as an HIGH pin.
 *		  	 If PORTxn is written logic STATUS_PIN_TOGGLE, Pn_x is configured as an TOGGLE pin.
 * @param1 : copyPortNum
 * @param2 : copyPinNum
 * @param3 : copyVal
 * @retVal : void
 */
void DIO_setPinVAL(_GPIO_PINS copyPinNum,_STATUS_PINS copyVal)
{
	switch (copyVal)
	{
		case _STATUS_PIN_LOW    : CLR_BIT(*(ARR_PORT[copyPinNum / 8]),(copyPinNum % 8));    break;
		case _STATUS_PIN_HIGH   : SET_BIT(*(ARR_PORT[copyPinNum / 8]),(copyPinNum % 8));    break;
		case _STATUS_PIN_TOGGLE : TOGGLE_BIT(*(ARR_PORT[copyPinNum / 8]),(copyPinNum % 8)); break;
	}
}

/**
 * @brief  : This function control Some Bits in the DDRx Register from Start Bit To End Bit
 * 			 selects the direction of this pin.
 * 			 If DDxn is written logic DIRECTION_PIN_OUTPUT,Pin_x is configured as an output pin.
 * 			 If DDxn is written logic DIRECTION_PIN_INPUT, Pn_x is configured as an input pin.
 * @param1 : copyPortNum
 * @param2 : copyStartPin
 * @param3 : copyEndPin
 * @param4 : copyDir
 * @retVal : void
 */
void DIO_setPINSDIR(_GPIO_PINS *copyStartPin, _GPIO_PINS copyEndPin, _DIRECTION_PINS copyDir)
{
	for (uint_8 Count = Zero_INIT ;  Count < copyEndPin ; Count++)
	{
		switch (copyDir)
		{
			case _DIRECTION_PIN_INPUT  : CLR_BIT(*(ARR_DDR[copyStartPin[Count] / 8]),(copyStartPin[Count] % 8)); break;
			case _DIRECTION_PIN_OUTPUT : SET_BIT(*(ARR_DDR[copyStartPin[Count] / 8]),(copyStartPin[Count] % 8)); break;
		}
	}
}

/**
 * @brief  : This function control in the Some Bits in PORTxn Register from Start Bit To End Bit
 * 			 selects the Status of this pin.
 * 			 If PORTxn is written logic STATUS_PIN_LOW,Pin_x is configured as an LOW pin.
 * 			 If PORTxn is written logic STATUS_PIN_HIGH, Pn_x is configured as an HIGH pin.
 *		  	 If PORTxn is written logic STATUS_PIN_TOGGLE, Pn_x is configured as an TOGGLE pin.
 * @param1 : copyPortNum
 * @param2 : copyStartPin
 * @param3 : copyEndPin
 * @param4 : copyVal
 * @retVal : void
 */
void DIO_setPINSVAL(_GPIO_PINS *copyStartPin, _GPIO_PINS copyEndPin, _STATUS_PINS copyVal)
{
	for (uint_8 Count = Zero_INIT ;  Count < copyEndPin ; Count++)
	{
		switch (copyVal)
		{
			case _STATUS_PIN_LOW    : CLR_BIT(*(ARR_PORT[copyStartPin[Count] / 8]),(copyStartPin[Count] % 8));    break;
			case _STATUS_PIN_HIGH   : SET_BIT(*(ARR_PORT[copyStartPin[Count] / 8]),(copyStartPin[Count] % 8));    break;
			case _STATUS_PIN_TOGGLE : TOGGLE_BIT(*(ARR_PORT[copyStartPin[Count] / 8]),(copyStartPin[Count] % 8)); break;
		}
	}
}

/**
 * @brief  : if DDxn configured input Pn_x This function get Status from PINxn Register
 * @param1 : copyPortNum
 * @param2 : copyPinNum
 * @retVal : Ret1
 */
Return_Value DIO_getPinVAL(_GPIO_PINS copyPinNum)
{
	uint_8 Ret = Zero_INIT;
	Ret = GET_BIT(*(ARR_PIN[copyPinNum / 8]),(copyPinNum % 8));
	return Ret;
}

	/* ----- FUNCTIONS PORTS ----- */
/**
 * @brief  : This function control in the DDRx Register selects the direction of this pin.
 * 			 If DDxn is written logic DIRECTION_PORT_OUTPUT,All port is configured as an output port.
 * 			 If DDxn is written logic DIRECTION_PORT_INPUT, All port is configured as an input port.
 * @param1 : copyPortNum
 * @param2 : copyDir
 * @retVal : void
 */
void DIO_setPortDIR(_GPIO_PORTS copyPortNum,_DIRECTION_PORTS copyDir)
{
	*ARR_DDR[copyPortNum] = copyDir;
}
/**
 * @brief  : This function control in the PORTxn Register selects the Status of this pin.
 * 			 If PORTxn is written logic STATUS_PORT_LOW,All port is configured as an LOW port.
 * 			 If PORTxn is written logic STATUS_PORT_HIGH,All port is configured as an HIGH port.
 * @param1 : copyPortNum
 * @param2 : copyVal
 * @retVal : void
 */
void DIO_setPortVAL(_GPIO_PORTS copyPortNum,_STATUS_PORTS copyVal)
{
	*ARR_PORT[copyPortNum] = copyVal;
}

/**
 * @brief  : if DDxn configured input All port This function get Status from PINxn Register
 * @param1 : copyPortNum
 * @retVal : Ret1
 */
Return_Value DIO_getPortVAL(_GPIO_PORTS copyPortNum)
{
	uint_8 Ret = Zero_INIT;
	Ret = *ARR_PIN[copyPortNum];
	return Ret;
}
