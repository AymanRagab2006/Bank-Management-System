#include <stdio.h>
#include <string.h>
#include "system_structs.h"

void loadaccounts(Account acc[], int max, int *count)
{
    FILE *f = fopen("accountss.txt", "r");
    if (!f)
    {
        printf("Error: file not found!\n");
        *count = 0;
        return;
    }
    else
    {
        printf("File opened successfully.\n");
    }

    *count = 0;
    char line[400];
    while (*count < max && fgets(line, sizeof(line), f))
    {
        line[strcspn(line, "\r\n")] = 0; // remove newline

        int fields = sscanf(line, "%lld,%49[^,],%49[^,],%10[^,],%f,%d,%d,%9s",
                            &acc[*count].accountNumber,
                            acc[*count].name,
                            acc[*count].email,
                            acc[*count].mobileNumber,
                            &acc[*count].balance,
                            &acc[*count].dateOpened.month,
                            &acc[*count].dateOpened.year,
                            acc[*count].status);

        if (fields == 8)
            (*count)++;
    }
    fclose(f);
}