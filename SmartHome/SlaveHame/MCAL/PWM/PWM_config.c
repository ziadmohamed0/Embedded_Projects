


#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "../PWM/PWM_config.h"

#include "../PWM/PWM_priv.h"

u8 PWM_u8TimerNum = TIMER_NUM;

PWM_t PWM_AstrPWMConfig[TIMER_NUM]=
{
		{TIMER0 , FAST_PWM , NON_INVERTED},
		{},
		{}
};
