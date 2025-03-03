

#ifndef SPI_INT_H_
#define SPI_INT_H_

void SPI_vidInit(void);

u8 SPI_ui8TransmitRecive(u8 Copy_u8Data);

void SPI_EnableINT();
void SPI_DisableINT();
#endif /* SPI_INT_H_ */
