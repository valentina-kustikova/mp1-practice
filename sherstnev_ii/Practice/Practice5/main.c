#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

//Sorts
void BubbleSort(ULONGLONG a[], int *b, int n)
{
	int i, j, k;
	ULONGLONG tmp;
	for (i = 0; i < n - 1; i++)
	for (j = 1; j < n - i; j++)
	if (a[j - 1] > a[j])
	{
		tmp = a[j - 1];
		a[j - 1] = a[j];
		a[j] = tmp;
		k = b[j - 1];
		b[j - 1] = b[j];
		b[j] = k;
	}
}

void SelectionSort(ULONGLONG a[], int *b, int n)
{
	int i, j, tmp;
	int minind;
	ULONGLONG t, min;
	for (i = 0; i < n; i++)
	{
		min = a[i];
		minind = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				minind = j;
			}
			t = a[i];
			a[i] = a[minind];
			a[minind] = t;
			tmp = b[i];
			b[i] = b[minind];
			b[minind] = tmp;
		}
	}
}

void InsertionSort(ULONGLONG a[], int n, int *b)
{
	int i, j, t;
	ULONGLONG tmp;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		tmp = a[i];
		t = b[i];
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			a[j] = tmp;
			b[j + 1] = b[j];
			b[j] = t;
			j--;
		}
	}
}

void CountingSort(ULONGLONG* a, int n, int *b)
{
	int i, j, q = 0;
	ULONGLONG* count;
	ULONGLONG* arr;
	ULONGLONG min = a[0], max = a[n - 1], k;
	arr = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
	for (i = 0; i < n; i++)
	{
		arr[i] = a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	k = max - min + 1;
	count = (ULONGLONG*)malloc(k * sizeof(ULONGLONG));
	for (i = 0; i < k; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < count[i]; j++)
			a[q++] = i + min;
	}
	q = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		if ((a[i] == arr[j]))
		{
			b[q] = j;
			arr[j] = -1;
			q++;
			break;
		}
	}
}


void Merge(ULONGLONG a[], int *b, int l, int m, int r)
{
	int i, j, v = 0;
	int *arr_ind;
	ULONGLONG *arr;
	arr = (ULONGLONG*)malloc((r - l + 1) * sizeof(ULONGLONG));
	arr_ind = (int*)malloc((r - l + 1) * sizeof(int));
	i = l;
	j = m + 1;
	while ((i <= m) && (j <= r))
	{
		if (a[i] < a[j])
		{
			arr_ind[v++] = b[i++];
			arr[v++] = a[i++];

		}
		else
		{
			arr_ind[v++] = b[j++];
			arr[v++] = a[j++];
		}
	}
	while (i <= m)
	{
		arr_ind[v++] = b[i++];
		arr[v++] = a[i++];
	}
	while (j <= r)
	{
		arr_ind[v++] = b[j++];
		arr[v++] = a[j++];
	}
	for (v = l; v <= r; v++)
	{
		arr_ind[v] = b[i - l];
		a[v] = arr[v - l];
	}
	free(arr);
	free(arr_ind);
}

void MergeSort(ULONGLONG a[], int l, int r, int *b)
{
	int m;
	if (l >= r) return;
	m = (l + r) / 2;
	MergeSort(a, l, r, b);
	MergeSort(a, m + 1, r, b);
	Merge(a, b, l, m, r);
}

void QuickSort(ULONGLONG* a, int *b, int first, int last)
{
	int i = first, j = last, t;
	ULONGLONG x = a[(first + last) / 2];
	ULONGLONG tmp;
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				t = b[i];
				b[i] = b[j];
				b[j] = t;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		QuickSort(a, b, i, last);
	if (first < j)
		QuickSort(a, b, first, j);
}

int ListDirectoryContents(wchar_t *sDir, wchar_t ***filename, ULONGLONG **filesize)
{
	int num = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		return -1;
	}
	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			num++;
		}
	} while (FindNextFile(hFind, &fdFile));
	hFind = FindFirstFile(sPath, &fdFile);
	*filename = (wchar_t**)malloc(num * sizeof(wchar_t*));
	*filesize = (ULONGLONG*)malloc(num * sizeof(ULONGLONG));
	num = 0;

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{

			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
			(*filename)[num] = (wchar_t*)malloc(2048 * sizeof(wchar_t));
			(*filesize)[num] = fileSize;
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wsprintf((*filename)[num], L"%s", sPath);
			num++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return num;
}

void Putpath(wchar_t* str, char* str1)
{
	fgets(str1, 2048, stdin);
	str1[strlen(str1) - 1] = '\0';
	swprintf(str, 2048, L"%hs", str1);
}

void ShowMenu()
{
	printf("\nChoose the sort\n");
	printf("1 - Bubble sort\n");
	printf("2 - Selection sort\n");
	printf("3 - Insertion sort\n");
	printf("4 - Counting sort\n");
	printf("5 - Merge sort\n");
	printf("6 - Quick sort\n");
	printf("7 - Close the program\n");
}

void copy_file(int *indfilename, ULONGLONG *copy_filesize, ULONGLONG *filesize, int p)
{
	int i;
	for (i = 0; i < p; i++)
	{
		indfilename[i] = i;
		copy_filesize[i] = filesize[i];
	}
}

void main()
{
	int num, i, choice;
	ULONGLONG* copy_filesize, *filesize;
	wchar_t **filename;
	char* str = (char*)malloc(2048);
	wchar_t* strclon = (wchar_t*)malloc(2048);
	int* indfilename;
	clock_t start, stop, time;
	printf("Enter the path\n");
	Putpath(strclon, str);
	num = ListDirectoryContents(strclon, &filename, &filesize);
	if (num == -1)
	{
		printf("Wrong path\n");
		return;
	}
	if (num == 0)
	{
		printf("Directory is empty\n");
		return;
	}
	indfilename = (int*)malloc(num * sizeof(int));
	copy_filesize = (ULONGLONG*)malloc(num * sizeof(ULONGLONG));
	choice = 0;
	while (choice != 7)
	{
		ShowMenu();
		scanf("%d", &choice);
		copy_file(indfilename, copy_filesize, filesize, num);
		switch (choice)
		{
		case 1: start = clock();
			BubbleSort(copy_filesize, indfilename, num);
			stop = clock();
			break;
		case 2: start = clock();
			SelectionSort(copy_filesize, indfilename, num);
			stop = clock();
			break;
		case 3:	start = clock();
			InsertionSort(copy_filesize, num, indfilename);
			stop = clock();
			break;
		case 4: start = clock();
			CountingSort(copy_filesize, num, indfilename);
			stop = clock();
			break;;
		case 5: start = clock();
			MergeSort(copy_filesize, num, 0, indfilename);
			stop = clock();
			break;
		case 6: start = clock();
			QuickSort(copy_filesize, indfilename, 0, num - 1);
			stop = clock();
			break;
		case 7: return;
		}
		for (i = 0; i < num; i++)
			wprintf(L"File: %s Size: %lld bytes\n", filename[indfilename[i]], filesize[indfilename[i]]);
		printf("\n");
		time = stop - start;
		printf("Sorted during %.5f", ((float)time) / CLK_TCK);
	}
	free(str);
	free(strclon);
	free(indfilename);
	free(copy_filesize);
}