
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_MODE 		FOUR_BIT


/*			control pins 		*/
#define RS_PORT			DIO_u8GROUP_B
#define RS_PIN			DIO_u8PIN1

#define RW_PORT			DIO_u8GROUP_B
#define RW_PIN			DIO_u8PIN2

#define EN_PORT			DIO_u8GROUP_B
#define EN_PIN			DIO_u8PIN3

/*			data pins			*/

#define D7_PORT			DIO_u8GROUP_A
#define D7_PIN			DIO_u8PIN7

#define D6_PORT			DIO_u8GROUP_A
#define D6_PIN			DIO_u8PIN6

#define D5_PORT			DIO_u8GROUP_A
#define D5_PIN			DIO_u8PIN5

#define D4_PORT			DIO_u8GROUP_A
#define D4_PIN			DIO_u8PIN4

#define D3_PORT			DIO_u8GROUP_A
#define D3_PIN			DIO_u8PIN3

#define D2_PORT			DIO_u8GROUP_A
#define D2_PIN			DIO_u8PIN2

#define D1_PORT			DIO_u8GROUP_A
#define D1_PIN			DIO_u8PIN1

#define D0_PORT			DIO_u8GROUP_A
#define D0_PIN			DIO_u8PIN0

#endif /* LCD_CONFIG_H_ */
