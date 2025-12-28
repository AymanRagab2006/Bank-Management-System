#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "system_structs.h"
#include "search_account.h"
#include "save_data.h"
#include "color.h"


void DeleteByAccountNumber(Account acc[], int *count)
{
    copyAccountData(tempAccounts, accounts, accountsCount);
    tempAccountsCount = accountsCount;

    set_color(COLOR_CYAN);
    printf("Enter account number to delete: ");
    reset_color();
    long long target;
    scanf("%lld", &target);

    int found = 0;
    for (int i = 0; i < tempAccountsCount; i++)
    {
        if (tempAccounts[i].accountNumber == target)
        {
            if (tempAccounts[i].balance != 0)
            {
                set_color(COLOR_RED);
                printf("Cannot delete account with non-zero balance.\n");
                reset_color();
                return;
            }
            
            found = 1;
            for (int j = i; j < tempAccountsCount - 1; j++)
            {
                tempAccounts[j] = tempAccounts[j + 1];
            }
            tempAccountsCount--;
            break;
        }
    }

    if (found)
    {
        set_color(COLOR_GREEN);
        printf("Account deleted successfully.\n");
        reset_color();
        SaveAccountsToFile(tempAccounts, tempAccountsCount);
    }
    else
    {
        set_color(COLOR_RED);
        printf("Account not found.\n");
        reset_color();
    }
}