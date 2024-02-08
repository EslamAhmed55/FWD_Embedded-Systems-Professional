//Card.c
//please check folder "notification"

#include "Card.h"
extern uint8_t check;


EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
    uint8_t read[25];
    printf("Enter card holder name [20-24]: ");


    gets(read);


    uint8_t count = 0, read_char = 0;


    while (read[read_char] != '\0') {
        if (read[read_char] != ' ') {
            if ((read[read_char] >= 'a' && read[read_char] <= 'z') || (read[read_char] >= 'A' && read[read_char] <= 'Z')) {
                count++;
            }
        }
        read_char++;
    }

    if (count < 20 || count > 24) {
        printf("WRONG_NAME\n");

        check = 1;
        return WRONG_NAME;

    }
    else {

        int i = 0;
        for ( ;i < count; i++) {
            cardData->cardHolderName[i] = read[i];
        }
        printf("\n");
        return CARD_OK;
    }


}

/*
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
    //For the following functions, there will be a safe check to see if the program should check or not.
    if (!check) {
        uint8_t in[6];
        printf("Enter card expiry date [MM/YY]: ");
        scanf_s("%s", in);
        uint8_t c = 0;
        uint8_t flag = 1;

        for (int i = 0; i < 6; i++) {
            //Counting the '\0' as read_char is supposed to be 1 to meet the requirement. one '\0' means there are exactly 5 characters.
            if (in[i] == '\0') {
                c++;
            }

            //Checks that all the input are numbers, except for th '/'.
            if ((in[i] < '0' || in[i] > '9') && i != 2 && i != 5) {
                flag = 0;
            }
        }

        if (c != 1 || flag != 1) {
            printf("WRONG_EXP_DATE\n");
            check = 1;
            return WRONG_EXP_DATE;
        }
        else {

            //Checks that the input is a valid date (month <=12)
            if ((in[0] - '0') * 10 + (in[1] - '0') <= 12 && in[2] == '/') {
                //Fill expiry date into card data
                for (int i = 0; i < 6; i++) {
                    cardData->cardExpirationDate[i] = in[i];
                }
                printf("\n");
                return CARD_OK;
            }
            else {
                printf("WRONG_EXP_DATE\n");
                check = 1;
                return WRONG_EXP_DATE;
            }
        }
    }
}

*/



EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    printf("please Enter The Card Expiry Data as This Format [MM/YY] Such As [05/25] ");
    fflush(stdin);
    gets(cardData->cardExpirationDate);
    if (strlen(cardData->cardExpirationDate) == 0 && strlen(cardData->cardExpirationDate) > 5 && strlen(cardData->cardExpirationDate) < 5)
    {
        return WRONG_EXP_DATE;
        check = 1;
    }
    else
    {
        if(cardData->cardExpirationDate[2]=='/'&&((cardData->cardExpirationDate[0] - '0') * 10 + (cardData->cardExpirationDate[1] - '0') <= 12 ))
        return CARD_OK;
        else
        {
            check = 1;
            printf("please enter expiry data such as a format");
            return WRONG_EXP_DATE;
        }


    }



}




EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
    if (!check) {
        uint8_t read[20];
        printf("Enter PAN [16-20]: ");
        scanf("%s", read, 20);
        uint8_t count = 0;
        uint8_t check_number = 1;


        while (read[count] != '\0') {
            if (read[count] > '9' || read[count] < '0') {
                check_number = 0;
            }
            count++;
        }


        if (count < 16 || count > 20 || check_number == 0) {
            printf("WRONG_PAN\n");
            check = 1;
            return WRONG_PAN;
        }
        else {

            int i = 0;
            for ( ;i < count; i++) {
                cardData->primaryAccountNumber[i] = read[i];
            }
            printf("\n");
            return CARD_OK;
        }
    }
}
