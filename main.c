#include <stdio.h>
#include "menu.h"
#include "system_structs.h"
#include "login.h"
#include "load_Accounts.h"

int main() {

    loadaccounts(accounts, 100, &accountsCount);
    login();
    displayMenu();
    return 0;
}