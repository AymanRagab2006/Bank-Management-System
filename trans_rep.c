#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "searchAccount.h"
#include "deposit.h"
#include "withdraw.h"
#include "overwrite.h"
#include <time.h>
#include "textgenerator.h"
#define MAX_ACCOUNTS 100
void transactionReport(Account acc[], const char *operationType, long long account_number)
{
    char filename[100];
    sprintf(filename, "%lld.txt", account_number);

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("File not found!\n");
        return;
    }

    char line[256];
    char op_str[50];
    int amount;
    char date[50];
    printf("Transaction history for account %lld:\n", account_number);
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "Operation:") != NULL) // Check if the line contains "Operation:"
        {
            if (sscanf(line, "Operation: %[^|]| amount: %d | Date: %[^\n]", op_str, &amount, date) == 3)
            {
                printf("Operation: %s, Amount: %d, Date: %s\n", op_str, amount, date);
            }
        }
    }

    fclose(file);
}
