#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define BUFFER_SIZE 2048
#define K 100
#define MAX_LEN 100

// Пузырьковая сортировка (1)
void bubble(int *a, ULONGLONG *size, int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - 1; j++)
		{
			if (size[a[j]] < size[a[j - 1]])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}
// Сортировка выбора (2)
void choose(int *a, ULONGLONG *size, int n)
{
	int i, j, tmp, idx;
	for (i = 0; i < n; i++)
	{
		idx = i;
		for (j = i + 1; j < n; i++)
		{
			if (size[a[idx]] > size[a[j]])
				idx = j;
		}
	}
	tmp = a[idx];
	a[idx] = a[i];
	a[i] = tmp;
}

// Сортировка подсчетом (3)
void count_sort(int *a, ULONGLONG *size, int n)
{
	int *b = (int*)malloc(K * sizeof(int));
	int i, j, idx = 0;
	int h = 0;
	for (i = 1; i < K; i++)
		b[i] = 0;
	for (i = 0; i < n; i++)
		b[size[a[i]]]++;
	for (i = 0; i < K; i++)
	{
		if (b[i] > 0)
		{
			h = 0;
			for (j = 0; j < b[i]; j++)
			{
				while (size[h] != i)
					h++;
				a[idx++] = h++;
			}
		}
	}
	free(b);
}
// Сортировка вставками (4)
void insert(int *a, ULONGLONG *size, int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		tmp = a[i];
		j = i - 1;
		while ((j >= 0) && (size[a[j]] > size[tmp]))
		{
			a[j + 1] = a[j];
			a[j] = tmp;
			j--;
		}
	}
}
// Быстрая сортировка (Хоара) (5)
void quick_split(int *a, ULONGLONG *size, int *i, int *j, ULONGLONG p)
{
	int tmp;
	do {
		while (size[a[(*i)]] < p)
			(*i)++;
		while (size[a[(*j)]] > p)
			(*j)--;
		if ((*i) <= (*j))
		{
			tmp = a[(*i)];
			a[(*i)] = a[(*j)];
			a[(*j)] = tmp;
			(*i)++;
			(*j)--;
		}
	} while ((*i) < (*j));
}

void quick_sort(int *a, ULONGLONG *size, int n1, int n2)
{
	int m = (n1 + n2) / 2;
	int i = n1, j = n2;
	quick_split(a, size, &i, &j, size[a[m]]);
	if (j > n1)
		quick_sort(a, size, n1, j);
	if (i < n2)
		quick_sort(a, size, i, n2);
}
// Сортировка слиянием (6)
void merge(int *a, ULONGLONG *size, int l, int m, int r)
{
	int i, j = m + 1, h, tmp;
	for (i = l; ((i < r) && (j <= r)); i++)
	{
		if (size[a[i]] > size[a[j]])
		{
			tmp = a[j];
			for (h = j; h > i; h--)
				a[h] = a[h - 1];
			a[i] = tmp;
			j++;
		}
	}

}

void merge_sort(int *a, ULONGLONG *size, int l, int r) 
{
	int m;
	if (l >= r) return;
	m = (l + r) / 2;
	merge_sort(a, size, l, m);
	merge_sort(a, size, m + 1, r);
	merge(a, size, l, m, r);
}


int ListDirectoryContents(const wchar_t *sDir, ULONGLONG **sizes, wchar_t ***names)
{
	int i = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t *sPath;
	sPath = (wchar_t*)malloc(BUFFER_SIZE * sizeof(wchar_t));
	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		return -1;
	}
	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
			i++;
	} while (FindNextFile(hFind, &fdFile));
	hFind = FindFirstFile(sPath, &fdFile);
	*names = (wchar_t**)malloc(i * sizeof(wchar_t*));
	*sizes = (ULONGLONG*)malloc(i * sizeof(ULONGLONG));
	i = 0;
	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
			(*names)[i] = (wchar_t*)malloc(BUFFER_SIZE * sizeof(wchar_t));
			(*sizes)[i] = fileSize;
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wsprintf((*names)[i], L"%s", sPath);
			i++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	free(sPath);
	return i;
}

void input(wchar_t **str_convert_to)
{
	char *input;
	*str_convert_to = (wchar_t*)malloc(BUFFER_SIZE * sizeof(wchar_t));
	input = (char*)malloc(BUFFER_SIZE * sizeof(char));
	fgets(input, BUFFER_SIZE, stdin);
	input[strlen(input) - 1] = '\0';
	swprintf(*str_convert_to, BUFFER_SIZE, L"%hs", input);
	free(input);
}

void print_menu()
{
	printf("Выберите сортировку на усмотрение:\n");
	printf("1 ПУЗЫРЬКОВАЯ СОРТИРОВКА          | 2 СОРТИРОВКА ВЫБОРОМ\n");
	printf("3 СОРТИРОВКА ПОДСЧЕТОМ            | 4 СОРТИРОВКА ВСТАВКАМИ\n");
	printf("5 БЫСТРАЯ СОРТИРОВКА (ХОАРА)      | 6 СОРТИРОВКА СЛИЯНИЕМ\n");
}

void Output(int *Idxes, wchar_t **names, ULONGLONG *sizes, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		wprintf(L"Файл: %s Размер: ", names[Idxes[i]]);
		printf("%lld байт", sizes[Idxes[i]]);
		printf("\n");
	}
}

void main()
{
	int c, i = 0;
	int* Idx;
	int count = 0;
	ULONGLONG* sizes;
	wchar_t** names;
	wchar_t* path = (wchar_t*)malloc(BUFFER_SIZE * sizeof(wchar_t));
	clock_t start, stop;
	float total_time = 0.0f;
	setlocale(LC_ALL, "Russian");

	do
	{
		printf("\nВведите путь к папке: ");
		input(&path);
		count = ListDirectoryContents(path, &sizes, &names);
		if (count == -1)
		{
			printf("Путь не найден\n");
			continue;
		}
		if (count == 0)
		{
			printf("В папке отсутствуют элементы\n");
			continue;
		}
	} while (count < 1);
	do {
		print_menu();
		Idx = (int*)malloc(count * sizeof(int));
		for (i = 0; i < count; i++)
			Idx[i] = i;
		scanf("%d", &c);
		start = clock();
		switch (c)
		{
		case 1:
			start = clock();
			bubble(Idx, sizes, count);
			stop = clock();
			break;
		case 2:
			start = clock();
			choose(Idx, sizes, count);
			stop = clock();
			break;
		case 3:
			start = clock();
			count_sort(Idx, sizes, count);
			stop = clock();
			break;
		case 4:
			start = clock();
			insert(Idx, sizes, count);
			stop = clock();
			break;
		case 5:
			start = clock();
			quick_sort(Idx, sizes, 0, count - 1);
			stop = clock();
			break;
		case 6:
			start = clock();
			merge_sort(Idx, sizes, 0, count - 1);
			stop = clock();
			break;
		}
		stop = clock();
		total_time = (float)(stop - start) / CLOCKS_PER_SEC;
		Output(Idx, names, sizes, count);
		printf("Время, затраченное на сортировку: %.3f с\n", total_time);
		free(Idx);
	} while (c != 7);
	for (i = 0; i < count; i++)
		free(names[i]);
	free(names);
	free(sizes);
	free(path);

}