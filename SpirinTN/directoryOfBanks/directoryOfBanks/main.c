#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

#include "banks.h"
#include "auxiliary.h"

int main(int argc, char** argv) {
    int i;
    STATUS status;
    char* fileName = NULL;
    BANK* banks = NULL;
    int countBanks;

    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    if (argc < 2) {
        status = INSUFFICIENT_ARGUMENTS_ERROR;
        printFrame();
        printError(status);
        return status;
    }

    fileName = argv[1];
    status = readBanks(&banks, &countBanks, fileName);
    if (status != SUCCESS) {
        printFrame();
        printError(status);
        free(banks);
        banks = NULL;
        return status;
    }

    status = programCycle(banks, countBanks);

    for (i = 0; i < countBanks; i++) {
        free(banks[i].deposits);
    }
    free(banks);
    banks = NULL;

    return status;
}