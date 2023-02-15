#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <winbase.h>
#include <profileapi.h>

#define _FilesLimit 100000

typedef struct _FIND_DATA {
	DWORD    nFileSize;
	WCHAR    cFileName[MAX_PATH];
} FIND_DATA, * P_FIND_DATA, * LP_FIND_DATA;

void bubble_sort(FIND_DATA* arr, ULONGLONG n);
void merge(FIND_DATA* arr, ULONGLONG left, ULONGLONG mid, ULONGLONG right);
void mergeSort(FIND_DATA* arr, ULONGLONG left, ULONGLONG right);
void qSort(FIND_DATA* arr, ULONGLONG left, ULONGLONG right);
int FindFiles(LPCSTR directory, FIND_DATA* filesArray);
int check(LPCSTR directory);

int main()
{
	ULONGLONG i,j;
	int n,k,r; //переменные для запросов пользователя для выбора сортировки и т.п.
	long long time1, time2, time3, time4, time5, time6;
	int fB=0, fM=0, fQ=0;
	char directoryName[255], directoryNameNC[255];
	FIND_DATA* filesArray, *filesArrayTmpB, *filesArrayTmpM, *filesArrayTmpQ;
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	filesArray = (FIND_DATA*)malloc(sizeof(FIND_DATA) * _FilesLimit);
	filesArrayTmpB = (FIND_DATA*)malloc(sizeof(FIND_DATA) * _FilesLimit);
	filesArrayTmpM = (FIND_DATA*)malloc(sizeof(FIND_DATA) * _FilesLimit);
	filesArrayTmpQ = (FIND_DATA*)malloc(sizeof(FIND_DATA) * _FilesLimit);
	printf("Pls write directory\n");
	i = 0;
	do {
		gets_s(directoryName, 254);
		strcpy(directoryNameNC, directoryName);

		strcat(directoryName, "\\*");

		n=check(directoryName);
		switch (n)
		{
			case (1):
			{
				printf("");
				break;
			}
			case (2):
			{
				printf("No Files. Try with other dir\n");
				break;
			}
			case (3):
			{
				printf("No such dir. Try again\n");
				break;
			}
		}
	} while (n != 1);

	i=FindFiles(directoryName, filesArray);
	printf("\n\nFiles Found:\n");
	for (j = 0; j < i; j++)
	{
		printf("%s %lld\n", filesArray[j].cFileName, filesArray[j].nFileSize);
	}
	printf("\nYou can check how long it takes different sorts to sort files in your directory\n");
	printf("If you want to leave, write 0\n");
	printf("\nChoose method:\n 1-bubble sort\n 2-mergeSort\n 3-qSort\n 4-Show which directory we are in\n");
	printf(" 5-If you want to output a certain sort with the execution time and sorted directory in ascending or descending order\n");
	do {

		scanf("%d", &n);
		switch (n) 
		{
			case(1):
			{
				fB = 0;
				
				for (j = 0; j < i; j++)
				{
					filesArrayTmpB[j].nFileSize = filesArray[j].nFileSize;
					strcpy(filesArrayTmpB[j].cFileName, filesArray[j].cFileName);
				}
				QueryPerformanceCounter(&time1);
				bubble_sort(filesArrayTmpB, i);
				QueryPerformanceCounter(&time2);
				fB++;
				printf("\nThe directory is sorted. Write - 5  if you want to see the result and you will see further instructions\n");
				break;
			}
			case(2):
			{
				fM = 0;
				for (j = 0; j < i; j++)
				{
					
					filesArrayTmpM[j].nFileSize = filesArray[j].nFileSize;
					strcpy(filesArrayTmpM[j].cFileName, filesArray[j].cFileName);
				}
				QueryPerformanceCounter(&time3);
				mergeSort(filesArrayTmpM, 0, i);
				QueryPerformanceCounter(&time4);
				fM++;
				printf("\nThe directory is sorted. Write - 5  if you want to see the result and you will see further instructions\n");
				break;
			}
			case(3):
			{
				fQ = 0;
				for (j = 0; j < i; j++) 
				{
					filesArrayTmpQ[j].nFileSize = filesArray[j].nFileSize;
					strcpy(filesArrayTmpQ[j].cFileName, filesArray[j].cFileName);
				}
				QueryPerformanceCounter(&time5);
				qSort(filesArrayTmpQ, 0, i-1);
				QueryPerformanceCounter(&time6);
				fQ++;
				printf("\nThe directory is sorted. Write - 5  if you want to see the result and you will see further instructions\n");
				break;
			}
			case(4):
			{
				printf("\n%s\n", directoryNameNC);
				break;
			}
			case(5):
			{
				
				printf("Choose which method you want to see\n 1-bubble sort\n 2-mergeSort\n 3-qSort\n\n");
				scanf("%d", &k);
				printf("\n");
				switch (k)
				{
					case(1):
					{
						if (fB == 0)
						{
							printf("Sorting was not requested for the directory\n");
							break;
						}
						else
						{
							printf("If you want to sort:\n write 1 - for increment\n write 2 - for decrement\n\n");
							scanf("%d",&r);
							printf("\n\n");
							switch (r)
							{
								case (1):
								{
									printf("\n\n-----\nSorted Files:\n-----\n\n");
									
									for (j = 0; j < i; j++)
									{
										printf("%s %lld\n", filesArrayTmpB[j].cFileName, (LONGLONG)filesArrayTmpB[j].nFileSize);
									}
									printf("\nThe time it took to sort the bubble = %lld milliseconds\n\n", time2 - time1);
									break;
								}
								case (2):
								{
									printf("\n\n-----\nSorted Files:\n-----\n\n");
									
									for (j = i; j > 0; j--)
									{
										printf("%s %lld\n", filesArrayTmpB[j-1].cFileName, (LONGLONG)filesArrayTmpB[j-1].nFileSize);
									}
									printf("\nThe time it took to sort the bubble = %lld milliseconds\n\n", time2 - time1);
									break;
								}
							}
						}
						break;
					}
					case(2):
					{
						if (fM == 0)
						{
							printf("Sorting was not requested for the directory\n");
						}
						else
						{
							printf("If you want to sort:\n write 1 - for increment\n write 2 - for decrement\n\n");

							scanf("%d", &r);
							switch (r)
							{
								case (1):
								{
									printf("\n\n-----\nSorted Files:\n-----\n\n");
									
									for (j = 0; j < i; j++)
									{
										printf("%s %lld\n", filesArrayTmpM[j].cFileName, (LONGLONG)filesArrayTmpM[j].nFileSize);
									}
									printf("\nThe time it took to sort the mergeSort = %lld milliseconds\n\n", time4 - time3);
									break;
								}
								case (2):
								{
									printf("\n\n-----\nSorted Files:\n-----\n\n");
									
									for (j = i; j > 0; j--)
									{
										printf("%s %lld\n", filesArrayTmpM[j-1].cFileName, (LONGLONG)filesArrayTmpM[j-1].nFileSize);
									}
									printf("\nThe time it took to sort the mergeSort = %lld milliseconds\n\n", time4 - time3);
									break;
								}
							}
							
						}
						break;
					}
					case(3):
					{
						if (fQ == 0)
						{
							printf("Sorting was not requested for the directory\n");
						}
						else
						{
							printf("If you want to sort:\n write 1 - for increment\n write 2 - for decrement\n\n");
							scanf("%d", &r);
							switch (r)
							{
								case (1):
								{
									printf("\n\n-----\nSorted Files:\n-----\n\n");
									
									for (j = 0; j < i; j++)
									{
										printf("%s %lld\n", filesArrayTmpQ[j].cFileName, (LONGLONG)filesArrayTmpQ[j].nFileSize);
									}
									printf("\nThe time it took to sort the qSort = %lld milliseconds\n\n", time6 - time5);
									break;
								}
								case (2):
								{
									printf("\n\n-----\nSorted Files:\n-----\n\n");
									
									for (j = i; j > 0; j--)
									{
										printf("%s %lld\n", filesArrayTmpQ[j-1].cFileName, (LONGLONG)filesArrayTmpQ[j-1].nFileSize);
									}
									printf("\nThe time it took to sort the qSort = %lld milliseconds\n\n", time6 - time5);
									break;
								}
							}
						}
						break;
					}
				}
				printf("\n");
			}
		}
	} while (n != 0);
	free(filesArray);
	free(filesArrayTmpB);
	free(filesArrayTmpM);
	free(filesArrayTmpQ);
	return 0;
}


void bubble_sort(FIND_DATA* arr, ULONGLONG n)
{
	ULONGLONG i, j ;
	FIND_DATA tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n-1; j > i; j--)
		{
			if (arr[j - 1].nFileSize > arr[j].nFileSize)
			{
				tmp.nFileSize =  arr[j - 1].nFileSize;
				strcpy(tmp.cFileName, arr[j - 1].cFileName);
				arr[j - 1].nFileSize = arr[j].nFileSize;
				strcpy(arr[j - 1].cFileName, arr[j].cFileName);
				arr[j].nFileSize = tmp.nFileSize;
				strcpy(arr[j].cFileName, tmp.cFileName);
			}
		}
	}
}

void merge(FIND_DATA* arr, ULONGLONG left, ULONGLONG mid, ULONGLONG right)
{
	ULONGLONG i=0, i1 = 0, i2 = 0;
	FIND_DATA* b = (FIND_DATA*)malloc(sizeof(FIND_DATA) * (right-left));
	while ((left + i1 < mid) && (mid + i2  <  right))
	{
		if (arr[left + i1].nFileSize < arr[mid + i2].nFileSize)
		{
			b[i1+i2].nFileSize = arr[left + i1].nFileSize;
			strcpy(b[i1 + i2].cFileName, arr[left + i1].cFileName);

			i1++;
		}
		else
		{
			b[i1+i2].nFileSize = arr[mid + i2].nFileSize;
			strcpy(b[i1 + i2].cFileName, arr[mid + i2].cFileName);
			i2++;
		}
	}
	while (left + i1 < mid)
	{
		b[i1+i2].nFileSize = arr[left + i1].nFileSize;
		strcpy(b[i1 + i2].cFileName, arr[left + i1].cFileName);
		i1++;
	}
	while (mid + i2 < right)
	{
		b[i1 + i2].nFileSize = arr[mid + i2].nFileSize;
		strcpy(b[i1 + i2].cFileName, arr[mid + i2].cFileName);
		
		i2++;
	}
	for (i = 0; i < (i1 + i2); i++)
	{
		arr[left + i].nFileSize = b[i].nFileSize;
		strcpy(arr[left + i].cFileName, b[i].cFileName);
	}
	free(b);
}

void mergeSort(FIND_DATA* arr, ULONGLONG left, ULONGLONG right)
{
	ULONGLONG mid ;
	if (left+1 >= right)
		return;
	mid = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid, right);
	merge(arr, left, mid, right);
}

int FindFiles(LPCSTR directory, FIND_DATA* filesArray)
{
	char name[250];
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind = FindFirstFileA(directory, &FindFileData);
	int i=0;

	FindNextFileA(hFind, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE)
	{

		while (FindNextFileA(hFind, &FindFileData) != 0)
		{
			filesArray[i].nFileSize = FindFileData.nFileSizeLow;
			strcpy(filesArray[i].cFileName, FindFileData.cFileName);
			i++;
			
		}
		FindClose(hFind);
	}
	return i;
}


int check(LPCSTR directory)
{
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind = FindFirstFileA(directory, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{

		if (GetLastError() == 2)
		{
			FindClose(hFind);
			return 2;
		}
		if (GetLastError() == 3)
		{
			FindClose(hFind);
			return 3;
		}
	}
	else
	{
		FindClose(hFind);
		return 1;
	}	
}

void qSort(FIND_DATA* arr, ULONGLONG left, ULONGLONG right)
{
	FIND_DATA pivot; 
	ULONGLONG l = left; 
	ULONGLONG r = right; 
	pivot.nFileSize = arr[left].nFileSize;
	strcpy(pivot.cFileName, arr[left].cFileName);
	while (left < right) 
	{
		while ((arr[right].nFileSize >= pivot.nFileSize) && (left < right))
			right--;
		if (left != right) 
		{
			arr[left].nFileSize = arr[right].nFileSize;
			strcpy(arr[left].cFileName, arr[right].cFileName);
			left++; 
		}
		while ((arr[left].nFileSize <= pivot.nFileSize) && (left < right))
			left++;
		if (left != right)
		{
			arr[right].nFileSize = arr[left].nFileSize;
			strcpy(arr[right].cFileName, arr[left].cFileName);
			right--; 
		}
	}
	arr[left].nFileSize = pivot.nFileSize;
	strcpy(arr[left].cFileName,pivot.cFileName); 
	pivot.nFileSize = left;
	left = l;
	right = r;
	if (left < pivot.nFileSize)
		qSort(arr, left, pivot.nFileSize - 1);
	if (right > pivot.nFileSize)
		qSort(arr, pivot.nFileSize + 1, right);
}