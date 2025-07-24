/*
 * LCD_prog.c
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */

#include "LCD_init.h"
#include "LCD_cfg.h"

uint8 LCD_Data_Pin[4]={D0,D1,D2,D3};
uint8 i=0;


void LCD_vidInit(){
	GPIO_vSetPinDirection(LCD_PORT,LCD_Data_Pin[0],Pin_Output);
	GPIO_vSetPinDirection(LCD_PORT,LCD_Data_Pin[1],Pin_Output);
	GPIO_vSetPinDirection(LCD_PORT,LCD_Data_Pin[2],Pin_Output);
	GPIO_vSetPinDirection(LCD_PORT,LCD_Data_Pin[3],Pin_Output);

	GPIO_vSetPinDirection(LCD_PORT,RS,Pin_Output);
	GPIO_vSetPinDirection(LCD_PORT,E,Pin_Output);
	_delay_ms(40);
	GPIO_vSetPinValue(LCD_PORT,RS,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],(GET_BIT(_LCD_BIT_4_MODE,(4+i))));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
	LCD_vidWriteCmd(_LCD_BIT_4_MODE);
	_delay_ms(1);
	LCD_vidWriteCmd(_LCD_DISPLAY_ON);
	_delay_ms(1);
	LCD_vidWriteCmd(_LCD_CLEAR_DIS);
	_delay_ms(2);
	LCD_vidWriteCmd(_LCD_ENTRY_MODE_INC);
}

void LCD_vidWriteCmd(uint8 u8CmdCopy){
	uint8 i=0;
	GPIO_vSetPinValue(LCD_PORT,RS,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],(GET_BIT(u8CmdCopy,(4+i))));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],(GET_BIT(u8CmdCopy,(i))));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
}

void LCD_vidWriteChar(uint8 u8CharCopy){
	uint8 i=0;
	GPIO_vSetPinValue(LCD_PORT,RS,Pin_High);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],((u8CharCopy >> (i+4))& 0x01));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],((u8CharCopy >> (i))& 0x01));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
}


void LCD_vidClrDisp(){
	uint8 i=0;
	GPIO_vSetPinValue(LCD_PORT,RS,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],((_LCD_CLEAR_DIS >> (i+4))& 0x01));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],((_LCD_CLEAR_DIS >> (i))& 0x01));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
}

void LCD_vidShiftLeft(){
	uint8 i=0;
	GPIO_vSetPinValue(LCD_PORT,RS,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],((_LCD_SHIFT_DIS_L >> (i+4))& 0x01));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],((_LCD_SHIFT_DIS_L >> (i))& 0x01));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
}


void LCD_vidShiftRight(){
	uint8 i=0;
	GPIO_vSetPinValue(LCD_PORT,RS,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],((_LCD_SHIFT_DIS_R >> (i+4))& 0x01));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
	for(i=0;i<4;i++){
		GPIO_vSetPinValue(LCD_PORT,LCD_Data_Pin[i],((_LCD_SHIFT_DIS_R >> (i))& 0x01));
	}
	GPIO_vSetPinValue(LCD_PORT,E,Pin_High);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_PORT,E,Pin_Low);
}

void LCD_vidWriteInt(sint32 u32NumCopy){
	uint8 arr[11]={0};
	sint8 i=0;
	if(u32NumCopy <0){
		LCD_vidWriteChar('-');
		u32NumCopy *= -1;
	}

	while(u32NumCopy){
		arr[i]=(uint8)(u32NumCopy%10);
		u32NumCopy /=10;
		i++;
	}

	for(i=i-1;i>=0;i--){
		LCD_vidWriteChar((arr[i]+'0'));
	}
}

void LCD_vidWriteStr(uint8 *u8StrCopy){
	while(((*u8StrCopy) != '\0')){
		LCD_vidWriteChar((*(u8StrCopy++)));
	}
}

void LCD_vidGoto(uint8 u8RowCopy,uint8 u8ColCopy){
	uint8 add=0;
	switch(u8RowCopy){
	case 1 : add=u8ColCopy;  break;
	case 2 : add=u8ColCopy+0x40;  break;
	}
	LCD_vidWriteCmd((add+_LCD_AD_DDRAM));
}

void LCD_vidWritePatternCGRAM(uint8 *u8Pattern,uint8 u8Loc){
	LCD_vidWriteCmd((_LCD_AD_CGRAM + ((u8Loc-1)*8)));
	uint8 i=0;
	for(i=0;i<8;i++){
		LCD_vidWriteChar(u8Pattern[i]);
	}
}
