#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "searchByAccountNumber.h"

int main()
{
    Account accounts[100]; 
    Account *foundAccount;
    int coun = 0;
    loadaccounts(accounts, 100, &coun); 
    searchByAccountNumber(accounts, coun, 1000000001, &foundAccount);
    if (foundAccount != NULL)
    {
        char choice;
        printf("Account found. Print details? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            printAccount(foundAccount);
        }
    }
    else
    {
        printf("Account not found.\n");
    }
}
