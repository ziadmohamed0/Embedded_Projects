/*
 * StopWatchProject.c
 *
 *  Created on: Sep 14, 2022
 *      Author: Ziad Ayman
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



/*                                         GLOBAL VARIABLES                                          */
unsigned char seconds=0 , minutes=0 , hours=0;



/*                                         FUNCTIONS PROTOTYPES                                          */
void SevenSegment_init(void);
void SevenSegment_Display(void);
void Timer1_init(void);
void Reset (void);
void Pause(void);
void Resume (void);



/*                                         MAIN FUNCTION                                          */
int main ()
{
	SevenSegment_init(); //FUNCTION TO INITIALIZE 6-DIGIT SEVEN SEGMENT
	sei(); // SET I-BIT
	Reset (); //FUNCTION TO INITIALIZE RESET BUTTOM
	Pause();  //FUNCTION TO INITIALIZE PAUSE BUTTOM
	Resume ();  //FUNCTION TO INITIALIZE RESUME BUTTOM
	Timer1_init();  //FUNCTION TO INITIALIZE TIMER1 WITH COMP MODE

	while (1)
	{
		SevenSegment_Display();  //FUNCTION TO DISPLAY 7 SEGMENT
	}
}



/*                                         7 SEGMENT FUNCTION                                          */
void SevenSegment_init(void)
{
	DDRC |= 0x0F;   //INITIALIZE FIRST 4-PINS IN PORTC
	DDRA |= 0x3F;   //INITIALIZE FIRST 6-PINS IN PORTA
	PORTC =0;       //TURN OFF PORTC
}



/*                                         TIMER FUNCTION                                          */
void Timer1_init(void)
{
	TCNT1 = 0;  //INITIAL VALUE

	/* Description:
	 * For System Clock=1Mhz and timer prescaler is F_CPU/1024.
	 * Timer frequency will be around 1Khz, TICK TIME = 1024us
	 * WE WANT 1 SEC
	 * 1/1024 =976 , 976 IS COMP VALUE
	 */

	OCR1A = 976; // COMP VALUE

	/* Configure the timer control register
	 * 1. Non PWM mode FOC1A=1
	 * 2. CTC Mode WGM12=1
	 * 3. clock = F_CPU/1024 CS10=1 CS11=0 CS12=1
	 * 4. CTC INTERRUPT OCIE1A=1
	 */

	TCCR1A |= (1<<FOC1A);
	TCCR1B |= (1<<CS10) | (1<<CS12) | (1<<WGM12);
	TIMSK |= (1<<OCIE1A);
}



/*                                         RESET FUNCTION                                          */
void Reset (void)
{
	DDRD &= ~(1<<PD2);  // INPUT PIN
	PORTD |= (1<<PD2);  // ENABLE INTERNAL PULL UP
	GICR |= (1<<INT0);  //ENABLE INTERRUPT FOR INT0
	MCUCR |= (1<<ISC01); // FALLING FLAG
}




/*                                         PAUSE FUNCTION                                          */
void Pause(void)
{
	GICR |= (1<<INT1);  //ENABLE INTERRUPT FOR INT1
	MCUCR |= (1<<ISC10) | (1<<ISC11);  // RISING FLAG
}



/*                                         RESUME FUNCTION                                          */
void Resume (void)
{
	DDRB &= ~(1<<PB2);  // INPUT PIN
	PORTB |= (1<<PB2);  // ENABLE INTERNAL PULL UP
	GICR |= (1<<INT2);  //ENABLE INTERRUPT FOR INT2
	MCUCSR &= ~(1<<ISC2);  // FALLING FLAG
}



/*                                         DISPLAY FUNCTION                                          */
void SevenSegment_Display(void)
{
	// DISPLAY FIRST DIGIT IN SECONDS
	PORTA = (1<<PA0);
	PORTC = seconds%10;

	_delay_ms(1);

	// DISPLAY SECOND DIGIT IN SECONDS
	PORTA = (1<<PA1);
	PORTC = seconds/10;

	_delay_ms(1);

	// DISPLAY FIRST DIGIT IN MINUTES
	PORTA = (1<<PA2);
	PORTC = minutes%10;

	_delay_ms(1);

	// DISPLAY SECOND DIGIT IN MINUTES
	PORTA = (1<<PA3);
	PORTC = minutes/10;

	_delay_ms(1);

	// DISPLAY FIRST DIGIT IN HOURS
	PORTA = (1<<PA4);
	PORTC = hours%10;

	_delay_ms(1);

	// DISPLAY SECOND DIGIT IN H
	PORTA = (1<<PA5);
	PORTC = hours/10;

	_delay_ms(1);
}



/*                                         TIMER1 INTERRUPT                                          */
ISR (TIMER1_COMPA_vect)  // STOP WATCH INCREAMENT
{
	seconds++;

	if (seconds == 60)
	{
		minutes++;
		seconds=0;
	}

	if (minutes == 60)
	{
		hours++;
		minutes=0;
	}
}



/*                                         INT0 INTERRUPT                                          */
ISR (INT0_vect)  // RESET BUTTOM
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}




/*                                         INT1 INTERRUPT                                          */
ISR (INT1_vect) // PAUSE BUTTOM
{
	TCCR1B &= ~(1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS12);
}




/*                                         INT2 INTERRUPT                                          */
ISR (INT2_vect)  // RESUME BUTTOM
{
	TCCR1B |= (1<<CS10);
	TCCR1B |= (1<<CS12);
}
