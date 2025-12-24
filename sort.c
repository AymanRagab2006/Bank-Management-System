#include <stdio.h>
#include <string.h>
#include "sort.h"


void sortByName(Account accounts[], int size) {
    Account temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(accounts[i].name, accounts[j].name) > 0) {
                temp = accounts[i];
                accounts[i] = accounts[j];
                accounts[j] = temp;
            }
        }
    }
}

void sortByBalance(Account accounts[], int size) {
    Account temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (accounts[i].balance > accounts[j].balance) {
                temp = accounts[i];
                accounts[i] = accounts[j];
                accounts[j] = temp;
            }
        }
    }
}

void sortByDateOpened(Account accounts[], int size) {
    Account temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (accounts[i].dateOpened.year > accounts[j].dateOpened.year ||
                (accounts[i].dateOpened.year == accounts[j].dateOpened.year &&
                 accounts[i].dateOpened.month > accounts[j].dateOpened.month)) {
                temp = accounts[i];
                accounts[i] = accounts[j];
                accounts[j] = temp;
            }
        }
    }
}

void sortByStatus(Account accounts[], int size) {
    Account temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (accounts[i].status > accounts[j].status) {
                temp = accounts[i];
                accounts[i] = accounts[j];
                accounts[j] = temp;
            }
        }
    }
}