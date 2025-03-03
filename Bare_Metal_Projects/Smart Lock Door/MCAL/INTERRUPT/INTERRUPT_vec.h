/*
 * INTERRUPT_vec.h
 *
 *  Created on: Jun 14, 2024
 *      Author: ziad
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_VEC_H_
#define MCAL_INTERRUPT_INTERRUPT_VEC_H_

/*********** INCLUDES ***********/
#include "../../SERV/LIB/Includes.h"
#include "../../SERV/LIB/Std_Types.h"
#include "../../SERV/LIB/Bit_Math.h"
#include "../DIO/DIO_Init.h"
/*********** ISR ***********/
#define ISR(vector)            \
    void vector (void)  __attribute__ ((signal,used,externally_visible)); \
    void vector (void)

/*********** VECTORS ***********/
	/* ----- EXTERNAL INTERRUPT -----*/
#define INT0_VEC		__vector_1
#define INT1_VEC		__vector_2
#define INT2_VEC		__vector_3

	/* ----- TIMER 2 INTERRUPT -----*/
#define TIMER2_COM_VEC	__vector_4
#define TIMER2_OVF_VEC	__vector_5

	/* ----- TIMER 1 INTERRUPT -----*/
#define TIMER1_CAP_VEC	__vector_6
#define TIMER1_COMA_VEC	__vector_7
#define TIMER1_COMB_VEC	__vector_8
#define TIMER1_OVF_VEC	__vector_9


	/* ----- TIMER 0 INTERRUPT -----*/
#define TIMER0_COM_VEC	__vector_10
#define TIMER0_OVF_VEC	__vector_11

	/* ----- SPI INTERRUPT -----*/
#define SPI_VEC			__vector_12

	/* ----- UART INTERRUPT -----*/
#define UART_RXC_VEC	__vector_13
#define UART_UDRE_VEC	__vector_14
#define UART_TXC_VEC	__vector_15

	/* ----- ADC INTERRUPT -----*/
#define ADC_VEC			__vector_16

	/* ----- EEPROM INTERRUPT -----*/
#define EE_RDY_VEC		__vector_17

	/* ----- ANALOG COMP INTERRUPT -----*/
#define ANA_COM_VEC		__vector_18

	/* ----- TWO WIRES INTERRUPT -----*/
#define TWI_VEC			__vector_19

	/* ----- STOR PROGRAM MEMORY INTERRUPT -----*/
#define SPM_RDY_VEC		__vector_20

#endif /* MCAL_INTERRUPT_INTERRUPT_VEC_H_ */
