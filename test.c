#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"

void loadaccounts(Account acc[], int max)
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
        int fields = sscanf(line, "%lld,%[^,],%[^,],%[^,],%f,%d,%d,%d",
                            &acc[count].accountNumber,
                            acc[count].name,
                            acc[count].email,
                            acc[count].mobileNumber,
                            &acc[count].balance,
                            &acc[count].dateOpened.month,
                            &acc[count].dateOpened.year,
                            &acc[count].status);

        if (fields == 8)
        {
            count++;
        }
    }
    printf("Loaded %d accounts from file.\n", count);
    printf("Number: %lld\n", acc[3].accountNumber);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"
#include "load_Accounts.h"

int main()
{
    Account acc[100];
    loadaccounts(acc, 100);
    // searchByAccountNumber(acc, 100, 9780136019);
    return 0;
}