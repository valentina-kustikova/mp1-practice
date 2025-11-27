#include <stdio.h>
#include <windows.h>
#include <string.h>
#include<locale.h>
#include<time.h>
#define maxPath 260
struct fileInf
{
	char name[1000];
	ULONGLONG size;
};
struct fileInf files[1000];
int n = 0;
int CheckE(char path[])
{
	HANDLE prov;
	WIN32_FIND_DATAA fileD;
	prov = FindFirstFileA(path, &fileD);
	if (prov == INVALID_HANDLE_VALUE)
	{
		printf("Директории не существует\n");
		return 1;
	}
	else { FindClose(prov); return 0; }
}
void getL(char path[])
{
	HANDLE hand;
	WIN32_FIND_DATAA fileD;
	ULONGLONG fileSi;
	int i = 0;
	hand = FindFirstFileA(path, &fileD);
	while (FindNextFileA(hand, &fileD))
	{
		if (strcmp(fileD.cFileName, ".") != 0 && strcmp(fileD.cFileName, "..") != 0)
		{
			if ((((ULONGLONG)fileD.nFileSizeHigh << 32) | fileD.nFileSizeLow) != 0)
			{
				strcpy_s(files[i].name, 1000, fileD.cFileName);
				fileSi = ((ULONGLONG)fileD.nFileSizeHigh << 32) | fileD.nFileSizeLow;
				files[i].size = fileSi;
				i++;
			}
		}
	}
	FindClose(hand);
	n = i + 1;
}
void sortIn(struct fileInf list[], int amount)
{
	int i, j;
	for (i = 1; i < amount; i++)
	{
		j = i - 1;
		while (j >= 0 && list[j].size > list[j + 1].size)
		{
			struct fileInf temp = list[j + 1];
			list[j + 1] = list[j];
			list[j] = temp;
			j--;
		}
	}
}
void sortRe(struct fileInf list[], int amount)
{
	int i, j;
	for (i = 1; i < amount; i++)
	{
		j = i - 1;
		while (j >= 0 && list[j].size < list[j + 1].size)
		{
			struct fileInf temp = list[j + 1];
			list[j + 1] = list[j];
			list[j] = temp;
			j--;
		}
	}
}
void print(struct fileInf list[], int amount, int way, double time)
{
	int i;
	if (way == 1)
	{
		for (i = 1; i < amount; i++)
		{
			printf("%d. %s %llu байт(а)\n", i, files[i].name, files[i].size);
		}
	}
	else
	{
		for (i = 0; i < amount - 1; i++)
		{
			printf("%d. %s %llu байт(а)\n", i + 1, files[i].name, files[i].size);
		}
	}
	printf("Время сортировки: %f миллисекунд\n", time);
}
int main()
{
	int way = 1, ans = 1;
	char path[maxPath];
	clock_t start, end;
	setlocale(LC_ALL, "RUS");
	do {
		printf("Укажите путь: ");
		scanf_s("%s", path, (unsigned)sizeof(path));
		snprintf(path, maxPath, "%s\\\\*", path);
	} while (CheckE(path) != 0);
	getL(path);
	while (ans != 0)
	{
		do {
			printf("Метод сортировки(1 - по возрастанию размера, 2 - по убыванию размера): ");
			scanf_s("%d", &way);
		} while (way != 1 && way != 2);
		if (way == 1)
		{
			start = clock();
			sortIn(files, n);
			end = clock();
		}
		else {
			start = clock(); sortRe(files, n); end = clock();
		}
		print(files, n, way, (double)(end - start) * 1000 / CLOCKS_PER_SEC);
		do {
			printf("Cменить метод сортировки(1 - да, 0 - нет): ");
			scanf_s("%d", &ans);
		} while (ans != 1 && ans != 0);
	}
	return 0;
}