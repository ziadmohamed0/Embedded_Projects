/*
 * ADC_program.c
 *
 *  Created: 17/2/2024 7:43:18 PM
 *  Author: Ziad
 */ 

/* UTILES_LIB */
#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/DIO/DIO_REG.h"


void ADC_init( void )
{
	// SELECT REFRENCE VOLTAGE "Vref" = AVCC
	SET_BIT( ADMUX , 6 );
	CLR_BIT( ADMUX , 7 );
	// Select right adjustment to read all 10 bits 
	CLR_BIT( ADMUX , 5 );
	// SINGLE MODE (close auto trigger) 
	CLR_BIT( ADCSRA , 5 );
	//ADC ENABLE
	SET_BIT( ADCSRA , 7 );
	// Prescaler to adjust the clock 128 for 16MHZ ( 125 KHZ)
	SET_BIT( ADCSRA , 0 );
	SET_BIT( ADCSRA , 1 );
	SET_BIT( ADCSRA , 2 );

}


void ADC_getDigitalValue( u8 channelNum , u16* digitalValue )
{
		
	if ( ( channelNum < 32 ) && ( digitalValue != NULL ) )
	{
		ADMUX &= (0b11100000);//Clear the 5 bits to avoid error when changing channel number at runtime
		ADMUX |= channelNum;//select channel number 
		SET_BIT( ADCSRA , 6 );// start conversion 
		while( GET_BIT( ADCSRA , 4 ) == 0 );//READ FLAG-> CONVERSION HAS BEEN ENDED WHEN FLAG =1  ( INFINITE LOOP UNTIL THE HARDWARE UPDATES THE FLAG )
        SET_BIT( ADCSRA , 4 );// TO CLEAR THE FLAG.....SETTING THE BIT -> THE FLAG WILL BE CLEARED TO AVOID CHANGING FLAG STATUS  	
	    *digitalValue = ADC_u16;//read digital value (all 10 bits ) 
		
	}
	
}