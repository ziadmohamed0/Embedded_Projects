/*
 * Terminal.h
 *
 *  Created on: Apr 30, 2024
 *      Author: ziad
 */

#ifndef TERMINAL_TERMINAL_H_
#define TERMINAL_TERMINAL_H_

/*********** Section : Includes ***********/
#include  "../Lib/Includes.h"
#include  "../Lib/Std_Type.h"
#include "../Card/Card.h"

/*********** Section : Macros ***********/
#define MIN_Transaction	10

#define MAX_Transaction_Amount	5000.00
/*********** Section : Struct ***********/
typedef struct ST_terminalData_t
{
	float32_t	transAmount;
	float32_t	maxtransAmount;
	uint8_t		transactionDate[11];
}ST_terminalData_t;

/*********** Section : Enums ***********/
typedef enum EN_terminalError_t
{
	TERMINAL_OK,
	WRONG_DATE,
	EXPIRED_CARD,
	INVALID_CARD,
	INVALID_AMOUNT,
	EXCEED_MAX_AMOUNT,
	INVALID_MAX_AMOUNT,
}EN_terminalError_t;

/*********** Section : Functions Prototypes ***********/

/**
 * @ brief		: function will ask for the transaction data and store it in terminal data.
 * @ param_1	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tgetTransactionDate(ST_terminalData_t *termData);

/**
 * @ brief		:  function will compares the card expiry date with transaction data.
 * @ param_1	: cardData
 * @ param_2	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tisCardExpired(ST_CardData_t *cardData , ST_terminalData_t *termData);

/**
 * @ brief		: function will ask for the transaction amount and save it into terminal data.
 * @ param_1	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tgetTransactionAmount(ST_terminalData_t *termData);

/**
 * @ brief		: function will compares the transaction amount with the terminal data.
 * @ param_1	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tisBelowMaxAmount(ST_terminalData_t *termData);

/**
 * @ brief		: function sets the maximum allowed amount into terminal data.
 * @ param_1	: termData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tsetMaxAmount(ST_terminalData_t *termData);

/**
 * @ brief		: function will compares the PAN Card with the Pan terminal data.
 * @ param_1	: cardData
 * @ Return		: Ret
 */
uint8_t	EN_terminalError_tisValidCardPAN(ST_CardData_t *cardData);

#endif /* TERMINAL_TERMINAL_H_ */
