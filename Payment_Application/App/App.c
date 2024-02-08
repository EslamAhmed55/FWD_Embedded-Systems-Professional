//App.c
//App.c
//please check folder "notification"
#include "App.h"
#include<time.h>

uint8_t check = 0;


ST_cardData_t Data_Card;
ST_terminalData_t terminal_Data;
ST_transaction_t Transaction_Data;



void appStart(void) {

    if (getCardHolderName(&Data_Card)==WRONG_NAME)
    {
        printf("invalid name \n");
        check=1;
    }
    else{
    getCardExpiryDate(&Data_Card);


    getCardPAN(&Data_Card);


    getTransactionDate(&terminal_Data);
    isCardExpired(Data_Card, terminal_Data);
    getTransactionAmount(&terminal_Data);
    setMaxAmount(&terminal_Data);
    isBelowMaxAmount(&terminal_Data);


    Transaction_Data.cardHolderData = Data_Card;
    Transaction_Data.terminalData = terminal_Data;


    recieveTransactionData(&Transaction_Data);
    saveTransaction(&Transaction_Data);
    listSavedTransactionsTest();



    check = 0;
}

}
