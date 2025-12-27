#include <stdio.h>
#include <string.h>
#include "system_structs.h"
void searchByAccountName(Account acc[], int count)
{
    const char *target = "ali";
    for (int i = 0; i < count; i++)
    {
        char firstName[50];
        // Extract first word from name
        sscanf(acc[i].name, "%49s", firstName);

        if (strcmp(firstName, target) == 0)
        {
            printAccount(&acc[i]);
            printf("________________________________\n");
        }
    }
}
int main()
{
    Account accounts[100];
    int count = 0;
    // char target[] = "ali3";
    loadaccounts(accounts, 100, &count);
    searchByAccountName(accounts, count);
    return 0;
}
