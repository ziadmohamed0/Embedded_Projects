/*
 * Interrupt_prog.c
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */
#include "Interrupt_external_init.h"


static void EX_Int0(uint8 copySense);
static void EX_Int1(uint8 copySense);
static void EX_Int2(uint8 copySense);

void EX_Interrupt_init(uint8 copyExNumber, uint8 copySense) {
	SET_BIT(SREG, GIE);
	switch(copyExNumber) {
		case EX_INT0:
			EX_Int0(copySense);
			break;

		case EX_INT1:
			EX_Int1(copySense);
			break;

		case EX_INT2:
			EX_Int2(copySense);
			break;

		default :
			/* Nothing */
			break;
	}

}


static void EX_Int0(uint8 copySense) {
	CLR_BIT(GIFR,INTF0);
	GPIO_vSetPinDirection(Port_D, Pin_2, Pin_Input);
	SET_BIT(GICR,INT0);
	switch(copySense) {
		case EX_Low_Level:
			CLR_BIT(MCUCR, ISC01);
			CLR_BIT(MCUCR, ISC00);
			break;

		case EX_Any_Logical:
			CLR_BIT(MCUCR, ISC01);
			SET_BIT(MCUCR, ISC00);
			break;

		case EX_Falling_Edge:
			SET_BIT(MCUCR, ISC01);
			CLR_BIT(MCUCR, ISC00);
			break;

		case EX_Rising_Edge:
			SET_BIT(MCUCR, ISC01);
			SET_BIT(MCUCR, ISC00);
			break;

		default :
			/* Nothing  */
			break;
	}
}

static void EX_Int1(uint8 copySense) {
	CLR_BIT(GIFR,INTF1);
	GPIO_vSetPinDirection(Port_D, Pin_3, Pin_Input);
	SET_BIT(GICR,INT1);
	switch(copySense) {
		case EX_Low_Level:
			CLR_BIT(MCUCR, ISC11);
			CLR_BIT(MCUCR, ISC10);
			break;

		case EX_Any_Logical:
			CLR_BIT(MCUCR, ISC11);
			SET_BIT(MCUCR, ISC10);
			break;

		case EX_Falling_Edge:
			SET_BIT(MCUCR, ISC11);
			CLR_BIT(MCUCR, ISC10);
			break;

		case EX_Rising_Edge:
			SET_BIT(MCUCR, ISC11);
			SET_BIT(MCUCR, ISC10);
			break;

		default :
			/* Nothing  */
			break;
	}
}

static void EX_Int2(uint8 copySense) {
	CLR_BIT(GIFR,INTF2);
	GPIO_vSetPinDirection(Port_B, Pin_2, Pin_Input);
	SET_BIT(GICR,INT2);
	switch (copySense) {
		case EX_Falling_Edge:
			CLR_BIT(MCUCSR, ISC2);
			break;

		case EX_Rising_Edge:
			SET_BIT(MCUCSR, ISC2);
			break;

		default :
			/* Nothing  */
			break;
	}
}
