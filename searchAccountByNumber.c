#include <stdio.h>
#include <string.h>
#include "system_structs.h"

Account *searchByAccountNumber(Account acc[], int count, int target)
{
    for (int i = 0; i < count; i++)
    {
        if (acc[i].accountNumber == target)
        {
            return &acc[i];
        }
    }
    return NULL;
}
