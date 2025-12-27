#ifndef searchAccount_H
#define searchAccount_H
#include "system_structs.h"

Account *searchByAccountNumber(Account acc[], int count, long long target, int *foun);
void searchByAccountName(Account acc[], int count, char target[]);

#endif
