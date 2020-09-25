#include <stdio.h>
#include "myBank.h"


int main() {

    char typeOfTransaction='0';
    while (typeOfTransaction!='E')
    {
        printf("Transaction type? O-B-D-W-C-I-P-E\n");
       if (scanf(" %c", &typeOfTransaction)==1)
        {
            switch (typeOfTransaction)
            {
                case 'O':
                    openAccount();
                    break;
                case 'B':
                    balance();
                    break;
                case 'D':
                    Deposit();
                    break;
                case 'W':
                    Withdrawal();
                    break;
                case 'C':
                    closeAccount();
                    break;
                case 'I':
                    addInterest();
                    break;
                case 'P':
                    printAccounts();
                    break;
                default:
                    if (typeOfTransaction!='E')
                    {
                        printf("illegal char please try again\n");

                    }

                    else
                        closeAll();
                    break;
            }
        }

    }

    return 0;
}

