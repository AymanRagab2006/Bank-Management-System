#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "system_structs.h"
#include "print_data.h"
#include "color.h"


Account* copyAccounts(Account accounts[], int size) {
    Account* copy = (Account*)malloc(size * sizeof(Account));
    if (copy == NULL) {
        set_color(COLOR_RED);
        printf("Memory allocation failed!\n");
        reset_color();
        return NULL;
    }
    memcpy(copy, accounts, size * sizeof(Account));
    return copy;
}

Account* sortByName(Account accounts[], int size) {
    Account* sorted = copyAccounts(accounts, size);
    if (sorted == NULL) return NULL;
    
    Account temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(sorted[i].name, sorted[j].name) > 0) {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return sorted;
}

Account* sortByBalance(Account accounts[], int size) {
    Account* sorted = copyAccounts(accounts, size);
    if (sorted == NULL) return NULL;
    
    Account temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sorted[i].balance > sorted[j].balance) {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return sorted;
}

Account* sortByDateOpened(Account accounts[], int size) {
    Account* sorted = copyAccounts(accounts, size);
    if (sorted == NULL) return NULL;
    
    Account temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sorted[i].dateOpened.year > sorted[j].dateOpened.year ||
                (sorted[i].dateOpened.year == sorted[j].dateOpened.year &&
                 sorted[i].dateOpened.month > sorted[j].dateOpened.month)) {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return sorted;
}

Account* sortByStatus(Account accounts[], int size) {
    Account* sorted = copyAccounts(accounts, size);
    if (sorted == NULL) return NULL;
    
    Account temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if(strcmp(sorted[i].status, sorted[j].status) > 0) {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return sorted;
}

void printAccounts(Account accounts[], int size) {
    int choice;
    Account* sortedAccounts = NULL;
    
    while (1) {
        set_color(COLOR_MAGENTA);
        printf("Choose sorting option:\n");
        reset_color();
        set_color(COLOR_YELLOW);
        printf("1. Sort by Name\n");
        printf("2. Sort by Balance\n");
        printf("3. Sort by Date Opened\n");
        printf("4. Sort by Status\n");
        printf("5. Exit\n");
        reset_color();
        set_color(COLOR_CYAN);
        printf("Enter your choice: ");
        reset_color();
        

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            set_color(COLOR_RED);
            printf("Invalid input! Please enter a number.\n");
            reset_color();
            continue;
        }
        
        if (choice == 1) {
            sortedAccounts = sortByName(accounts, size);
            break;
        }
        else if (choice == 2) {
            sortedAccounts = sortByBalance(accounts, size);
            break;
        }
        else if (choice == 3) {
            sortedAccounts = sortByDateOpened(accounts, size);
            break;
        }
        else if (choice == 4) {
            sortedAccounts = sortByStatus(accounts, size);
            break;
        }
        else if (choice == 5) {
            return;
        }
        else {
            set_color(COLOR_RED);
            printf("Invalid choice! Please choose 1-5.\n");
            reset_color();
        }
    }
    
    if (sortedAccounts == NULL) {
        set_color(COLOR_RED);
        printf("Sorting failed!\n");
        reset_color();
        return;
    }

    const char* monthNames[] = {
        "Invalid", "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };

    set_color(COLOR_GREEN);
    printf("\nAccount List:\n");
    reset_color();
    set_color(COLOR_MAGENTA);
    printf("=======================\n");
    reset_color();
    for (int i = 0; i < size; i++) {
        int month = sortedAccounts[i].dateOpened.month;
        const char* monthName = (month >= 1 && month <= 12) ? monthNames[month] : "Invalid Month";

        set_color(COLOR_CYAN);
        printf("Account Number: ");
        set_color(COLOR_WHITE);
        printf("%lld\n", sortedAccounts[i].accountNumber);
        set_color(COLOR_CYAN);
        printf("Name: ");
        set_color(COLOR_WHITE);
        printf("%s\n", sortedAccounts[i].name);
        set_color(COLOR_CYAN);
        printf("Email: ");
        set_color(COLOR_WHITE);
        printf("%s\n", sortedAccounts[i].email);
        set_color(COLOR_CYAN);
        printf("Mobile Number: ");
        set_color(COLOR_WHITE);
        printf("%s\n", sortedAccounts[i].mobileNumber);
        set_color(COLOR_CYAN);
        printf("Balance: ");
        set_color(COLOR_GREEN);
        printf("%.2f\n", sortedAccounts[i].balance);
        set_color(COLOR_CYAN);
        printf("Date Opened: ");
        set_color(COLOR_WHITE);
        printf("%s %d\n", monthName, sortedAccounts[i].dateOpened.year);
        set_color(COLOR_CYAN);
        printf("Status: ");
        if (strcmp(sortedAccounts[i].status, "active") == 0) {
            set_color(COLOR_GREEN);
        } else {
            set_color(COLOR_RED);
        }
        printf("%s\n", sortedAccounts[i].status);
        reset_color();
        set_color(COLOR_MAGENTA);
        printf("-----------------------\n");
        reset_color();
    }
    
    free(sortedAccounts);
}