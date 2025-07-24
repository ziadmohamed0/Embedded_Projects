/*
 * Timer2_reg.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_TIMER2_TIMER2_REG_H_
#define MCAL_TIMER2_TIMER2_REG_H_

/* -------------------- Include Start -------------------- */
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define TCCR2_ADDRESS  (0x45)
#define TCNT2_ADDRESS  (0x44)
#define OCR2_ADDRESS   (0x43)
#define ASSR_ADDRESS   (0x42)
#define TIMSK_ADDRESS  (0x59)
#define TIFR_ADDRESS   (0x58)

#define TCCR2   *((volatile uint8 *) TCCR2_ADDRESS )
#define TCNT2   *((volatile uint8 *) TCNT2_ADDRESS )
#define OCR2    *((volatile uint8 *) OCR2_ADDRESS  )
#define ASSR    *((volatile uint8 *) ASSR_ADDRESS  )
#define TIMSK   *((volatile uint8 *) TIMSK_ADDRESS )
#define TIFR    *((volatile uint8 *) TIFR_ADDRESS  )

/*----ASSR---*/
#define AS2   (uint8)3

#define TOIE2    (uint8)6
#define OCIE2    (uint8)7

/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
	CS20 = 0 ,
	CS21     ,
	CS22     ,
	WGM21    ,
	COM20    ,
	COM21    ,
	WGM20    ,
	FOC2
}TCCR2_BIT_Reg;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_TIMER2_TIMER2_REG_H_ */
