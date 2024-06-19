/*
 * SPI_reg.h
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

#ifndef MCAL_SPI_SPI_REG_H_
#define MCAL_SPI_SPI_REG_H_

/*********** INCLUDES ***********/
#include "../INTERRUPT/INTERRUPT_init.h"

/*********** REGISTERS ***********/
#define SPDR *((volatile uint_8 *) 0x2F)
#define SPSR *((volatile uint_8 *) 0x2E)
#define SPCR *((volatile uint_8 *) 0x2D)

/*********** BITS ***********/

	/* ----- SPCR BITS ----- */
typedef enum
{
	SPR0,
	SPR1,
	CPHA,
	CPOL,
	MSTR,
	DORD,
	SPE,
	SPIE
}_BITS_SPCR;

	/* ----- SPSR BITS ----- */
typedef enum
{
	SPI2X,
	WCOL = 6,
	SPIF
}_BITS_SPSR;

	/* ----- SPDR BITS ----- */
typedef enum
{
	LSB,
	MSB = 7,
}_BITS_SPDR;

#endif /* MCAL_SPI_SPI_REG_H_ */
