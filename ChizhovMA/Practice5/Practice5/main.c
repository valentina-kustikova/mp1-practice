#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include<tchar.h>

WIN32_FIND_DATA names[MAX_PATH];
WIN32_FIND_DATA File;
HANDLE hfile;

void Choice(int a[], int N);
void Insert(int b[], int N);
void Quicksort(int c[], int low, int high);
void swap(int* a, int* b);
void Index(int a[], int b[], int size, int check[]);

void Input()
{
	char* a = (char*)malloc(MAX_PATH);
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));

	do {
		printf("Enter the open path to the existing directory with the files: \n");
		//translating the path to wchar_t
		scanf("%s", a);
		strcat(a, "\\*.*");
		mbstowcs(path, a, strlen(a) + 1);
		hfile = FindFirstFileW(path, &File);

	} while (hfile == INVALID_HANDLE_VALUE);
	printf("Your path: %s \n", a);
}

int PrintFile(int size[], int size1[], wchar_t** fname[])
{
	int i = 0;
	printf("Data in your directory: \n");
	printf("Names: %50c Size(Bytes):\n", ' ');
	do {
		if ((i == 0) || (i == 1)) {
			i++;
			continue;
		}
		names[i] = File;
		fname[i] = names[i].cFileName;
		size[i] = names[i].nFileSizeLow;
		size1[i] = names[i].nFileSizeLow;//size of file
		printf("\n%-60S", fname[i]);//name of file
		if (size[i] == 0)
			printf("This is a folder, the size is undefined\n");
		else
			printf("%d  \n", (size[i]));
		i++;
	} while (FindNextFileW(hfile, &File) != NULL);
	return i;
}

void Sorting(int a[], int b[], wchar_t** fname[], int i)
{
	int k, n, r, index, c;
	int* d = (int*)malloc(MAX_PATH * sizeof(int));
	int* check = (int*)malloc(MAX_PATH * sizeof(int));
	clock_t start, end;
	double elapsed;

	do
	{
		printf("\nSelect the sort type(enter a number) or '0' to exit:\n1)Sorting by choice\n2)Sorting by inserts\n3)Quick sorting\n");
		scanf("%d", &n);
	} while ((n < 0) || (n > 3));
	while (n != 0)
	{
		
			
		if (n != 0)
		{
			for (c = 0; c < i; c++)
				d[c] = a[c];
			start = clock();
			if (n == 1)
				Choice(d, i);
			else if (n == 2)
				Insert(d, i);
			else if (n == 3)
				Quicksort(d, 0, i - 1);

			do
			{
				printf("Select the output type(enter a number)\n1)Ascending order\n2)Descending order\n");
				scanf("%d", &r);
				if (r == 1)
				{
					printf("Names: %50c Size(Bytes):\n", ' ');
					Index(d, b, i, check);
					for (k = 0; k < i; k++)
					{
						if (d[k] <= 0)
							continue;
						else {
							index = check[k];
							printf("\n%-60S", fname[index]);
							printf("%d  \n", (d[k]));
						}
					}
				}
				else if (r == 2)
				{
					printf("Names: %50c Size(Bytes):\n", ' ');
					Index(d, b, i, check);
					for (k = i; k > 0; k--)
					{
						if (d[k] <= 0)
							continue;
						else {
							index = check[k];
							printf("\n%-60S", fname[index]);
							printf("%d  \n", (d[k]));
						}
					}
				}
			} while ((r < 1) || (r > 2));
			end = clock();
			elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
			printf("\nTime: %.3f seconds\n", elapsed);
			do
			{
				printf("Select the sort type(enter a number) or '0' to exit:\n1)Sorting by choice\n2)Sorting by inserts\n3)Quick sorting\n");
				scanf("%d", &n);
			} while ((n < 0) || (n > 3));

		}
		else
			break;
	}

}

void Index(int c[], int v[], int size, int check[])
{
	int i, j, l, flag;
	for (i = 0; i < size; i++) 
		for (j = 0; j < size; j++) {
			flag = 0;
			if (c[i] == v[j]) {
				for (l = 0; l < size; l++)
					if (check[l] == j) {
						flag = 1;
						break;
					}
				if (flag == 0)
					check[i] = j;
				else
					continue;
				break;
			}
		}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, k;
	int* size = (int*)malloc(MAX_PATH * sizeof(int));
	int* size1 = (int*)malloc(MAX_PATH * sizeof(int));
	wchar_t** fname = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
	for (int i = 0; i < MAX_PATH; i++) {
		fname[i] = (wchar_t*)malloc(200 * sizeof(wchar_t));
		fname[i] = L" ";
	}

	Input();

	i = PrintFile(size, size1, fname);

	Sorting(size1, size, fname, i);

	return 0;
}

void Choice(int a[], int N)
{
	int i, j, min, ind, tmp;
	for (i = 0; i < N; i++)
	{
		min = a[i];
		ind = i;
		for (j = i + 1; j < N; j++)
			if (a[j] < min)
			{
				min = a[j];
				ind = j;
			}
		swap(&a[i], &a[ind]);
	}
}

void Insert(int b[], int N)
{
	int i, j, tmp;
	for (i = 1; i < N; i++)
	{
		tmp = b[i];
		j = i - 1;
		while ((j >= 0) && (b[j] > tmp))
		{
			swap(&b[j + 1], &b[j]);
			j--;
		}

	}
}

void Quicksort(int c[], int low, int high)
{
	int mid, count;
	int l = low, h = high;
	mid = c[(l + h) / 2]; //calculation of the reference element
	do
	{
		while (c[l] < mid) l++;
		while (c[h] > mid) h--;
		if (l <= h) //rearranging elements
		{
			count = c[l];
			c[l] = c[h];
			c[h] = count;
			l++;
			h--;
		}
	} while (l < h);
	if (low < h) Quicksort(c, low, h);
	if (l < high) Quicksort(c, l, high);
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}