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

#define MAX_ACCOUNTS 100

void report(const char *operation, long long account_number, int value, char data[])
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", t);
    if (strcmp(operation, "deposit") == 0 || strcmp(operation, "withdraw") == 0)
    {
        char filename[100];
        sprintf(filename, "%lld.txt", account_number);
        FILE *fp = fopen(filename, "a");
        fprintf(fp, "----------------------------------------------\n");
        fprintf(fp, "Operation: %s | amount: %d | Date: %s\n", operation, value, date);
        fprintf(fp, "----------------------------------------------\n");
        // fclose(fp);
    }

    if (strcmp(operation, "transfer") == 0)
    {
        char filename[100];
        sprintf(filename, "%lld.txt", account_number);
        FILE *fp = fopen(filename, "a");
        fprintf(fp, "----------------------------------------------\n");
        fprintf(fp, "Operation: %s | amount: %d | Date: %s | To: %s\n", operation, value, date, data);
        fprintf(fp, "----------------------------------------------\n");
        // fclose(fp);
    }
    if (strcmp(operation, "recieved") == 0)
    {
        char filename[100];
        sprintf(filename, "%lld.txt", account_number);
        FILE *fp = fopen(filename, "a");
        fprintf(fp, "----------------------------------------------\n");
        fprintf(fp, "Operation: %s | amount: %d | Date: %s | from: %s\n", operation, value, date, data);
        fprintf(fp, "----------------------------------------------\n");
        // fclose(fp);
    }
}
