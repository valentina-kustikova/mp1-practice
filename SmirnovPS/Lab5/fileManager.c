#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>


void scan_files(char* folderPath, char*** scannedNames, int** scannedSizes, int* count);
void copy_files(char** scannedNames, int* scannedSizes, int count, char*** sortedNames, int** sortedSizes);
void print_files(char** names, int* sizes, int count);

void selection_sort(char** names, int* sizes, int count, int order);
void insertion_sort(char** names, int* sizes, int count, int order);
void bubble_sort(char** names, int* sizes, int count, int order);
void merge_sort(char** names, int* sizes, int count, int order, int l, int r);
void merge(char** names, int* sizes, int order, int l, int m, int r);


int main() {
	char folderPath[256];
	char** scannedNames = NULL;
	int* scannedSizes = NULL;
	int i, count = 0;

	printf("Enter catalogue path: ");
	scanf_s("%s", folderPath, (unsigned)_countof(folderPath));

	scan_files(folderPath, &scannedNames, &scannedSizes, &count);
	if (count == 0)
		return 1;

	while (1) {
		clock_t start, end;
		int choice, order;
		double time_spent;

		printf("\nSelect sorting choice: \n");
		printf("1 - selection\n");
		printf("2 - insertion\n");
		printf("3 - bubble\n");
		printf("4 - merge\n");
		printf("0 - exit\n");
		scanf_s("%d", &choice);

		if (choice == 0)
			break;

		printf("Select sording order: ascending (0) or descending (1) ");
		scanf_s("%d", &order);

		char** sortedNames; 
		int* sortedSizes; 
		copy_files(scannedNames, scannedSizes, count, &sortedNames, &sortedSizes);

		switch (choice) {
			case 1:
				start = clock();
				selection_sort(sortedNames, sortedSizes, count, order);
				end = clock();
				time_spent = (double)(end - start) / CLOCKS_PER_SEC;
				break;
			case 2:
				start = clock();
				insertion_sort(sortedNames, sortedSizes, count, order);
				end = clock();
				time_spent = (double)(end - start) / CLOCKS_PER_SEC;
				break;
			case 3:
				start = clock();
				bubble_sort(sortedNames, sortedSizes, count, order);
				end = clock();
				time_spent = (double)(end - start) / CLOCKS_PER_SEC;
				break;
			case 4:
				start = clock();
				merge_sort(sortedNames, sortedSizes, count, order, 0, count - 1);
				end = clock();
				time_spent = (double)(end - start) / CLOCKS_PER_SEC;
				break;
			default:
				printf("Incorrect choice!\n");
				continue;
		}	
		
		print_files(sortedNames, sortedSizes, count);
		printf("\nSorting completed in %.3f seconds\n", time_spent);

		for (i = 0; i < count; i++) 
			free(sortedNames[i]);
		free(sortedNames);
		free(sortedSizes);
	}

	for (i = 0; i < count; i++)
		free(scannedNames[i]);
	free(scannedNames);
	free(scannedSizes);

	return 0;
}


void scan_files(char* folderPath, char*** scannedNames, int** scannedSizes, int* count) {
	WIN32_FIND_DATAA data;
	HANDLE find;
	char path[256];
	int capacity = 10;
	int fileCount = 0;

	*scannedNames = (char**)malloc(capacity * sizeof(char*));
	*scannedSizes = (int*)malloc(capacity * sizeof(int));

	strcpy_s(path, sizeof(path), folderPath);
	strcat_s(path, sizeof(path), "\\*.*");

	find = FindFirstFileA(path, &data);
	if (find == INVALID_HANDLE_VALUE) {
		printf("Error opening catalogue\n");
		*count = 0;
		return;
	}

	do {
		if (strcmp(data.cFileName, ".") == 0 || strcmp(data.cFileName, "..") == 0 || (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			continue;

		if (fileCount >= capacity) {
			capacity *= 2;
			*scannedNames = (char**)realloc(*scannedNames, capacity * sizeof(char*));
			*scannedSizes = (int*)realloc(*scannedSizes, capacity * sizeof(int));
		}

		(*scannedNames)[fileCount] = (char*)malloc(strlen(data.cFileName) + 1);
		strcpy_s((*scannedNames)[fileCount], strlen(data.cFileName) + 1, data.cFileName);

		(*scannedSizes)[fileCount] = data.nFileSizeLow;
		fileCount++;

	} while (FindNextFileA(find, &data));

	FindClose(find);
	*count = fileCount;
}



void copy_files(char** scannedNames, int* scannedSizes, int count, char*** sortedNames, int** sortedSizes)
{
	*sortedNames = (char**)malloc(count * sizeof(char*));
	*sortedSizes = (int*)malloc(count * sizeof(int));

	int i;

	for (i = 0; i < count; i++) {
		(*sortedNames)[i] = (char*)malloc(strlen(scannedNames[i]) + 1);
		strcpy_s((*sortedNames)[i], strlen(scannedNames[i]) + 1, scannedNames[i]);
		(*sortedSizes)[i] = scannedSizes[i];
	}
}



void print_files(char** names, int* sizes, int count) {
	int i;
	for (i = 0; i < count; i++) {
		printf("%s - %d bytes\n", names[i], sizes[i]);
	}
}


void selection_sort(char** names, int* sizes, int count, int order) {
	int i;
	for (i = 0; i < count - 1; i++) {
		int minmax = i;
		int j;
		for (j = i + 1; j < count; j++) {
			if (order ? sizes[j] > sizes[minmax] : sizes[j] < sizes[minmax])
				minmax = j;
		}
		if (minmax != i) {
			int tempSize = sizes[i];
			sizes[i] = sizes[minmax];
			sizes[minmax] = tempSize;

			char* tempName = names[i];
			names[i] = names[minmax];
			names[minmax] = tempName;
		}
	}
}


void insertion_sort(char** names, int* sizes, int count, int order) {
	int i;
	for (i = 1; i < count; i++) {
		int tempSize = sizes[i];
		char* tempName = names[i];
		int j = i - 1;

		while (j >= 0 && (order ? sizes[j] < tempSize : sizes[j] > tempSize)) {
			sizes[j + 1] = sizes[j];
			names[j + 1] = names[j];
			j--;
		}

		sizes[j + 1] = tempSize;
		names[j + 1] = tempName;
	}
}


void bubble_sort(char** names, int* sizes, int count, int order) {
	int i, j;
	for (i = 0; i < count - 1; i++) {
		for (j = 0; j < count - i - 1; j++) {
			if (order ? sizes[j] < sizes[j + 1] : sizes[j] > sizes[j + 1]) {
				int tempSize = sizes[j];
				sizes[j] = sizes[j + 1];
				sizes[j + 1] = tempSize;

				char* tempName = names[j];
				names[j] = names[j + 1];
				names[j + 1] = tempName;
			}
		}
	}
}


void merge_sort(char** names, int* sizes, int count, int order, int l, int r) {
	int m;
	if (l >= r)
		return;
	m = l + (r - l) / 2;
	merge_sort(names, sizes, count, order, l, m);
	merge_sort(names, sizes, count, order, m + 1, r);
	merge(names, sizes, order, l, m, r);
}


void merge(char** names, int* sizes, int order, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int i, j, k;

	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));
	char** Lnames = (char**)malloc(n1 * sizeof(char*));
	char** Rnames = (char**)malloc(n2 * sizeof(char*));

	for (i = 0; i < n1; i++) {
		L[i] = sizes[l + i];
		Lnames[i] = names[l + i];
	}

	for (j = 0; j < n2; j++) {
		R[j] = sizes[m + 1 + j];
		Rnames[j] = names[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (order == 0) {
			if (L[i] <= R[j]) {
				sizes[k] = L[i];
				names[k] = Lnames[i];
				i++;
			}
			else {
				sizes[k] = R[j];
				names[k] = Rnames[j];
				j++;
			}
		}
		else {
			if (L[i] >= R[j]) {
				sizes[k] = L[i];
				names[k] = Lnames[i];
				i++;
			}
			else {
				sizes[k] = R[j];
				names[k] = Rnames[j];
				j++;
			}
		}
		k++;
	}
	while (i < n1) {
		sizes[k] = L[i];
		names[k] = Lnames[i];
		i++; 
		k++;
	}
	while (j < n2) {
		sizes[k] = R[j];
		names[k] = Rnames[j];
		j++; 
		k++;
	}
	
	free(L);
	free(R);
	free(Lnames);
	free(Rnames);
}


