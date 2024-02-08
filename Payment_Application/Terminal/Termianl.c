//Terminal.c
//Terminal.c
//please check folder "notification"
#include<time.h>
#include "Terminal.h"

extern uint8_t check;

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
    if (!check) {
        time_t t;
        t = time(NULL);
        struct tm now= *localtime( &t);
        uint32_t dy, mn, yy;
        dy = now.tm_mday;
        mn = now.tm_mon + 1;
        yy = now.tm_year + 1900;

        termData->transactionDate[0] = dy / 10 + 48;
        termData->transactionDate[1] = dy % 10 + 48;

        termData->transactionDate[2] = 47;

        termData->transactionDate[3] = mn / 10 + 48;
        termData->transactionDate[4] = mn % 10 + 48;

        termData->transactionDate[5] = 47;

        termData->transactionDate[6] = yy / 1000 + 48;
        termData->transactionDate[7] = (yy / 100) % 10 + 48;
        termData->transactionDate[8] = (yy / 10) % 10 + 48;
        termData->transactionDate[9] = yy % 10 + 48;

        termData->transactionDate[10] = '\0';
        return TERMINAL_OK;
    }
}


/*

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
    if (!check)
    {
        printf("Please Enter The Transaction date [it must contains 10 digits with this format DD/MM/YY]");
        fflush(stdin);
        gets(termData->transactionDate);

        if (strlen(termData->transactionDate) == 0 || strlen(termData->transactionDate) < 10 || termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/')

        {
            return WRONG_DATE;
            check = 1;
        }
        else
        {

            return TERMINAL_OK;

        }
    }

}

*/
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
    if (!check) {
        uint8_t Expiry_year = (cardData.cardExpirationDate[3] - '0') * 10 + (cardData.cardExpirationDate[4] - '0');
        uint8_t Trans_year = (termData.transactionDate[8] - '0') * 10 + (termData.transactionDate[9] - '0');

        uint8_t Expiry_month = (cardData.cardExpirationDate[0] - '0') * 10 + (cardData.cardExpirationDate[1] - '0');
        uint8_t Trans_month = (termData.transactionDate[3] - '0') * 10 + (termData.transactionDate[4] - '0');

        if (Expiry_year < Trans_year) {
            printf("EXPIRED_CARD\n");
            check = 1;
            return EXPIRED_CARD;
        }
        else if (Expiry_year == Trans_year) {
            if (Expiry_month < Trans_month) {
                printf("EXPIRED_CARD\n");
                check = 1;
                return EXPIRED_CARD;
            }
            else {
                return TERMINAL_OK;
            }
        }
        else {
            return TERMINAL_OK;
        }
    }
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
    if (!check) {
        float read;
        printf("Enter transaction amount [>0]: ");
        scanf("%f", &read);


        if (read <= 0) {
            printf("INVALID_AMOUNT");
            check = 1;
            return INVALID_AMOUNT;
        }
        else {
            printf("\n");
            termData->transAmount = read;
            return TERMINAL_OK;
        }
    }
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
    if (!check) {
        float read;
        printf("Enter Max amount: ");
        scanf("%f", &read);


        if (read <= 0) {
            printf("INVALID_MAX_AMOUNT");
            check = 1;
            return INVALID_MAX_AMOUNT;
        }
        else {
            printf("\n");
            termData->maxTransAmount =read;
            return TERMINAL_OK;
        }
    }
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
    if (!check) {
        if (termData->transAmount > termData->maxTransAmount) {
            printf("EXCEED_MAX_AMOUNT");
            check = 1;
            return EXCEED_MAX_AMOUNT;
        }
        else {
            printf("\n");
            return TERMINAL_OK;
        }
    }
}
