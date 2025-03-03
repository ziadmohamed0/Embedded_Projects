/*
 * UART_Init.h
 *
 *  Created on: Jun 8, 2024
 *      Author: ziad
 */

#ifndef MCAL_UART_UART_INIT_H_
#define MCAL_UART_UART_INIT_H_

/*********** INCLUDES ***********/
#include "UART_Config.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : UART initialization function by put baud rate you need
 * 			 and select your configurations from configurations file.
 * @param1 : copyBaudRate
 * @retVal : void
 */
void UART_init(BAUD_RATE copyBaudRate);

/**
 * @brief  : UART send data functions to send data from MCU to any device
 * 			 communicated with MCU UART.
 * @param1 : copyData
 * @retVal : void
 */
void UART_sendData(uint_16 copyData);

/**
 * @brief  : UART receive data functions to receive data from any device
 * 			 communicated with MCU UART.
 * @param1 : copyVar
 * @retVal : void
 */
uint_8 UART_receiveData(uint_8 *copyVar);

/**
 * @brief  : UART receive data functions to receive data from any device
 * 			 communicated with MCU UART (polling).
 * @param1 : copyVar
 * @retVal : UDR
 */
uint_8 UART_reciveDataBlock(void);

#endif /* MCAL_UART_UART_INIT_H_ */
