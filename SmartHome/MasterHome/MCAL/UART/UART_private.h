

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define YES			55
#define NO			77

#define MCUCR		*((volatile u8*)0x55)
#define MCUCSR		*((volatile u8*)0x54)

#define UBRRL		*((volatile u8*)0x29)
#define UBRRH		*((volatile u8*)0x40)

#define UCSRC		*((volatile u8*)0x40)
#define UCSRA		*((volatile u8*)0x2B)
#define UCSRB		*((volatile u8*)0x2A)

#define UDR			*((volatile u8*)0x2C)

#define MASK_BIT	1

#define UART_RX_INT_ENABLE_BIT_7	7	//RXCIE

#define UART_RX_ENABLE_BIT_4			4
#define UART_TX_ENABLE_BIT_3			3



#endif /* MCAL_UART_UART_PRIVATE_H_ */
