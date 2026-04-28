#include "reader.h"
#include <windows.h>


int fcount(char dir[], int* pmx) {
	int k = 0;
	WIN32_FIND_DATA data;
	HANDLE hFind = FindFirstFileA(dir, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes != 32) continue;
			if (strlen(data.cFileName) > *pmx) *pmx = strlen(data.cFileName);
			k++;
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
	else {
		printf("Несуществующая директория!\n");
		return -1;
	}
	return k;
}

void read(char dir[], char flag, char** name, int* sz, int* num) {
	WIN32_FIND_DATAA data;
	HANDLE hFind = FindFirstFileA(dir, &data);
	int i = 0;
	hFind = FindFirstFileA(dir, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes != 32) continue;
			if (flag) printf("Прочитан файл %s размером %d байтов\n", data.cFileName, data.nFileSizeLow);
			strcpy(name[i], data.cFileName);
			sz[i] = data.nFileSizeLow;
			num[i] = i;
			i++;
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
}