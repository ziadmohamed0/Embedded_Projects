/*
 * ADC_reg.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

/* -------------------- Include Start -------------------- */
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define ADMUX    *((volatile uint8 *)0x27)
#define ADCSRA   *((volatile uint8 *)0x26)
#define ADCH     *((volatile uint8 *)0x25)
#define ADCL     *((volatile uint8 *)0x24)
#define SFIOR    *((volatile uint8 *)0x50)

/*-------ADMUX_REG--------*/
#define ADMUX_ADLAR   (uint8)5
#define ADMUX_REFS0   (uint8)6
#define ADMUX_REFS1   (uint8)7



/*------ADCSRA-------*/
#define ADCSRA_ADEN     (uint8)7
#define ADCSRA_ADSC     (uint8)6
#define ADCSRA_ADATE    (uint8)5
#define ADCSRA_ADIF     (uint8)4
#define ADCSRA_ADIE     (uint8)3
#define ADCSRA_ADPS2    (uint8)2
#define ADCSRA_ADPS1    (uint8)1
#define ADCSRA_ADPS0    (uint8)0
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_ADC_ADC_REG_H_ */
