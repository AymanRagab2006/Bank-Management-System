#include <stdio.h>
#include <string.h>
#include "system_structs.h"
void searchByAccountName(Account acc[], int count, char target[])
{
    int cal = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(acc[i].name, target) == 0)
        {
            printAccount(&acc[i]);
            printf("________________________________\n");
        }
    }
}
int main()
{
    int coun = 0;
    Account accounts[100];
    loadaccounts(accounts, 100, &coun);
    printf("Loaded %d accounts.\n", coun);
    searchByAccountName(accounts, coun, "ali");
    return 0;
}
