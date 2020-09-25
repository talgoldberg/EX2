#include <stdio.h>
#include "myBank.h"
#define maxAccounts 50
#define FirstNumAccount 901

double arr[maxAccounts][2]={0};
double money=0;
int counterAccounts=0;
int indexMyAccountNum=0;
int myAccountNum=0;


void openAccount()

{
    if (counterAccounts==maxAccounts)
    {
        printf("Sorry, we have too much accounts\n");
    }
    int flag=0;
    for (int i = 0; (i < maxAccounts)&&(flag==0); ++i)
    {
            if (arr[i][0]==0)
            {
                printf("Initial deposit?\n");
                if(scanf("%lf",&money)==1)
                {
                    if(money<=0)
                    {
                        printf("sorry you must deposit money\n");
                        i--;
                    }
                    else
                    {
                        money=money*100;
                        money=((int)money);
                        money=money /100;
                        arr[i][1] = money;
                        arr[i][0] = 1;
                        printf("Thanks, your number account is: %d\n", FirstNumAccount+i);
                        flag = 1;
                        counterAccounts++;

                    }
                }
                else
                {
                    printf("Not legal\n");
                    i--;
                    getchar();

                }

            }
    }

    }

void balance()
{

if(openOrClose())
{
    printf("Your balance in your bank account is %.2f\n",arr[indexMyAccountNum][1]);
}
}
void Deposit()
{

    if (openOrClose())
    {
       double newDeposite=0;
       double saveAns=0;
       printf("How much maney do you want to deposite?");
       if(scanf("%lf",&newDeposite)==1)
       {
           saveAns=arr[indexMyAccountNum][1]+newDeposite;
           saveAns=saveAns*100;
           saveAns=((int)saveAns);
           saveAns=saveAns/100;
           arr[indexMyAccountNum][1]=saveAns;
           printf("Your new balance in your bank account is %.2f\n",saveAns);
       }
       else
       {
           printf("this is not a legal account\n");

       }

    }

}

void Withdrawal()
{
    if (openOrClose())
    {
        double amount;
        double saveAns=0;
        printf("How much do you want to Withdrawal?\n");
        if(scanf("%lf",&amount)==1)
        {
            if (amount>arr[indexMyAccountNum][1])
            {
                printf("Sorry but you have not enough money\n");
            }
            else
            {

               saveAns=arr[indexMyAccountNum][1]-amount;
                saveAns=saveAns*100;
                saveAns=((int)saveAns);
                saveAns=saveAns /100;
                arr[indexMyAccountNum][1]=saveAns;
                printf("Done!\n");
            }
        }
        else
        {
            printf("this is not a legal account\n");

        }


    }

}

void closeAccount()
{
    if(openOrClose())
    {
        arr[indexMyAccountNum][0] = 0;
        arr[indexMyAccountNum][1] = 0;
        counterAccounts--;
        printf("Your account %d close now\n", myAccountNum);
    }

}

void addInterest()
{
    double interest;
    double saveAns;
    printf("How much percent of interest do you want to add?\n");
    if(scanf("%lf",&interest)==1)
    {
        for (int i = 0; i < maxAccounts; ++i)
        {
            if(arr[i][0] == 1)
            {
                double calcInterest= (interest/100) * arr[i][1];
                saveAns= arr[i][1] + calcInterest;
                saveAns=saveAns*100;
                saveAns=((int)saveAns);
                saveAns= saveAns/100;
                arr[i][1]=saveAns;
            }
        }
        printf("done!\n");
    }
    else
    {
        printf("this is not a legal account\n");

    }

}

void printAccounts()
{
    printf("The open Accounts:\n");

    for (int i = 0; i < maxAccounts; ++i)
    {
        if (arr[i][0]==1)
        {
            printf("Account number %d\n",i+FirstNumAccount);
            printf("Your balance in your bank account is %.2f\n",arr[i][1]);
        }

    }
}

int openOrClose()
{

    printf("Hello, what is your account number?\n");
    if((scanf("%d",&myAccountNum)==1)&&(myAccountNum>=901)&&(myAccountNum<=950))
    {
            indexMyAccountNum = myAccountNum - FirstNumAccount;
            if (arr[indexMyAccountNum][0] == 1)
            {
                return 1;
            }
        printf("Sorry but account %d is closed\n",myAccountNum);
    }
    else
    {
        printf("this is not a legal account\n");

    }

    return 0;

}

void closeAll()
{
    for (int i = 0; i < maxAccounts; ++i)
    {
        if (arr[i][0] == 1)
        {
            arr[i][0] = 0;
        }

    }
    printf("All the Accounts are closed");
}