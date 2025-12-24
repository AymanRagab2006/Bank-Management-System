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

    printf("Account List:\n");
    for(int i = 0; i < size; i++){
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Email: %s\n", accounts[i].email);
        printf("Mobile Number: %s\n", accounts[i].mobileNumber);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("Date Opened: %02d/%04d\n", accounts[i].dateOpened.month, accounts[i].dateOpened.year);
        printf("Status: %s\n", accounts[i].status ? "Active" : "Inactive");
        printf("-----------------------\n");
    }
}
