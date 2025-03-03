
#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define INTERRUPT_NUM	3

#define MCUCR		*((volatile u8*)0x55)	//Control Register for interrupt sense control
/*** Bit 2,3 controls INT1 ********* Bits 0,1 controls INT0 *********/
////////////////////////////////////////////////////////////////////////////////////////////////

#define MCUCSR		*((volatile u8*)0x54)   //Status regester ->>
/*** Bit 6 controls INT2 Sense Level -> 0 for falling edge & 1 for rising edge  **/
//////////////////////////////////////////////////////////////////////////////////////////////

#define GICR		*((volatile u8*)0x5B)	//works as PIE for EXTI
/****  BIT 5 => INT2	BIT 6 => INT0	BIT 7 => INT1 ****/
//////////////////////////////////////////////////////////////////////////////////////////////

#define GIFR		*((volatile u8*)0x5A)	//works as PIF for EXTI
/****  BIT 5 => INT2	BIT 6 => INT0	BIT 7 => INT1 ****/
//////////////////////////////////////////////////////////////////////////////////////////////

enum
{
	LOW_LEVEL ,
	ANY_LOGICAL,
	FALLING ,
	RISING ,

	ENABELED =0 ,
	DISABELED ,

	INT0 = 0,
	INT1 ,
	INT2
};


#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
