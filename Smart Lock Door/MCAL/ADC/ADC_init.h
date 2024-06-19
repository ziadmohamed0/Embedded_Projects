/*
 * ADC_init.h
 *
 *  Created on: Jun 15, 2024
 *      Author: ziad
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_

/*********** INCLUDES ***********/
#include "ADC_config.h"

/*********** FUNCTIONS DECLER ***********/
/**
  * @brief  : ADC initialization by Writing the ADEN Bit one enables the ADC.
  * 		  By writing it to zero, the ADC is turned off. Select ADC VOLT Reference.
  * @param1 : void
  * @retVal : void
  */
void ADC_init(void);

/**
  * @brief  : ADC analog read value select channel used and return value
  * 		  in variable uint_16
  * @param1 : copyChannel
  * @retVal : Ret1
  */
uint_16 ADC_analogRead(_ADC_CHANNELS copyChannel);

/**
  * @brief  : ADC enable Writing the ADEN bit to one the ADC is turned on.
  * @param1 : void
  * @retVal : void
  */
void ADC_enable(void);

/**
  * @brief  : ADC disable By writing it to zero, the ADC is turned off.
  * @param1 : void
  * @retVal : void
  */
void ADC_disable(void);

/**
  * @brief  : ADC enable interrupt signal When the ADIE bit is written to one and the GIE in SREG is set,
  *  		  the ADC Conversion Complete Interrupt is activated.
  * @param1 : void
  * @retVal : void
  */
void ADC_enableInterrupt(void);

/**
  * @brief  : ADC Disable interrupt signal When the ADIE bit is written to zero and the GIE in SREG is clear,
  *  		  the ADC Conversion Complete Interrupt is activated.
  * @param1 : void
  * @retVal : void
  */
void ADC_disableInterrupt(void);

/**
  * @brief  : ADC clear flag when conversion is complete this flag set
  * 		  we can clear this flag by this function and started again
  * 		  conversion.
  * @param1 : void
  * @retVal : void
  */
void ADC_clearFlag(void);

#endif /* MCAL_ADC_ADC_INIT_H_ */
