#ifndef searchAccount_H
#define searchAccount_H
#include "system_structs.h"

Account *searchByAccountNumber(Account acc[], int count);
void searchByAccountName(Account acc[], int count);
void printAccount(Account *acc);

#endif