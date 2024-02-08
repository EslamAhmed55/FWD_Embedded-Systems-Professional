//Server.c
//Server.c
//please check folder "notification"
#include "Server.h"
#include<time.h>
extern uint8_t check;

float trans_state=0;
ST_accountsDB_t* Arrow;

int x;
ST_accountsDB_t DataBase_arr[255] = { {14548.3, RUNNING, "789456123123456798"},
                                {151522, RUNNING, "456123789456123789"},
                                {1659.5, RUNNING, "123798456123465987"},
                                {2000, RUNNING, "321654987456132798"},
                                {491212, RUNNING, "654789123654987321"},
                                {20215, RUNNING, "648971248962468452"},
                                {1598742, BLOCKED, "654987123456798732"},
                                {11100, BLOCKED, "321546789513654897"},
                                {45555, BLOCKED, "136871323216548751"},
                                {785412, BLOCKED, "645854132168787654"} };

ST_transaction_t ArrOfTrans[256] = { 0 };

uint32_t seqaunce_number = 1;


EN_transStat_t state;



EN_transStat_t recieveTransactionData(ST_transaction_t* transData) {




    if (isValidAccount(transData->cardHolderData, &Arrow)) {
        printf("FRAUD_CARD\n");
        state = FRAUD_CARD;
        return FRAUD_CARD;
    }

    if (isBlockedAccount(Arrow)) {
        printf("DECLINED_STOLEN_CARD\n");
        state = DECLINED_STOLEN_CARD;
        return DECLINED_STOLEN_CARD;
    }
    if (isAmountAvailable(&transData->terminalData)) {
        printf("DECLINED_INSUFFECIENT_FUND\n");
        state = DECLINED_INSUFFECIENT_FUND;
        return DECLINED_INSUFFECIENT_FUND;
    }


   Arrow->balance -= transData->terminalData.transAmount;
   trans_state= Arrow->balance;
    state = APPROVED;
    printf("Transaction is successful!\n");

    return APPROVED;
}

EN_serverError_t isValidAccount(ST_cardData_t cardData, ST_accountsDB_t** accountArrowrence) {
    if (!check) {
        uint8_t Ac_in_DB = 0;


        int i = 0;
        for (; i < 10; i++) {
            if (strcmp(cardData.primaryAccountNumber, DataBase_arr[i].primaryAccountNumber) == 0) {

                *accountArrowrence = &DataBase_arr[i];
                Ac_in_DB = 1;
                x=i;

            }
        }

        if (Ac_in_DB) {
            return SERVER_OK;
        }
        else {
            printf("ACCOUNT_NOT_FOUND\n");
            check = 1;
            return ACCOUNT_NOT_FOUND;
        }
    }
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountArrowrence) {
    if (!check) {
        if (Arrow->state == BLOCKED) {
            check = 1;
            printf("BLOCKED_ACCOUNT\n");
            return BLOCKED_ACCOUNT;
        }
        else {
            return SERVER_OK;
        }
    }
}


EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
    if (!check) {
        if (termData->transAmount > Arrow->balance) {
            check = 1;
            printf("LOW_BALANCE\n");
            return LOW_BALANCE;
        }
        else {
            return SERVER_OK;
        }
    }
}


EN_serverError_t saveTransaction(ST_transaction_t* transData) {

    transData->transState = state;

    transData->transactionSequenceNumber = seqaunce_number;

    ArrOfTrans[seqaunce_number] = *transData;

    seqaunce_number++;


    getTransaction(transData->transactionSequenceNumber, transData);


}


EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData  ) {
    if (ArrOfTrans[transactionSequenceNumber].transactionSequenceNumber == 0) {
        printf("TRANSACTION_NOT_FOUND\n");
        return TRANSACTION_NOT_FOUND;
    }
    //else {
           // printf("the transaction seqauntion number is%f \n ",(&DataBase_arr[transactionSequenceNumber])+1);
            /*
    float current_mony;
    current_mony=DataBase_arr[seqaunce_number].balance- current_amount.transAmount;
    printf(" your current balance is /n %f",mony);
        return SERVER_OK;
    }
    */
//}
}
/*
float balance_avilable(ST_accountsDB_t ** accountArrowrence ,ST_terminalData_t data)
{
    float mony;
    mony= DataBase_arr[seqaunce_number].balance-data.transAmount;
    return mony;

}

*/

void listSavedTransactionsTest()
{
    if(!check)
    {

        printf("Transaction Sequence Number: %d \n",x+1);

         time_t t = time(NULL);
    struct tm tm = *localtime(&t);



    printf("Transaction State: %f \n",trans_state);


   printf("Transaction Date And Time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);



}
}
