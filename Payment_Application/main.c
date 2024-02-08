//main

//please check folder "notification"

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>
#include "time.h"
#include "App/App.h"
int main()
{
    int num_of_transaction = 1;
    char choise;
    while (num_of_transaction) {


        appStart();



        fflush(stdin);

        printf("End of proscess. if you want to continue  \n: ");
        printf("please enter 1 to continue another transaction  or 2 to exist \n");
        scanf("%c", &choise);
        if (choise == '1') {
            num_of_transaction = 1;
            fflush(stdin);
        }
        else if (choise == '2') {
            num_of_transaction = 0;
        }
    }

    return 0;
}
