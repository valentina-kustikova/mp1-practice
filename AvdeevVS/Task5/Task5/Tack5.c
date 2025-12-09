#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define T 256
//C:\Users\1\Desktop\Maybe
void StartProv(int* cn, char ad[], unsigned int* ma) {
	int i;
	char plus[3] = "\\*\0";
	printf("Enter the address of the directory:\n");
	scanf("%s", ad);
	strcat(ad, plus);
	WIN32_FIND_DATAA data;
	HANDLE hFind = FindFirstFileA(ad, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes == 32) {
				if ((*ma) < strlen(data.cFileName)) {
					(*ma) = strlen(data.cFileName);
				}
				(*cn)++;
			}
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
	else {
		DWORD error = GetLastError();
		printf("Fatal -- Invalid directory address\n");
		printf("Error ñode -- %d\n", error);
	  exit(0);
	}
	if ((*cn) == 0) {
		printf("There are no files in the directory!\n");
		exit(0);
	}
}
void StartReady(int cnt,int* size,int* ind, char** name,char ad[],unsigned int max) {
	int q = 0;
	WIN32_FIND_DATAA data;
	HANDLE hFind = FindFirstFileA(ad, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes == 32) {
				strcpy(name[q], data.cFileName);
				size[q++] = data.nFileSizeLow;
				printf("FILE --> %s --> %d\n", data.cFileName, data.nFileSizeLow);
			}
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
}
void Clean(int cnt, int* cl,int* size,int* ind) {
	int i;
	for (i = 0; i < cnt; i++) {
		size[i] = cl[i];
		ind[i] = i;
	}
}
void BubbleSort(int cnt, int* size, int* ind, char** name) {
	int i, j, p, e;
	LARGE_INTEGER st, end, freq;
	double t;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&st);
	for (i = 0; i < cnt - 1; i++) {
		for (j = 0; j < cnt - i - 1; j++) {
			if (size[j] > size[j + 1]) {
				e = size[j];
				size[j] = size[j + 1];
				size[j + 1] = e;
				p = ind[j];
			  ind[j] = ind[j + 1];
				ind[j + 1] = p;
			}
		}
	}
	QueryPerformanceCounter(&end);
	t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[ind[i]], size[i]);
	}
	printf("Execution time - %.6f nanoseconds\n", t);
}
void InsertSort(int cnt, int* size, int* ind, char** name) {
	int i, j, temp,z;
	LARGE_INTEGER st, end, freq;
	double t;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&st);
	for (i = 0; i < cnt; i++) {
		z = size[i];
		temp = ind[i];
		j = i - 1;
		while (j >= 0 && (size[j] > z)) {
			size[j + 1] = size[j];
			ind[j + 1] = ind[j];
			j--;
		}
		size[j + 1] = z;
		ind[j + 1] = temp;
	}
	QueryPerformanceCounter(&end);
	t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[ind[i]], size[i]);
	}
	printf("Execution time - %.6f nanoseconds\n", t);
}
void Merge(int l, int m, int r,int cnt,int* size,int* ind) {
	int i = l, j = m + 1, k = 0;
	int* arr;
	int* iarr;
	arr = (int*)malloc(cnt * sizeof(int));
	iarr = (int*)malloc(cnt * sizeof(int));
	while (i <= m && j <= r) {
		if (size[i] <= size[j]) {
			arr[k] = size[i];
			iarr[k++] = ind[i++];
		}
		else {
			arr[k] = size[j];
			iarr[k++] = ind[j++];
		}
	}
	while (i <= m) {
		arr[k] = size[i];
		iarr[k] = ind[i];
		k++; i++;
	}
	while (j <= r) {
		arr[k] = size[j];
		iarr[k] = ind[j];
		k++; j++;
	}
	for (i = 0; i < r - l + 1; i++) {
		size[l + i] = arr[i];
		ind[l + i] = iarr[i];
	}
	free(arr);
	free(iarr);
}
void MergeSort(int l, int r,int cnt, int* size, int* ind) {
	int m;
	if (l + 1 <= r) {
		m = l + (r - l) / 2;
		MergeSort(l, m,cnt,size, ind);
		MergeSort( m + 1, r,cnt, size, ind);
		Merge( l, m, r,cnt, size, ind);
	}
}
void Msort(int cnt, int* size, int* ind, char** name) {
	int l = 0, r = cnt - 1, i;
	LARGE_INTEGER st, end, freq;
	double t;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&st);
	MergeSort(l, r,cnt, size, ind);
	QueryPerformanceCounter(&end);
	t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[ind[i]], size[i]);
	}
	printf("Execution time - %.6f nanoseconds\n", t);
}
void SimpleSort(int cnt, int* size, int* ind, char** name) {
	LARGE_INTEGER st, end, freq;
	double g;
	int i, j, p, t;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&st);
	for (i = 0; i < cnt; i++) {
		for (j = i + 1; j < cnt; j++) {
			if (size[i] > size[j]) {
				t = size[i];
				size[i] = size[j];
				size[j] = t;
				p = ind[i];
				ind[i] = ind[j];
				ind[j] = p;
			}
		}
	}
	QueryPerformanceCounter(&end);
	g = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[ind[i]], size[i]);
	}
	printf("Execution time - %.6f nanoseconds\n", g);
}
void ChoiceSort(int cnt, int* size, int* ind, char** name) {
	int i, j, min, in, p,t;
	LARGE_INTEGER st, end, freq;
	double g;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&st);
	for (i = 0; i < cnt; i++) {
		min = size[i];
		in = i;
		for (j = i + 1; j < cnt; j++) {
			if (size[j] < min) {
				min = size[j];
				in = j;
			}
		}
		t = size[i];
		size[i] = size[in];
		size[in] = t;
		p = ind[i];
		ind[i] = ind[in];
		ind[in] = p;
	}
	QueryPerformanceCounter(&end);
	g = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[ind[i]], size[i]);
	}
	printf("Execution time - %.6f nanoseconds\n", g);
}
void HoarSort(int cnt,int n1,int n2, int* size, int* ind) {
	int m = n1 + (n2 - n1) / 2;
	int i = n1, j = n2,t,f;
	int p = size[m];
	do {
		while (size[i] < p) {
			i++;
		}
		while (size[j] > p) {
			j--;
		}
		if (i <= j) {
			t = ind[i];
			ind[i] = ind[j];
			ind[j] = t;
			f = size[i];
			size[i] = size[j];
			size[j] = f;
			i++;
			j--;
		}
	} while (i <= j);
	if (n1 < j) {
		HoarSort(cnt, n1, j, size, ind);
	}
	if (i < n2) {
		HoarSort(cnt, i, n2, size, ind);
	}
}
void Hsort(int cnt, int* size, int* ind, char** name) {
	int n1 = 0, n2 = cnt - 1, i;
	LARGE_INTEGER st, end, freq;
	double t;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&st);
	HoarSort(cnt,n1, n2, size, ind);
	QueryPerformanceCounter(&end);
	t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[ind[i]], size[i]);
	}
	printf("Execution time - %.6f nanoseconds\n", t);
}
void Print_and_Protect(int cnt,int* cl, int* size) {
	int i;
	for (i = 0; i < cnt; i++) {
		cl[i] = size[i];
	}
	printf("\n");
	printf("Select sorting or end the program:\n");
	printf("1 - Bubble sorting\n");
	printf("2 - Insertion sorting\n");
	printf("3 - Merge sorting\n"); 
	printf("4 - Simplest sorting\n");
	printf("5 - Choice sorting\n");
	printf("6 - Quick sorting\n");
	printf("7 - End the program\n\n");
}
int main() {
	unsigned int max = 0;
	unsigned int* ma = &max;
	int* size;
	int* ind;
	char** name;
	char* locale = setlocale(LC_ALL, "");
	int cnt = 0, fl, b = 1,i;
	int* cl;
	int* cn = &cnt;
	char ad[T];
	StartProv(cn, ad,ma);
	size = (int*)malloc(cnt * sizeof(int));
	name = (char**)malloc(cnt * sizeof(char*));
	ind = (int*)malloc(cnt * sizeof(int));
	for (i = 0; i < cnt; i++) {
		ind[i] = i;
		name[i] = (char*)malloc((max + 2) * sizeof(char));
	}
	StartReady(cnt, size, ind, name, ad,max);
	cl = (int*)malloc(cnt * sizeof(int));
	Print_and_Protect(cnt,cl,size);
	while (b != 0) {
		scanf("%d", &fl);
		switch (fl) {
		case 1:
			BubbleSort(cnt, size, ind, name);
			Clean( cnt,cl, size, ind);
			break;
		case 2:
			InsertSort(cnt, size, ind, name);
			Clean(cnt, cl, size, ind);
			break;
		case 3:
			Msort(cnt, size, ind, name);
			Clean( cnt, cl, size, ind);
			break;
		case 4:
			SimpleSort(cnt, size, ind, name);
			Clean( cnt, cl, size, ind);
			break;
		case 5:
			ChoiceSort(cnt, size, ind, name);
			Clean(cnt, cl, size, ind);
			break;
		case 6:
			Hsort(cnt, size, ind, name);
			Clean( cnt, cl, size, ind);
			break;
		case 7:
			b = 0;
			printf("The end!");
			break;
		default:
			printf("Fatal -- There is no sorting with a given number\n");
		}
	}
	free(cl);
	free(size);
	free(ind);
	for (i = 0; i < cnt; i++) {
		free(name[i]);
	}
	free(name);
	return 0;
}