#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#define K 10000
#define MAX_BUFF 2048

struct file
{
	unsigned long size;
	wchar_t name[32];
};

int ListDirectoryContents(const wchar_t *sDir, struct file a[], int n)
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];
	int i = 0;

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Путь не найден: [%s]\n", sDir);
		return 1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
			struct file file;
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wcsncpy(file.name, sPath, 100);
			file.size = fileSize;
			a[i] = file;
			i++;
		}
	} while (FindNextFile(hFind, &fdFile) && i < n);
	FindClose(hFind);
	return 0;
}

int NumOfFiles(const wchar_t *sDir)
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];
	int i = 0;

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			i++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return i;
}

void put_Patch(wchar_t* str, char* str1)
{
	fgets(str1, 2048, stdin);
	str1[strlen(str1) - 1] = '\0';
	swprintf(str, 2048, L"%hs", str1);
}

void chooseSortSort(struct file a[], long size, int c)
{
	long i, j;
	struct file min;
	long min_idx;
	for (i = 0; i < size; i++)
	{
		min_idx = i;
		min = a[i];
		for (j = i + 1; j < size; j++)
		{
			if (comparing(a[j], min, c) == 1)
			{
				min = a[j];
				min_idx = j;
			}
		}
		a[min_idx] = a[i];
		a[i] = min;
	}
}

int comparing(struct file a, struct file b, int c)
{
	if (c == 1)
		if (a.size > b.size)
			return 1;
		else
			return 0;
	if (c == 2)
		if (a.size < b.size)
			return 1;
		else
			return 0;
}

void quickSort(struct file *a, long size, int c)
{
	long i = 0, j = size - 1;
	struct file buf, mid;
	mid = a[size >> 1];
	do
	{
		while (comparing(a[i], mid, c) == 1)
			i++;
		while (comparing(mid, a[j], c) == 1)
			j--;
		if (i <= j)
		{
			buf = a[i];
			a[i] = a[j];
			a[j] = buf;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		quickSort(a, j + 1, c);
	if (size > i)
		quickSort(a + i, size - i, c);
}

void bubbleSort(struct file a[], long size, int c)
{
	long i, j;
	struct file tmp;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (comparing(a[j], a[j - 1], c) == 1)
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}


void insertSort(struct file a[], long size, int c)
{
	long i, j;
	struct file tmp;
	for (i = 0; i < size; i++)
	{
		tmp = a[i];
		j = i - 1;
		while (j >= 0 && (comparing(tmp, a[j], c) == 1))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}

void merge(struct file a[], long l, long mid, long r, int c)
{
	long p1 = mid - l + 1;
	long p2 = r - mid;
	int i, j;
	int d;
	struct file* L = (struct file*)malloc(p1 * sizeof(struct file));
	struct file* R = (struct file*)malloc(p2 * sizeof(struct file));
	for (i = 0; i < p1; i++)
		L[i] = a[l + i];
	for (j = 0; j < p2; j++)
		R[j] = a[mid + 1 + j];
	i = 0;
	j = 0;
	d = l;
	while (i < p1 && j < p2)
	{
		if (comparing(L[i], R[j], c) == 1)
		{
			a[d] = L[i];
			i++;
		}
		else
		{
			a[d] = R[j];
			j++;
		}
		d++;
	}
	while (i < p1)
	{
		a[d] = L[i];
		i++;
		d++;
	}
	while (j < p2)
	{
		a[d] = R[j];
		j++;
		d++;
	}
}

void mergeSort(struct file a[], long l, long r, int c)
{
	long mid;
	if (l < r)
	{
		mid = l + (r - l) / 2;
		mergeSort(a, l, mid, c);
		mergeSort(a, mid + 1, r, c);
		merge(a, l, mid, r, c);
	}
}

void countingSort(struct file a[], int size, int k)
{
	int i, b = 0;
	int j;
	struct file* c = (struct file*)malloc(K * sizeof(struct file));
	for (i = 0; i < size; i++)
		c[a[i].size] = a[i];
	for (j = 0; j < K; j++)
		if (a[j].size == 0)
		{
			a[b] = c[j];
			b++;
		}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	wchar_t* wt;
	struct file* fi;
	clock_t start, stop;
	char* a;
	int check, num = 0, mode_sort = 0, exit = 1, i, n, N = 0;
    float t = 0;
	printf("Введите путь к директории с файлами:\n");
	wt = (wchar_t*)malloc(MAX_BUFF);
	a = (char*)malloc(MAX_BUFF);
	put_Patch(wt, a);
	n = NumOfFiles(wt);
	fi = (struct file*)malloc(n * sizeof(struct file));
	check = ListDirectoryContents(wt, fi, n);
	if (check == 0)
	{
		printf("В данной директории файлы не найдены\n");
		return;
	}
	while (1)
	{
		printf("Выберите тип сортировки:\n");
		printf("1 - Вставками\n");
		printf("2 - Слиянием\n");
		printf("3 - Пузырковый\n");
		printf("4 - Выбором\n");
		printf("5 - Подсчётом\n");
		printf("6 - Хоара\n");
		do
		{
			scanf("%d", &num);
		} while (num < 1 || num > 6);
		printf("Выберите режим сортировки:\n1 - по убыванию, 2 - по возрастанию\n");
		do
		{
			scanf("%d", &mode_sort);
		} while (mode_sort < 1 || mode_sort > 2);
		switch (num)
		{
		case 1:
			start = clock();
			insertSort(a, N, mode_sort);
			stop = clock();
			break;
		case 2:
			start = clock();
			mergeSort(a, 0, N - 1, mode_sort);
			stop = clock();
			break;
		case 3:
			start = clock();
			bubbleSort(a, N, mode_sort);
			stop = clock();
			break;
		case 4:
			start = clock();
			chooseSortSort(a, N, mode_sort);
			stop = clock();
			break;
		case 5:
			start = clock();
			countingSort(a, N, mode_sort);
			stop = clock();
			break;
		case 6:
			start = clock();
			quickSort(a, N, mode_sort);
			stop = clock();
			break;
		}
		t = stop - start;
		printf("Сортировка выполнена за %.5f\n", t / CLOCKS_PER_SEC);
		printf("1 - Начать заного   2 - Выйти : ");
		scanf("%d", &exit);
		free(fi);
		fi = (struct file*)malloc(n * sizeof(struct file));
		ListDirectoryContents(wt, fi, n);
		if (exit == 0) return;
	}
}