#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 20
int main()
{
    int n, i;
    char accountNumbers[MAX_ACCOUNTS][ACCOUNT_NUMBER_LENGTH];

    printf("Enter number of accounts: ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        printf("Enter account number %d: ", i + 1);
        fgets(accountNumbers[i], ACCOUNT_NUMBER_LENGTH, stdin);
        accountNumbers[i][strcspn(accountNumbers[i], "\n")] = 0;
    }

    return 0;
}
