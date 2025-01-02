
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "../../MCAL/DIO/DIO_priv.h"
#include "ADC_config.h"
#include <avr/delay.h>

void ADC_Init()
{
	DDRA |= (1<<0) ;			/* Make ADC port as input */
	ADCSRA = 0x87 ;		/* Enable ADC, freq/128  */
	ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */

}

int ADC_Read(char channel)
{
	int Ain,AinLow;
    //ADMUX=ADMUX & 0xf8;
	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */
	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA & (1<<ADIF))==0);	/* Monitor end of conversion interrupt */

	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and
					Multiply with weight */
	Ain = Ain + AinLow;
	return(Ain);			/* Return digital value*/
}
