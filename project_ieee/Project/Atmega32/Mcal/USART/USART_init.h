/*
 * USART_init.h
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#ifndef MCAL_ADC_USART_USART_INIT_H_
#define MCAL_ADC_USART_USART_INIT_H_

/* -------------------- Include Start -------------------- */
#include "USART_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define USART_RX_vec					__vector_13
#define USART_UDRE_vec					__vector_14
#define USART_TX_vec					__vector_15
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void UART_vidInit();
void UART_vidSendData(uint8 u8DataCopy);
uint8 UART_u8RecevieData();
/* -------------------- API End -------------------- */

#endif /* MCAL_ADC_USART_USART_INIT_H_ */
