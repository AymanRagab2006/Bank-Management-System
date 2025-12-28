#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "system_structs.h"
#include "color.h"
#define MAX_ACCOUNTS 100

void SaveAccountsToFile(Account temp[], int count)
{
    char response;
    set_color(COLOR_YELLOW);
    printf("Saving changes to file...\n");
    reset_color();
    set_color(COLOR_CYAN);
    printf("y/n? ");
    reset_color();
    scanf(" %c", &response);

    if (response != 'y' && response != 'Y')
    {
        set_color(COLOR_YELLOW);
        printf("Changes not saved.\n");
        reset_color();
        return;
    }

    copyAccountData(accounts, temp, count);
    accountsCount = count;

    FILE *fp = fopen("accounts.txt", "w");
    if (!fp)
    {
        set_color(COLOR_RED);
        printf("Error opening file for saving!\n");
        reset_color();
        return;
    }

    set_color(COLOR_YELLOW);
    printf("Writing %d accounts to file...\n", count);
    reset_color();
    for (int i = 0; i < count; i++)
    {
        // Fixed format to match loading function
        fprintf(fp, "%lld,%s,%s,%.2f,%s,%d-%d, %s\n",
                temp[i].accountNumber,
                temp[i].name,
                temp[i].email,
                temp[i].balance,      // balance comes before mobileNumber
                temp[i].mobileNumber, // mobileNumber comes after balance
                temp[i].dateOpened.month,
                temp[i].dateOpened.year, // use dash, not comma
                temp[i].status);         // space before status
    }
    set_color(COLOR_GREEN);
    printf("All changes saved successfully!\n");
    reset_color();
    fclose(fp);
}