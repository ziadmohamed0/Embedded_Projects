/*
 * ADC_interface.h
 *
 *  Created: 17/2/2024 7:43:11 PM
 *  Author: Ziad
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_SINGLE_ENDED_CHANNEL_0          0
#define ADC_SINGLE_ENDED_CHANNEL_1          1
#define ADC_SINGLE_ENDED_CHANNEL_2          2
#define ADC_SINGLE_ENDED_CHANNEL_3          3
#define ADC_SINGLE_ENDED_CHANNEL_4          4
#define ADC_SINGLE_ENDED_CHANNEL_5          5
#define ADC_SINGLE_ENDED_CHANNEL_6          6
#define ADC_SINGLE_ENDED_CHANNEL_7          7

void ADC_init( void );
void ADC_getDigitalValue( u8 channelNum , u16* digitalValue );


#endif /* ADC_INTERFACE_H_ */