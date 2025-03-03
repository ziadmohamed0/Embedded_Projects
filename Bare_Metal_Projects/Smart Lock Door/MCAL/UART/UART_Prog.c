/*
 * UART_Prog.c
 *
 *  Created on: Jun 8, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "UART_Init.h"


/*********** FUNCTIONS DEFIN ***********/
/**
 * @brief  : UART initialization function by put baud rate you need
 * 			 and select your configurations from configurations file.
 * @param1 : copyBaudRate
 * @retVal : void
 */
void UART_init(BAUD_RATE copyBaudRate)
{
	UBRRH = (copyBaudRate >> 8);
	UBRRL = copyBaudRate;

	/* ----- SYNCH MODE ----- */
#if	(SYNCH_MODE == ASYNCHRONOUS_MODE)
	CLR_BIT(UCSRC,UMSEL);
#elif (SYNCH_MODE == SYNCHRONOUS_MODE)
	SET_BIT(UCSRC,UMSEL);
#endif

	/* ----- PARITY MODE ----- */

#if (PARITY_MODE == PARITY_EVEN)
	SET_BIT(UCSRC,UPM1);
	CLR_BIT(UCSRC,UPM0);
#elif (PARITY_MODE == PARITY_ODD)
	SET_BIT(UCSRC,UPM1);
	SET_BIT(UCSRC,UPM0);
#endif

	/* ----- STOP NUM BITS MODE ----- */
#if	(STOP_NUM_BITS == STOP_1_BIT)
	CLR_BIT(UCSRC,USBS);
#elif (STOP_NUM_BITS == STOP_2_BIT)
	SET_BIT(UCSRC,USBS);
#endif

	/* ----- DATA SIZE MODE ----- */
#if (DATA_SIZE == DATA_5_BITS)
	CLR_BIT(UCSRC,UCSZ2);
	CLR_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRC,UCSZ0);
#elif (DATA_SIZE == DATA_6_BITS)
	CLR_BIT(UCSRC,UCSZ2);
	CLR_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
#elif (DATA_SIZE == DATA_7_BITS)
	CLR_BIT(UCSRC,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRC,UCSZ0);
#elif (DATA_SIZE == DATA_8_BITS)
	 SET_BIT(UCSRC,UCSZ0);
	 SET_BIT(UCSRC,UCSZ1);
	 CLR_BIT(UCSRC,UCSZ2);
#elif (DATA_SIZE == DATA_9_BITS)
	SET_BIT(UCSRC,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
#endif
	 SET_BIT(UCSRB,TXEN);
	 SET_BIT(UCSRB,RXEN);
}

/**
 * @brief  : UART send data functions to send data from MCU to any device
 * 			 communicated with MCU UART.
 * @param1 : copyData
 * @retVal : void
 */
void UART_sendData(uint_16 copyData)
{
	while(GET_BIT(UCSRA,UDRE) == 0);
	UDR = copyData;
}

/**
 * @brief  : UART receive data functions to receive data from any device
 * 			 communicated with MCU UART.
 * @param1 : copyVar
 * @retVal : Ret1
 */
uint_8 UART_receiveData(uint_8 *copyVar)
{
	uint_8 Ret1 = 0;
	if(GET_BIT(UCSRA,RXC))
	{
		*copyVar = UDR;
		Ret1 = 1;
	}
	else
	{
		Ret1 = 0;
	}
	return Ret1;
}

/**
 * @brief  : UART receive data functions to receive data from any device
 * 			 communicated with MCU UART (polling).
 * @param1 : copyVar
 * @retVal : UDR
 */
uint_8 UART_reciveDataBlock(void)
{
	while(GET_BIT(UCSRA,RXC) == 0);
	return UDR;
}
