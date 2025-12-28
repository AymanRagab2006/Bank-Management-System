#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "system_structs.h"
#include "searchAccount.h"
#include "overwrite.h"
#include "textgenerator.h"

void Transer()
{
    float Amount;
    Account acc;
    FILE *f = fopen("accounts.txt", "r");
    if (f == NULL)
    {
        printf("Error : File Not Found");
        return;
    }
    Account *Ac = NULL, *temp = NULL;
    int count = 0;
    int flag = 1;
    while (fscanf(f, "%lld,%49[^,],%49[^,],%f,%11[^,],%d-%d, %9s",
                  &acc.accountNumber,
                  acc.name,
                  acc.email,
                  &acc.balance,
                  acc.mobileNumber,
                  &acc.dateOpened.month,
                  &acc.dateOpened.year,
                  acc.status) == 8)
    {

        temp = realloc(Ac, (count + 1) * sizeof(Account));
        if (temp == NULL)
        {
            printf("Memory Error.");
            free(Ac);
            fclose(f);

            return;
        }
        else
        {
            Ac = temp;
            Ac[count++] = acc;
        }
    }

    fclose(f);
    long long AccountNumber1, AccountNumber2;
    printf("Please Enter The First Account Number : ");
    scanf("%lld", &AccountNumber1);
    printf("Please Enter The Second Account Number : ");
    scanf("%lld", &AccountNumber2);
    Account *P = searchByAccountNumber(Ac, count, AccountNumber1); // sender
    Account *A = searchByAccountNumber(Ac, count, AccountNumber2); // receiver
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
    if (!flag)
    {
        free(Ac);
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
    SaveAccountsToFile("accounts.txt", Ac, count);
    if (1)
    {
        char operation[] = "recieved";
        report(operation, A->accountNumber, (int)Amount, P->name);
    }
    if (1)
    {
        char operation[] = "transfer";
        report(operation, P->accountNumber, (int)Amount, A->name);
    }
    free(Ac);
}

