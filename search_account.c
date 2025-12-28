#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "color.h"


void printAccount(Account *acc)
{
    if (acc == NULL)
    {
        set_color(COLOR_RED);
        printf("Account not found.\n");
        reset_color();
        return;
    }
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    set_color(COLOR_CYAN);
    printf("Account Number : ");
    set_color(COLOR_WHITE);
    printf("%lld\n", acc->accountNumber);
    set_color(COLOR_CYAN);
    printf("Name           : ");
    set_color(COLOR_WHITE);
    printf("%s\n", acc->name);
    set_color(COLOR_CYAN);
    printf("E-mail         : ");
    set_color(COLOR_WHITE);
    printf("%s\n", acc->email);
    set_color(COLOR_CYAN);
    printf("Balance        : ");
    set_color(COLOR_GREEN);
    printf("%.2f $\n", acc->balance);
    set_color(COLOR_CYAN);
    printf("Mobile         : ");
    set_color(COLOR_WHITE);
    printf("%s\n", acc->mobileNumber);
    set_color(COLOR_CYAN);
    printf("Date Opened    : ");
    set_color(COLOR_WHITE);
    printf("%s %d\n", months[acc->dateOpened.month - 1], acc->dateOpened.year);
    set_color(COLOR_CYAN);
    printf("Status         : ");
    if (strcmp(acc->status, "active") == 0) {
        set_color(COLOR_GREEN);
    } else {
        set_color(COLOR_RED);
    }
    printf("%s\n", acc->status);
    reset_color();
}

Account *searchByAccountNumber(Account acc[], int count)
{
    set_color(COLOR_CYAN);
    printf("Enter account number: ");
    reset_color();
    long long target;
    scanf("%lld", &target);

    for (int i = 0; i < count; i++)
    {
        if (acc[i].accountNumber == target)
        {
            return &acc[i];
        }
    }
    return NULL;
}


void searchByAccountName(Account acc[], int count)
{
    set_color(COLOR_CYAN);
    printf("Enter name to search: ");
    reset_color();
    char target[50];
    scanf("%s", target);
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        char firstName[50], secondName[50];

        sscanf(acc[i].name, "%49s %49s", firstName, secondName);
        

        if (strcmp(firstName, target) == 0 || strcmp(secondName, target) == 0)
        {
            printAccount(&acc[i]);
            set_color(COLOR_MAGENTA);
            printf("________________________________\n");
            reset_color();
            found = 1;
        }
    }
    if (!found)
    {
        set_color(COLOR_RED);
        printf("No accounts found with the name: (%s)\n", target);
        reset_color();
    }
}