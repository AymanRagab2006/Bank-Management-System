#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "search_account.h"
#include "save_data.h"
#include "color.h"

void modifyAccount(Account accounts[], int *count)
{
    /*Account temp[100];
    long long acc_num;
    int found = 0;
    printf("Enter account number: ");
    scanf("%lld", &acc_num);
    loadaccounts(temp, 100, count);*/

    copyAccountData(tempAccounts, accounts, accountsCount);
    tempAccountsCount = accountsCount;

    Account *acc = searchByAccountNumber(tempAccounts, tempAccountsCount);
    if (!acc)
    {
        set_color(COLOR_RED);
        printf("Account not found.\n");
        reset_color();
        return;
    }
    //printf("Modifying account for user account number: %lld\n", acc_num);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    char newName[50];
    set_color(COLOR_CYAN);
    printf("Enter new account name: ");
    reset_color();
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = 0;
    strncpy(acc->name, newName, sizeof(acc->name) - 1);
    acc->name[sizeof(acc->name) - 1] = '\0';
    //printf("Account name updated successfully.\n");

    set_color(COLOR_CYAN);
    printf("Enter a new Email: ");
    reset_color();
    char newEmail[50];
    scanf("%s", newEmail);
    strncpy(acc->email, newEmail, sizeof(acc->email) - 1);
    acc->email[sizeof(acc->email) - 1] = '\0';
    //printf("Email updated successfully.\n");

    set_color(COLOR_CYAN);
    printf("Enter new Mobile Number: ");
    reset_color();
    char newMobile[12];
    scanf("%s", newMobile);
    strncpy(acc->mobileNumber, newMobile, sizeof(acc->mobileNumber) - 1);
    acc->mobileNumber[sizeof(acc->mobileNumber) - 1] = '\0';
    //printf("Mobile Number updated successfully.\n");

    SaveAccountsToFile(tempAccounts, tempAccountsCount);

}