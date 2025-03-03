/*
 * dio_Init.h
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */

#ifndef MCAL_DIO_DIO_INIT_H_
#define MCAL_DIO_DIO_INIT_H_

/* -------------------- Section : Includes -------------------- */
#include "dio_Reg.h"
#include "../../Serv/Std_Types.h"
#include "../../Serv/Bit_Math.h"
/* -------------------- Section : Enums -------------------- */
typedef enum{
	PortA_p0 , PortA_p1 , PortA_p2 , PortA_p3 , PortA_p4 , PortA_p5 , PortA_p6 , PortA_p7,
	PortB_p0 , PortB_p1 , PortB_p2 , PortB_p3 , PortB_p4 , PortB_p5 , PortB_p6 , PortB_p7,
	PortC_p0 , PortC_p1 , PortC_p2 , PortC_p3 , PortC_p4 , PortC_p5 , PortC_p6 , PortC_p7,
	PortD_p0 , PortD_p1 , PortD_p2 , PortD_p3 , PortD_p4 , PortD_p5 , PortD_p6 , PortD_p7,
}Pins;

typedef enum{
	p0 = 0,
	p1,
	p2,
	p3,
	p4,
	p5,
	p6,
	p7
}dio_Pins;

typedef enum{
	PORTA_reg = 0,
	PORTB_reg,
	PORTC_reg,
	PORTD_reg,
}Ports;

typedef enum{
	direction_Input = 0,
	direction_Output
}dio_Direction;

typedef enum{
	dio_Low = 0,
	dio_High
}dio_Value;

/* -------------------- Section : Structes -------------------- */
typedef struct {
	u8 Pin  		;
	u8 Direction 	;
	u8 Value 		;
}Pin_Config;
/* -------------------- Section : Macros -------------------- */
#define	Status_Port_High		(u8)0xFF
#define	Status_Port_Low			(u8)0x00

#define Direction_Port_Input	(u8)0x00
#define Direction_Port_Output	(u8)0xFF

#define	Status_Pin_Toggle		(u8)2
#define	Status_Pin_High			(u8)1
#define	Status_Pin_Low			(u8)0

#define Direction_Pin_Input		(u8)0
#define Direction_Pin_Output	(u8)1

/* -------------------- Section : Pins Functions Declarations -------------------- */
void Dio_setPinDir(u8 CopyPinNum,u8 CopyPinDir);
void Dio_setPinVal(u8 CopyPinNum,u8 CopyPinVal);
Std_Return Dio_getPinVal(u8 CopyPinNum);
void DIO_vidSetPinSDir(u8 * u8PinsNum,u8 Copyu8Size,u8 Copyu8Dir);
void DIO_vidSetPinSVal(u8 * u8PinsNum,u8 Copyu8Size,u8 Copyu8Val);


/* -------------------- Section : Ports Functions Declarations -------------------- */
void Dio_setPortDir(u8 CopyPortNum,u8 CopyPinDir);
void Dio_setPortVal(u8 CopyPortNum,u8 CopyPinVal);
Std_Return Dio_getPortVal(u8 CopyPortNum);


#endif /* MCAL_DIO_DIO_INIT_H_ */
