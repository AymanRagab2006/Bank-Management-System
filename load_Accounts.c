#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"

int loadaccounts(Account acc[], int max)
{
    int fields;
    FILE *f = fopen("accounts.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file!!!!!\n");
        return 0;
    }
    int count = 0;
    char line[400];
    while (count < max && fgets(line, sizeof(line), f)) /*sscanf evaluate the buffer (line) to strings and numbers */
    {
        fields = sscanf(line, "%i,%[^,],%[^,],%f,%[^,],%i,%i,%i",
                        &acc[count].accountNumber,
                        acc[count].name,
                        acc[count].email,
                        &acc[count].balance,
                        acc[count].mobileNumber,
                        &acc[count].dateOpened.month,
                        &acc[count].dateOpened.year,
                        &acc[count].status);
        count++;
    }
    return count;
}