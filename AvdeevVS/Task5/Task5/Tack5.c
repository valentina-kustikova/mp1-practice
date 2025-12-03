#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define T 256
int* size;
int* ind;
char** name;
//C:\Users\1\Desktop\Maybe
void Start(int* cn, char ad[]) {
	int i,q=0;
	unsigned int max = 0;
	char plus[3] = "\\*\0";
	printf("Enter the address of the directory:\n");
	scanf("%s", ad);
	strcat(ad, plus);
	//C:\Users\1\Desktop\Maybe
	WIN32_FIND_DATAA data;
	//printf("%s\n", ad);
	HANDLE hFind = FindFirstFileA(ad, &data);
	//printf("%p\n", hFind);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes == 32) {
				if (max < strlen(data.cFileName)) {
					//printf("%d ", strlen(data.cFileName));
					max = strlen(data.cFileName);
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
	//printf("%d", max);
	size = (int*)malloc((*cn) * sizeof(int));
	name = (char**)malloc((*cn) * sizeof(char*));
	/*if (name) {
		printf("2\n");
	}*/
	for (i = 0; i < (*cn); i++) {
		name[i] = (char*)malloc((max + 2) * sizeof(char));
	}
	hFind = FindFirstFileA(ad, &data);
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
void Clean(int cnt, int* cl) {
	int i;
	for (i = 0; i < cnt; i++) {
		size[i] = cl[i];
		ind[i] = i;
	}
}
void BubbleSort(int cnt) {
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
void InsertSort(int cnt) {
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
void Merge(int l, int m, int r,int cnt) {
	/*int i, j, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* h;
	int* rArr;
	int* lArr;
	h = (int*)malloc((r - l + 1) * sizeof(int));
	lArr = (int*)malloc(n1 * sizeof(int));
	rArr = (int*)malloc(n2 * sizeof(int));
	for (i = 0; i < n1; i++) {
		lArr[i] = size[l + i];
	}
	for (j = 0; j < n2; j++) {
		rArr[j] = size[m + 1 + j];
	}
	for (j = 0; j < n2; j++) {
		h[j] = j;
	}
	i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (lArr[i] <= rArr[j]) {
			h[k] = ind[l+i];
			size[k++] = lArr[i++];
		}
		else {
			h[k] = ind[m+1+j];
			size[k++] = rArr[j++];
		}
	}
	while (i < n1) {
		h[k] = ind[l+i];
		size[k++] = lArr[i++];
	}
	while (j < n2) {
		h[k] = ind[m+1+j];
		size[k++] = rArr[j++];
	}
	for (j = l; j <= r; j++) {
		ind[j] = h[j];
	}
	free(lArr);
	free(rArr);
	free(h);*/
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
void MergeSort(int l, int r,int cnt) {
	int m;
	if (l + 1 <= r) {
		m = l + (r - l) / 2;
		MergeSort(l, m,cnt);
		MergeSort( m + 1, r,cnt);
		Merge( l, m, r,cnt);
	}
}
void Msort(int cnt) {
	int l = 0, r = cnt - 1, i;
	LARGE_INTEGER st, end, freq;
	double t;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&st);
	MergeSort(l, r,cnt);
	QueryPerformanceCounter(&end);
	t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[ind[i]], size[i]);
	}
	printf("Execution time - %.6f nanoseconds\n", t);
}
void SimpleSort(int cnt) {
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
void ChoiceSort(int cnt) {
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
void HoarSort(int cnt,int n1,int n2) {
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
		HoarSort(cnt, n1, j);
	}
	if (i < n2) {
		HoarSort(cnt, i, n2);
	}
}
void Hsort(int cnt) {
	int n1 = 0, n2 = cnt - 1, i;
	LARGE_INTEGER st, end, freq;
	double t;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&st);
	HoarSort(cnt,n1, n2);
	QueryPerformanceCounter(&end);
	t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[ind[i]], size[i]);
	}
	printf("Execution time - %.6f nanoseconds\n", t);
}
void Print_and_Protect(int cnt,int* cl) {
	int i;
	ind = (int*)malloc(cnt * sizeof(int));
	for (i = 0; i < cnt; i++) {
		cl[i] = size[i];
		ind[i] = i;
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
	char* locale = setlocale(LC_ALL, "");
	int cnt = 0, fl, b = 1,i;
	int* cl;
	int* cn = &cnt;
	char ad[T];
	Start(cn, ad);
	cl = (int*)malloc(cnt * sizeof(int));
	Print_and_Protect(cnt,cl);
	while (b != 0) {
		scanf("%d", &fl);
		switch (fl) {
		case 1:
			BubbleSort(cnt);
			Clean( cnt,cl);
			break;
		case 2:
			InsertSort(cnt);
			Clean(cnt, cl);
			break;
		case 3:
			Msort(cnt);
			Clean( cnt, cl);
			break;
		case 4:
			SimpleSort(cnt);
			Clean( cnt, cl);
			break;
		case 5:
			ChoiceSort(cnt);
			Clean(cnt, cl);
			break;
		case 6:
			Hsort(cnt);
			Clean( cnt, cl);
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