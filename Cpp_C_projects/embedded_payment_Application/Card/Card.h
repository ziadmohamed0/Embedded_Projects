/*
 * Card.h
 *
 *  Created on: Apr 30, 2024
 *      Author: ziad
 */

#ifndef CARD_CARD_H_
#define CARD_CARD_H_

/*********** Section : Includes ***********/
#include  "../Lib/Includes.h"
#include  "../Lib/Std_Type.h"

/*********** Section : Macros ***********/
#define MAX_HolderName	24
#define MIN_HolderName	20

#define MAX_Expiry_Date	5

#define MAX_PAN			19
#define MIN_PAN			16
/*********** Section : Struct ***********/
typedef struct ST_CardData_t
{
	uint8_t	cardHolderName[25];
	uint8_t primaryAccountName[25];
	uint8_t cardExpirationDate[6];
}ST_CardData_t;

/*********** Section : Enum ***********/
typedef enum EN_cardError_t
{
	CARD_OK,
	WRONG_NAME,
	WRONG_EXP_DATE,
	WRONG_PAN
}EN_cardError_t;

/*********** Section : Functions Prototypes ***********/
/**
 * @ brief		: function will ask for card holder name and store it into card data.
 * @ param_1	: cardData
 * @ Return		: Ret
 */
uint8_t	EN_cardError_tgetCardHolderName(ST_CardData_t *cardData);

/**
 * @ brief		: Function will ask for the card expiry date and store it in card data.
 * @ param_1	: cardData
 * @ Return		: Ret
 */
uint8_t	EN_cardError_tgetCardExpiryDate(ST_CardData_t *cardData);

/**
 * @ brief		: function will ask for card's primary account number and store it in card data.
 * @ param_1	: cardData
 * @ Return		: Ret
 */
uint8_t	EN_cardError_tgetCardHolderPan(ST_CardData_t *cardData);


#endif /* CARD_CARD_H_ */
