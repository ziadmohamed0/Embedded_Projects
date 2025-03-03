

#ifndef MCAL_TIMER_TIMER1_CONFIG_H_
#define MCAL_TIMER_TIMER1_CONFIG_H_

//Prescalers
#define TIMO_NO_CLK  0
#define TIMO_NO_PRES 1
#define TIMO_8_PRES  2
#define TIMO_64_PRES 3
#define TIMO_256_PRES 4
#define TIMO_1024_PRES 5
#define TIMO_PRES  TIMO_64_PRES

//mode
#define TIMER1_NORMAL 0
#define TIMER1_PWM_PHASE_CORRECT_8 1
#define TIMER1_PWM_PHASE_CORRECT_9 2
#define TIMER1_PWM_PHASE_CORRECT_10 3
#define TIMER1_CTC 4
#define TIMER1_PWM_FAST_8 5
#define TIMER1_PWM_FAST_9 6
#define TIMER1_PWM_FAST_10 7
#define TIMER1_MODE  TIMER1_PWM_FAST_9

//compare output mode
#define COM_OUT_DIS 0
#define COM_OUT_TOG 1
#define COM_OUT_CLR 2
#define COM_OUT_SET 3
#define TIMER1_COMPARE_OUTPUT  COM_OUT_CLR

#define WGM10  0
#define WGM11  1
#define WGM12  3
#define WGM13  4

#define COM1A0 6
#define COM1A1 7
#define COM1B0 4
#define COM1B1 5

#define CS10   0
#define CS11   1
#define CS12   2


#define TIMSK	*((volatile u8*) 0x59)

/*TIFR*/
#define TIFR	*((volatile u8*) 0x58)

/*TCCR*/
#define TCCR0	*((volatile u8*) 0x53)
#define TCCR1A	*((volatile u8*) 0x4f)
#define TCCR1B	*((volatile u8*) 0x4e)
#define TCCR2	*((volatile u8*) 0x45)

/*TCNT*/
#define TCNT0	*((volatile u8*) 0x52)

#define TCNT1H	*((volatile u8*) 0x4d)
#define TCNT1L	*((volatile u8*) 0x4c)

#define TCNT1	*((volatile u16*) 0x4c)

#define TCNT2	*((volatile u8*) 0x44)

/*OCR*/
#define OCR0	*((volatile u8*) 0x5C)
#define OCR1AH	*((volatile u8*) 0x4B)
#define OCR1AL	*((volatile u8*) 0x4A)


#define OCR1A	(*(volatile u16*)((0x2A) + 0x20))

#define OCR1BH	*((volatile u8*) 0x49)
#define OCR1BL	*((volatile u8*) 0x48)

#define OCR1B	*((volatile u16*) 0x48)

#define OCR2	*((volatile u8*) 0x43)
#define ICR1H	*((volatile u8*) 0x47)
#define ICR1L	*((volatile u8*) 0x46)
#define ICR1    (*(volatile u16*)((0x26) + 0x20))

#endif /* MCAL_TIMER_TIMER1_CONFIG_H_ */
