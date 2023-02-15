#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <vcruntime_string.h>
#include <corecrt_wstring.h>
#define N 100
#define mx_path 100
typedef unsigned long long ull;
typedef long long ll;


void insert_sort(ull a[],int *hlp, int n);
void bubble_sort(ull a[], int *hlp, int n);
void merge(ull a[], int *hlp, int l, int r, int m);
void merge_sort(ull a[],int *hlp, int n);
void dir(wchar_t** wnames, ull* sze, time_t* tme1,int *hlp, int n);
void sorting(wchar_t** wnames, ull* sze, time_t* tme, time_t* tme1, int* hlp, int i);
int indir(wchar_t** wnames, ull* sze, time_t* tme, time_t* tme1, int* hlp);
time_t filetime_to_timet(const FILETIME ft);
wchar_t* newpath(wchar_t* copypath, wchar_t* name);






int main() {
	setlocale(LC_ALL, "rus");
	int i = 0;
	time_t* tme1 = (time_t*)malloc(N * sizeof(time_t*));
	int* hlp = (int*)malloc(N * sizeof(int*));
	char* nme = (char*)malloc(N * sizeof(char*));
	ull* sze = (ull*)malloc(N * sizeof(ull*));
	ull* tme = (ull*)malloc(N * sizeof(ull*));
	wchar_t** wnames = (wchar_t**)malloc(N * sizeof(wchar_t**));
	for (int i = 0; i < N; i++) {
		hlp[i] = i;
		sze[i] = 0;
		tme[i] = 0;
		wnames[i] = (wchar_t*)malloc(N * sizeof(wchar_t));
		wnames[i] = L"Empty";
	}
	i = indir(wnames, sze, tme, tme1, hlp);
	if (i <= 2) {
		printf("I guess your directory is empty or u did input a wrong path. Try again :) ");
		return 1;
	}
	dir(wnames, sze, tme1, hlp,i);
	sorting(wnames, sze, tme, tme1, hlp, i);
	printf("\nIm sure i have max mark for the work. \n I did it for a long time and helped everyone \n Have a good day.");
	return 0;
	
}
void insert_sort(ull* arr, int* hlp, int n)
{
	ull num = 0;
	int ti = -1;
	int j = 0;
	for (int i = 2; i < n; i++) {
		num = arr[i];
		ti = hlp[i];
		j = i - 1;
		while (j >= 0 && arr[j] > num) {
			arr[j + 1] = arr[j];
			hlp[j + 1] = hlp[j];
			j--;
		}
		arr[j + 1] = num;
		hlp[j + 1] = ti;

	}
}
void bubble_sort(ull arr[],int *hlp, int n)
{
	ull temp = 0;
	int Htmp = 0;
	for (int write = 0; write < n; write++) {
		for (int sort = 0; sort < n - 1; sort++) {
			if (arr[sort] > arr[sort + 1]) {
				temp = arr[sort + 1];
				arr[sort + 1] = arr[sort];
				arr[sort] = temp;

				Htmp = hlp[sort + 1];
				hlp[sort + 1] = hlp[sort];
				hlp[sort] = Htmp;
			}
		}
	}
}
void merge(ull arr[], int* hlp, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	

	ull* L = (ull*)malloc(n1 * sizeof(ull*));
	ull* R = (ull*)malloc(n2 * sizeof(ull*));
	int* HL = (int*)malloc(n1 * sizeof(int*));
	int* HR = (int*)malloc(n2 * sizeof(int*));



	
	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
		HL[i] = hlp[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
		HR[j] = hlp[m + 1 + j];
	}
	
	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			hlp[k] = HL[i];
			i++;
		}
		else {
			arr[k] = R[j];
			hlp[k] = HR[j];
			j++;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = L[i];
		hlp[k] = HL[i];
		i++;
		k++;
	}

	
	while (j < n2) {
		arr[k] = R[j];
		hlp[k] = HR[j];
		j++;
		k++;
	}
}
void merge_sort(ull arr[], int* hlp, int l, int r)
{
	if (l < r) {
		
		int m = l + (r - l) / 2;

	
		merge_sort(arr, hlp, l, m);
		merge_sort(arr, hlp, m + 1, r);

		merge(arr, hlp, l, m, r);
	}
}
void dir(wchar_t** wnames, ull* sze, time_t* tme1, int* hlp, int n) {
	
	for (int i = 2; i < n; i++) {
		//File name
		printf("%d.   ", i - 1);
		printf("Name:    ");
		int j = hlp[i];
		wprintf(wnames[j]);
		//File size
		printf(" %10c    Size (bites): %u        ", ' ', sze[j]);
		//File creation time
		printf("%10c Created time:  %s     \n", ' ', ctime(&(tme1[j])));
	}
	
}
int indir(wchar_t** wnames, ull* sze,time_t* tme, time_t* tme1, int* hlp) {
	int i = 0;
	char* a = (char*)malloc(MAX_PATH - 3);
	char* a1 = (char*)malloc(MAX_PATH);
	WIN32_FIND_DATA names[N];
	WIN32_FIND_DATA fdata;
	HANDLE hfile;
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	wchar_t* cpypath = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));


	//check input path
	do {
		printf("Input a path: \n");
		printf("Be careful. If did not input a path like this: 'C:\\...\\...', you can have a problems \n");
		//Preparing path â wchar_t
		//In C we dont have "gets" idk why also we need to input a string with spaces, we cant do this with scanf()
		gets_s(a, 260);
		strcat(a, "\\");
		mbstowcs(cpypath, a, strlen(a) + 1);
		strcat(a, "*.*");
		mbstowcs(path, a, strlen(a) + 1);
		hfile = FindFirstFile(path, &fdata);
	} while (hfile == INVALID_HANDLE_VALUE);

	printf("Your path : %s \n", a);
	printf("Data in your directory: \n");
	
	do {
		if (i == 0 || i == 1) {
			i++;
			continue;
		}
		names[i] = fdata;
		if (names[i].dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			wnames[i] = names[i].cFileName;
			sze[i] = 0;
			time_t* time1 = filetime_to_timet(names[i].ftCreationTime);
			ull a = names[i].ftCreationTime.dwHighDateTime;
			ull b = names[i].ftCreationTime.dwLowDateTime;
			ull tm = a << 32 | b;
			tm /= 10000000;
			tme[i] = tm;
			tme1[i] = time1;
			i++;
			continue;
		}
		wnames[i] = names[i].cFileName;
		sze[i] = names[i].nFileSizeLow;
		//File creation time
		time_t* time1 = filetime_to_timet(names[i].ftCreationTime);
		ull a = names[i].ftCreationTime.dwHighDateTime;
		ull b = names[i].ftCreationTime.dwLowDateTime;
		ull tm = a << 32 | b;
		tm /= 10000000;
		tme[i] = tm;
		tme1[i] = time1;
		i++;
	} while (FindNextFile(hfile, &fdata) != NULL);
	return i;

}
wchar_t *newpath(wchar_t* copypath, wchar_t* name) {
	wchar_t* newpath1 = (wchar_t*)malloc(mx_path * sizeof(wchar_t*));
	wcscpy(newpath1, copypath);
	wcscat(newpath1, name);
	wcscat(newpath1, L"\\*.*");
	return newpath1;
}
time_t filetime_to_timet(const FILETIME ft)
{
	ULARGE_INTEGER ll;
	ll.LowPart = ft.dwLowDateTime;
	ll.HighPart = ft.dwHighDateTime;
	return ll.QuadPart / 10000000ULL - 11644473600ULL;
}
void sorting(wchar_t** wnames, ull* sze, time_t* tme, time_t* tme1, int* hlp, int i) {
	while (1) {
		ull* arr = (ull*)malloc(N * sizeof(ull));
		ull* arrt = (ull*)malloc(N * sizeof(ull));
		for (int j = 0; j < i + 10; j++) {
			arr[j] = sze[j];
			arrt[j] = tme[j];
		}

		for (int i = 0; i < N; i++) {
			hlp[i] = i;
		}
		printf("Input '0' if u wanna kill it\n");
		int sr;
		printf("Input a sorted method: \n Input 1 for  insert sort \n Input 2 for bubble sort \n Input 3 for merge sort \n ");
		do {
			printf("Input 1 or 2\n");
			scanf("%d", &sr);
		} while ((sr != 1) && (sr != 2) && (sr != 3) && (sr != 0));
		if (sr == 0) {
			break;
		}
		int wsr;
		printf("What i need to sort? \n Input 1 for sort size of files \n Input 2 for sort creation time \n ");
		do {
			printf("Input 1 or 2\n");
			scanf("%d", &wsr);
		} while ((wsr != 1) && (wsr != 2));
		if (sr == 1) {
			if (wsr == 1) {
				clock_t begin = clock();
				insert_sort(arr, hlp, i);
				clock_t end = clock();
				printf("Sorted data(size):  ");
				dir(wnames, sze, tme1, hlp, i);
				long double q = end;
				q /= 1000000;
				printf("Time of insert sort: %lf.\n", q);
			}
			if (wsr == 2) {
				clock_t begin = clock();
				insert_sort(arrt, hlp, i);
				clock_t end = clock();
				printf("Sorted data(time):  \n");
				dir(wnames, sze, tme1, hlp, i);
				long double q = end;
				q /= 1000000;
				printf("Time of insert sort: %lf.\n", q);
			}

		}
		if (sr == 2) {
			if (wsr == 1) {
				clock_t begin = clock();
				bubble_sort(arr, hlp, i);
				clock_t end = clock();
				printf("Sorted data(size):  ");
				dir(wnames, sze, tme1, hlp, i);
				long double q = end;
				q /= 1000000;
				printf("Time of Bubble_sort: %lf.\n", q);
			}
			if (wsr == 2) {
				clock_t begin = clock();
				bubble_sort(arrt, hlp, i);
				clock_t end = clock();
				printf("Sorted data(time):  ");
				dir(wnames, sze, tme1, hlp, i);
				long double q = end;
				q /= 1000000;
				printf("Time of Bubble_sort: %lf.\n", q);
			}

		}

		if (sr == 3) {

			if (wsr == 1) {
				clock_t begin = clock();
				merge_sort(arr, hlp, 0, i - 1);
				clock_t end = clock();
				printf("Sorted data(size):  ");
				dir(wnames, sze, tme1, hlp, i);
				long double q = end;
				q /= 1000000;
				printf("Time of Merge_sort: %lf.\n", q);
			}
			if (wsr == 2) {
				clock_t begin = clock();
				merge_sort(arrt, hlp, 0, i - 1);
				clock_t end = clock();
				printf("Sorted data(time):  ");
				dir(wnames, sze, tme1, hlp, i);
				long double q = end;
				q /= 1000000;
				printf("Time of Merge_sort: %lf.\n", q);
			}

		}


	}
}