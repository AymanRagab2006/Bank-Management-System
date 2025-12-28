#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "system_structs.h"
#include "search_account.h"
#include "save_data.h"
#include "textgenerator.h"

void Transfer()
{
    copyAccountData(tempAccounts, accounts, accountsCount);
    tempAccountsCount = accountsCount;
    
    int flag = 1;
    float Amount;
    long long AccountNumber1, AccountNumber2;
    /*printf("Please Enter The Sender Account Number : ");
    scanf("%lld", &AccountNumber1);
    printf("Please Enter The Receiver Account Number : ");
    scanf("%lld", &AccountNumber2);*/
    Account *P = searchByAccountNumber(tempAccounts, tempAccountsCount); // sender
    Account *A = searchByAccountNumber(tempAccounts, tempAccountsCount); // receiver
    if (P == NULL)
    {
        printf("Error Messege:Sender Acount Not Founded.\n");
        flag = 0;
    }
    if (A == NULL)
    {
        printf("Error Messege:Receiver Acount Not Founded.\n");
        flag = 0;
    }
    if (flag == 0)
    {
        return;
    }
    else
    {

        if (strcmp(P->status, "active") == 0)
        {
            if (strcmp(A->status, "active") == 0)
            {
                printf("Please enter the amount to be transferred : ");
                scanf("%f", &Amount);
                if (Amount > 0 && P->balance > Amount || P->balance == Amount)
                {
                    P->balance = P->balance - Amount;
                    A->balance = A->balance + Amount;
                }
                else
                {
                    printf("The sender does not have enough money .\n");
                    return;
                }
            }
            else if (strcmp(A->status, "inactive") == 0)
            {
                printf("Error:receiver Account Is Inactive.");
                return;
            }
        }
        else if (strcmp(P->status, "inactive") == 0)
        {
            printf("Error:sender Account Is Inactive.");
            return;
        }
    }
    SaveAccountsToFile(tempAccounts, tempAccountsCount);
    char operation[] = "recieved";
    report(operation, A->accountNumber, Amount, P->name);
    char operation2[] = "transfer";
    report(operation2, P->accountNumber, Amount, A->name);
    
}