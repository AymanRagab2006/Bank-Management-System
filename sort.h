#ifndef SORT_H
#define SORT_H
#include "system_structs.h"


void sortByName(Account accounts[], int size);
void sortByBalance(Account accounts[], int size);
void sortByDateOpened(Account accounts[], int size);
void sortByStatus(Account accounts[], int size);

#endif // SORT_H