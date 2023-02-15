#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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


void Choice(int a[], wchar_t** b[], int N);
void Insert(int a[], wchar_t** b[], int N);
void merge_sort(int a[], wchar_t** name[], int N);
void output(int size[], wchar_t** name[], int N);
void merge_sort_lr(int a[], wchar_t** name[], int l, int r);
void merge(int get[], wchar_t** name[], int l, int mid, int r);
int form_array(int size[], wchar_t** name[], wchar_t** path[]);						



int main()
{
	printf("2 \n");
	int i = 0, N = 0, number, flag = 1;
	int* size = (int*)malloc(MAX_PATH * sizeof(int));
	wchar_t** name = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	N=form_array(size, name, path);
	sorting(size, name, N);
	return 0;
}



int sorting(int size[], wchar_t** name[], int N)
{
	int i, number, flag;
	long long time1, time2;
	int* size_copy = (int*)malloc(MAX_PATH * sizeof(int));
	wchar_t** name_copy = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
	do
	{
		for (i = 0; i < N; i++)
		{
			size_copy[i] = size[i];
			name_copy[i] = name[i];
		}
		printf("Choose the type of sorting: 1-selection sorting, 2-insertion sorting, 3-merge sorting  ");
		scanf("%d", &number);

		if ((number < 1) || (number > 3))
		{
			printf("Invalid number.  \n");
			continue;
		}
		else if (number == 1)
		{
			QueryPerformanceCounter(&time1);
			Choice(size_copy, name_copy, N);
			QueryPerformanceCounter(&time2);
		}
		else if (number == 2)
		{
			QueryPerformanceCounter(&time1);
			Insert(size_copy, name_copy, N);
			QueryPerformanceCounter(&time2);
		}
		else if (number == 3)
		{
			QueryPerformanceCounter(&time1);
			merge_sort(size_copy, name_copy, N);
			QueryPerformanceCounter(&time2);
		}
		if ((number >= 1) || (number <= 3))
			output(size_copy, name_copy, N);
		printf("\nThe time it took to sort the bubble = %lld milliseconds\n\n", time2 - time1);
		printf("\n");
		printf("If you want to finish, write 0, if not - 1:  ");
		scanf("%d", &flag);
	} while (flag == 1);

}



int form_array(int size[], wchar_t** name[], wchar_t** path[])
{
	
	char* a = (char*)malloc(MAX_PATH);
	int i = 0, N = 0;;
	printf("Enter the path to the directory (Example: D:\\photo\\1\)  \n");
	scanf("%s", a);
	strcat(a, "\\*.*");
	mbstowcs(path, a, strlen(a) + 1);
	hfile = FindFirstFileW(path, &File);

	FindNextFileW(hfile, &File);
	while (FindNextFileW(hfile, &File) != NULL)
	{
		names[i] = File;
		name[i] = names[i].cFileName;
		size[i] = names[i].nFileSizeLow;
		i++;
	}
	N = i;
	return N;
}





void output(int size_copy[], wchar_t** name_copy[], int N)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("\n%-60S ", name_copy[i]);
		printf("%d ", size_copy[i]);
	}
}



void Choice(int a[], wchar_t** b[], int N)  //сортировка выбором  (2)
{
	int i, j, min, ind, tmp;
	wchar_t* t = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
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
		tmp = a[ind];
		a[ind] = a[i];
		a[i] = tmp;

		t = b[ind];
		b[ind] = b[i];
		b[i] = t;
	}
}


void Insert(int a[], wchar_t** b[], int N)  //сортировка вставками  (3)
{
	int i, j, tmp, k;
	wchar_t* t = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	for (i = 1; i < N; i++)
	{
		tmp = a[i];
		t = b[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			b[j + 1] = b[j];
			j--;

		}
		a[j + 1] = tmp;
		b[j + 1] = t;

	}
}




void merge(int get[], wchar_t** name[], int l, int mid, int r)   //функция слияния
{
	int k = 0, i = 0, j = 0;
	int N = mid - l;
	int M = r - mid + 1;

	int* c = (int*)malloc((r - l + 1) * sizeof(int));
	wchar_t** name_c = (wchar_t**)malloc((r - l + 1) * sizeof(wchar_t*));
	i = l;
	j = mid;
	while (((i-l) < N) && ((j-mid)< M))
	{
		if (get[i] < get[j]) {
			c[k] = get[i];
			name_c[k] = name[i];
			k++;
			i++;
		}
		else
		{
			c[k] = get[j];
			name_c[k] = name[j];
			k++;
			j++;
		}
	}
	while ((i-l) < N)
	{
		c[k] = get[i];
		name_c[k] = name[i];
		k++;
		i++;
	}
	while ((j - mid) < M)
	{
		c[k] = get[j];
		name_c[k] = name[j];
		k++;
		j++;
	}

	for (i = l; i < r + 1; i++)
	{
		get[i] = c[i - l];
		name[i] = name_c[i - l];
	}
}


void merge_sort(int a[], wchar_t** name[], int N)
{

	merge_sort_lr(a, name, 0, N - 1);
}

void merge_sort_lr(int a[], wchar_t** name[], int l, int r)
{
	int mid;
	if (l >= r)
		return;
	mid = l + (r - l) / 2;
	merge_sort_lr(a, name, l, mid);
	merge_sort_lr(a, name, mid + 1, r);
	merge(a, name, l, mid+1, r);
}
