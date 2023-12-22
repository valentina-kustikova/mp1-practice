#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <omp.h>
#define BUFFER 2048

int arr_fill(wchar_t** names, unsigned long long* sizes);
void sort(wchar_t** names, unsigned long long* sizes, int numoffiles);
void insertion_sort(wchar_t** names, unsigned long long* sizes, int numoffiles);
void selection_sort(wchar_t** names, unsigned long long* sizes, int numoffiles);
void merge_sort(wchar_t** names, unsigned long long* sizes, int left, int right);
void merge(wchar_t** names, unsigned long long* sizes, int left, int mid, int right);
void output(wchar_t** names, unsigned long long* sizes, int numoffiles);

int main() {
	int num1 = 0;
	wchar_t** names = (wchar_t*) malloc (BUFFER * sizeof(wchar_t*));
	unsigned long long* sizes = (unsigned long long*)malloc(BUFFER * sizeof(unsigned long long));
	int numoffiles = arr_fill(names, sizes);
	sort(names, sizes, numoffiles);

	do {	
		printf("Do you want to choose another sort? [1/0]: ");
		scanf("%d", &num1);
		if (num1 == 1) {
			printf("\n");
			sort(names, sizes, numoffiles);
		}
	} while (num1 != 0);
	free(names);
	free(sizes);
	return 0;
}
int arr_fill(wchar_t** names, unsigned long long* sizes) {
	int numoffiles = 1, i = 0;
	WIN32_FIND_DATA finddata;
	char* adress[BUFFER];
	wchar_t* end_adress;
	end_adress = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
	HANDLE firstin;
	printf("Please, enter the path to the folder and then press Enter. \n");
	_getws(adress);

	wsprintf(end_adress, L"%s\\*", adress);
	firstin = FindFirstFile(end_adress, &finddata);


	if (firstin != INVALID_HANDLE_VALUE) {
		do
		{
			if (strcmp(finddata.cFileName, ".") != 0 && strcmp(finddata.cFileName, "..") != 0) {
				sizes[numoffiles - 1] = finddata.nFileSizeLow;
				numoffiles++;
				names[i] = (wchar_t*)malloc(sizeof(wchar_t) * BUFFER);
				wsprintf(end_adress, L"%s", finddata.cFileName);
				wsprintf(names[i], L"%s", end_adress);
				i++;
			}
		} while (FindNextFile(firstin, &finddata));
		FindClose(firstin);
	}
	
	return numoffiles;
}

void sort(wchar_t** names, unsigned long long* sizes, int numoffiles) {
	wchar_t** names_copy = (wchar_t*)malloc(BUFFER * sizeof(wchar_t*));
	unsigned long long* sizes_copy = (unsigned long long*)malloc(BUFFER * sizeof(unsigned long long));
	memcpy(sizes_copy, sizes, BUFFER * sizeof(wchar_t*));
	memcpy(names_copy, names, BUFFER * sizeof(unsigned long long));
	int num = 0;
	double start = 0;
	double end = 0;
	printf("Please select the sorting method: \n1. Insertion sort; \n2. Selection sort; \n3. Merge sort. \n");
		// вставками, выбором, слиянием
	scanf("%d", &num);
	if (num == 1) {
		start = omp_get_wtime();
		insertion_sort(names_copy, sizes_copy, numoffiles);
	}
	
	if (num == 2) {
		start = omp_get_wtime();
		selection_sort(names_copy, sizes_copy, numoffiles);
	}
	if (num == 3) {
		start = omp_get_wtime();
		merge_sort(names_copy, sizes_copy, 0, numoffiles);
	}
	end = omp_get_wtime();
	output(names_copy, sizes_copy, numoffiles);
	printf("\nTime: %5.15lf sec.\n", end - start);
	
	free(names_copy);
	free(sizes_copy);
}

void insertion_sort(wchar_t** names, unsigned long long* sizes, int numoffiles) {
	unsigned long long min;
	int i = 1, j;
	wchar_t* tmp;
	for (i; i < numoffiles; i++) {
		min = sizes[i];
		tmp = names[i];
		j = i - 1;
		while (j >= 0 && sizes[j] > min) {
			sizes[j + 1] = sizes[j];
			names[j + 1] = names[j];
			j--;
		}
		sizes[j+1] = min;
		names[j + 1] = tmp;
	}
}

void selection_sort(wchar_t** names, unsigned long long* sizes, int numoffiles) {
	int min = 0, i, j;
	unsigned long long tmpsize;
	wchar_t* tmpname;
	for (i = 0; i < numoffiles; i++) {
		min = i;
		for (j = i + 1; j < numoffiles; j++) {
			if (sizes[j] < sizes[min]) {
				min = j;
			}
		}
		tmpsize = sizes[min];
		sizes[min] = sizes[i];
		sizes[i] = tmpsize;
		tmpname = names[min];
		names[min] = names[i];
		names[i] = tmpname;
	}
}

void merge_sort(wchar_t** names, unsigned long long* sizes, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(names, sizes, left, mid);
		merge_sort(names, sizes, mid + 1, right);
		merge(names, sizes, left, mid, right);
	}

}

void merge(wchar_t** names, unsigned long long* sizes, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	unsigned long long* L = (unsigned long long*)malloc(n1 * sizeof(unsigned long long));
	unsigned long long* R = (unsigned long long*)malloc(n2 * sizeof(unsigned long long));
	wchar_t** LA = (wchar_t*)malloc(n1 * sizeof(wchar_t*));
	wchar_t** RA = (wchar_t*)malloc(n2 * sizeof(wchar_t*));


	for (i = 0; i < n1; i++) {
		L[i] = sizes[left + i];
		LA[i] = names[left + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = sizes[mid + 1 + j];
		RA[j] = names[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			sizes[k] = L[i];
			names[k] = LA[i];
			i++;
		}
		else {
			sizes[k] = R[j];
			names[k] = RA[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		sizes[k] = L[i];
		names[k] = LA[i];
		i++;
		k++;
	}

	while (j < n2) {
		sizes[k] = R[j];
		names[k] = RA[j];
		j++;
		k++;
	}
}


void output(wchar_t** names, unsigned long long* sizes, int numoffiles) {
	printf("\n");
	printf("Name                 Size\n");
	for (int i = 0; i < numoffiles-1; i++) {
		printf("%S", names[i]);
		if (sizes[i] == 0) {
			printf("                  Folder\n");
		}
		else {
			printf("           %llu bytes\n", sizes[i]);
		}
	}
}
