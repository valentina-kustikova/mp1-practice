#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <tchar.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <stdlib.h>
#include <synchapi.h>
#include "SORT.h"
#define MAX_PATH 260
#define EOF 27
#define SEARCH_MASK "/*"
char* COPYPATH;

struct FILE_INFO{
	wchar_t fName[MAX_PATH];
	unsigned long long int fSizeL;
	unsigned long long int fSizeH;
}FILES[100000], *P;




unsigned long long int SORT_SIZE[100000];




void main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Rus");
	WIN32_FIND_DATA DATA;
	HANDLE hFind;
	int count = 0;
	COPYPATH = (char*)malloc(MAX_PATH * sizeof(char));


	int choose;
	printf("Hello, choose your sort metod: ");
	scanf_s("%d", &choose);
	getchar();



	char ENTERED_PATH[MAX_PATH];
	printf("\nEnter your path:\t");
	gets(ENTERED_PATH);
	strcat_s(&ENTERED_PATH, MAX_PATH, SEARCH_MASK);
	puts(&ENTERED_PATH);



	hFind = FindFirstFile(ENTERED_PATH, &DATA);
	int i = 0;
	while (FindNextFile(hFind, &DATA) != 0) {
		if ((DATA.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY) || (strcmp(DATA.cFileName, "..") == 0))
			continue;
		/*printf("\t%ld", DATA.nFileSizeLow);
		printf("\t%ld", DATA.nFileSizeHigh);
		printf("\t%s \n", DATA.cFileName);*/
		P = &FILES[i];
		P -> fSizeL = DATA.nFileSizeLow;
		P -> fSizeH = DATA.nFileSizeHigh;
		strcpy_s(P->fName, MAX_PATH, DATA.cFileName);
		i++;
		count++;
	}




	for (int i = 0; i < count; i++) {
		SORT_SIZE[i] = FILES[i].fSizeL;
		//printf("%lld \t", SORT_SIZE[i]);
	}



	clock_t start = clock();
	switch (choose) {
		case 1: sorto(SORT_SIZE, count); break;
		case 2: insert_sort(SORT_SIZE, count); break;
		case 3: fastsort(SORT_SIZE, count); break;
	}
	clock_t end = clock();
	long double time = 0.0;
	time += (double)(end - start) / CLOCKS_PER_SEC;



	int indx[100000];
	for (int i = 0; i < count; i++) {
		for (int k = 0; k < count; k++) {
			if (SORT_SIZE[i] == FILES[k].fSizeL)
				indx[i] = k;
		}
	}


	for (int i = 0; i < count; i++) {
		printf("%lld \t", SORT_SIZE[i]);
		int l = indx[i];
		printf("%s \n", FILES[l].fName);
	}

	printf("\n\nЧисло элементов: %d \nВремя выполнения сортировки: %Lf", count, time);


}