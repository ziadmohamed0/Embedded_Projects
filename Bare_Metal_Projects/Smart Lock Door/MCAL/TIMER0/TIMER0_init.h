/*
 * TIMER0_init.h
 *
 *  Created on: Jun 16, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER0_TIMER0_INIT_H_
#define MCAL_TIMER0_TIMER0_INIT_H_

/************ INCLUDE ***********/
#include "TIMER0_config.h"

/************ FUNCTIONS DECLER ***********/
/**
 * @brief  : Timer/Counter {0} initialization function by select timer wave mode
 *			 from configuration file.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_Init(void);

/**
 * @brief  : Timer/Counter {0} Start counting by select prescaler from configuration file.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_Start(void);

/**
 * @brief  : Timer/Counter {0} Stop counting.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_Stop(void);

/**
 * @brief  : Timer/Counter {0} write over flow by put start value over flow.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER0_writeOVR(uint_8 Copy_Start_Value);

/**
 * @brief  : Timer/Counter {0} write Compare match put start value comparing.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER0_writeCOM(uint_8 Copy_Start_Value);

/**
 * @brief  : Timer/Counter {0} interrupt over flow enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_ovrInterruptEnable(void);

/**
 * @brief  : Timer/Counter {0} interrupt over flow disable by write zero in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_ovrInterruptDisable(void);

/**
 * @brief  : Timer/Counter {0} interrupt Compare match enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_compInterruptEnable(void);

/**
 * @brief  : Timer/Counter {0} interrupt Compare match disable by write zero in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_comInterruptDisable(void);

#endif /* MCAL_TIMER0_TIMER0_INIT_H_ */
