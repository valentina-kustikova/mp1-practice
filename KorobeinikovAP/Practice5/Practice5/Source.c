#define _CRT_SECURE_NO_WARNINGS

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

int F_main_work(wchar_t** fname[], int* size, int* size1);
void F_init(int* ind, wchar_t** fname[]);

void Bubble_sort(int size[], int quantity);
void Insert(int b[], int N);

void Merge(int get[], int l, int mid, int r);
void Merge_sort(int a[], int N);
void Merge_sort_lr(int a[], int l, int r);

void Swap(int* a, int* b);

void Input();
void Sorting(int size1[], int size[], wchar_t** fname[], int i);
int Index(int size1[], int size[], int quantity, int k);






int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0, k;
	int ind[200];
	int* size = (int*)malloc(200 * sizeof(int));
	int* size1 = (int*)malloc(200 * sizeof(int));
	wchar_t** fname = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));	
	F_init(ind, fname);
	Input();
	i = F_main_work(fname,size,size1);
	Sorting(size1, size, fname, i);
	return 0;
}







void Input()
{
	char* a = (char*)malloc(MAX_PATH);
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));

	do {
		printf("Enter the open path of the directory with the files: \n");
		//translating the path to wchar_t
		scanf("%s", a);
		strcat(a, "\\*.*");
		mbstowcs(path, a, strlen(a) + 1);
		hfile = FindFirstFileW(path, &File);

	} while (hfile == INVALID_HANDLE_VALUE);
	printf("Your path: %s \n", a);
}



void Sorting(int size1[], int size[], wchar_t** fname[], int i)
{
	int j, k, n, r, index;
	clock_t start, end;
	double elapsed;

	do
	{
		printf("\nSelect the sort type(enter a number) or '0' to exit: \n1 - Bubble\n2 - Inserts\n3 - Merge\n");
		scanf("%d", &n);
	} while ((n < 0) || (n > 3));
	while (n != 0)
	{
		for (j = 0; j < i; j++) {
			size1[j] = size[j];
		}
		if (n != 0)
		{
			start = clock();
			if (n == 1)
				Bubble_sort(size1, i-1);
			else if (n == 2)
				Insert(size1, i);
			else if (n == 3)
				Merge_sort (size1, i);

			do
			{
				printf("Select the output type(enter a number)\n1)Ascending order\n2)Descending order\n");
				scanf("%d", &r);
				if (r == 1)
				{
					printf("Names: %50c Size(Bytes):\n", ' ');
					for (k = 0; k < i; k++)
					{
						if (size1[k] <= 0)
							continue;
						else {
							index = Index(size1, size, i, k);
							printf("\n%-60S", fname[index]);
							printf("%d  \n", (size1[k]));
						}
					}
				}
				else if (r == 2)
				{
					printf("Names: %50c Size(Bytes):\n", ' ');
					for (k = i; k > 0; k--)
					{
						if (size1[k] <= 0)
							continue;
						else {
							index = Index(size1, size, i, k);
							printf("\n%-60S", fname[index]);
							printf("%d  \n", (size1[k]));
						}
					}
				}
			} while ((r < 1) || (r > 2));
			end = clock();
			elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
			printf("\nTime: %.3f seconds\n", elapsed);
			do
			{
				printf("Select the sort type(enter a number) or '0' to exit:\n1 - Bubble\n2 - Inserts\n3 - Merge\n");
				scanf("%d", &n);
			} while ((n < 0) || (n > 3));

		}
		else
			break;
	}

}




int Index(int size1[], int size[], int quantity, int k)
{
	int i, ind;
	for (i = 0; i < quantity; i++)
		if (size1[k] == size[i])
			ind = i;
	return ind;
}






void Bubble_sort(int size[], int quantity) {
	int i, j;
	for (i = 0; i < quantity; i++) {
		for (j = 0; j < quantity - i; j++) {
			if (size[j + 1] < size[j]) {
				Swap(&size[j + 1], &size[j]);
			}
		}
	}
}


void Insert(int size[], int quantity)
{
	int i, j, tmp;
	for (i = 1; i < quantity; i++)
	{
		tmp = size[i];
		j = i - 1;
		while ((j >= 0) && (size[j] > tmp))
		{
			Swap(&size[j + 1], &size[j]);
			j--;
		}

	}
}



void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}








void Merge(int get[],  int l, int mid, int r)  
{
	int k = 0, i = 0, j = 0;
	int N = mid - l;
	int M = r - mid + 1;

	int* c = (int*)malloc((r - l + 1) * sizeof(int));
	
	i = l;
	j = mid;
	while (((i - l) < N) && ((j - mid) < M))
	{
		if (get[i] < get[j]) {
			c[k] = get[i];
			k++;
			i++;
		}
		else
		{
			c[k] = get[j];
			k++;
			j++;
		}
	}
	while ((i - l) < N)
	{
		c[k] = get[i];
		k++;
		i++;
	}
	while ((j - mid) < M)
	{
		c[k] = get[j];
		k++;
		j++;
	}

	for (i = l; i < r + 1; i++)
	{
		get[i] = c[i - l];
	}
}




void Merge_sort(int a[], int N)
{

	Merge_sort_lr(a, 0, N - 1);
}




void Merge_sort_lr(int a[],  int l, int r)
{
	int mid;
	if (l >= r)
		return;
	mid = l + (r - l) / 2;
	Merge_sort_lr(a, l, mid);
	Merge_sort_lr(a,  mid + 1, r);
	Merge(a, l, mid + 1, r);
}




int F_main_work(wchar_t** fname[], int* size, int* size1) {
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


void F_init(int* ind, wchar_t** fname[]) {
	int i;
	for (int i = 0; i < MAX_PATH; i++) {
		fname[i] = (wchar_t*)malloc(200 * sizeof(wchar_t));
		fname[i] = L" ";
	}
	for (int i = 0; i < 200; i++) {
		ind[i] = i;
	}

}