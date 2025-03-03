/*
 * SPI_init.h
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_

/*********** INCLUDES ***********/
#include "SPI_config.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : SPI initialization function select your configurations from configurations file.
 * @param1 : void
 * @retVal : void
 */
void SPI_init(void);

/**
 * @brief  : SPI interrupt enable function by set GIE bit in SREG register
 * 			 & set SPIE bit in SPCR register.
 * @param1 : void
 * @retVal : void
 */
void SPI_interruptEnable(void);

/**
 * @brief  : SPI interrupt disable function by clear SPIE bit in SPCR register.
 * @param1 : void
 * @retVal : void
 */
void SPI_interruptDisable(void);

#endif /* MCAL_SPI_SPI_INIT_H_ */
