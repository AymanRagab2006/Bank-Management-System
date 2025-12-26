#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "searchByAccountNumber.h"

int main()
{
    Account accounts[100]; // array to hold accounts

    int coun = 0;
    loadaccounts(accounts, 100, &coun);
    Account *found = searchByAccountNumber(accounts, 2, 1000000001);
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
