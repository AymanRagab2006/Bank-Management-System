#include <stdio.h>
#include <string.h>
#include "system_structs.h"

void searchByAccountNumber(Account acc[], int count, long target)
{
    int found = 0;

    for (int i = 0; i < count; i++)
    {
        if (acc[i].accountNumber == target)
        {
            printf("Account Number : %ld\n", acc[i].accountNumber);
            printf("Name           : %s\n", acc[i].name);
            printf("E-mail         : %s\n", acc[i].email);
            printf("Balance        : %.2f $\n", acc[i].balance);
            printf("Mobile         : %s\n", acc[i].mobileNumber);

            char *months[] = {
                "January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"};

            printf("Date Opened    : %s %d\n", months[acc[i].dateOpened.month - 1], acc[i].dateOpened.year);

            printf("Status         : %s\n", acc[i].status);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }
}
