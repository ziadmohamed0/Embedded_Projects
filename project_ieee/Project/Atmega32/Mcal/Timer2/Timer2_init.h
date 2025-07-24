/*
 * Timer2_init.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_TIMER2_TIMER2_INIT_H_
#define MCAL_TIMER2_TIMER2_INIT_H_

/* -------------------- Include Start -------------------- */
#include "../Interrupt/Interrupt_external_init.h"
#include "Timer2_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define TIMER2_OVF_vec				__vector_5
#define TIMER2_COMP_vec				__vector_4
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void TIMER2_vidInit(void);

void TIMER2_vidStart(void);
void TIMER2_vidStop(void);

void TIMER2_vidWriteOVRTCNT2(uint8 Copy_Start_Value);
void TIMER2_vidWriteCOMPOCR2(uint8 Copy_Start_Value);

void TIMER2_vidOVRInterruptEnable(void);
void TIMER2_vidOVRInterruptDisable(void);
void TIMER2_vidCOMPInterruptEnable(void);
void TIMER2_vidCOMPInterruptDisable(void);
/* -------------------- API End -------------------- */

#endif /* MCAL_TIMER2_TIMER2_INIT_H_ */
