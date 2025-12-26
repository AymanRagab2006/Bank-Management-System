#ifndef SYSTEM_STRUCTS_H
#define SYSTEM_STRUCTS_H

typedef struct
{
    int month;
    int year;
} Date;

typedef struct
{
    long long accountNumber;
    char name[50];
    char email[50];
    float balance;
    char mobileNumber[11];
    Date dateOpened;
    char status[10]; // 1 for active, 0 for inactive
} Account;

#endif
