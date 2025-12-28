#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "search_account.h"
#include "save_data.h"
#include "deposit.h"
#include "textgenerator.h"

void deposit(Account accounts[], int count)
{
    char operation[] = "deposit";
    Account temp[MAX_ACCOUNTS];
    copyAccountData(tempAccounts, accounts, accountsCount);
    tempAccountsCount = accountsCount;
    
    float amount;
    int stop = 0;
    
    Account *acc = searchByAccountNumber(tempAccounts, tempAccountsCount);
    
    if (!acc)
    {
        printf("Account not found.\n");
        stop=1;
        return;
    }

    if (strcmp(acc->status, "active") != 0)
    {
        printf("WARNING: Account is not active.\n");
        stop=1;
        return;
    }

    printf("Enter amount to deposit (max 10000): ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > 10000)
    {
        printf("Invalid amount or exceeds limit.\n");
        stop=1;
        return;
    }
    acc->balance += amount;
    printf("Deposit successful. New balance: %.2f\n", acc->balance);

    if (!stop) {
        char choice;
        printf("Confirm deposit? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            printf("Deposit cancelled.\n");
            stop = 1;
        }
    }

    if (!stop) {
        acc->balance += amount;
        SaveAccountsToFile(tempAccounts, tempAccountsCount);
        report(operation, acc->accountNumber, amount, acc->name);
        printf("Deposit successful. New balance: %.2f\n", acc->balance);
    }
}