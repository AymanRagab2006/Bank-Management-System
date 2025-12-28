#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "color.h"

void loadaccounts(Account acc[], int max, int *count)
{
    FILE *f = fopen("accounts.txt", "r");
    if (!f)
    {
        set_color(COLOR_RED);
        printf("Error: file not found!\n");
        reset_color();
        *count = 0;
        return;
    }

    *count = 0;
    char line[400];
    while (*count < max && fgets(line, sizeof(line), f))
    {
        line[strcspn(line, "\r\n")] = 0; // remove newline

            int fields = sscanf(line,
                                "%lld,%49[^,],%49[^,],%f,%49[^,],%d%*[-,]%d,%9s",
                                &acc[*count].accountNumber,
                                acc[*count].name,
                                acc[*count].email,
                                &acc[*count].balance,
                                acc[*count].mobileNumber,
                                &acc[*count].dateOpened.month,
                                &acc[*count].dateOpened.year,
                                acc[*count].status);

        if (fields == 8)
            (*count)++;
        if (fields != 8)
        {
            set_color(COLOR_YELLOW);
            printf("Skipped line (fields=%d): %s\n", fields, line);
            reset_color();
        }
    }
    fclose(f);
}