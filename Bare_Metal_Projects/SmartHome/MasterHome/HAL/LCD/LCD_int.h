
#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuSendData(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

//ES_t LCD_enuDisplaySignedInteger(s32 Copy_s32Data);

ES_t LCD_enuDisplayUnsignedInteger(u16 Copy_u32Data);

//ES_t LCD_enuDisplayFloat(f64 Copy_f64Data);

ES_t LCD_enuDisplayString(const char * Copy_pcString);

ES_t LCD_enuSetCursorPosition(u8 Copy_u8YDimension, u8 Copy_uXDimension);

ES_t LCD_enuClearDisplay( void );

enum
{
	LCD_u8YDIM_0=0,
	LCD_u8YDIM_1,

	LCD_u8XDIM_0=0,
	LCD_u8XDIM_1,
	LCD_u8XDIM_2,
	LCD_u8XDIM_3,
	LCD_u8XDIM_4,
	LCD_u8XDIM_5,
	LCD_u8XDIM_6,
	LCD_u8XDIM_7,
	LCD_u8XDIM_8,
	LCD_u8XDIM_9,
	LCD_u8XDIM_10,
	LCD_u8XDIM_11,
	LCD_u8XDIM_12,
	LCD_u8XDIM_13,
	LCD_u8XDIM_14,
	LCD_u8XDIM_15

};


#endif /* LCD_INT_H_ */
