/*
 * Timer1_init.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_TIMER1_TIMER1_INIT_H_
#define MCAL_TIMER1_TIMER1_INIT_H_

/* -------------------- Include Start -------------------- */
#include "../Interrupt/Interrupt_external_init.h"
#include "Timer1_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define TIMER1_OVF_vec				__vector_9
#define TIMER1_COMPB_vec			__vector_8
#define TIMER1_COMPA_vec			__vector_7
#define TIMER1_CAPT_vec				__vector_6
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void TIMER1_vidInit(void);

void TIMER1_vidOCRAWrite(uint16 Copy_u16ValueOCRA);
void TIMER1_vidOCRBWrite(uint16 Copy_u16ValueOCRB);
void TIMER1_vidICRWrite(uint16 Copy_u16ValueICR);
void ICU_setCallBack(void (*func)(void));

void TIMER1_vidStart(void);
void TIMER1_vidStop(void);
void TIMER1_vidReset(void);

void TIMER1_vidINCAPFalling(void);
void TIMER1_vidINCAPRissing(void);
uint16 TIMER1_u16INCAPRead(void);

void TIMER1_vidOVRInterruptEnable(void);
void TIMER1_vidCOMPAInterruptEnable(void);
void TIMER1_vidCOMBInterruptEnable(void);
void TIMER1_vidCAPInterruptEnable(void);

void TIMER1_vidOVRInterruptDisable(void);
void TIMER1_vidCOMPAInterruptDisable(void);
void TIMER1_vidCOMBInterruptDisable(void);
void TIMER1_vidCAPInterruptDisable(void);
/* -------------------- API End -------------------- */

#endif /* MCAL_TIMER1_TIMER1_INIT_H_ */
