/*
 * Timer2_prog.c
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#include "Timer2_init.h"

void TIMER2_vidInit(void){
#if TIMER2_CLK_SOURCE == TIEMR2_INT
	CLEAR_BIT(ASSR,AS2);
#elif TIMER2_CLK_SOURCE == TIMER2_EXTR
	SET_BIT(ASSR,AS2);
#endif
#if TIMER2_MODE_WAVE == NORMAL_MODE
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
#elif TIMER2_MODE_WAVE == PWM_MODE
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	TCCR2 |= TIMER2_COMP_OUTPUT_MODE;
#elif TIMER2_MODE_WAVE == CTC_MODE
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	TCCR2 |= TIMER2_COMP_OUTPUT_MODE;
#elif TIMER2_MODE_WAVE == FAST_PWM_MODE
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	TCCR2 |= TIMER2_COMP_OUTPUT_MODE;
#endif

}


void TIMER2_vidStart(void){
	TCCR2 |= TIMER2_SELECT_ENABLE;
}
void TIMER2_vidStop(void){
	TCCR2 &= TIMER2_CLOCK_STOP;
}


void TIMER2_vidWriteOVRTCNT0(uint8 Copy_Start_Value){
	TCNT2 = Copy_Start_Value;
}

void TIMER2_vidWriteCOMPOCR0(uint8 Copy_Start_Value){
	OCR2 = Copy_Start_Value;
}

void TIMER2_vidOVRInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TOIE2);
}

void TIMER2_vidOVRInterruptDisable(void){
	CLR_BIT(TIMSK,TOIE2);
}

void TIMER2_vidCOMPInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE2);
}

void TIMER2_vidCOMPInterruptDisable(void){
	CLR_BIT(TIMSK,OCIE2);
}
