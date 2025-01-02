
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/AVR_REG.h"
#include "../../LIBRARIES/interrupt.h"

#include <util/delay.h>

#include "SPI_config.h"
#include "SPI_priv.h"

u8 data;

void SPI_vidInit(void)
{
#if SPI_MODE == MASTER
	SPCR |=(1<<4);
#elif SPI_MODE == SLAVE
	SPCR &=~(1<<4);
	DDRB =0;
	DDRB |=(1<<6);
#endif

#if SPI_PRES == PRES_64
	SPCR |=(1<<1);
	SPCR &=~(1<<0);
#endif

	SPCR |=(1<<6);
}

u8 SPI_ui8TransmitRecive(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while(! ((SPSR>>7)&1));
	return SPDR;
}
void SPI_EnableINT()
{
	SPCR |= (1<<7);
}

void SPI_DisableINT()
{
	SPCR &= ~(1<<7);
}
