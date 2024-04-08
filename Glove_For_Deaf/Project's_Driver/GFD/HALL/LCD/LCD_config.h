/*
 * cofig.h
 *
 *  Created: 17/2/2024 8:43:28 PM
 *  Author: Ziad
 */ 


#ifndef COFIG_H_
#define COFIG_H_


/* Macros For Rs configuration */
#define LCD_RS_PORT           DIO_PORTB
#define LCD_RS_PIN            DIO_PIN1

/* Macros For Rw configuration */
#define LCD_RW_PORT           DIO_PORTB
#define LCD_RW_PIN            DIO_PIN2

/* Macros For En configuration */
#define LCD_EN_PORT           DIO_PORTB
#define LCD_EN_PIN            DIO_PIN3


/* Options FOR LCD Mode:
1- LCD_8_BIT_MODE
2- LCD_4_BIT_MODE */

#define LCD_MODE              LCD_4_BIT_MODE


#define LCD_DATA_PORT         DIO_PORTA


/* 4 Bit Mode Pins Configurtion */


#define LCD_D4_PIN            DIO_PIN4
#define LCD_D4_PORT           DIO_PORTA

#define LCD_D5_PIN            DIO_PIN5
#define LCD_D5_PORT           DIO_PORTA

#define LCD_D6_PIN            DIO_PIN6
#define LCD_D6_PORT           DIO_PORTA

#define LCD_D7_PIN            DIO_PIN7
#define LCD_D7_PORT           DIO_PORTA


#endif /* COFIG_H_ */