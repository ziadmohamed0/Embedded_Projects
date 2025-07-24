/*
 * GPIO_init.h
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#ifndef MCAL_GPIO_GPIO_INIT_H_
#define MCAL_GPIO_GPIO_INIT_H_

/* -------------------- Include Start -------------------- */
#include " GPIO_reg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define Port_Output									0xFF
#define Port_Input									0x00

#define Port_High									0xFF
#define Port_Low									0x00
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
	Pin_Output,
	Pin_Input
}Pin_Direction_t;

typedef enum {
	Pin_Low,
	Pin_High,
	Pin_Toggle
}Pin_Status_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
	/* GPIOx Pins APIs */
void GPIO_vSetPinDirection(uint8 copyPort, uint8 copyPin, uint8 copyDirection);
void GPIO_vSetPinValue(uint8 copyPort, uint8 copyPin, uint8 copyStatus);
uint8 GPIO_u8GetPinValue(uint8 copyPort, uint8 copyPin);

	/* GPIOx Ports APIs */
void GPIO_vSetPortDirection(uint8 copyPort, uint8 copyDirection);
void GPIO_vSetPortValue(uint8 copyPort, uint8 copyStatus);
/* -------------------- API End -------------------- */

#endif /* MCAL_GPIO_GPIO_INIT_H_ */
