#include <stdio.h>
#include <string.h>
#include "system_structs.h"

Account *searchByAccountNumber(Account acc[], int count, long long target)
{
    // *found = 0;
    for (int i = 0; i < count; i++)
    {
        if (acc[i].accountNumber == target)
        {
            return &acc[i];
        }
    }

    return NULL;
}
