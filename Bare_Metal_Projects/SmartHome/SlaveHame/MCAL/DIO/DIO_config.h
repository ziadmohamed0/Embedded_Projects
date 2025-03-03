
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/*				Direction is DIO_u8OUTPUT or DIO_u8INPUT  */

#define DIO_u8PA0_DIR		DIO_u8OUTPUT
#define DIO_u8PA1_DIR		DIO_u8INPUT
#define DIO_u8PA2_DIR		DIO_u8INPUT
#define DIO_u8PA3_DIR		DIO_u8INPUT
#define DIO_u8PA4_DIR		DIO_u8OUTPUT
#define DIO_u8PA5_DIR		DIO_u8OUTPUT
#define DIO_u8PA6_DIR		DIO_u8INPUT
#define DIO_u8PA7_DIR		DIO_u8OUTPUT


/*				Value is DIO_u8HIGH or DIO_u8LOW if pin is output
 * 				Value is DIO_u8PULL_UP or DIO_u8FLOAT if pin is input */

#define DIO_u8PA0_VALUE		DIO_u8LOW
#define DIO_u8PA1_VALUE		DIO_u8PULL_UP
#define DIO_u8PA2_VALUE		DIO_u8PULL_UP
#define DIO_u8PA3_VALUE		DIO_u8FLOAT
#define DIO_u8PA4_VALUE		DIO_u8HIGH
#define DIO_u8PA5_VALUE		DIO_u8LOW
#define DIO_u8PA6_VALUE		DIO_u8FLOAT
#define DIO_u8PA7_VALUE		DIO_u8LOW

#endif /* DIO_CONFIG_H_ */
