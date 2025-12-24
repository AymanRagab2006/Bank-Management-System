#include <stdio.h>
#include <string.h>
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
        fields = sscanf(line, "%i,%[^,],%[^,],%s,%f,%i,%i,%i",
                        &acc[count].accountNumber,
                        acc[count].name,
                        acc[count].email,
                        acc[count].mobileNumber,
                        &acc[count].balance,
                        &acc[count].dateOpened.month,
                        &acc[count].dateOpened.year,
                        &acc[count].status);
    }
    if (fields == 8)
    {
        count++;
    }
    fclose(f);
    return count;
}
int main()
{
    Account acc[100];
    int total = loadaccounts(acc, 100);

    printf("loaded %i accounts\n", total);
    return 0;
}