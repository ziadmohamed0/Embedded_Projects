/*
 * Server.c
 *
 *  Created on: Apr 30, 2024
 *      Author: ziad
 */

#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

/*********** Section : Includes ***********/
#include  "../Lib/Includes.h"
#include  "../Lib/Std_Type.h"
#include "../Terminal/Terminal.h"



/*********** Section : Enum ***********/

typedef enum EN_transState_t
{
	APPROVED,
	DECLINED_INSUFFECIENT_FUND,
	DECLINED_STOLEN_CARD,
	FRAUD_CARD,
	INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef enum EN_serverError_t
{
	SERVER_OK,
	SAVING_FAILED,
	TRANSACTION_NOT_FOUND,
	ACCOUNT_NOT_FOUND,
	LOW_BALANCE,
	BLOCKED_ACCOUNT
}EN_serverError_t;

typedef enum EN_accountStatus_t
{
	RUNNING,
	BLOCKED
}EN_accountStatus_t;

/*********** Section : Struct ***********/
typedef struct ST_transaction_t
{
	ST_CardData_t		cardHolderData;
	ST_terminalData_t	terminalData;
	EN_transState_t		transState;
	uint32_t			transactionSequenceNumber;
}ST_transaction_t;

typedef struct ST_accountsDB_t
{
	float32_t			balance;
	EN_accountStatus_t	state;
	uint8_t				primaryAccountNumber[20];
}ST_accountsDB_t;

/*********** Section : Functions Prototypes ***********/
/**
 * @ brief		: function will take all transaction data and valid data
 * 				  verifies the account details and the availability of the amount
 * 				  The database will be updated with the new balance.
 * @ param_1	: transData
 * @ Return		: Ret
 */
EN_transState_t recieveTransactionData(ST_transaction_t *transData);

/**
 * @ brief		: This function will take the card data and validate whether
 * 				  the account associated with this card exists or not Checks whether
 * 				  PAN exists or not in server database (it searches for PAN card in database).
 * @ param_1	: cardData
 * @ param_1	: accountRefrence
 * @ Return		: Ret
 */
EN_serverError_t isValidAccount(ST_CardData_t *cardData, ST_accountsDB_t **accountRefrence);

/**
 * @ brief		: This function will take the terminal data and verify the validity of this data
 * 				  Checks whether the transaction amount is available or not.
 * @ param_1	: cardData
 * @ param_1	: accountRefrence
 * @ Return		: Ret
 */
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence);

/**
 * @ brief		: This function will store all transaction data in the transaction database
 * 				  transaction is processed in the server, you must Gives a serial number to the transaction,
 * 				  and this number increases once the Check the last serial number in the server to give the new
 * 				  transaction a new serial numberIt saves any type of transaction, whether approved or rejected,
 * 				  mentioning the specific reason for the rejection/transaction status.
 * @ param_1	: transData
 * @ Return		: Ret
 */
EN_serverError_t saveTransaction(ST_transaction_t *transData);

/**
 * @ brief		: This function takes the transaction serial number and returns the transaction data if found
 * 				   in the transaction database.
 * @ param_1	: cardData
 * @ param_1	: accountRefrence
 * @ Return		: Ret
 */
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData);

#endif /* SERVER_SERVER_C_ */
