/*
 * ADC_cfg.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

/* -------------------- Include Start -------------------- */
#include "ADC_reg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define ADC_AREF       0
#define ADC_AVCC       1
#define ADC_INTERNAL   2
#define ADC_VOLT   ADC_AVCC



#define ADC_DIVISION_FACTOR_2        (uint8)0x01
#define ADC_DIVISION_FACTOR_4        (uint8)0x02
#define ADC_DIVISION_FACTOR_8        (uint8)0x03
#define ADC_DIVISION_FACTOR_16       (uint8)0x04
#define ADC_DIVISION_FACTOR_32       (uint8)0x05
#define ADC_DIVISION_FACTOR_64       (uint8)0x06
#define ADC_DIVISION_FACTOR_128      (uint8)0x07

#define ADC_PRESCALER   ADC_DIVISION_FACTOR_128


/*---------CHANNEL CLEAR MASK-------*/
#define ADC_CLEAR_MASK  (uint8)0xE0

/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_ADC_ADC_CFG_H_ */
