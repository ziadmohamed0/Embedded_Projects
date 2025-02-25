/*
 * Server.c
 *
 *  Created on: Apr 30, 2024
 *      Author: ziad
 */

/*********** Section : Includes ***********/
#include "Server.h"

/*********** Section : Global Variables ***********/
ST_accountsDB_t accounts[255];
ST_transaction_t transactions[255] = { 0 };
uint8_t blockedAccounts[255][25];

/*********** Section : Static Functions Decelerations ***********/
static EN_transState_t checkBlockList(ST_CardData_t cardData);
static void updateBalance(ST_accountsDB_t *accountRefrence, int amount);
static void dummyFile(void);
static void dummyValues(void);

/*********** Section : Functions Definitions ***********/
/**
 * @ brief		: function will take all transaction data and valid data
 * 				  verifies the account details and the availability of the amount
 * 				  The database will be updated with the new balance.
 * @ param_1	: transData
 * @ Return		: Ret
 */
EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
	EN_serverError_t Ret = SERVER_OK;
    strcpy(blockedAccounts[0], "1234567890123456790");
    dummyValues();
    dummyFile();

    ST_accountsDB_t *accountRefrence;

    if(checkBlockList(transData->cardHolderData) != APPROVED)
    {
        printf("FAILED: DECLINED_STOLEN_CARD");
        Ret =  DECLINED_STOLEN_CARD;
    }
    if(isValidAccount(&transData->cardHolderData, &accountRefrence) != 0)
    {
        printf("FAILED: Account is not valid\n");
        Ret =  ACCOUNT_NOT_FOUND;
    }


    if(isAmountAvailable(&transData->terminalData, accountRefrence) != 0)
    {
        printf("FAILED: LOW_BALANCE\n");
        Ret =  DECLINED_INSUFFECIENT_FUND;
    }
     else
         updateBalance(accountRefrence, transData->terminalData.transAmount);

    return Ret ;
}

/**
 * @ brief		: This function will take the card data and validate whether
 * 				  the account associated with this card exists or not Checks whether
 * 				  PAN exists or not in server database (it searches for PAN card in database).
 * @ param_1	: cardData
 * @ param_1	: accountRefrence
 * @ Return		: Ret
 */
EN_serverError_t isValidAccount(ST_CardData_t *cardData, ST_accountsDB_t **accountRefrence)
{
    for (int i = 0; i < 255; i++){
        if(strcmp(accounts[i].primaryAccountNumber, cardData->primaryAccountName) == 0)
        {

            *accountRefrence = &accounts[i];
            return SERVER_OK;
        }
    }
    return DECLINED_STOLEN_CARD; // ACCOUNT_NOTFOUND

}

/**
 * @ brief		: This function will take the terminal data and verify the validity of this data
 * 				  Checks whether the transaction amount is available or not.
 * @ param_1	: cardData
 * @ param_1	: accountRefrence
 * @ Return		: Ret
 */
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence)
{
	EN_serverError_t Ret = SERVER_OK;
    if (accountRefrence->balance < termData->transAmount)
    {
    	Ret = LOW_BALANCE;
    }

    accountRefrence->balance -= termData->transAmount;

    return Ret;


}

/**
 * @ brief		: This function will store all transaction data in the transaction database
 * 				  transaction is processed in the server, you must Gives a serial number to the transaction,
 * 				  and this number increases once the Check the last serial number in the server to give the new
 * 				  transaction a new serial numberIt saves any type of transaction, whether approved or rejected,
 * 				  mentioning the specific reason for the rejection/transaction status.
 * @ param_1	: transData
 * @ Return		: Ret
 */
EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    dummyFile();

    FILE *transfile;

    transfile = fopen ("/home/ziad/Documents/GDSC_C_Programming_Project/Final_Project/Data_Base/transactions.txt", "a");
     if (transfile == NULL)
     {
         fprintf(stderr, "\nError opened file\n");
         exit (1);
     }

    if(transData->transactionSequenceNumber < 255)
    {

        transactions[transData->transactionSequenceNumber] = *transData;
        transData->transactionSequenceNumber++;

        fwrite (transData, sizeof(struct ST_transaction_t), 1, transfile);
        fprintf(transfile, "\n");
        fclose (transfile);

        return SERVER_OK;
    }
    return SAVING_FAILED;
}

//EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData)
//{
//
//}

/*********** Section : Static Functions Definitions ***********/
static void dummyValues(void)
{
    for (int i = 0; i < 10; i++)
    {
        accounts[i].balance = 1000 + (i * 100);
        sprintf(accounts[i].primaryAccountNumber, "%ld", (1234567890123456789+i));
    }
}

static void dummyFile(void)
{
    FILE *acc;
    acc = fopen ("/home/ziad/Documents/GDSC_C_Programming_Project/Final_Project/Data_Base/accounts.txt", "w");
    //FILL dumb data for accounts

    for (int i = 0; i < 10; i++)
    {
        fprintf(acc, "%f\t", accounts[i].balance);
        fprintf(acc, "%s\n", accounts[i].primaryAccountNumber);
    }

    fclose (acc);
}

static void updateBalance(ST_accountsDB_t *accountRefrence, int amount)
{
    accountRefrence->balance -= amount;
}

static EN_transState_t checkBlockList(ST_CardData_t cardData)
{
	EN_serverError_t Ret = SERVER_OK;
    printf("REACHED\n");
    for (int i = 0; i < 255; i++)
    {
        if(strcmp(blockedAccounts[i], cardData.primaryAccountName) == 0)
        {
        	Ret = DECLINED_STOLEN_CARD;
        }
    }

    return Ret;
}

