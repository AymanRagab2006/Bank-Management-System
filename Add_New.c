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

int NumChecker(long long accnum)
{
    FILE *f = fopen("accounts.txt", "r");
    if (f == NULL)
        return 1;

    char line[250];
    long long existingAccNum;
    while (fgets(line, sizeof(line), f))
    {
        if (sscanf(line, "%lld,", &existingAccNum) == 1)
        {
            if (existingAccNum == accnum)
            {
                fclose(f);
                return 0;
            }
        }
    }
    fclose(f);
    return 1;
}

void AddAccount(Account acc[], int *count)
{
    Account newAcc;
    char input[50];
    long long accNum;

    int validNum = 0;
    while (!validNum)
    {
        printf("Enter account number (13 digits): ");
        scanf("%49s", input);

        int len = strlen(input);
        validNum = 1;

        if (len != 13)
        {
            printf("Account number must be 13 digits! Try again.\n");
            validNum = 0;
            continue;
        }

        for (int i = 0; i < len; i++)
        {
            if (!isdigit(input[i]))
            {
                printf("Account number must contain digits only! Try again.\n");
                validNum = 0;
                break;
            }
        }

        if (!validNum)
            continue;

        accNum = atoll(input);

        if (!NumChecker(accNum))
        {
            printf("Account number already exists in database! Try again.\n");
            validNum = 0;
        }
    }

    newAcc.accountNumber = accNum;

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Enter name: ");
    fgets(newAcc.name, sizeof(newAcc.name), stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = '\0';

    printf("Enter email: ");
    fgets(newAcc.email, sizeof(newAcc.email), stdin);
    newAcc.email[strcspn(newAcc.email, "\n")] = '\0';

    char mobileInput[50];

    int validMobile = 0;
    while (!validMobile)
    {
        printf("Enter mobile number (must be 11 digits): ");
        scanf(" %49s", mobileInput);

        int len = strlen(mobileInput);
        if (len > 11)
        {
            printf("Mobile number too long! Try again.\n");
            continue;
        }
        if (len < 11)
        {
            printf("Mobile number too short! Try again.\n");
            continue;
        }
        validMobile = 1;
        for (int i = 0; i < len; i++)
        {
            if (!isdigit(mobileInput[i]))
            {
                validMobile = 0;
                printf("Mobile number must contain digits only! Try again.\n");
                break;
            }
        }

        if (validMobile)
        {
            strcpy(newAcc.mobileNumber, mobileInput);
        }
    }

    printf("Enter balance: ");
    scanf("%f", &newAcc.balance);

    newAcc.dateOpened = getcurrentdate();
    strcpy(newAcc.status, "active");

    FILE *f = fopen("accounts.txt", "a");
    if (f != NULL)
    {
        fprintf(f, "%lld,%s,%s,%.1f,%s,%d-%d,%s\n",
                newAcc.accountNumber,
                newAcc.name,
                newAcc.email,
                newAcc.balance,
                newAcc.mobileNumber,

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

    acc[*count] = newAcc;
    (*count)++;
}

    return 0;
}
