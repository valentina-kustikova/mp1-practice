#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include<locale.h>
#include<time.h>

#define maxPath 260

struct fileInf
{
	char name[100];
	ULONGLONG size;
};

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

int count(char path[])
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
				i++;
			}
		}
	}
	FindClose(hand);
	return i;
}

void getL(char path[], int n, struct fileInf list[], struct fileInf ns_list[])
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
				strcpy_s(list[i].name, 100, fileD.cFileName);
				strcpy_s(ns_list[i].name, 100, fileD.cFileName);
				fileSi = ((ULONGLONG)fileD.nFileSizeHigh << 32) | fileD.nFileSizeLow;
				list[i].size = fileSi;
				ns_list[i].size = fileSi;
				i++;
			}
		}
	}
	FindClose(hand);
}

void swap(struct fileInf* x, struct fileInf* y)
{
	struct fileInf temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

void simple_sort(struct fileInf list[], int amount)
{
	int i, j;
	for (i = 0; i < amount; i++)
	{
		for (j = i + 1; j < amount; j++)
		{
			if (list[i].size > list[j].size)
			{
				swap(&list[i], &list[j]);
			}
		} 
	}
}

void select_sort(struct fileInf list[], int amount)
{
	int i, j, min_idx;
	for (i = 0; i < amount; i++)
	{
		min_idx = i;
		struct fileInf temp;
		for (j = i + 1; j < amount; j++)
		{
			if (list[min_idx].size > list[j].size)
			{
				min_idx = j;
			}
		}
		swap(&list[i], &list[min_idx]);
	}
}

void insert_sort(struct fileInf list[], int amount)
{
	int i, j;
	for (i = 1; i < amount; i++)
	{
		j = i - 1;
		while (j >= 0 && list[j].size > list[j + 1].size)
		{
			swap(&list[j+1], &list[j]);
			j--;
		}
	}
}

void merge(struct fileInf list[], int l, int m, int r, int n)
{
	struct fileInf* b = (struct fileInf*)malloc(n * sizeof(struct fileInf));
	int k = 0, it1 = 0, it2 = 0;
	while (it1 + l <= m && it2 + m + 1 <= r)
	{
		if(list[l+it1].size < list[m+1+it2].size)
		{
			b[k++] = list[l + (it1++)];
		}
		else { b[k++] = list[m + 1 + (it2++)]; }
	}
	while (l + it1 <= m) { b[k++] = list[l + (it1++)]; }
	while (m + 1 + it2 <= r) { b[k++] = list[m + 1 + (it2++)]; }
	for (it1 = 0; it1 < k; it1++)
	{
		list[l + it1] = b[it1];
	}
	free(b);
}

void merge_sort(struct fileInf list[], int l, int r, int n)
{
	int m;
	if (l + 1 > r) { return; }
	m = l + (r - l) / 2;
	merge_sort(list, l, m, n);
	merge_sort(list, m + 1, r, n);
	merge(list, l, m, r, n);
}

void quick_sort(struct fileInf list[], int n1, int n2)
{
	int mid = n1 + (n2 - n1) / 2;
	int i = n1, j = n2, p = list[mid].size;
	do
	{
		while (list[i].size < p) { i++; }
		while (list[j].size > p) { j--; }
		if (i <= j)
		{
			swap(&list[i], &list[j]);
			i++; j--;
		}
	} while (i <= j);
	if (n1 < j) { quick_sort(list, n1, j); }
	if (i < n2) { quick_sort(list, i, n2); }
}

void refill_list(struct fileInf list[], struct fileInf ns_list[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		list[i] = ns_list[i];
	}	
}

void print(struct fileInf list[], struct fileInf ns_list[], int amount, double time)
{
	int i;
	for (i = 0; i < amount; i++)
	{
		printf("%d. %s %llu байт(а)\n", i+1, list[i].name, list[i].size);
	}
	printf("Время сортировки: %.2f миллисекунд\n", time);
	refill_list(list, ns_list, amount);
}

int main()
{
	int way = 1, ans = 1, n;
	char path[maxPath];
	struct fileInf* list;
	struct fileInf* ns_list;
	clock_t start, end;
	setlocale(LC_ALL, "RUS");
	do {
		printf("Укажите путь: ");
		scanf_s("%s", path, (unsigned)sizeof(path));
		snprintf(path, maxPath, "%s\\\\*", path);
	} while (CheckE(path) != 0);
	n = count(path);
	list = (struct fileInf*)malloc((n) * sizeof(struct fileInf));
	ns_list = (struct fileInf*)malloc((n) * sizeof(struct fileInf));
	getL(path, n, list, ns_list);
	while (ans != 0)
	{
		do {
			printf("Метод сортировки(1 - простейшая, 2 - выбором, " );
			printf("3 - вставками, 4 - слиянием, 5 - быстрая): ");
			scanf_s("%d", &way);
		} while (way != 1 && way != 2 && way!= 3 && way != 4 && way != 5);
		switch (way)
		{
		case 1: start = clock(); simple_sort(list, n); end = clock();
			break;
		case 2: start = clock(); select_sort(list, n); end = clock();
			break;
		case 3: start = clock(); insert_sort(list, n); end = clock();
			break;
		case 4: start = clock(); merge_sort(list, 0, n-1, n); end = clock();
			break;
		case 5: start = clock(); quick_sort(list, 0, n - 1); end = clock();
		}
		print(list, ns_list, n, (double)(end - start) * 1000 / CLOCKS_PER_SEC);
		do {
			printf("Cменить метод сортировки(1 - да, 0 - нет): ");
			scanf_s("%d", &ans);
		} while (ans != 1 && ans != 0);
	}
	return 0;
}