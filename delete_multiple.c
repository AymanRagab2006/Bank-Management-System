#include <stdio.h>
#include <string.h>
#include "system_structs.h"
#include "save_data.h"
#include "add_account.h"
#include "color.h"


void deleteMultiple(Account acc[], int count)
{
    int cnt = 0;
    while(1){
        set_color(COLOR_MAGENTA);
        printf("Delete accounts by:\n");
        reset_color();
        set_color(COLOR_YELLOW);
        printf("1. Date Opened\n");
        printf("2. Inactive Status\n");
        printf("3. Exit\n");
        reset_color();
        set_color(COLOR_CYAN);
        printf("Enter your choice: ");
        reset_color();
        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            copyAccountData(tempAccounts, accounts, accountsCount);
            tempAccountsCount = accountsCount;

            set_color(COLOR_CYAN);
            printf("Enter date to delete accounts (YYYY-MM): ");
            reset_color();
            int year, month;
            scanf("%d-%d", &year, &month);

        
            int i = 0;
            while (i < tempAccountsCount)
            {
                if (tempAccounts[i].dateOpened.year == year && tempAccounts[i].dateOpened.month == month && tempAccounts[i].balance == 0.0)
                {
                    for (int j = i; j < tempAccountsCount - 1; j++)
                    {
                        tempAccounts[j] = tempAccounts[j + 1];
                    }
                    tempAccountsCount--;
                    cnt++;
                }
                else
                {
                    i++;
                }
            }
            set_color(COLOR_GREEN);
            printf("%d accounts deleted.\n", cnt);
            reset_color();
            SaveAccountsToFile(tempAccounts, tempAccountsCount);
            return;
        }
        else if(choice == 2)
        {
            copyAccountData(tempAccounts, accounts, accountsCount);
            tempAccountsCount = accountsCount;

            Date currentDate = getcurrentdate();
            int currentDays = currentDate.year * 12 + currentDate.month;
            

            int i = 0;
            while (i < tempAccountsCount)
            {
                int accouuntDays = tempAccounts[i].dateOpened.year * 12 + tempAccounts[i].dateOpened.month;
                int diffMonths = currentDays - accouuntDays; 
                if(strcmp(tempAccounts[i].status, "inactive") == 0 && tempAccounts[i].balance == 0.0 && diffMonths > 3)
                {
                    for (int j = i; j < tempAccountsCount - 1; j++)
                    {
                        tempAccounts[j] = tempAccounts[j + 1];
                    }
                    tempAccountsCount--;
                    cnt++;
                }
                else
                {
                    i++;
                }
            }
            set_color(COLOR_GREEN);
            printf("%d accounts deleted.\n", cnt);
            reset_color();
            SaveAccountsToFile(tempAccounts, tempAccountsCount);
            return;
        }
        else if(choice == 3)
        {
            return;
        }
        else
        {
            set_color(COLOR_RED);
            printf("Invalid choice. Please try again.\n");
            reset_color();
        }
    }
}