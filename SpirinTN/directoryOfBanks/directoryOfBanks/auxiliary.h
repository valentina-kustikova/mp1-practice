#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "banks.h"

#define MAIN_FRAME "\
|-----------------------------|\n\
|      Справочник банков      |\n\
|-----------------------------|\n\n"

#define OPERATIONS "\
1. Показать список банков\n\
2. Найти банк с максимальным процентом для вклада\n\
0. Выход\n\n"

void printFrame();
int inputOperation();
void printError(STATUS status);
STATUS programCycle(BANK* banks, int countBanks);
STATUS printListBanks(BANK* banks, int countBanks);
STATUS searchMaxInterface(BANK* banks, int countBanks);
void inputDepositType(char* depositType, int maxLen);

#endif
