/*
 * Timer0_init.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_TIMER0_TIMER0_INIT_H_
#define MCAL_TIMER0_TIMER0_INIT_H_

/* -------------------- Include Start -------------------- */
#include "../Interrupt/Interrupt_external_init.h"
#include "Timer0_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define TIMER0_COMP_vec			__vector_10
#define TIMER0_OVF_vec			__vector_11
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void TIMER0_vidInit(void);

void TIMER0_vidStart(void);
void TIMER0_vidStop(void);

void TIMER0_vidWriteOVRTCNT0(uint8 Copy_Start_Value);
void TIMER0_vidWriteCOMPOCR0(uint8 Copy_Start_Value);
void PWM_Timer0_Start(uint8 duty_cycle);

void TIMER0_vidOVRInterruptEnable(void);
void TIMER0_vidOVRInterruptDisable(void);

void TIMER0_vidCOMPInterruptEnable(void);
void TIMER0_vidCOMPInterruptDisable(void);
/* -------------------- API End -------------------- */

#endif /* MCAL_TIMER0_TIMER0_INIT_H_ */
