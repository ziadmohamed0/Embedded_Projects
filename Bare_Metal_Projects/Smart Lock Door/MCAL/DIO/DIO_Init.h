/*
 * DIO_Init.h
 *
 *  Created on: Jun 12, 2024
 *      Author: ziad
 */

#ifndef MCAL_DIO_DIO_INIT_H_
#define MCAL_DIO_DIO_INIT_H_

/*********** INCLUDES ***********/
#include "DIO_Config.h"

/*********** FUNCTIONS DECLER ***********/
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
void DIO_setPinDIR(_GPIO_PINS copyPinNum,_DIRECTION_PINS copyDir);

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
void DIO_setPinVAL(_GPIO_PINS copyPinNum,_STATUS_PINS copyVal);

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
void DIO_setPINSDIR(_GPIO_PINS *copyStartPin, _GPIO_PINS copyEndPin, _DIRECTION_PINS copyDir);

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
void DIO_setPINSVAL(_GPIO_PINS *copyStartPin, _GPIO_PINS copyEndPin, _STATUS_PINS copyVal);

/**
 * @brief  : if DDxn configured input Pn_x This function get Status from PINxn Register
 * @param1 : copyPortNum
 * @param2 : copyPinNum
 * @retVal : Ret1
 */
Return_Value DIO_getPinVAL(_GPIO_PINS copyPinNum);

	/* ----- FUNCTIONS PORTS ----- */
/**
 * @brief  : This function control in the DDRx Register selects the direction of this pin.
 * 			 If DDxn is written logic DIRECTION_PORT_OUTPUT,All port is configured as an output port.
 * 			 If DDxn is written logic DIRECTION_PORT_INPUT, All port is configured as an input port.
 * @param1 : copyPortNum
 * @param2 : copyDir
 * @retVal : void
 */
void DIO_setPortDIR(_GPIO_PORTS copyPortNum,_DIRECTION_PORTS copyDir);

/**
 * @brief  : This function control in the PORTxn Register selects the Status of this pin.
 * 			 If PORTxn is written logic STATUS_PORT_LOW,All port is configured as an LOW port.
 * 			 If PORTxn is written logic STATUS_PORT_HIGH,All port is configured as an HIGH port.
 * @param1 : copyPortNum
 * @param2 : copyVal
 * @retVal : void
 */
void DIO_setPortVAL(_GPIO_PORTS copyPortNum,_STATUS_PORTS copyVal);

/**
 * @brief  : if DDxn configured input All port This function get Status from PINxn Register
 * @param1 : copyPortNum
 * @retVal : Ret1
 */
Return_Value DIO_getPortVAL(_GPIO_PORTS copyPortNum);

#endif /* MCAL_DIO_DIO_INIT_H_ */
