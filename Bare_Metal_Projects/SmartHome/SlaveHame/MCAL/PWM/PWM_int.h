
#ifndef MCAL_PWM_PWM_INT_H_
#define MCAL_PWM_PWM_INT_H_

ES_t PWM_enuInit(PWM_t * Copy_pAstrPWMConfig);

ES_t PWM_enuSetFrequency(u16 Copy_u16Frequency , PWM_t * Copy_pstrPWMConfig);

ES_t PWM_enuSetDutyCycle(u8 Copy_u8DutyCycle, PWM_t * Copy_pstrPWMConfig);



#endif /* MCAL_PWM_PWM_INT_H_ */
