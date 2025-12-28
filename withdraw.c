#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "searchAccount.h"
#include "overwrite.h"
#include "textgenerator.h" re
#define MAX_ACCOUNTS 100

void withdraw(Account accounts[], int *count)
{
    char operation[] = "withdraw";
    Account temp[MAX_ACCOUNTS];
    loadaccounts(temp, MAX_ACCOUNTS, count);
    int found = 0;
    printf("%d\n", *count);
    if (*count == 0)
    {
        printf("No accounts found.\n");
        return;
    }
    long long acc_num;
    float amount;
    printf("Enter account number: ");
    scanf("%lld", &acc_num);
    Account *acc = searchByAccountNumber(temp, *count, acc_num);
    printf("Found count: %d\n", found);

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
    SaveAccountsToFile("accounts.txt", temp, *count);
    report(operation, acc->accountNumber, (int)amount, acc->name);
}
