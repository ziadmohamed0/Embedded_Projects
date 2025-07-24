/*
 * USART_cfg.h
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#ifndef MCAL_USART_USART_CFG_H_
#define MCAL_USART_USART_CFG_H_

/* -------------------- Include Start -------------------- */
#include "USART_reg.h"
#include "USART_init.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/****************************Mode_Select **********************************/

#define Asynchronous_Operation 			0
#define Synchronous_Operation  			1

#define Mode_Select   					Asynchronous_Operation

/************************ Parity_Mode *************************************/
#define Disabled         				0
#define Even_Parity      				2
#define Odd_Parity       				3

#define Parity_Mode      				Disabled
/*****************************Stop_Bit_Select *****************************/
#define _1_bit  						0
#define _2_bit  						1

#define Stop_Bit_Select    				_1_bit
/*********************** Data_bits ****************************************/

#define _5_bit   						0
#define _6_bit   						1
#define _7_bit   						2
#define _8_bit   						3
#define _9_bit   						4

#define Data_bits  	 					_8_bit

/********************* Transmitted_Data_Clock_Polarity ***********************/

#define Rising_Edge_Falling_Edge  		0
#define Falling_Edge_Rising_Edge   		1

/************************** Boud_Rate************************/
#define Baud_Rate_4800      			103
#define Baud_Rate_9600      			51
#define Baud_Rate_14_4k     			34
#define Baud_Rate_19_2k     			25
#define Baud_Rate_28_8k     			16
#define Baud_Rate_38_4k    				12
#define Baud_Rate_57_6k     			8
#define Baud_Rate_76_8k     			6
#define Baud_Rate_115_2k    			3

#define baud_rate_select    			Baud_Rate_9600
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_USART_USART_CFG_H_ */
