/*
 * USART_prog.c
 *
 *  Created on: Dec 6, 2024
 *      Author: s
 */

#include "USART_init.h"

void UART_vidInit(){
	 UBRRL = baud_rate_select ;                   /* Set baud rate */

  #if    (Mode_Select == Synchronous_Operation)
         SET_BIT(UCSRC,UMSEL);
  #elif  (Mode_Select == Asynchronous_Operation)
         CLR_BIT(UCSRC,UMSEL);
  #endif

	#if   (Parity_Mode==Even_Parity)
	      SET_BIT(UCSRC,UPM1);
	#elif (Parity_Mode==Odd_Parity )
	      SET_BIT(UCSRC,UPM1);
		  SET_BIT(UCSRC,UPM0);
   #endif
   #if   (Stop_Bit_Select==_2_bit)
         SET_BIT(UCSRC,USBS);
  #elif  (Stop_Bit_Select==_1_bit)
         CLR_BIT(UCSRC,USBS);
   #endif

   #if (Data_bits==_5_bit)             //number of data bits
         CLR_BIT(UCSRC,UCSZ0);
       CLR_BIT(UCSRC,UCSZ1);
       CLR_BIT(UCSRC,UCSZ2);
  #elif 	(Data_bits==_6_bit)
      SET_BIT(UCSRC,UCSZ0);
      CLR_BIT(UCSRC,UCSZ1);
      CLR_BIT(UCSRC,UCSZ2);
  #elif 	(Data_bits==_7_bit)
      CLR_BIT(UCSRC,UCSZ0);
     SET_BIT(UCSRC,UCSZ1);
     CLR_BIT(UCSRC,UCSZ2);
	 #elif 	(Data_bits==_8_bit)
	 SET_BIT(UCSRC,UCSZ0);
	 SET_BIT(UCSRC,UCSZ1);
	 CLR_BIT(UCSRC,UCSZ2);
	  #elif 	(Data_bits==_9_bit)
	  SET_BIT(UCSRC,UCSZ0);
	  SET_BIT(UCSRC,UCSZ1);
	  SET_BIT(UCSRC,UCSZ2);
   #endif
	 SET_BIT(UCSRB,TXEN);
	 SET_BIT(UCSRB,RXEN);
 }


uint8 UART_u8RecevieData(){
	 while(GET_BIT(UCSRA,RXC) == 0);	    /* Wait for data to be received */
	 return UDR;                      // why ?? /* Get and return received data from buffer */
 }
 void UART_vidSendData(uint8 u8DataCopy){
	 while(GET_BIT(UCSRA,UDRE) == 0);  /* Wait for empty transmit buffer */
	 UDR = u8DataCopy;       /* Put data into buffer, sends the data */
 }
