/*
 * TIMER0_prog.c
 *
 *  Created on: Jun 16, 2024
 *      Author: ziad
 */
/************ INCLUDE ***********/
#include "TIMER0_init.h"

/************ FUNCTIONS DIFEN ***********/
/**
 * @brief  : Timer/Counter {0} initialization function by select timer wave mode
 *			 from configuration file.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_Init(void)
{
#if TIMER_MODE_WAVE == NORMAL_MODE
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif TIMER_MODE_WAVE == PWM_MODE
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif TIMER_MODE_WAVE == CTC_MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif TIMER_MODE_WAVE == FAST_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#endif
}

/**
 * @brief  : Timer/Counter {0} Start counting by select prescaler from configuration file.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_Start(void)
{
	TCCR0 |= _PRESCALER_SELECT_;
}

/**
 * @brief  : Timer/Counter {0} Stop counting.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_Stop(void)
{
	TCCR0 &= TIMER0_CLOCK_STOP;
}

/**
 * @brief  : Timer/Counter {0} write over flow by put start value over flow.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER0_writeOVR(uint_8 Copy_Start_Value)
{
	TCNT0 = Copy_Start_Value;
}

/**
 * @brief  : Timer/Counter {0} write Compare match put start value comparing.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER0_writeCOM(uint_8 Copy_Start_Value)
{
	OCR0 = Copy_Start_Value;
}

/**
 * @brief  : Timer/Counter {0} interrupt over flow enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_ovrInterruptEnable(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TOIE0);
}

/**
 * @brief  : Timer/Counter {0} interrupt over flow disable by write zero in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_ovrInterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}

/**
 * @brief  : Timer/Counter {0} interrupt Compare match enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_compInterruptEnable(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE0);
}

/**
 * @brief  : Timer/Counter {0} interrupt Compare match disable by write zero in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_comInterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}

