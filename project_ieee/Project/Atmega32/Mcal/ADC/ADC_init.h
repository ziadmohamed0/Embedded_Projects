/*
 * ADC_init.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_

/* -------------------- Include Start -------------------- */
#include "ADC_cfg.h"
#include "../Interrupt/Interrupt_external_init.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define ADC_vec		__vector_16
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum{
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7,
	ADC_CHANNEL8
}ADC_CHANNEL;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void ADC_vidInit();
uint16 ADC_u16ReadDigitalVal(ADC_CHANNEL ChannelCopy);


void ADC_vidInterruptEnable();
void ADC_vidInterruptDisable();
void ADC_vidClrFlag();


void ADC_vidEnable();
void ADC_vidDisable();
/* -------------------- API End -------------------- */

#endif /* MCAL_ADC_ADC_INIT_H_ */
