/*
 * ADC_prog.c
 *
 *  Created on: Jun 15, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "ADC_init.h"


/*********** FUNCTIONS DEFIN ***********/
/**
  * @brief  : ADC initialization by Writing the ADEN Bit one enables the ADC.
  * 		  By writing it to zero, the ADC is turned off. Select ADC VOLT Reference.
  * @param1 : void
  * @retVal : void
  */
void ADC_init(void)
{
#if (_ADC_VOLT == AVCC)
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#elif (_ADC_VOLT == AREF)
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);
#elif (_ADC_VOLT == INTERNAL)
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#endif

#if (ADC_AUTO_TRIGGER == FREE_RUNNING_MODE)
	CLR_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif (ADC_AUTO_TRIGGER == ANALOG_COMPARATOR_MODE)
	SET_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif (ADC_AUTO_TRIGGER == EXTERNAL_INTERRUPT_MODE)
	CLR_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif (ADC_AUTO_TRIGGER == TIMER0_COMPARE_MODE)
	CLR_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS0);
#elif (ADC_AUTO_TRIGGER == TIMER0_OVERFLOW_MODE)
	SET_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif (ADC_AUTO_TRIGGER == TIMER1_COMPARE_B_MODE)
	SET_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS0);
#elif (ADC_AUTO_TRIGGER == TIMER1_OVERFLOW_MODE)
	SET_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif (ADC_AUTO_TRIGGER == TIMER1_CAPTURE_MODE)
	SET_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS0);
#endif
	SET_BIT(ADCSRA,ADEN);
	ADCSRA |= _ADC_PRESCALER_SELECT;
}

/**
  * @brief  : ADC analog read value select channel used and return value
  * 		  in variable uint_16
  * @param1 : copyChannel
  * @retVal : Ret1
  */
uint_16 ADC_analogRead(_ADC_CHANNELS copyChannel)
{
	uint_16 Ret1 = Zero_INIT;
	ADMUX &= _ADC_CLEAR_MASK;
	ADMUX |= copyChannel;
	SET_BIT(ADCSRA,ADSC);
	while((GET_BIT(ADCSRA,ADSC)));	// polling data
	Ret1 = ADCL;
	Ret1 |= (ADCH << 8);
	return Ret1;
}

/**
  * @brief  : ADC enable Writing the ADEN bit to one the ADC is turned on.
  * @param1 : void
  * @retVal : void
  */
void ADC_enable(void)
{
	SET_BIT(ADCSRA,ADEN);
}

/**
  * @brief  : ADC disable By writing it to zero, the ADC is turned off.
  * @param1 : void
  * @retVal : void
  */
void ADC_disable(void)
{
	CLR_BIT(ADCSRA,ADEN);
}

/**
  * @brief  : ADC enable interrupt signal When the ADIE bit is written to one and the GIE in SREG is set,
  *  		  the ADC Conversion Complete Interrupt is activated.
  * @param1 : void
  * @retVal : void
  */
void ADC_enableInterrupt(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(ADCSRA,ADIE);
}

/**
  * @brief  : ADC Disable interrupt signal When the ADIE bit is written to zero and the GIE in SREG is clear,
  *  		  the ADC Conversion Complete Interrupt is activated.
  * @param1 : void
  * @retVal : void
  */
void ADC_disableInterrupt(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

/**
  * @brief  : ADC clear flag when conversion is complete this flag set
  * 		  we can clear this flag by this function and started again
  * 		  conversion.
  * @param1 : void
  * @retVal : void
  */
void ADC_clearFlag(void)
{
	CLR_BIT(ADCSRA,ADIF);
}
