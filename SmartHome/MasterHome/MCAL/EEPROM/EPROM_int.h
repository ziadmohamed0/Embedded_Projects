

#ifndef HAL_EPROM3_EPROM_INT_H_
#define HAL_EPROM3_EPROM_INT_H_

u8 EEPROM_ui8ReadByteFromAddress( u8  u16Address,  u8 * data);

void EEPROM_vReadBlockFromAddress(const u16 uAddress, u8* dist,const u16 size);

void EEPROM_vWriteByteToAddress(const u16 uiAddress, const u8 uiData);

void EEPROM_vWriteBlockToAddress(const u16 uiAddress, const u8* uiData,const u16 size);





#endif /* HAL_EPROM3_EPROM_INT_H_ */
