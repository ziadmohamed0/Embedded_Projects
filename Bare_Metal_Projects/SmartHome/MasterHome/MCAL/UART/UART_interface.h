

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

ES_t UART_enuUART_Init(void);

ES_t UART_enuSendChar( u8 Copy_u8CharData);

ES_t UART_enuSendString(u8 * Copy_Au8StringData[]);

ES_t UART_enuRecieveChar(u8 * Copy_u8RxChar);

ES_t UART_enuRecieveString(u8 * Copy_Au8RxString[]);

u8 UART_enuCheck_Connection();

#endif /* MCAL_UART_UART_INTERFACE_H_ */
