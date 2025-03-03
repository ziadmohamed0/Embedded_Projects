
#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#include "EXTI_config.h"

//ES_t EXTI_enuInit(EXTI_T * Copy_AstrEXTI_CONFIG);
ES_t EXTI_enuInit();

//ES_t EXTI_enuSetSenseLevel(u8 Copy_u8InterruptNum , u8 Copy_u8SenseLevel);

//ES_t EXTI_enuEnableInterrupt(u8 Copy_u8InterruptNum);
ES_t EXTI_enuEnableInterrupt();
//ES_t EXTI_enuDisableInterrupt(u8 Copy_u8InterruptNum);
ES_t EXTI_enuDisableInterrupt();

//ES_t EXTI_enuCallBack(volatile void  (*pfunAppFunction)(void) , u8 Copy_u8InterruptNum);
ES_t EXTI_enuCallBack(volatile void  (* pfunAppFunction)(void));


#endif /* MCAL_EXTI_EXTI_INT_H_ */
