#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "system_structs.h"
#include "load_Accounts.h"
#include "save_data.h"
#include "color.h"

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
    for (int i = 0; i < accountsCount; i++)
    {
        if (accounts[i].accountNumber == accnum)
        {
            return 0;
        }
    }
    return 1;
}

void AddAccount(Account acc[], int *count)
{
    copyAccountData(tempAccounts, accounts, accountsCount);
    tempAccountsCount = accountsCount;

    Account newAcc;
    char input[50];
    long long accNum;

    int validNum = 0;
    while (!validNum)
    {
        set_color(COLOR_CYAN);
        printf("Enter account number (13 digits): ");
        reset_color();
        scanf("%49s", input);

        int len = strlen(input);
        validNum = 1;

        if (len != 13)
        {
            set_color(COLOR_RED);
            printf("Account number must be 13 digits! Try again.\n");
            reset_color();
            validNum = 0;
            continue;
        }

        for (int i = 0; i < len; i++)
        {
            if (!isdigit(input[i]))
            {
                set_color(COLOR_RED);
                printf("Account number must contain digits only! Try again.\n");
                reset_color();
                validNum = 0;
                break;
            }
        }

        if (!validNum)
            continue;

        accNum = atoll(input);

        if (!NumChecker(accNum))
        {
            set_color(COLOR_RED);
            printf("Account number already exists in database! Try again.\n");
            reset_color();
            validNum = 0;
        }
    }

    newAcc.accountNumber = accNum;

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    set_color(COLOR_CYAN);
    printf("Enter name: ");
    reset_color();
    fgets(newAcc.name, sizeof(newAcc.name), stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = '\0';

    set_color(COLOR_CYAN);
    printf("Enter email: ");
    reset_color();
    fgets(newAcc.email, sizeof(newAcc.email), stdin);
    newAcc.email[strcspn(newAcc.email, "\n")] = '\0';

    set_color(COLOR_CYAN);
    printf("Enter balance: ");
    reset_color();
    scanf("%f", &newAcc.balance);

    char mobileInput[50];

    int validMobile = 0;
    while (!validMobile)
    {
        set_color(COLOR_CYAN);
        printf("Enter mobile number (must be 11 digits): ");
        reset_color();
        scanf(" %49s", mobileInput);

        int len = strlen(mobileInput);
        if (len > 11)
        {
            set_color(COLOR_RED);
            printf("Mobile number too long! Try again.\n");
            reset_color();
            continue;
        }
        if (len < 11)
        {
            set_color(COLOR_RED);
            printf("Mobile number too short! Try again.\n");
            reset_color();
            continue;
        }
        validMobile = 1;
        for (int i = 0; i < len; i++)
        {
            if (!isdigit(mobileInput[i]))
            {
                validMobile = 0;
                set_color(COLOR_RED);
                printf("Mobile number must contain digits only! Try again.\n");
                reset_color();
                break;
            }
        }

        if (validMobile)
        {
            strcpy(newAcc.mobileNumber, mobileInput);
        }
    }


    newAcc.dateOpened = getcurrentdate();
    strcpy(newAcc.status, "active");


    tempAccounts[tempAccountsCount++] = newAcc;
    SaveAccountsToFile(tempAccounts, tempAccountsCount);

}