#include <stdio.h>
#include "menu.h"
#include "color.h"
#include "system_structs.h"
#include "print_data.h"
#include "add_account.h"
#include "login.h"
#include "search_account.h"
#include "change_status.h"
#include "delete_multiple.h"
#include "delete.h"
#include "modify_account.h"

void displayMenu() {
    set_color(COLOR_GREEN);
    printf("=== Welcome To Bank Management System ===\n");
    reset_color();
    while(1){
        set_color(COLOR_MAGENTA);
        printf("==============================\n");
        reset_color();
        set_color(COLOR_YELLOW);
        printf("1. Add New Account\n");
        printf("2. Delete Account\n");
        printf("3. Modify Account Data\n");
        printf("4. Search by Account Number\n");
        printf("5. Search by Name\n");
        printf("6. Change Account Status\n");
        printf("7. Withdraw Amount\n");
        printf("8. Deposit Amount\n");
        printf("9. Tranfer Amount\n");
        printf("10. Transaction Report\n");
        printf("11. Display All Accounts\n");
        printf("12. Delete Multiple\n");
        printf("13. Quit\n");
        reset_color();

        set_color(COLOR_MAGENTA);
        printf("==============================\n");
        reset_color();
        set_color(COLOR_CYAN);
        printf("Please select an option (1-13): ");
        reset_color();
        int choice;
        scanf("%d", &choice);

        if(choice < 1 || choice > 13) {
            set_color(COLOR_RED);
            printf("Invalid choice. Please select a valid option.\n");
            reset_color();
            displayMenu();
        }

        switch(choice) {
            case 1: {
                AddAccount(accounts, &accountsCount);
                break;
            }
            case 2: {
                DeleteByAccountNumber(accounts, &accountsCount);
                break;
            }
            case 3: {
                modifyAccount(accounts, &accountsCount);
                break;
            }
            case 4: {
                printAccount(searchByAccountNumber(accounts, accountsCount));
                break;
            }
            case 5: {
                searchByAccountName(accounts, accountsCount);
                break;
            }
            case 6: {
                changeStatus(accounts, accountsCount);
                break;
            }
            case 7: {
                // Withdraw Amount
                break;
            }
            case 8: {
                // Deposit Amount
                break;
            }
            case 9: {
                // Transfer Amount
                break;
            }
            case 10: {
                // Transaction Report
                break;
            }
            case 11: {
                printAccounts(accounts, accountsCount);
                break;
            }
            case 12: {
                deleteMultiple(accounts, accountsCount);
                break;
            }
            case 13: {
                set_color(COLOR_GREEN);
                printf("Thank you for using the Bank Management System. Goodbye!\n");
                reset_color();
                Quit();
                break;
            }
            default: {
                break;
            }
        }
    }

}