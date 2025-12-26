#include <stdio.h>
#include <string.h>
#include "system_structs.h"
Account *searchByAccountName(Account acc[], int count,  char target[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(acc[i].name, target) == 0)
        {
            return &acc[i];
        }
    }
    return NULL;
}
