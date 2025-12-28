#include "system_structs.h"

Account accounts[MAX_ACCOUNTS];
int accountsCount = 0;
Account tempAccounts[MAX_ACCOUNTS];
int tempAccountsCount = 0;

void copyAccountData(Account dest[], Account src[], int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = src[i];
    }
}