#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliary.h"

void printFrame() {
    system("cls");
    printf(MAIN_FRAME);
}

int inputOperation() {
    int operation;
    printf(OPERATIONS);
    printf("Введите операцию: ");
    scanf("%d", &operation);
    while (operation < 0 || operation > 2) {
        printf("Неверная операция! Введите операцию: ");
        scanf("%d", &operation);
    }
    return operation;
}

void printError(STATUS status) {
    switch (status) {
    case INSUFFICIENT_ARGUMENTS_ERROR:
        printf("Количество аргументов при запуске программы меньше двух!\n");
        break;
    case ERROR_MEMORY:
        printf("Ошибка выделения памяти!\n");
        break;
    case INVALID_FILE:
        printf("Текстовый файл некорректный!\n");
        break;
    case FILE_OPENING_ERROR:
        printf("Ошибка при открытии файла!\n");
        break;
    case FILE_CLOSE_ERROR:
        printf("Ошибка при закрытии файла!\n");
        break;
    case ERROR_NO_BANKS:
        printf("В справочнике банков нет!\n");
        break;
    case ERROR_NO_DEPOSIT_TYPE:
        printf("Вклада с указанным названием не найдено ни в одном банке!\n");
        break;
    }
}

STATUS programCycle(BANK* banks, int countBanks) {
    int operation;
    STATUS status = SUCCESS;
    while (1) {
        if (status != SUCCESS) {
            printError(status);
            break;
        }
        printFrame();
        operation = inputOperation();

        if (operation == 1) {
            printFrame();
            status = printListBanks(banks, countBanks);
        }
        else if (operation == 2) {
            status = searchMaxInterface(banks, countBanks);
        }
        else {
            break;
        }
    }
    return status;
}

STATUS printListBanks(BANK* banks, int countBanks) {
    int i, j;
    if (countBanks == 0) {
        return ERROR_NO_BANKS;
    }

    for (i = 0; i < countBanks; i++) {
        printf("%d. %s\nФорма собственности: %s\nВклады:\n", i + 1, banks[i].name, banks[i].ownership);
        for (j = 0; j < banks[i].depositsCount; j++) {
            printf("   %s: %.2f%%\n", banks[i].deposits[j].type, banks[i].deposits[j].percent);
        }
        printf("\n");
    }
    system("pause");
    return SUCCESS;
}

STATUS searchMaxInterface(BANK* banks, int countBanks) {
    char depositType[LENGTH_STRING + 1];
    BANK* resultBank = NULL;
    float maxPercent;
    STATUS status;

    printFrame();
    inputDepositType(depositType, sizeof(depositType));

    status = searchMaxPercent(banks, countBanks, depositType, &resultBank, &maxPercent);

    if (status == ERROR_NO_DEPOSIT_TYPE) {
        printError(status);
        return SUCCESS;
    }

    if (status != SUCCESS) {
        return status;
    }

    printf("\nБанк с максимальным процентом для вклада \"%s\":\n", depositType);
    printf("%s\nФорма собственности: %s\nПроцент: %.2f%%\n\n",
        resultBank->name, resultBank->ownership, maxPercent);
    system("pause");
    return SUCCESS;
}

void inputDepositType(char* depositType, int maxLen) {
    printf("Введите название вклада: ");
    while (getchar() != '\n');
    fgets(depositType, maxLen, stdin);
    depositType[strcspn(depositType, "\n")] = '\0';
}