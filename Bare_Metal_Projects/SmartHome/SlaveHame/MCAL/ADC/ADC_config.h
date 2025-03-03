
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define  ADCSRA   *((u8*)0x26)
#define  ADMUX    *((u8*)0x27)
#define  ADCL     *((u8*)0x24)
#define  ADCH     *((u8*)0x25)

#define  ADSC      6
#define  ADIF      4
#endif /* ADC_CONFIG_H_ */
