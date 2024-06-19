/*
 * INTERRUPT_init.h
 *
 *  Created on: Jun 14, 2024
 *      Author: ziad
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_INIT_H_
#define MCAL_INTERRUPT_INTERRUPT_INIT_H_

/*********** INCLUDES ***********/
#include "INTERRUPT_config.h"

/*********** FUNCTIONS DECLER ***********/
/**
  * @brief  : Initialization External Interrupt
  * 		  put number of external interrupt &
  * 		  put status or sense of signal.
  * @param1  : copyNumInt
  * @param2  : copySense
  */
void EXINTER_init(_NUM_EX_INTERRUPT copyNumInt,_SENSE_SELECT copySense);

#endif /* MCAL_INTERRUPT_INTERRUPT_INIT_H_ */
