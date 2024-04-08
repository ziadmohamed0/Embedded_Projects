/*
 * DIO_program.c
 *
 *  Created: 17/2/2024 7:44:30 PM
 *  Author: Ziad
 */ 

 /* UTILES_LIB */
#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_REG.h"


/* Pin Apis */								   
void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection)
{
	if((PortId<=3) && (PinId<=7) && ((PinDirection == DIO_PIN_OUTPUT)||(PinDirection == DIO_PIN_INPUT)))
	{
		switch(PortId)
	 {
		case DIO_PORTA:
		if (DIO_PIN_OUTPUT == PinDirection)
		{
			SET_BIT(DDRA,PinId);
		}
		else
		{
			CLR_BIT(DDRA,PinId);
		}
		break;
		
		case DIO_PORTB:
		if (DIO_PIN_OUTPUT == PinDirection)
		{
			SET_BIT(DDRB,PinId);
		}
		else
		{
			CLR_BIT(DDRB,PinId);
		}
		break;
		
		case DIO_PORTC:
		if (DIO_PIN_OUTPUT == PinDirection)
		{
			SET_BIT(DDRC,PinId);
		}
		else
		{
			CLR_BIT(DDRC,PinId);
		}
		break;
		
		case DIO_PORTD:
		if (DIO_PIN_OUTPUT == PinDirection)
		{
			SET_BIT(DDRD,PinId);
		}
		else
		{
			CLR_BIT(DDRD,PinId);
		}
		break;
	 }
	}
}


void DIO_setPinValue(u8 PortId, u8 PinId, u8 PinValue)
{
	if((PortId<=3) && (PinId<=7) && ((PinValue == DIO_PIN_HIGH)||(PinValue == DIO_PIN_LOW)))
	{
		switch(PortId)
	{
		case DIO_PORTA:
		if (DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTA,PinId);
		}
		else
		{
			CLR_BIT(PORTA,PinId);
		}
		break;
		
		case DIO_PORTB:
		if (DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTB,PinId);
		}
		else
		{
			CLR_BIT(PORTB,PinId);
		}
		break;
		
		case DIO_PORTC:
		if (DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTC,PinId);
		}
		else
		{
			CLR_BIT(PORTC,PinId);
		}
		break;
		
		case DIO_PORTD:
		if (DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTD,PinId);
		}
		else
		{
			CLR_BIT(PORTD,PinId);
		}
		break;
	}
	}
}


void DIO_getPinValue(u8 PortId, u8 PinId, u8* PinValue)
{
	if((PortId<=3) && (PinId<=7) && (PinValue!=NULL))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			if (DIO_PIN_HIGH == GET_BIT(PINA,PinId))
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
			
			case DIO_PORTB:
			if (DIO_PIN_HIGH == GET_BIT(PINB,PinId))
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
			
			case DIO_PORTC:
			if (DIO_PIN_HIGH == GET_BIT(PINC,PinId))
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
			
			case DIO_PORTD:
			if (DIO_PIN_HIGH == GET_BIT(PIND,PinId))
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
		}
	}
}


void DIO_togglePinValue(u8 PortId, u8 PinId)
{
	if((PortId<=3) && (PinId<=7))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA,PinId);
			break;
			
			case DIO_PORTB:
			TOG_BIT(PORTB,PinId);
			break;
			
			case DIO_PORTC:
			TOG_BIT(PORTC,PinId);
			break;
			
			case DIO_PORTD:
			TOG_BIT(PORTD,PinId);
			break;
		}
	}
}


/* Port Apis */								   
void DIO_setPortDirection(u8 PortId, u8 PortDirection)
{ 
    if ((PortId<=3) && ((PortDirection == DIO_PORT_OUTPUT)||(PortDirection == DIO_PORT_INPUT)))
	{
		switch(PortId)
		{
			case 0:
			if (PortDirection == DIO_PORT_OUTPUT)
			{
				DDRA = 0xff;
			}
			else
			{
				DDRA = 0x00;
			}
			break;
			
			case 1:
			if (PortDirection == DIO_PORT_OUTPUT)
			{
				DDRB = 0xff;
			}
			else
			{
				DDRB = 0x00;
			}
			break;
			
			case 2:
			if (PortDirection == DIO_PORT_OUTPUT)
			{
				DDRC = 0xff;
			}
			else
			{
				DDRC = 0x00;
			}
			break;
			
			case 3:
			if (PortDirection == DIO_PORT_OUTPUT)
			{
				DDRD = 0xff;
			}
			else
			{
				DDRD = 0x00;
			}
			break;
		}
	}
}


void DIO_setPortValue(u8 PortId, u8 PortValue)
{
	if (PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = PortValue;
			break;
			
			case 1:
			PORTB = PortValue;
			break;
			
			case 2:
			PORTC = PortValue;
			break;
			
			case 3:
			PORTD = PortValue;
			break;
		}
	}
}


void DIO_getPortValue(u8 PortId, u8* PortValue)
{
	if((PortId<=3) && (PortValue != NULL))
	{
		switch(PortId)
		{
			case 0:
				*PortValue = PINA;
			break;
			
			case 1:
				*PortValue = PINB;
			break;
			
			case 2:
				*PortValue = PINC;
			break;
			
			case 3:
				*PortValue = PIND;
			break;
		}
	
	}
}


void DIO_togglePortValue (u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = ~PORTA;
			break;
			
			case 1:
			PORTB = ~PORTB;
			break;
			
			case 2:
			PORTC = ~PORTC;
			break;
			
			case 3:
			PORTD = ~PORTD;
			break;
		}
	}
}