/*
 * Timer0_reg.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_TIMER0_TIMER0_REG_H_
#define MCAL_TIMER0_TIMER0_REG_H_

/* -------------------- Include Start -------------------- */
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define TCCR0_ADDRESS  (0x53)
#define TCNT0_ADDRESS  (0x52)
#define OCR0_ADDRESS   (0x5C)
#define TIMSK_ADDRESS  (0x59)
#define TIFR_ADDRESS   (0x58)


#define TCCR0   *((volatile uint8 *) TCCR0_ADDRESS )
#define TCNT0   *((volatile uint8 *) TCNT0_ADDRESS )
#define OCR0    *((volatile uint8 *) OCR0_ADDRESS  )
#define TIMSK   *((volatile uint8 *) TIMSK_ADDRESS )
#define TIFR    *((volatile uint8 *) TIFR_ADDRESS  )

#define TOIE0    (uint8)0
#define OCIE0    (uint8)1
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
	CS00 = 0 ,
	CS01     ,
	CS02     ,
	WGM01    ,
	COM00    ,
	COM01    ,
	WGM00    ,
	FOC0
}TCCR0_BIT_Reg;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_TIMER0_TIMER0_REG_H_ */
