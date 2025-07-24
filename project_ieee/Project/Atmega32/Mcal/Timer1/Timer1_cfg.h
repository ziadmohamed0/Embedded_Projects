/*
 * Timer1_cfg.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_TIMER1_TIMER1_CFG_H_
#define MCAL_TIMER1_TIMER1_CFG_H_

/* -------------------- Include Start -------------------- */
#include "Timer1_reg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/***** Clock Select ENABLE TIMER*****/
/*****---TIMER1 SELSET FACTOR---*****/
#define TIMER1_FACTOR_NO             ((0 << CS12) | (0 << CS11) | (0 << CS10))    // 0U
#define TIMER1_FACTOR_1              ((0 << CS12) | (0 << CS11) | (1 << CS10))    // 1U
#define TIMER1_FACTOR_8              ((0 << CS12) | (1 << CS11) | (0 << CS10))    // 2U
#define TIMER1_FACTOR_64             ((0 << CS12) | (1 << CS11) | (1 << CS10))    // 3U
#define TIMER1_FACTOR_256            ((1 << CS12) | (0 << CS11) | (0 << CS10))    // 4U
#define TIMER1_FACTOR_1024           ((1 << CS12) | (0 << CS11) | (1 << CS10))    // 5U
#define TIMER1_FACTOR_EXT_FALLING    ((1 << CS12) | (1 << CS11) | (0 << CS10))    // 6U
#define TIMER1_FACTOR_EXT_RISING     ((1 << CS12) | (1 << CS11) | (1 << CS10))    // 7U


#define TIMER1_CLOCK_SELECT      TIMER1_FACTOR_8


/*********** TIMER1 Mask CLear********/
#define TIMER1_CLOCK_STOP     (uint8)0xF8

/*********** Timer1 Noise**************/
#define TIMER1_NO_NOISE     0
#define TIMER1_NOISE        1
#define TIMER1_NOISE_SEL   TIMER1_NO_NOISE

/***************Timer1 Compare output********************/
#define NORMAL_PORT_COMP      (uint8)0x00
#define TOGGLE_COMP           (uint8)0x50
#define CLEAR_ON_COMP         (uint8)0xA0
#define SET_ON_COMP           (uint8)0xF0

#define TIMER1_COMP_OUTPUT    CLEAR_ON_COMP

/************ Timer1 Mode *****************/

#define TIMER1_NORMAL                 TCCR1A |= ((0 << TCCR1A_WGM11) | (0 << TCCR1A_WGM10)); \
	                                  TCCR1B |= ((0 << TCCR1B_WGM13) | (0 << TCCR1B_WGM12))

#define TIMER1_FAST_PWM_MODE          TCCR1A |= ((1 << TCCR1A_WGM11) | (0 << TCCR1A_WGM10)); \
	                                  TCCR1B |= ((1 << TCCR1B_WGM13) | (1 << TCCR1B_WGM12))

#define TIMER1_CTC_MODE               TCCR1A |= ((0 << TCCR1A_WGM11) | (0 << TCCR1A_WGM10)); \
	                                  TCCR1B |= ((0 << TCCR1B_WGM13) | (1 << TCCR1B_WGM12))

#define TIMER1_PHASE_CORRECT          TCCR1A |= ((1 << TCCR1A_WGM11) | (0 << TCCR1A_WGM10)); \
	                                  TCCR1B |= ((1 << TCCR1B_WGM13) | (0 << TCCR1B_WGM12))


#define TIMER1_MODE   TIMER1_NORMAL
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */

/* -------------------- API End -------------------- */

#endif /* MCAL_TIMER1_TIMER1_CFG_H_ */
