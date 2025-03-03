/*
 * SPI_config.h
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

/*********** INCLUDES ***********/
#include "SPI_reg.h"

/*********** CPOL FUNCTIONALITY ***********/
#define _RISING_FALLING	0
#define _FALLING_RISING	1

#define CPOL_MODE _FALLING_RISING

/*********** MASTER OR SLAVE ***********/
#define _SPI_MASTER	0
#define _SPI_SLAVE  1

#define _SPI_MODE	_SPI_MASTER
/*********** LSB OR MSB ***********/
#define LSB	0
#define MSB 1

#define _SPI_DATA_ORDER LSB
/*********** CPHA FUNCTIONALITY ***********/
#define _SAMPLE_SETUP 0
#define _SETUP_SAMPLE 1

#define CPHA_MODE _SETUP_SAMPLE

/*********** SCK FREQUENCY ***********/
#define CLK_4	0
#define CLK_16	1
#define CLK_64	2
#define CLK_128	3
#define CLK_2	4
#define CLK_8	5
#define CLK_32	6
#define CLK_64_	7


#endif /* MCAL_SPI_SPI_CONFIG_H_ */
