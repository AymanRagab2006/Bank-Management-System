#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"
#define MAX_ACCOUNTS 100

void SaveAccountsToFile(const char *accounts, Account temp[], int count)
{
    char response;
    printf("Saving changes to file...\n");
    printf("y/n? ");
    scanf(" %c", &response);

    if (response != 'y' && response != 'Y')
    {
        printf("Changes not saved.\n");
        return;
    }

    FILE *fp = fopen(accounts, "w");
    if (!fp)
    {
        printf("Error opening file for saving!\n");
        return;
    }

    printf("Writing %d accounts to file...\n", count);
    for (int i = 0; i < count; i++)
    {
        // Fixed format to match loading function
        fprintf(fp, "%lld,%s,%s,%.2f,%lld,%d-%d, %s\n",
                temp[i].accountNumber,
                temp[i].name,
                temp[i].email,
                temp[i].balance,      // balance comes before mobileNumber
                temp[i].mobileNumber, // mobileNumber comes after balance
                temp[i].dateOpened.month,
                temp[i].dateOpened.year, // use dash, not comma
                temp[i].status);         // space before status
    }
    printf("All changes saved successfully!\n");
    fclose(fp);
}
