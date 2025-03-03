/*
 * TIMER0_config.h
 *
 *  Created on: Jun 16, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_

/************ INCLUDE ***********/
#include "TIMER0_reg.h"

/*********** TIMER MODE ***********/
#define NORMAL_MODE    0
#define PWM_MODE       1
#define CTC_MODE       2
#define FAST_PWM_MODE  3

#define TIMER_MODE_WAVE       NORMAL_MODE

/*********** TIMER PRESCALER ***********/

	/* --- TIMER SELSET PRESCLER --- */
#define _NO_PRESCLER         (uint_8)0x00
#define _1_PRESCLER          (uint_8)0x01
#define _8_PRESCLER          (uint_8)0x02
#define _64_PRESCLER         (uint_8)0x03
#define _256_PRESCLER        (uint_8)0x04
#define _1024_PRESCLER       (uint_8)0x05
#define _FALLING_PRESCLER    (uint_8)0x06
#define _RISING_PRESCLER     (uint_8)0x07

#define TIMER0_CLOCK_STOP    (uint_8)0xF8

#define _PRESCALER_SELECT_         _8_PRESCLER

	/* --- Compare Output Mode USED In PWM Mode --- */
/******* START_CLEAR_COMP - TOGGLE_CTC_MODE - START_SET_COMP - NURMAL_MODE_OUTPUT******/

	/* --- Compare Output Mode USED In PWM Mode --- */

#define NURMAL_MODE_OUTPUT       (( 0 << COM01) | (0 << COM00))         //(0U << COM00)
#define TOGGLE_CTC_MODE          (( 0 << COM01) | (1 << COM00))
#define START_CLEAR_COMP         (( 1 << COM01) | (0 << COM00))        //(2U << COM00)
#define START_SET_COMP           (( 1 << COM01) | (1 << COM00))         //(3U << COM00)


#define TIMER_COMP_OUTPUT_MODE   TOGGLE_CTC_MODE

#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
