
#ifndef DIO_INT_H_
#define DIO_INT_H_

ES_t DIO_enuInit(void);

ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Direction);

ES_t DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

ES_t DIO_enuTogPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

ES_t DIO_enuGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_pu8Value);

enum
{
	DIO_u8GROUP_A 		,
	DIO_u8GROUP_B 		,
	DIO_u8GROUP_C 		,
	DIO_u8GROUP_D 		,

	DIO_u8PIN0=0		,
	DIO_u8PIN1			,
	DIO_u8PIN2			,
	DIO_u8PIN3			,
	DIO_u8PIN4			,
	DIO_u8PIN5			,
	DIO_u8PIN6			,
	DIO_u8PIN7
	,
	DIO_u8INPUT=0		,
	DIO_u8OUTPUT		,

	DIO_u8LOW=0			,
	DIO_u8HIGH			,

	DIO_u8FLOAT=0		,
	DIO_u8PULL_UP		,
};

#endif /* DIO_INT_H_ */
