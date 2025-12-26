#include <stdio.h>
#include <string.h>
#include "system_structs.h"

void searchByAccountNumber(Account acc[], int count, int target, Account **result)
{
    *result = NULL;

    for (int i = 0; i < count; i++)
    {
        if (acc[i].accountNumber == target)
        {
            *result = &acc[i]; 
            return;
        }
    }
}
