/*
 * Terminal.c
 *
 *  Created on: Apr 30, 2024
 *      Author: ziad
 */

/*********** Section : Includes ***********/
#include "Terminal.h"

/*********** Section : Static Functions Prototypes ***********/
/**
 * @ brief		: function return the length of string as a number.
 * @ param_1	: str
 * @ Return		: length
 */
static uint8_t string_length(const uint8_t *str);

/*********** Section : Functions Definitions ***********/

/**
 * @ brief		: function will ask for the transaction data and store it in terminal data.
 * @ param_1	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tgetTransactionDate(ST_terminalData_t *termData)
{
	EN_terminalError_t Ret = TERMINAL_OK;
	uint8_t Length = Zero_Init;
	printf("================================================\n");
	printf("=> Enter Transaction Date : \n");
	printf("=> * NOTE : Format like this -> DD/MM/YYYY <=\n");
	scanf("%s",(&(termData->transactionDate)));

	Length = string_length(&(termData->transactionDate));

	if((termData == NULL) || (Length < MIN_Transaction))
	{
		Ret = WRONG_DATE;
	}
	else
	{
		Ret = TERMINAL_OK;
	}

	return Ret;
}

/**
 * @ brief		:  function will compares the card expiry date with transaction data.
 * @ param_1	: cardData
 * @ param_2	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tisCardExpired(ST_CardData_t *cardData , ST_terminalData_t *termData)
{
	EN_terminalError_t Ret = TERMINAL_OK;
	int num1;
	int num2;

	num1 = ( cardData->cardExpirationDate[3] - '0' ) * 10;
	num1 += cardData->cardExpirationDate[4] - '0';

	num2 = ( termData->transactionDate[8] - '0' ) * 10;
	num2 += termData->transactionDate[9] - '0';

	if(num1 < num2)
		Ret = EXPIRED_CARD;
	else if(num1 == num2)
	{
	    num1 = ( cardData->cardExpirationDate[0] - '0' ) * 10;
	    num1 += cardData->cardExpirationDate[1] - '0';

	    num2 = ( termData->transactionDate[3] - '0' ) * 10;
	    num2 += termData->transactionDate[4] - '0';

	    if(num1 < num2)
	    	Ret = EXPIRED_CARD;
	}

	return Ret;
}

/**
 * @ brief		: function will ask for the transaction amount and save it into terminal data.
 * @ param_1	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tgetTransactionAmount(ST_terminalData_t *termData)
{
	EN_terminalError_t Ret = TERMINAL_OK;

	uint8_t Length = Zero_Init;

	printf("================================================\n");
	printf("=> Enter Transaction Amount : \n");
	scanf("%f",(&(termData->transAmount)));

	if(termData->transAmount <= 0)
	{
		Ret = WRONG_DATE;
	}
	else
	{
		Ret = TERMINAL_OK;
	}
	return Ret;
}

/**
 * @ brief		: function will compares the transaction amount with the terminal data.
 * @ param_1	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tisBelowMaxAmount(ST_terminalData_t *termData)
{
	EN_terminalError_t Ret = TERMINAL_OK;


	if((termData->transAmount > termData->maxtransAmount) || (termData->transAmount <= 0))
	{
		Ret = EXCEED_MAX_AMOUNT;
	}
	else
	{
		Ret = TERMINAL_OK;
	}
	return Ret;
}

/**
 * @ brief		: function sets the maximum allowed amount into terminal data.
 * @ param_1	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tsetMaxAmount(ST_terminalData_t *termData)
{
	EN_terminalError_t Ret = TERMINAL_OK;
	printf("================================================\n");
	printf("=> Enter Max Amount : \n");
	scanf("%f",(&(termData->maxtransAmount)));

	if((termData->maxtransAmount <= 0))
	{
		Ret = INVALID_MAX_AMOUNT;
	}
	else
	{
		Ret = TERMINAL_OK;
	}
	return Ret;
}


/**
 * @ brief		: function will compares the PAN Card with the Pan terminal data.
 * @ param_1	: cardData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tisValidCardPAN(ST_CardData_t *cardData)
{
	EN_cardError_t Ret = CARD_OK;

	return Ret;
}
/*********** Section : Static Functions Definitions ***********/
/**
 * @ brief		: function return the length of string as a number.
 * @ param_1	: str
 * @ Return		: length
 */
static uint8_t string_length(const uint8_t *str)
{
	uint8_t length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
