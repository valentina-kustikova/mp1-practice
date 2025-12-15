#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define MAXAMOUNT 200


void print_files(char** names, int* sizes, int count);

void selection_sort(char** names, int* sizes, int count, int order);
void insertion_sort(char** names, int* sizes, int count, int order);
void bubble_sort(char** names, int* sizes, int count, int order);
void merge_sort(char** names, int* sizes, int count, int order, int l, int r);
void merge(char** names, int* sizes, int order, int l, int m, int r);


int main() {
	char path[256];
	WIN32_FIND_DATAA data;
	HANDLE find;
	char** names = NULL;
	int* sizes = NULL;
	int count = 0;
	int choice, order, i;

	printf("Enter catalogue path: ");
	scanf_s("%s", path, 256);
	strcat_s(path, sizeof(path), "\\*.*");
	printf("Searching in: %s\n", path);

	names = (char**)malloc(MAXAMOUNT * sizeof(char*));
	sizes = (int*)malloc(MAXAMOUNT * sizeof(int));

	find = FindFirstFileA(path, &data);
	if (find == INVALID_HANDLE_VALUE) {
		printf("Error opening catalogue");
		return 1;
	}

	do {
		if (strcmp(data.cFileName, ".") == 0 || strcmp(data.cFileName, "..") == 0)
			continue;

		printf("Found file: %s\n", data.cFileName);

		names[count] = (char*)malloc(strlen(data.cFileName) + 1);
		strcpy_s(names[count], strlen(data.cFileName) + 1, data.cFileName);

		sizes[count] = data.nFileSizeLow;
		count++;
	} while (FindNextFileA(find, &data));

	FindClose(find);

	while (1) {
		printf("\nSelect sorting choice: \n");
		printf("1 - selection\n");
		printf("2 - insertion\n");
		printf("3 - bubble\n");
		printf("4 - merge\n");
		printf("0 - exit programm\n");
		scanf_s("%d", &choice);

		if (choice == 0)
			break;

		printf("Select sording order: ascending (0) or descending (1) ");
		scanf_s("%d", &order);

		switch (choice) {
		case 1:
			selection_sort(names, sizes, count, order);
			break;
		case 2:
			insertion_sort(names, sizes, count, order);
			break;
		case 3:
			bubble_sort(names, sizes, count, order);
			break;
		case 4:
			merge_sort(names, sizes, count, order, 0, count - 1);
			break;
		default:
			printf("Incorrect choice!\n");
		}

		print_files(names, sizes, count);
	}

	for (i = 0; i < count; i++) {
		free(names[i]);
	}

	free(names);
	free(sizes);

	return 0;
}


void print_files(char** names, int* sizes, int count) {
	int i;
	for (i = 0; i < count; i++) {
		printf("%s - %d bytes\n", names[i], sizes[i]);
	}
}


// Сортировка выбором
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


// Сортировка вставкой
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


// Сортировка пузырьком
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


// Сортировка слиянием
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