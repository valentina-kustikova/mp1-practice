#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "banks.h"

STATUS readBanks(BANK** banks, int* countBanks, char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        return FILE_OPENING_ERROR;
    }

    *countBanks = getCountBanks(fp);
    if (*countBanks == 0) {
        fclose(fp);
        return ERROR_NO_BANKS;
    }

    rewind(fp);
    *banks = (BANK*)malloc((*countBanks) * sizeof(BANK));
    if (*banks == NULL) {
        fclose(fp);
        return ERROR_MEMORY;
    }

    STATUS status = stringToBank(fp, *banks, *countBanks);
    if (fclose(fp) != 0) {
        return FILE_CLOSE_ERROR;
    }
    return status;
}

int getCountBanks(FILE* fp) {
    int count = 0;
    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        count++;
    }
    return count;
}

STATUS stringToBank(FILE* fp, BANK* banks, int count) {
    int indexBank = 0;
    char line[1000];

    while (indexBank < count && fgets(line, sizeof(line), fp)) {
        STATUS status;
        char* token = NULL;
        line[strcspn(line, "\r\n")] = '\0';

        token = strtok(line, ";");
        if (token == NULL) return INVALID_FILE;
        strncpy(banks[indexBank].name, token, LENGTH_STRING);
        banks[indexBank].name[LENGTH_STRING] = '\0';

        token = strtok(NULL, ";");
        if (token == NULL) return INVALID_FILE;
        strncpy(banks[indexBank].ownership, token, LENGTH_STRING);
        banks[indexBank].ownership[LENGTH_STRING] = '\0';

        token = strtok(NULL, "\n");
        if (token == NULL) return INVALID_FILE;
        status = parseDeposits(&banks[indexBank], token);
        if (status != SUCCESS) {
            return status;
        }

        indexBank++;
    }
    return SUCCESS;
}

STATUS parseDeposits(BANK* bank, char* depositsStr) {
    int i;
    int count = 0;
    int countColon = 0;
    char* token;
    char temp[600];
    strcpy(temp, depositsStr);

    token = strtok(temp, ";");
    while (token != NULL) {
        count++;
        token = strtok(NULL, ";");
    }
    //printf("%d", count); 50 ÌÈÍÓÒ ÑÒÐÀÄÀÍÈÉ ÈÇ-ÇÀ ÝÒÎÉ ÑÒÐÎ×ÊÈ ! ! !

    if (count == 0) {
        return INVALID_FILE;
    }

    bank->deposits = (DEPOSIT*)malloc(count * sizeof(DEPOSIT));
    if (bank->deposits == NULL) {
        return ERROR_MEMORY;
    }
    bank->depositsCount = count;

    strcpy(temp, depositsStr);
    i = 0;
    token = strtok(temp, ";");
    while (token != NULL && i < count) {
        char* colon = strchr(token, ':');
        if (colon != NULL) {
            countColon++;
            int typeLen = colon - token;
            if (typeLen > LENGTH_STRING) typeLen = LENGTH_STRING;
            strncpy(bank->deposits[i].type, token, typeLen);
            bank->deposits[i].type[typeLen] = '\0';
            bank->deposits[i].percent = (float)atof(colon + 1);

        }
        i++;
        token = strtok(NULL, ";");
    }
    if (count != countColon) {
        return INVALID_FILE;
    }
    return SUCCESS;
}

STATUS searchMaxPercent(BANK* banks, int countBanks, char* depositType, BANK** resultBank, float* maxPercent) {
    int i, j;
    char lowerDepositType[LENGTH_STRING + 1];
    strncpy(lowerDepositType, depositType, LENGTH_STRING);
    lowerDepositType[LENGTH_STRING] = '\0';
    toLowerCase(lowerDepositType);

    *maxPercent = -1.0f;
    *resultBank = NULL;

    for (i = 0; i < countBanks; i++) {
        for (j = 0; j < banks[i].depositsCount; j++) {
            char lowerType[LENGTH_STRING + 1];
            strncpy(lowerType, banks[i].deposits[j].type, LENGTH_STRING);
            lowerType[LENGTH_STRING] = '\0';
            toLowerCase(lowerType);
            if (strcmp(lowerType, lowerDepositType) == 0) {
                if (banks[i].deposits[j].percent > *maxPercent) {
                    *maxPercent = banks[i].deposits[j].percent;
                    *resultBank = &banks[i];
                }
            }
        }
    }

    if (*resultBank == NULL) {
        return ERROR_NO_DEPOSIT_TYPE;
    }
    return SUCCESS;
}

void toLowerCase(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}