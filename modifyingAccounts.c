#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "searchAccount.h"
#include "overwrite.h"
#define MAX_ACCOUNTS 100
void modifyAccount(Account accounts[], int *count)
{
    Account temp[100];
    long long acc_num;
    int found = 0;
    printf("Enter account number: ");
    scanf("%lld", &acc_num);
    loadaccounts(temp, 100, count);
    Account *acc = searchByAccountNumber(temp, *count, acc_num);
    if (!acc)
    {
        printf("Account not found.\n");
        return;
    }
    printf("Modifying account for user account number: %lld\n", acc_num);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    char newName[50];
    printf("Enter new account name: ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = 0;
    strncpy(temp[found].name, newName, sizeof(temp[found].name) - 1);
    temp[found].name[sizeof(temp[found].name) - 1] = '\0';
    printf("Account name updated successfully.\n");

    printf("Enter a new Email: ");
    char newEmail[50];
    scanf("%s", newEmail);
    strncpy(temp[found].email, newEmail, sizeof(temp[found].email) - 1);
    temp[found].email[sizeof(temp[found].email) - 1] = '\0';
    printf("Email updated successfully.\n");

    printf("Enter new Mobile Number: ");
    char newMobile[11];
    scanf("%s", newMobile);
    strncpy(temp[found].mobileNumber, newMobile, sizeof(temp[found].mobileNumber) - 1);
    temp[found].mobileNumber[sizeof(temp[found].mobileNumber) - 1] = '\0';
    printf("Mobile Number updated successfully.\n");

    SaveAccountsToFile("accounts.txt", temp, *count);
}
