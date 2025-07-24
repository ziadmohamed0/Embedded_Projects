/*
 * Interrupt_init.h
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_EXTERNAL_INIT_H_
#define MCAL_INTERRUPT_INTERRUPT_EXTERNAL_INIT_H_

/* -------------------- Include Start -------------------- */
#include "Interrupt_external_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define INT0_vec					__vector_1
#define INT1_vec					__vector_2
#define INT2_vec					__vector_3
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
	EX_INT0,
	EX_INT1,
	EX_INT2
}EX_Interrupt_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void EX_Interrupt_init(uint8 copyExNumber, uint8 copySense);
/* -------------------- API End -------------------- */

#endif /* MCAL_INTERRUPT_INTERRUPT_EXTERNAL_INIT_H_ */
