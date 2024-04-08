/*
 * EEPROM_Interface.h
 *
 *  Created: 17/2/2024 7:44:30 PM
 *  Author: Ziad 
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


void EEPROM_Write_Byte(u8 address,u8 value);

u8 EEPROM_Read_Byte(u8 address);



#endif /* EEPROM_INTERFACE_H_ */