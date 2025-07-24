/*
 * Timer1_reg.h
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#ifndef MCAL_TIMER1_TIMER1_REG_H_
#define MCAL_TIMER1_TIMER1_REG_H_

/* -------------------- Include Start -------------------- */
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define TCCR1A_ADDRESS  (0x4F)
#define TCCR1B_ADDRESS  (0x4E)
#define TCNT1H_ADDRESS  (0x4D)
#define TCNT1L_ADDRESS  (0x4C)
#define OCR1AH_ADDRESS  (0x4B)
#define OCR1AL_ADDRESS  (0x4A)
#define OCR1BH_ADDRESS  (0x49)
#define OCR1BL_ADDRESS  (0x48)
#define ICR1H_ADDRESS   (0x47)
#define ICR1L_ADDRESS   (0x46)
#define TIMSK_ADDRESS   (0x59)
#define TIFR_ADDRESS    (0x58)


#define TCCR1A   *((volatile uint8 *) TCCR1A_ADDRESS )
#define TCCR1B   *((volatile uint8 *) TCCR1B_ADDRESS )

#define TCNT1    *((volatile uint16 *) TCNT1L_ADDRESS )
//#define TCNT1L   *((volatile uint8  *) TCNT1L_ADDRESS )
//#define TCNT1H   *((volatile uint8  *) TCNT1H_ADDRESS )

#define OCR1A    *((volatile uint16 *) OCR1AL_ADDRESS )
//#define OCR1AL   *((volatile uint8  *) OCR1AL_ADDRESS )
//#define OCR1AH   *((volatile uint8  *) OCR1AH_ADDRESS )

#define OCR1B    *((volatile uint16 *) OCR1BL_ADDRESS )
//#define OCR1BL   *((volatile uint8  *) OCR1BL_ADDRESS )
//#define OCR1BH   *((volatile uint8  *) OCR1BH_ADDRESS )

#define ICR1     *((volatile uint16 *) ICR1L_ADDRESS  )
//#define ICR1L    *((volatile uint8  *) ICR1L_ADDRESS  )
//#define ICR1H    *((volatile uint8  *) ICR1H_ADDRESS  )


#define TIMSK    *((volatile uint8 *) TIMSK_ADDRESS  )
#define TIFR     *((volatile uint8 *) TIFR_ADDRESS   )

/*****---TIMSK Interrupt Register Control Enable/Disable---*****/
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5

/*****---TIMER1 Control BIT Register select the clock source---*****/
#define CS10   0
#define CS11   1
#define CS12   2


/*****---TIMER1_BIT_Register_Select_Mode---*****/

#define TCCR1A_WGM10  0
#define TCCR1A_WGM11  1
#define TCCR1B_WGM12  3
#define TCCR1B_WGM13  4

/********INP CAP********/
#define ICES1  (uint8)6
#define ICNC1  (uint8)7
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif /* MCAL_TIMER1_TIMER1_REG_H_ */
