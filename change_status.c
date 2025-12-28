#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "search_account.h"
#include "save_data.h"
#include "color.h"

void changeStatus(Account *acc, int count) {
    copyAccountData(tempAccounts, accounts, accountsCount);
    tempAccountsCount = accountsCount;
    Account *found = searchByAccountNumber(tempAccounts, tempAccountsCount);
    if(found == NULL) {
        set_color(COLOR_RED);
        printf("Account not found.\n");
        reset_color();
        return;
    }
    
    set_color(COLOR_YELLOW);
    printf("Current status: %s\n", found->status);
    reset_color();
    set_color(COLOR_CYAN);
    printf("Enter new status (1. active/ 2. inactive): ");
    reset_color();
    int statusChoice;
    scanf("%d", &statusChoice);
    if(statusChoice == 1) {
        strcpy(found->status, "active");
    } else if(statusChoice == 2) {
        strcpy(found->status, "inactive");
    } else {
        set_color(COLOR_RED);
        printf("Invalid choice. Status not changed.\n");
        reset_color();
        return;
    }

    SaveAccountsToFile(tempAccounts, tempAccountsCount);

    //printf("Status changed to %s.\n", found->status);
}