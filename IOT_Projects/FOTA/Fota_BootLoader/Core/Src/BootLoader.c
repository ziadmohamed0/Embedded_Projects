/*
 * BootLoader.c
 *
 *  Created on: Dec 1, 2024
 *      Author: s
 */
#include "Bootloader.h"

static void BL_Get_Version(uint8_t *Host_buffer);
static void BL_Get_Help(uint8_t *Host_buffer);
static void BL_Get_Chip_Idendification_nNumber(uint8_t *Host_buffer);
static void BL_Flash_Erase(uint8_t *Host_buffer);
static void BL_Write_Data(uint8_t *Host_buffer);


static uint32_t BL_CRC_verfiy(uint8_t * pdata,uint32_t DataLen,uint32_t HosrCRC);
static uint8_t Perform_Flash_Erase(uint32_t PageAddress, uint8_t page_Number);
static uint8_t BL_Address_Varification(uint32_t Addresss);
static uint8_t FlashMemory_Paylaod_Write(uint16_t * pdata,uint32_t StartAddress,uint8_t Payloadlen);
static void BL_Send_ACK(uint8_t dataLen);
static void BL_Send_NACK();
void Jump_Application();

static uint8_t Host_buffer[HOSTM_MAX_SIZE];

BL_status BL_FeatchHostCommand()
{

	BL_status status = BL_NACK;
	HAL_StatusTypeDef Hal_status=HAL_ERROR;
	uint8_t DataLen=0;
	memset(Host_buffer,0,HOSTM_MAX_SIZE);
	Hal_status = HAL_UART_Receive(&huart2,Host_buffer,1,HAL_MAX_DELAY);
	if(Hal_status != HAL_OK)
	{
		status = BL_NACK;
	}
	else{
		DataLen = Host_buffer[0];
		Hal_status = HAL_UART_Receive(&huart2,&Host_buffer[1],DataLen,HAL_MAX_DELAY);
		DataLen++;
		if(Hal_status != HAL_OK)
		{
			status = BL_NACK;
		}
		else{
			switch(Host_buffer[1])
			{

			case CBL_GET_VER_CMD: BL_Get_Version(Host_buffer);break;
			case CBL_GET_HELP_CMD: BL_Get_Help(Host_buffer) ;break;
			case CBL_GET_CID_CMD: BL_Get_Chip_Idendification_nNumber(Host_buffer); break;
			case CBL_GO_TO_ADDR_CMD: BL_SendMessage("jump to adderss"); break;
			case CBL_FLASH_ERASE_CMD: BL_Flash_Erase(Host_buffer); break;
			case CBL_MEM_WRITE_CMD: BL_Write_Data(Host_buffer); break;
			default  : status = BL_NACK;

			}

		}

	}
	return status;
}

void BL_SendMessage(char *format,...)
{
	char message[100]={0};
	va_list args;
	va_start(args,format);
	vsprintf(message,format,args);
	HAL_UART_Transmit(&huart2,(uint8_t*)message,sizeof(message),HAL_MAX_DELAY);
	va_end(args);

}

static void BL_Get_Version(uint8_t *Host_buffer)
{
	uint8_t Veraion[4]={CBL_VENDOR_ID,CBL_SW_MAJOR_VERSION,CBL_SW_MINOR_VERSION,CBL_SW_PATCH_VERSION};
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_buffer[0]+1;
	CRC_valu = *(uint32_t*)(Host_buffer+Host_Packet_Len -4);
	if(CRC_VERIFING_PASS == BL_CRC_verfiy((uint8_t*)&Host_buffer[0],Host_Packet_Len-4,CRC_valu))
	{
		BL_Send_ACK(4);
		HAL_UART_Transmit(&huart2,(uint8_t*)Veraion,4,HAL_MAX_DELAY);
	}
	else
	{
		BL_Send_NACK();
	}
}


static void BL_Get_Help(uint8_t *Host_buffer)
{
	uint8_t BL_supported_CMS[6]={

			CBL_GET_VER_CMD,
			CBL_GET_HELP_CMD,
			CBL_GET_CID_CMD,
			CBL_GO_TO_ADDR_CMD,
			CBL_FLASH_ERASE_CMD,
			CBL_MEM_WRITE_CMD
	};
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_buffer[0]+1;
	CRC_valu = *(uint32_t*)(Host_buffer+Host_Packet_Len -4);
	if(CRC_VERIFING_PASS == BL_CRC_verfiy((uint8_t*)&Host_buffer[0],Host_Packet_Len-4,CRC_valu))
	{
		BL_Send_ACK(6);
		HAL_UART_Transmit(&huart2,(uint8_t*)BL_supported_CMS,4,HAL_MAX_DELAY);
	}
	else
	{
		BL_Send_NACK();
	}
}

static void BL_Get_Chip_Idendification_nNumber(uint8_t *Host_buffer)
{
	uint16_t Chip_ID=0;
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_buffer[0]+1;
	CRC_valu = *(uint32_t*)(Host_buffer+Host_Packet_Len -4);
	if(CRC_VERIFING_PASS == BL_CRC_verfiy((uint8_t*)&Host_buffer[0],Host_Packet_Len-4,CRC_valu))
	{
		Chip_ID = (uint16_t)(DBGMCU->IDCODE & 0x00000FFF);
		BL_Send_ACK(2);
		HAL_UART_Transmit(&huart2,(uint8_t*)&Chip_ID,2,HAL_MAX_DELAY);
	}
	else
	{
		BL_Send_NACK();
	}
}

static void BL_Flash_Erase(uint8_t *Host_buffer)
{
	uint8_t Erase_status = UNSUCCESSFUL_ERASE;
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_buffer[0]+1;
	CRC_valu = *(uint32_t*)(Host_buffer+Host_Packet_Len -4);
	if(CRC_VERIFING_PASS == BL_CRC_verfiy((uint8_t*)&Host_buffer[0],Host_Packet_Len-4,CRC_valu))
	{

		Erase_status = Perform_Flash_Erase(*((uint32_t*)&Host_buffer[2]),Host_buffer[6]);
		BL_Send_ACK(1);
		HAL_UART_Transmit(&huart2,(uint8_t*)&Erase_status,1,HAL_MAX_DELAY);

	}
	else
	{
		BL_Send_NACK();
	}
}

uint16_t i=0;

static void BL_Write_Data(uint8_t *Host_buffer)
{
	uint8_t Adress_varfiy=ADDRESS_IS_INVALID;
	uint32_t Address_Host=0;
	uint8_t DataLen=0;
	uint8_t payload_status =FLASH_PAYLOAD_WRITE_FAILED;
	uint16_t Host_Packet_Len=0;
	uint32_t CRC_valu=0;
	Host_Packet_Len =  Host_buffer[0]+1;
	CRC_valu = *(uint32_t*)(Host_buffer+Host_Packet_Len -4);
	//if(CRC_VERIFING_PASS == BL_CRC_verfiy((uint8_t*)&Host_buffer[0],Host_Packet_Len-4,CRC_valu))
	//{
		//BL_Send_ACK(1);
		Address_Host = *((uint32_t*)&Host_buffer[2]) + 64*i;
		i++;
		DataLen = Host_buffer[6];
		Adress_varfiy = BL_Address_Varification(Address_Host);
		if(Adress_varfiy == ADDRESS_IS_VALID)
		{
			//flash
			payload_status = FlashMemory_Paylaod_Write((uint16_t*)&Host_buffer[7],Address_Host,DataLen);
			HAL_UART_Transmit(&huart2,(uint8_t*)&payload_status,1,HAL_MAX_DELAY);

		}
		else
		{
			HAL_UART_Transmit(&huart2,(uint8_t*)&Adress_varfiy,1,HAL_MAX_DELAY);
		}
	//}
/*	else
	{
		BL_Send_NACK();
	}*/
}

static uint8_t BL_Address_Varification(uint32_t Addresss)
{
	uint8_t Adress_varfiy=ADDRESS_IS_INVALID;
	if(Addresss>=FLASH_BASE &&Addresss<=STM32F103_FLASH_END)
	{
		Adress_varfiy=ADDRESS_IS_VALID;
	}
	else if(Addresss>=SRAM_BASE &&Addresss<=STM32F103_SRAM_END)
	{
		Adress_varfiy=ADDRESS_IS_VALID;
	}
	else{
		Adress_varfiy=ADDRESS_IS_INVALID;
	}
	return Adress_varfiy;
}

static uint32_t BL_CRC_verfiy(uint8_t * pdata,uint32_t DataLen,uint32_t HostCRC)
{
	uint8_t crc_status=CRC_VERIFING_FAILED;
	uint32_t MCU_CRC=0;
	uint32_t dataBuffer=0;
	for(uint8_t count =0;count<DataLen ;count++)
	{
		dataBuffer = (uint32_t)pdata[count];
		MCU_CRC = HAL_CRC_Accumulate(&hcrc,&dataBuffer,1);
	}
	__HAL_CRC_DR_RESET(&hcrc);
	if(HostCRC == MCU_CRC )
	{
		crc_status=CRC_VERIFING_PASS;
	}
	else{
		crc_status=CRC_VERIFING_FAILED;
	}
	return crc_status;
}

static void BL_Send_ACK(uint8_t dataLen)
{
	uint8_t ACK_value[2]={0};
	ACK_value[0]=SEND_ACK;
	ACK_value[1]=dataLen;
	HAL_UART_Transmit(&huart2,(uint8_t*)ACK_value,2,HAL_MAX_DELAY);
}

static void BL_Send_NACK()
{
	uint8_t ACk_value=SEND_NACK;
	HAL_UART_Transmit(&huart2,&ACk_value,sizeof(ACk_value),HAL_MAX_DELAY);
}

static uint8_t Perform_Flash_Erase(uint32_t PageAddress, uint8_t page_Number)
{
	FLASH_EraseInitTypeDef pEraseInit;
	HAL_StatusTypeDef Hal_status  = HAL_ERROR;
	uint32_t PageError =0;
	uint8_t PageStatus=INVALID_PAGE_NUMBER;
	if(page_Number>CBL_FLASH_MAX_PAGE_NUMBER)
	{
		PageStatus=INVALID_PAGE_NUMBER;
	}
	else
	{
		PageStatus=VALID_PAGE_NUMBER;
		if(page_Number<= (CBL_FLASH_MAX_PAGE_NUMBER - 1) || PageAddress == CBL_FLASH_MASS_ERASE)
		{
			if(PageAddress ==CBL_FLASH_MASS_ERASE )
			{
				pEraseInit.TypeErase =FLASH_TYPEERASE_PAGES;
				pEraseInit.Banks = FLASH_BANK_1;
				pEraseInit.PageAddress = 0x8008000;
				pEraseInit.NbPages =12;
			}
			else{
				pEraseInit.TypeErase =FLASH_TYPEERASE_PAGES;
				pEraseInit.Banks = FLASH_BANK_1;
				pEraseInit.PageAddress = PageAddress;
				pEraseInit.NbPages =page_Number;
			}
			HAL_FLASH_Unlock();
			Hal_status = HAL_FLASHEx_Erase(&pEraseInit,&PageError);
			HAL_FLASH_Lock();
			if(PageError == HAL_SUCCESSFUL_ERASE)
			{
				PageStatus=SUCCESSFUL_ERASE;
			}
			else{
				PageStatus=UNSUCCESSFUL_ERASE;
			}
		}
		else
		{
			PageStatus=INVALID_PAGE_NUMBER;
		}
	}
return PageStatus;

}

static uint8_t FlashMemory_Paylaod_Write(uint16_t * pdata,uint32_t StartAddress,uint8_t Payloadlen)
{
	uint32_t Address=0;
	uint8_t UpdataAdress=0;
	HAL_StatusTypeDef Hal_status=HAL_ERROR;
	uint8_t payload_status =FLASH_PAYLOAD_WRITE_FAILED;
	HAL_FLASH_Unlock();

	for(uint8_t payload_count=0,UpdataAdress=0;payload_count<Payloadlen/2;payload_count++,UpdataAdress+=2)
	{
		Address =  StartAddress +UpdataAdress;
		Hal_status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,Address,pdata[payload_count]);
		if(Hal_status != HAL_OK)
		{
			payload_status =FLASH_PAYLOAD_WRITE_FAILED;
		}
		else{
			payload_status =FLASH_PAYLOAD_WRITE_PASSED;
		}
	}
	HAL_FLASH_Lock();
	return payload_status;

}

#define FLASH_SECTOR2_BASE_ADDRESS   0x08008000U
typedef void (*pMainApp)(void);

void Jump_Application()
{
	uint32_t MSP_Value = *((volatile uint32_t*)FLASH_SECTOR2_BASE_ADDRESS);
	uint32_t MainAppAdd = *((volatile uint32_t*)(FLASH_SECTOR2_BASE_ADDRESS+4));

	pMainApp ResetHandler_Address=(pMainApp)MainAppAdd;
	HAL_RCC_DeInit();
	__set_MSP(MSP_Value);
	ResetHandler_Address();
}
