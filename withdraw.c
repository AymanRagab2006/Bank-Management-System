
#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "search_account.h"
#include "save_data.h"
#include "textgenerator.h"

void withdraw(Account accounts[], int count)
{
    char operation[] = "withdraw";
    Account temp[MAX_ACCOUNTS];
    copyAccountData(tempAccounts, accounts, accountsCount);
    tempAccountsCount = accountsCount;
    
    float amount;
    
    Account *acc = searchByAccountNumber(tempAccounts, tempAccountsCount);

    if (!acc)
    {
        printf("Account not found.\n");
        return;
    }

    if (strcmp(acc->status, "active") != 0)
    {
        printf("WARNING: Account is not active.\n");
        return;
    }

    printf("Enter amount to withdraw(10000): ");
    scanf("%f", &amount);
    if (amount > acc->balance)
    {
        printf("Insufficient balance.\n");
        return;
    }

    if (amount <= 0 || amount > 10000)
    {
        printf("Invalid amount or exceeds limit.\n");
        return;
    }
    acc->balance -= amount;
    printf("Withdraw successful. New balance: %.2f\n", acc->balance);
    SaveAccountsToFile(tempAccounts, tempAccountsCount);
    report(operation, acc->accountNumber, amount, acc->name);
}
