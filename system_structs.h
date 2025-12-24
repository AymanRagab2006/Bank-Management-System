#ifndef SYSTEM_STRUCTS_H
#define SYSTEM_STRUCTS_H

typedef struct {
    int month;
    int year;
} Date;

typedef struct {
    int accountNumber;
    char name[50];
    char email[50];
    char mobileNumber[11];
    float balance;
    Date dateOpened;
    int status; // 1 for active, 0 for inactive
} Account;

#endif // SYSTEM_STRUCTS_H