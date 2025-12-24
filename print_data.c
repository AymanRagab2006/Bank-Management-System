#include <stdio.h>
#include "sort.h"
#include "system_structs.h"

void printAccounts(Account accounts[], int size){
    
    printf("1. Sort by Name\n");
    printf("2. Sort by Balance\n");
    printf("3. Sort by Date Opened\n");
    printf("4. Sort by Status\n");
    printf("5. Exit\n");

    int choice;
    scanf("%d", &choice);
    
    if(choice == 1){
        sortByName(accounts, size);
    }
    else if(choice == 2){
        sortByBalance(accounts, size);
    }
    else if(choice == 3){
        sortByDateOpened(accounts, size);
    }
    else if(choice == 4){
        sortByStatus(accounts, size);
    }
    else if(choice == 5){
        return;
    }
    else {
        printf("Invalid choice!\n");
        return;
    }
    char monthName[20];

    printf("Account List:\n");
    for(int i = 0; i < size; i++){

        if(accounts[i].dateOpened.month == 1) strcpy(monthName, "January");
        else if(accounts[i].dateOpened.month == 2) strcpy(monthName, "February");
        else if(accounts[i].dateOpened.month == 3) strcpy(monthName, "March");
        else if(accounts[i].dateOpened.month == 4) strcpy(monthName, "April");
        else if(accounts[i].dateOpened.month == 5) strcpy(monthName, "May");
        else if(accounts[i].dateOpened.month == 6) strcpy(monthName, "June");
        else if(accounts[i].dateOpened.month == 7) strcpy(monthName, "July");
        else if(accounts[i].dateOpened.month == 8) strcpy(monthName, "August");
        else if(accounts[i].dateOpened.month == 9) strcpy(monthName, "September");
        else if(accounts[i].dateOpened.month == 10) strcpy(monthName, "October");
        else if(accounts[i].dateOpened.month == 11) strcpy(monthName, "November");
        else if(accounts[i].dateOpened.month == 12) strcpy(monthName, "December");
        else strcpy(monthName, "Invalid Month");

        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Email: %s\n", accounts[i].email);
        printf("Mobile Number: %s\n", accounts[i].mobileNumber);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("Date Opened: %s %d\n", monthName, accounts[i].dateOpened.year);
        printf("Status: %s\n", accounts[i].status ? "Active" : "Inactive");
        printf("-----------------------\n");
    }
}
