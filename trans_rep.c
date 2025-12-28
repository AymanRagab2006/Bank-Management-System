#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "search_account.h"
#include "deposit.h"
#include "withdraw.h"
#include "save_data.h"
#include <time.h>
#include "textgenerator.h"

void transactionReport(long long account_number)
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
    char extra[50];
    printf("Transaction history for account %lld:\n", account_number);
    int count = 0;

    while (count < 5 && fgets(line, sizeof(line), file))
    {
        if (strstr(line, "Operation:") != NULL)
        {
            int n = sscanf(line, "Operation: %[^|]| amount: %d | Date: %[^|]| %[^\n]", op_str, &amount, date, extra);

            printf("Operation: %s, Amount: %d, Date: %s", op_str, amount, date);

            if (n == 4) // extra field exists
            {
                printf(", %s", extra);
            }
            printf("\n");
            count++;
        }
    }

    fclose(file);
}