
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/AVR_REG.h"

#include "SPI_config.h"
#include "SPI_priv.h"

void SPI_vidInit(void)
{
#if SPI_MODE == MASTER
	SPCR |=(1<<4);
DDRB |=(1<<4);
DDRB |=(1<<5);
DDRB &=~(1<<6);
DDRB |=(1<<7);
#elif SPI_MODE == SLAVE
	SPCR &=~(1<<4);
#endif

#if SPI_PRES == PRES_64
	SPCR |=(1<<1);
	SPCR &=~(1<<0);
#endif

	SPCR |=(1<<6);
}

u8 SPI_ui8TransmitRecive(u8 Copy_u8Data)
{
	PORTB &=~(1<<4);
	SPDR = Copy_u8Data;
	while(! ((SPSR>>7)&1));
	PORTB |=(1<<4);
	return SPDR;
}
