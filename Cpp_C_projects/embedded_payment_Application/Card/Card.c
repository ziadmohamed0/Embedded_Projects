/*
 * Card.c
 *
 *  Created on: Apr 30, 2024
 *      Author: ziad
 */

#ifndef CARD_CARD_C_
#define CARD_CARD_C_

/*********** Section : Includes ***********/
#include "Card.h"

/*********** Section : Static Functions Prototypes ***********/

/**
 * @ brief		: function return the length of string as a number.
 * @ param_1	: str
 * @ Return		: length
 */
static uint8_t string_length(const uint8_t *str);

/*********** Section : Functions Definitions ***********/

/**
 * @ brief		: function will ask for card holder name and store it into card data.
 * @ param_1	: cardData
 * @ Return		: Ret
 */
uint8_t	EN_cardError_tgetCardHolderName(ST_CardData_t *cardData)
{
	EN_cardError_t Ret = CARD_OK;
	uint8_t Length = Zero_Init;
	printf("================================================\n");
	printf("=> Enter Your Card Holder Name : \n");
	printf("* Note : Max Character is 24 & Min Character 20\n");
	gets(&(cardData->cardHolderName));

	Length = string_length(&(cardData->cardHolderName));

	if((Length > MAX_HolderName) || (Length < MIN_HolderName) || (*(cardData->cardHolderName) == NULL))
	{
		Ret = WRONG_NAME;
	}
	else
	{
		Ret = CARD_OK;
	}
	return Ret;
}

/**
 * @ brief		: Function will ask for the card expiry date and store it in card data.
 * @ param_1	: cardData
 * @ Return		: Ret
 */
uint8_t	EN_cardError_tgetCardExpiryDate(ST_CardData_t *cardData)
{
	EN_cardError_t Ret = CARD_OK;
	uint8_t Length = Zero_Init;
	printf("================================================\n");
	printf("=> Enter Your Expiration Date : \n");
	printf("* NOTE : Format like this -> MM/YY <=\n");
	scanf("%s",(&(cardData->cardExpirationDate)));

	Length = string_length(&(cardData->cardExpirationDate));

	if((*(cardData->cardExpirationDate) == NULL) || (Length != MAX_Expiry_Date))
	{
		Ret = WRONG_EXP_DATE;
	}
	else
	{
		Ret = CARD_OK;
	}

	return Ret;
}

/**
 * @ brief		: function will ask for card's primary account number and store it in card data.
 * @ param_1	: cardData
 * @ Return		: Ret
 */
uint8_t	EN_cardError_tgetCardHolderPan(ST_CardData_t *cardData)
{
	EN_cardError_t Ret = CARD_OK;
	uint8_t Length = Zero_Init;
	printf("================================================\n");
	printf("=> Enter Your Primary Account Name (PAN) : \n");
	printf("* Note : Max Character is 19 & Min Character 16\n");
	scanf("%s",(&(cardData->primaryAccountName)));

	Length = string_length(&(cardData->primaryAccountName));

	if((*(cardData->primaryAccountName) == NULL) || (Length > MAX_PAN) || (Length < MIN_PAN))
	{
		Ret = WRONG_PAN;
	}
	else
	{
		Ret = CARD_OK;
	}
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

#endif /* CARD_CARD_C_ */
