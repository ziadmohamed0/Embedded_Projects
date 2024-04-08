/*
 * LCD_program.c
 *
 *  Created: 17/2/2024 8:12:08 PM
 *  Author: Ziad
 */ 



#define F_CPU 16000000UL
#include <util/delay.h>
/* UTILIES */

#include "../../SERV/BIT_MATH.h"
#include "../../SERV/STD_TYPES.h"

/*MCAL*/
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_REG.h"

/* HAL */
#include "LCD_config.h"
#include "LCD_interface.h"


void LCD_sendCmnd(u8 cmnd)
{
	/* SET RS TO 0 (write commend) */
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	
	/* SET RW TO 0 (write) */
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	/* write the most 4 bits of command on data pins */
	PRIVATE_WriteHalfPort(cmnd>>4);
	
	/* Enable pulse */
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	/* write the least 4 bits of command on data pins */
	PRIVATE_WriteHalfPort(cmnd);
	
	/* Enable pulse */
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	
}
void LCD_init(void)
{
	_delay_ms(35);
	
	#if LCD_MODE == LCD_8_BIT_MODE
	LCD_sendCmnd(0b00111000); // Function Set command 2*16 LCD
	#elif LCD_MODE == LCD_4_BIT_MODE
	// set Rs pin = 0 (write command)
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	
	// set Rw pin = 0 (write)
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	PRIVATE_WriteHalfPort(0b0010);
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	LCD_sendCmnd(0b00101000);
	#endif
	
	
	
	_delay_us(42);
	
	/* Display on/off Control (Display on(D) ,Cursor on(C),Blink off(B)) */
	LCD_sendCmnd(0b00001111);
	
	_delay_us(42);
	
	/* Clear Display */
	LCD_sendCmnd(0b00000001);
	_delay_us(1600);
	
	/* Entry Mode Set (Increment on (I/D) ,Shift Display off(S) */
	LCD_sendCmnd(0b00000110);
	
	
}
void LCD_sendChar(u8 data)
{
	/* SET RS TO 1 (write commend) */
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	
	/* SET RW TO 0 (write) */
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	/* write the most 4 bits of command on data pins */
	PRIVATE_WriteHalfPort(data>>4);
	
	/* Enable pulse */
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	/* write the least 4 bits of command on data pins */
	PRIVATE_WriteHalfPort(data);
	
	/* Enable pulse */
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

void LCD_writeNumber(u32 number)
{
	u32 Local_reversed = 1;
	if (number == 0)
	{
		LCD_sendChar('0');
	}
	else
	{
		// Reverse Number
		while (number != 0)
		{
			Local_reversed = Local_reversed*10 + (number%10);
			number /= 10;
		}
		
		do
		{
			LCD_sendChar((Local_reversed%10)+'0');
			Local_reversed /= 10;
		}while (Local_reversed != 1);
	}
}
void LCD_goToSpecificPosition(u8 LineNumber, u8 Position)
{
	if(LineNumber == LCD_LINE_ONE)
	{
		if(Position <= 15)
		{
			LCD_sendCmnd(0x80 + Position);
		}
	}

	else if (LineNumber == LCD_LINE_TWO)
	{
		if(Position <= 15)
		{
			LCD_sendCmnd(0xc0 + Position);
		}
	}
}

void LCD_display(u8*string)
{
	u8 i = 0;
	u8 length = 1;
	while(string[i] != '\0')
	{
		length++;
		i++;
	}
	
	if(length > 17)
	{
		u8 check = -1;
		if((string[16] != ' ') || (string[16] != '\0'))
		{
			for(u8 j = 16; j > 0; j--)
			{
				if(string[j] == ' ')
				{
					check = j;
					break;
				}
			}
			u8 counter1 = 0;
			while (string[counter1]!='\0')
			{
				if(counter1 == (check+1))
				{
					LCD_goToSpecificPosition(2, 0);
					LCD_sendChar(string[counter1]);
					++counter1;
				}
				else
				{
					LCD_sendChar(string[counter1]);
					++counter1;
				}
			}
		}
	}
	else if(string[16] == ' ')
	{
		u8 counter2 = 0;
		while (string[counter2]!='\0')
		{
			if(counter2 <= 16)
			{
				LCD_goToSpecificPosition(2, 0);
				LCD_sendChar(string[counter2]);
				++counter2;
			}
			else
			{
				LCD_sendChar(string[counter2]);
				++counter2;
			}
		}
	}
	else
	{
		u8 counter3=0;
		while (string[counter3]!='\0')
		{
			LCD_sendChar(string[counter3]);
			++counter3;
		}
	}
}

void LCD_clear(void)
{
	LCD_sendCmnd(0x01);		/* Clear display */
	_delay_ms(2);
	LCD_sendCmnd (0x80);		/* Cursor at home position */
}


static void PRIVATE_WriteHalfPort(u8 value)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN4,GET_BIT(value,0));
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,GET_BIT(value,1));
	DIO_setPinValue(DIO_PORTC,DIO_PIN6,GET_BIT(value,2));
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,GET_BIT(value,3));
}