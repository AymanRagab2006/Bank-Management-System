#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "search_account.h"
#include "save_data.h"
#include "textgenerator.h"

#include <time.h>
#include <string.h>
#include <stdio.h>

#define DAILY_WITHDRAW_LIMIT 50000.0f

float getDailyWithdrawTotal(long long account_number)
{
    char filename[100];
    sprintf(filename, "%lld.txt", account_number);

    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        return 0.0f;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char today[11];
    strftime(today, sizeof(today), "%Y-%m-%d", t);

    float total = 0.0f;
    char line[256];

    while (fgets(line, sizeof(line), fp))
    {
        // Check if line contains a withdraw operation from today
        if (strstr(line, "Operation: withdraw") != NULL && strstr(line, today) != NULL)
        {
            // Extract the amount
            char *amountPtr = strstr(line, "amount:");
            if (amountPtr)
            {
                float amount;
                if (sscanf(amountPtr, "amount: %f", &amount) == 1)
                {
                    total += amount;
                }
            }
        }
    }

    fclose(fp);
    return total;
}


void withdraw(Account accounts[], int count)
{
    char operation[] = "withdraw";
    copyAccountData(tempAccounts, accounts, accountsCount);
    tempAccountsCount = accountsCount;

    float amount;
    int stop = 0;

    Account *acc = searchByAccountNumber(tempAccounts, tempAccountsCount);

    if (!acc)
    {
        stop=1;
        printf("Account not found.\n");
        return;
    }

    if (strcmp(acc->status, "active") != 0)
    {
        printf("WARNING: Account is not active.\n");
        return;
    }

    float todayTotal = getDailyWithdrawTotal(acc->accountNumber);
    float remainingLimit = DAILY_WITHDRAW_LIMIT - todayTotal;

    printf("Today's withdrawals: %.2f | Remaining daily limit: %.2f\n", 
           todayTotal, remainingLimit);

    if (remainingLimit <= 0)
    {
        printf("Daily withdrawal limit (%.2f) already reached.\n", DAILY_WITHDRAW_LIMIT);
        return;
    }

    printf("Enter amount to withdraw (max 10000 per transaction): ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > 10000)
    {
        printf("Invalid amount or exceeds per-transaction limit.\n");
        stop=1;
        return;
    }

    if (amount > acc->balance)
    {
        printf("Insufficient balance.\n");
        stop=1;
        return;
    }

    if (todayTotal + amount > DAILY_WITHDRAW_LIMIT)
    {
        printf("This withdrawal would exceed daily limit.\n");
        printf("Maximum you can withdraw now: %.2f\n", remainingLimit);
        return;
    }

    acc->balance -= amount;
    printf("Withdraw successful. New balance: %.2f\n", acc->balance);


if (!stop) {
        char choice;
        printf("Confirm withdraw? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            printf("Withdraw cancelled.\n");
            stop = 1;
        }
    }

    if (!stop) {
        acc->balance -= amount;
        SaveAccountsToFile(tempAccounts, tempAccountsCount);
        report(operation, acc->accountNumber, amount, acc->name);
        printf("Withdraw successful. New balance: %.2f\n", acc->balance);
    }

}