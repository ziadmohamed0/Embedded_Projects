/*
 * Interrupt_cfg.h
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_EXTERNAL_CFG_H_
#define MCAL_INTERRUPT_INTERRUPT_EXTERNAL_CFG_H_

/* -------------------- Include Start -------------------- */
#include "Interrupt_reg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
	EX_Low_Level,
	EX_Any_Logical,
	EX_Falling_Edge,
	EX_Rising_Edge
}EX_Sense_Control;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_INTERRUPT_INTERRUPT_EXTERNAL_CFG_H_ */
