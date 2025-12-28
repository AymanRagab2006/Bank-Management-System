#ifndef SYSTEM_STRUCTS_H
#define SYSTEM_STRUCTS_H

#define MAX_ACCOUNTS 100

typedef struct {
    int month;
    int year;
} Date;

typedef struct {
    long long accountNumber;
    char name[50];
    char email[50];
    float balance;
    char mobileNumber[11];
    Date dateOpened;
    char status[10];
} Account;

extern Account accounts[MAX_ACCOUNTS];
extern int accountsCount;

extern Account tempAccounts[MAX_ACCOUNTS];
extern int tempAccountsCount;

void copyAccountData(Account dest[], Account src[], int count);

#endif // SYSTEM_STRUCTS_H