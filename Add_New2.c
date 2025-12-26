#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "system_structs.h"
#include "load_Accounts.h"
#define MAX_ACCOUNTS 100

Date getcurrentdate()
{
    Date d;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    d.month = tm_info->tm_mon + 1;
    d.year = tm_info->tm_year + 1900;
    return d;
}


int NumChecker(Account acc[], int count, long long accnum)
{
    for (int i = 0; i < count; i++)
    {
        if (acc[i].accountNumber == accnum)
            return 0;
    }
    return 1;
}

void AddAccount(Account acc[], int *count)
{
    Account newAcc;
    char input[50];
    int valid = 0;

    while (!valid)
    {
        printf("Enter account number (10 digits): ");
        scanf("%s", input);

        int len = strlen(input);
        valid = 1;

        if (len != 10)
        {
            printf("Account number must be exactly 10 digits! Try again.\n");
            valid = 0;
            continue;
        }

        for (int i = 0; i < len; i++)
        {
            if (!isdigit(input[i]))
            {
                printf("Account number must contain digits only! Try again.\n");
                valid = 0;
                break;
            }
        }

        if (valid && !NumChecker(acc, *count, atoll(input)))
        {
            printf("Account number already exists! Try again.\n");
            valid = 0;
        }
    }

    newAcc.accountNumber = atoll(input);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        

    printf("Enter name: ");
    fgets(newAcc.name, sizeof(newAcc.name), stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = 0;

    printf("Enter email: ");
    fgets(newAcc.email, sizeof(newAcc.email), stdin);
    newAcc.email[strcspn(newAcc.email, "\n")] = 0;

    valid = 0;
    while (!valid)
    {
        printf("Enter mobile number (max 13 digits): ");
        scanf("%s", newAcc.mobileNumber);
        int len = strlen(newAcc.mobileNumber);

        if (len > 13)
        {
            printf("Mobile number too long! Try again.\n");
            continue;
        }

        valid = 1;
        for (int i = 0; i < len; i++)
        {
            if (!isdigit(newAcc.mobileNumber[i]))
            {
                valid = 0;
                printf("Mobile number must contain digits only! Try again.\n");
                break;
            }
        }
    }

    printf("Enter balance: ");
    scanf("%f", &newAcc.balance);

    newAcc.dateOpened = getcurrentdate();
    newAcc.status = 1;

    acc[*count] = newAcc;
    (*count)++;

    FILE *f = fopen("accounts.txt", "a");
    if (f != NULL)
    {
        fprintf(f, "%lld,%s,%s,%s,%.2f,%d,%d,%d\n",
                newAcc.accountNumber,
                newAcc.name,
                newAcc.email,
                newAcc.mobileNumber,
                newAcc.balance,
                newAcc.dateOpened.month,
                newAcc.dateOpened.year,
                newAcc.status);
        fclose(f);
        printf("Account added and saved successfully!\n");
    }
    else
    {
        printf("Cannot open file to save account!\n");
    }
}

