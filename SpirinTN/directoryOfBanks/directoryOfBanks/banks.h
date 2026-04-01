#ifndef BANKS_H
#define BANKS_H

#define LENGTH_STRING 255

typedef enum {
    SUCCESS,
    INSUFFICIENT_ARGUMENTS_ERROR,
    ERROR_MEMORY,
    INVALID_FILE,
    FILE_OPENING_ERROR,
    FILE_CLOSE_ERROR,
    ERROR_NO_BANKS,
    ERROR_NO_DEPOSIT_TYPE
} STATUS;

typedef struct {
    char type[LENGTH_STRING + 1];
    float percent;
} DEPOSIT;

typedef struct {
    char name[LENGTH_STRING + 1];
    char ownership[LENGTH_STRING + 1];
    DEPOSIT* deposits;
    int depositsCount;
} BANK;

STATUS readBanks(BANK** banks, int* countBanks, char* fileName);
int getCountBanks(FILE* fp);
STATUS stringToBank(FILE* fp, BANK* banks, int count);
STATUS parseDeposits(BANK* bank, char* depositsStr);
STATUS searchMaxPercent(BANK* banks, int countBanks, char* depositType, BANK** resultBank, float* maxPercent);
void toLowerCase(char* str);

#endif
