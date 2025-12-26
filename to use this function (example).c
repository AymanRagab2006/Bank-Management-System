#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "searchAccount.h"

int main()
{
    Account accounts[100]; // array to hold accounts
    int coun = 0;
    loadaccounts(accounts, 100, &coun);
    printf("Loaded %d accounts.\n", coun);
    Account *found = searchByAccountName(accounts, coun, "John Doe");
    if (found != NULL)
    {
        char choice;
        printf("Account found. Print details? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            printAccount(found);
        }
    }
    else
    {
        printf("Account not found.\n");
    }
}
