

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define MASTER		15
#define SLAVE		19

#define MSB			16
#define LSB			19

#define RISING		15
#define FALLING		19

#define SETUP_SAMPLE	96
#define SAMPLE_SETUP	94

#define NORMAL		95
#define DOUBLE		12

#define PRES_64		19


#define SPDR	*((volatile u8*) 0x2f)
#define SPSR	*((volatile u8*) 0x2e)
#define SPCR	*((volatile u8*) 0x2d)

#endif /* SPI_PRIV_H_ */
