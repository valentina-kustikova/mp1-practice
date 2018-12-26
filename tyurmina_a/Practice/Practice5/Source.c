#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define N 1000
#define MAX_LEN 1000
#define BUFFER 2048

void SelectionSort(int *a, ULONGLONG *size, int n)
{
	int i, j, tmp, idx;
	for (i = 0; i < n - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (size[a[idx]] > size[a[j]])
			{
 			   idx = j;
			}
		}
		tmp = a[idx];
		a[idx] = a[i];
		a[i] = tmp;
	}
}


void InsertSort(int *a, ULONGLONG *size, int n)
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


void BubbleSort(int *a, ULONGLONG *size, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (size[a[j]] < size[a[j - 1]])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}


void CountingSort(int *a, ULONGLONG *size, int n)
{
	int *b = (int*)malloc(N * sizeof(int));
	int i, j, idx = 0;
	int h = 0;
	for (i = 0; i < N; i++)
	{
		b[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		b[size[a[i]]]++;
	}
	for (i = 0; i < N; i++)
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


void QuickSplit(int *a, ULONGLONG *size, int *i, int *j, ULONGLONG p)
{
	int tmp;
	do {
		while (size[a[(*i)]] < p)
		{
			(*i)++;
		}
		while (size[a[(*j)]] > p)
		{
			(*j)--;
		}
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


void QuickSort(int *a, ULONGLONG *size, int N1, int N2)
{
	int m = (N1 + N2) / 2;
	int i = N1, j = N2;
	QuickSplit(a, size, &i, &j, size[a[m]]);
	if (j > N1)
	{
		QuickSort(a, size, N1, j);
	}
	if (i < N2)
	{
		QuickSort(a, size, i, N2);
	}
}


void Merge(int *a, ULONGLONG *size, int N1, int med, int N2)
{
	int i, j = med + 1, h, tmp;
	for (i = 1; ((i < N2) && (j <= N2)); i++)
	{
		if (size[a[i]] > size[a[j]])
		{
			tmp = a[j];
			for (h = j; h > i; h--)
			{
				a[h] = a[h - 1];
			}
			a[i] = tmp;
			j++;
		}
	}
}


void MergeSort(int *a, ULONGLONG *size, int N1, int N2)
{
	int m;
	if (N2 <= 1)
		return;
	m = (N2 + 1) / 2;
	MergeSort(a, size, N1, m);
	MergeSort(a, size, m + 1, N2);
	Merge(a, size, N1, m, N2);
}



int FileDirectory(const wchar_t *sDirect, ULONGLONG **ssize, wchar_t ***nname)
{
	int i = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t *sPath;
	sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
	wsprintf(sPath, L"%s\\*.*", sDirect);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
		return -1;
	do
	{
		if ((wcscmp(fdFile.cFileName, L".") != 0) && (wcscmp(fdFile.cFileName, L"..") != 0))
		{
			i++;
		}
	} while (FindNextFile(hFind, &fdFile));
	hFind = FindFirstFile(sPath, &fdFile);
	*nname = (wchar_t**)malloc(i * sizeof(wchar_t*));
	*ssize = (ULONGLONG*)malloc(i * sizeof(ULONGLONG));
	i = 0;
	do
	{
		if ((wcscmp(fdFile.cFileName, L".") != 0) && (wcscmp(fdFile.cFileName, L"..") != 0))
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
			(*nname)[i] = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
			(*ssize)[i] = fileSize;
			wsprintf(sPath, L"%s\\%s", sDirect, fdFile.cFileName);
			wsprintf((*nname)[i], L"%s", sPath);
			i++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	free(sPath);
	return i;
}


void input(wchar_t **strin)
{
	char *input;
	*strin = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
	input = (char*)malloc(BUFFER * sizeof(char));
	fgets(input, BUFFER, stdin);
	input[strlen(input) - 1] = '\0';
	swprintf(*strin, BUFFER, L"%hs", input);
	free(input);
}


void CommandMenu()

{
	printf("Choose a sort:\n");
	printf(" 1 - Selection sort\n");
	printf(" 2 - Insert sort\n");
	printf(" 3 - Bubble sort\n");
	printf(" 4 - Counting sort\n");
	printf(" 5 - Quick sort\n");
	printf(" 6 - Merge sort\n");
	printf(" 7 - Exit\n");
}



void Output(int *index, wchar_t **nname, ULONGLONG *ssize, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		wprintf(L"File: %s Size: ", nname[index[i]]);
		printf("%lld bite", ssize[index[i]]);
		printf("\n");
	}
}


void main()
{
	int c = 0, i = 0;
	int* index;
	int count = 0;
	ULONGLONG* ssize = 0;
	wchar_t** nname = 0;
	wchar_t* path = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
	clock_t start, stop;
	float total_time = 0.0f;
	while (count < 1)
	{
		printf("\nThe path to the folder: ");
		input(&path);
		count = FileDirectory(path, &ssize, &nname);
		if (count == 0)
		{
			printf("Empty folder\n");
			continue;
		}
		if (count == -1)
		{
			printf("Not found\n");
			continue;
		}
	}
	while (c != 7)
	{
		CommandMenu();
		index = (int*)malloc(count * sizeof(int));
		for (i = 0; i < count; i++)
			index[i] = i;
		scanf("%d", &c);
		switch (c)
		{
		case 1:
		{
			start = clock();
			SelectionSort(index, ssize, count);
			stop = clock();
			break;
		}
		case 2:
		{
			start = clock();
			InsertSort(index, ssize, count);
			stop = clock();
			break;
		}
		case 3:
		{
			start = clock();
			BubbleSort(index, ssize, count);
			stop = clock();
			break;
		}
		case 4:
		{
			start = clock();
			CountingSort(index, ssize, count);
			stop = clock();
			break;
		}
		case 5:
		{
			start = clock();
			QuickSort(index, ssize, 0, count - 1);
			stop = clock();
			break;
		}
		case 6:
		{
			start = clock();
			MergeSort(index, ssize, 0, count - 1);
			stop = clock();
			break;
		}
		total_time = (float)(stop - start) / CLOCKS_PER_SEC;
		Output(index, nname, ssize, count);
		printf("Sorting time: %.3f señ \n", total_time);
		free(index);
		}
	}
	for (i = 0; i < count; i++)
	{
		free(nname[i]);
	}
	free(nname);
	free(ssize);
	free(path);
}
