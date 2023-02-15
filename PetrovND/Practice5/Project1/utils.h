#include <Windows.h>
#ifndef _UTILS_H
#define _UTILS_H
void userInput(char** a, wchar_t** path, HANDLE hf, WIN32_FIND_DATA FindFileData);
void output(char** filesName, unsigned long* filesSize, int* filesIndex, int count, long long time);
int filesAmount(wchar_t** path, HANDLE hf, WIN32_FIND_DATA FindFileData);
void add(unsigned long* copy, int* index, unsigned long* size, int count);
int choice();
void fill(HANDLE hf, WIN32_FIND_DATA FindFileData, char** fileNames, unsigned long* sizes);
void info(int count, char** fileNames, unsigned long* sizes);
void memFree(unsigned long* a, unsigned long* b);
void memFreeMulti(char* userStr, char** fileNames, wchar_t* path, unsigned long* sizes, int count);
#endif // !_UTILS_H
