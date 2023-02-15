#include "utils.h"
#include <stdio.h>
#include <windef.h>

void output(char** filesName, unsigned long* filesSize, int* filesIndex, int count, long long time)
{
    for (int i = 0; i < count; i++) {
        printf("%s", filesName[filesIndex[i]]);
        printf(" %lu B\n", filesSize[i]);
    }
    printf("It took %lld milliseconds to sort\n\n", time);
}

void userInput(char** a, wchar_t** path, HANDLE hf, WIN32_FIND_DATA FindFileData) {
    do {
        printf("Enter the open path of the directory with the files: \n");
        scanf("%s", a);
        strcat(a, "\\*.*");
        mbstowcs(path, a, strlen(a) + 1);
        hf = FindFirstFileW(path, &FindFileData);

    } while (hf == INVALID_HANDLE_VALUE);
    printf("Your path: %s \n", a);
}

void add(unsigned long* copy, int* index, unsigned long* size, int count) {
    for (int i = 0; i < count; i++) {
        copy[i] = size[i];
        index[i] = i;
    }
}

int filesAmount(wchar_t** path, HANDLE hf, WIN32_FIND_DATA FindFileData) {
    int count = 0;
    hf = FindFirstFile(path, &FindFileData);
    if (hf != INVALID_HANDLE_VALUE) {
        do {
            if (wcscmp(FindFileData.cFileName, L".") != 0 && wcscmp(FindFileData.cFileName, L"..") != 0) {
                count++;
            }

        } while (FindNextFile(hf, &FindFileData) != 0);
    }
    return count;
}

int choice() {
    int input;
    printf("|-----------------------------------------|\n");
    printf("Selected action:\n");
    printf("1) Merge Sort\n");
    printf("2) Quick Sort\n");
    printf("3) Bubble Sort\n");
    printf("4) Change dir\n");
    printf("5) Exit\n");
    printf("|-----------------------------------------|\n");
    if (scanf("%d", &input) != 1) {
        printf("Enter only numbers...");
        return NULL;
    }
    return input;
}

void fill(HANDLE hf, WIN32_FIND_DATA FindFileData, char** fileNames, unsigned long* sizes) {
    int j = 0;
    if (hf != INVALID_HANDLE_VALUE) {
        do {
            if (wcscmp(FindFileData.cFileName, L".") != 0 && wcscmp(FindFileData.cFileName, L"..") != 0) {
                fileNames[j] = (char*)malloc(MAX_PATH * sizeof(char));
                wcstombs(fileNames[j], FindFileData.cFileName, MAX_PATH);
                sizes[j] = FindFileData.nFileSizeLow;
                j++;

            }

        } while (FindNextFile(hf, &FindFileData) != 0);
    }
}

void info(int count, char** fileNames, unsigned long* sizes) {
    int i;
    printf("\nFiles amount in the directory: %d\n\n", count);
    for (i = 0; i < count; i++) {
        printf("%s size: %d B\n", fileNames[i], sizes[i]);
    }
}

void memFree(unsigned long* a, unsigned long* b) {
    free(a);
    free(b);
}

void memFreeMulti(char* userStr, char** fileNames, wchar_t* path, unsigned long* sizes, int count) {
    int i;
    free(userStr);
    for (i = 0; i < count; i++)
        free(fileNames[i]);
    free(fileNames);
    free(path);
    free(sizes);
}

