#include "EEPROM.h"
#include <avr/io.h>

#include "../../LIBRARY/stdTypes.h"


void EEPROM_ui8ReadByteFromAddress( const u16 u16Address ,  u8 * data)
{
	/* Wait for completion of previous write */
	while (((EECR & (1 << EEWE))>>EEWE)==1);
	/* Set up address register */
	EEAR = u16Address;
	/* Start EEPROM read by writing EERE */
	EECR |= (1 << EERE);
	/* Return data from data register */
	(*data) = EEDR;
	//return 1;
}

void EEPROM_vReadBlockFromAddress(const u16 uAddress, u8* dist,const u16 size)
{
	/* Wait for completion of previous write */
	while (((EECR & (1 << EEWE))>>EEWE)==1)
	;

	u16 counter = 0;//the counter of bytes that are read

	while (counter < size) //loop until move all bytes to the given array
	{
		/* Set up address register */
		EEAR = uAddress + counter;
		/* Start EEPROM read by writing EERE */
		EECR |= (1 << EERE);
		/* move data from data register to the array */
		*(dist + counter) = EEDR;

		counter++;//increase the bytes counter
	}
}


void EEPROM_vWriteByteToAddress(const u16 uiAddress, const u8 uiData)
{

	/* Wait for completion of previous write process*/
	while ( ( (EECR & (1 << EEWE) ) >>EEWE ) == 1)
	;
	/* Set up address register */
	EEAR = uiAddress;

	/* Read the byte in the address of EEAR */
	EECR |= (1 << EERE);
	if (EEDR != uiData)//compare the value read to the value to be written
	{//if they are not equal then write the data 
		EEDR = uiData;//move the data to EEDR

		/* Write logical one to EEMWE */
		EECR |= (1 << EEMWE);
		/* Start EEPROM write by setting EEWE */
		EECR |= (1 << EEWE);
	}
	else
	{

	}

}

void EEPROM_vWriteBlockToAddress(const u16 uiAddress, const u8* uiData,const u16 size)
{
	u16 counter = 0;//Bytes write counter
	while (counter < size)
	{
		/* Wait for completion of previous write process*/
		while (( (EECR & (1 << EEWE) ) >>EEWE ) == 1)
		;
		/* Set up address register */
		EEAR = uiAddress + counter;

		/* Read the byte in the address of EEAR */
		EECR |= (1 << EERE);
		if (EEDR != (*(uiData + counter)))//compare the value read to the value to be written
		{//if they are not equal then write the data 
			EEDR = *(uiData + counter);//move the data to EEDR

			/* Write logical one to EEMWE */
			EECR |= (1 << EEMWE);
			/* Start EEPROM write by setting EEWE */
			EECR |= (1 << EEWE);
		}
		else
		{

		}
		counter++;//increase bytes counter
	}
}
