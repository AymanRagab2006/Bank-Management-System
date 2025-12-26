#include <stdio.h>
#include "system_structs.h"

void printAccount(const Account *acc)
{
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    printf("Account Number : %ld\n", acc->accountNumber);
    printf("Name           : %s\n", acc->name);
    printf("E-mail         : %s\n", acc->email);
    printf("Mobile         : %s\n", acc->mobileNumber);
    printf("Balance        : %.2f $\n", acc->balance);
    printf("Date Opened    : %s %d\n", months[acc->dateOpened.month - 1], acc->dateOpened.year);
    printf("Status         : %s\n", acc->status ? "Active" : "Inactive");
}
