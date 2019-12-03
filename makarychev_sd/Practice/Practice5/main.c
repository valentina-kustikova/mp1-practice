#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define T 2048

typedef struct
{
	wchar_t name[T];
	ULONGLONG Size;
}files;

void choose(int n, files b[])
{
	int i, min, j, min_idx;
	for (i = 0; i < n; i++)
	{
		min = b[i].Size;
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (b[j].Size < min)
			{
				min = b[j].Size;
				min_idx = j;
			}
		}
		b[min_idx].Size = b[i].Size;
		b[i].Size = min;
	}
}


void insert(int n, files b[])
{
	int i, tmp, j;
	for (i = 1; i < n; i++)
	{
		tmp = b[i].Size;
		j = i - 1;
		while ((j >= 0) && (b[j].Size > tmp))
		{
			b[j + 1].Size = b[j].Size;
			b[j].Size = tmp;
			j--;
		}
	}
}

void bubble(int n, files b[])
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (b[j - 1].Size > b[j].Size)
			{
				tmp = b[j].Size;
				b[j].Size = b[j - 1].Size;
				b[j - 1].Size = tmp;
			}
		}
	}
}

void count_sort(int n, files b[], int k)
{
	int count[] = { 0 }, i, j, idx;
	for (i = 0; i < n; i++)
	{
		count[b[i].Size]++;
		idx = 0;
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < count[i]; j++)
		{
			b[idx++].Size = i;
		}
	}
}
void merge(struct files a[], long l, long m, long r)
{
	long q1 = m - l + 1;
	long q2 = r - m;
	int i, j;
	int d;
	struct files* L;
	struct files* R;
	for (i = 0; i < q1; i++)
		L[i] = a[l + i];
	for (j = 0; j < q2; j++)
		R[j] = a[m + 1 + j];
	i = 0;
	j = 0;
	d = l;
	while (i < q1)
	{
		a[d] = L[i];
		i++;
		d++;
	}
	while (j < q2)
	{
		a[d] = R[j];
		j++;
		d++;
	}
}

void merge_sort(struct fles a[], long l, long r)
{
	long m;
	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void quick_sort(files a[], int l, int r)
{
	int pidx = (l + r) / 2;
	int i = l, j = r;
	void quick_split(int, int*, int*, int);
	quick_split(a, &i, &j, a[pidx].Size);
	if (i < r)
		quick_sort(a, i, r);
	if (j > l)
		quick_sort(a, l, j);
}

void quick_split(int a[], int *i, int *j, int p)
{
	do
	{
		while (a[*i] < p)
			*i++;
		while (a[*j] > p)
			*j--;
		if (*i < *j)
		{
			int tmp = a[*i];
			a[*i] = a[*j];
			a[*j] = tmp;
			*i++;
			*j--;
		}
	} while (*i < *j);
}

void print(files b[], float y, int n)
{
	int i;
	for (i = 0; i < n; i++)
		wprintf(L"File: %ls Size: %lld\n", b[i].name, b[i].Size);
	printf("время сортировки = %f", y);
}

int sum_files(const wchar_t *sDir)
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
int ListDirectoryContents(const wchar_t *sDir, files a[], int n)
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];
	int i = 0;

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Path not found: [%s]\n", sDir);
		return 1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
			files file;
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wcsncpy(file.name, sPath, 50);
			file.Size = fileSize;
			a[i] = file;
			i++;
		}
	} while (FindNextFile(hFind, &fdFile) && i < n);
	FindClose(hFind);
	return 0;
}


void main()
{
	int i, n, p, m = 1, k;
	float y;
	wchar_t* xa;
	files* b;
	clock_t start, stop;
	setlocale(LC_ALL, "Rus");
	printf("введите путь до директории\n");
	fgets(xa, T, stdin);
	n = sum_files(xa);
	p = ListDirectoryContents(xa, b, n);
	if (p == 1)
	{
		printf("ошибка\n");
		return;
	}
	printf("введите число элементов с одинаковым размером");
	scanf("%d", &k);
	while (1)
	{
		printf("выберите сортировку\n");
		printf("1 - выбором\n 2 - вставками\n3 - пузырьковая\n4 - подсчетом\n5 - слиянием\n6 - Хоара\n");
		scanf("%d", &p);
		switch (p)
		{
		case 1:
			start = clock();
			choose(n, b);
			stop = clock();
			y = (stop - start) / CLK_TCK;
			print(b, y, n);
			break;
		case 2:
			start = clock();
			insert(n, b);
			stop = clock();
			y = (stop - start) / CLK_TCK;
			print(b, y, n);
			break;
		case 3:
			start = clock();
			bubble(n, b);
			stop = clock();
			y = (stop - start) / CLK_TCK;
			print(b, y, n);
			break;
		case 4:
			start = clock();
			count(n, b, k);
			stop = clock();
			y = (stop - start) / CLK_TCK;
			print(b, y, n);
			break;
		case 5:
			start = clock();
			mergesort(b, 0, n - 1);
			stop = clock();
			y = (stop - start) / CLK_TCK;
			print(b, y, n);
			break;
		case 6:
			start = clock();
			quick_sort(b, 0, n - 1);
			stop = clock();
			y = (stop - start) / CLK_TCK;
			print(b, y, n);
			break;
		default:
			printf("Задана неверная директория\n");
			break;
		}
		printf("выберите 0, если хотите выйти и 1, если хотите продолжить\n");
		scanf("%d", &m);
		ListDirectoryContents(xa, b, n);
		if (m == 0) return;
	}
}