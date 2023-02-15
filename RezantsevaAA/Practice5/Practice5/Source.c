#define _CRT_SECURE_NO_WARNINGS
//#include <windows.h>
#include <stdio.h>
#define N 10
void scan(int* a);
void output(int* a);
void swap(int* a);
void ChoiceSortMin(int* a);
//void ChoiceSortMax(int* a);
void BubbleSort(int* a);
void InsertSort(int* a);
int main()
{
	int arr[N];
	char mode;
	scan(arr);
	printf("Ñhoose sorting method: 1 - selection sort, 2 - baubble sort, 3 - insertion sort ");
	scanf("%c", &mode);
	switch (mode)
	{

	case '1':
	{
		ChoiceSortMax(arr);
		output(arr);
	}
	case '2':
	{
		BubbleSort(arr);
		output(arr);
	}
	case '3':
	{
		InsertSort(arr);
		output(arr);
	}
	}

}
void scan(int* a)
{
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &(a[i]));
	}
}
void output(int* a)
{
	for (int i = 0; i < N; i++)
	{
		printf(" %d", a[i]);
	}
}
void swap(int* a)
{
	int tmp, idx, i;
	tmp = a[idx];
	a[idx] = a[i];
	a[i] = tmp;
}
void ChoiceSortMin(int* a)
{
	int i, idx, min, tmp, j;
	for (i = 0; i < N; i++)
	{
		min = a[i];
		idx = i;
		for (j = 1 + i; j < N; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				idx = j;
			}
		}
		swap(a[idx], a[i]);
	}
}
//èñïðàâèòü
void ChoiceSortMax(int* a)
{
	int i, idx, max, tmp, j;
	for (i = 0; i < N; i++)
	{
		max = a[i];
		idx = i;
		for (j = 1 + i; j < N; j++)
		{
			if (a[j] > max)
			{
				max = a[j];
				idx = j;
			}
		}
		swap(a[idx], a[i]);
	}
}
void BubbleSort(int* a)
{
	int i, j, tmp;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			if (a[j + 1] < a[j])
			{
				swap(a[j + 1], a[j]);
			}
		}
	}
}
void InsertSort(int* a)
{
	int i, j, tmp;
	for (i = 0; i < N; i++)
	{
		tmp = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j] = tmp;
	}
}