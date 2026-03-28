#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define maxfile 5000

void print_files(char** file_name, int* file_size, int count);

void simple_sort(char** file_name, int* file_size, int count, int direction);
void selection_sort(char** file_name, int* file_size, int count, int direction);
void insertion_sort(char** file_name, int* file_size, int count, int direction);
void bubble_sort(char** file_name, int* file_size, int count, int direction);
void quick_sort(char** file_name, int* file_size, int count, int direction);
void quick_sort_recursive(char** file_name, int* file_size, int l, int r, int direction);
void merge_sort(char** file_name, int* file_size, int count, int l, int r, int direction);
void merge(char** file_name, int* file_size, int l, int r, int m, int direction);
int partition(char** file_name, int* file_size, int l, int r, int direction);



int main() {
	char way[256];
	WIN32_FIND_DATAA file_info;
	HANDLE find;
	char** file_name = NULL;
	int* file_size = NULL;
	int count = 0;
	int select, direction, i;

	printf("Vvedite put k failu\n");
	scanf_s("%s", way, 256);
	strcat_s(way, sizeof(way), "\\*.*");

	file_name = (char**)malloc(maxfile * sizeof(char*));
	file_size = (int*)malloc(maxfile * sizeof(int));

	find = FindFirstFileA(way, &file_info);
	if (find == INVALID_HANDLE_VALUE) {
		printf("Oshibka\n");
		free(file_name);
		free(file_size);
		return 1;
	}

	do {
		if (strcmp(file_info.cFileName, ".") == 0 || strcmp(file_info.cFileName, "..") == 0)
			continue;
		if (count >= maxfile) {
			printf("Slishkom mnogo failov, limit - %d.\n", maxfile);
			break;
		}

		file_name[count] = (char*)malloc(strlen(file_info.cFileName) + 1);
		strcpy_s(file_name[count], strlen(file_info.cFileName) + 1, file_info.cFileName);
		file_size[count] = file_info.nFileSizeLow;
		count += 1;

	} while (FindNextFileA(find, &file_info));

	FindClose(find);

	while (1) {
		printf("\nViberite metod sortirovki\n");
		printf("1 - prosteishaya\n2 - viborom\n3 - vstavkami\n4 - puzirkom\n"
			"5 - sliyaniem\n6 - bistraya\n0 - zakrit programmu\n");
		scanf_s("%d", &select);
		
		if (select == 0)
			break;

		printf("Viberi napravlenie: po vozrastaniyu - 1, po ubivaniyu - 0\n");
		scanf_s("%d", &direction);
		
		clock_t start, end;
		double time_used;

		switch (select) {
		case 1:
			start = clock();
			simple_sort(file_name, file_size, count, direction);
			end = clock();
			break;
		case 2:
			start = clock();
			selection_sort(file_name, file_size, count, direction);
			end = clock();
			break;
		case 3:
			start = clock();
			insertion_sort(file_name, file_size, count, direction);
			end = clock();
			break;
		case 4:
			start = clock();
			bubble_sort(file_name, file_size, count, direction);
			end = clock();
			break;
		case 5:
			start = clock();
			merge_sort(file_name, file_size, count, direction, 0, count-1);
			end = clock();
			break;
		case 6:
			start = clock();
			quick_sort(file_name, file_size, count, direction);
			end = clock();
			break;
		}
		
		time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

		print_files(file_name, file_size, count);
		
		printf("Vremya vipolneniya: %.6f sekund\n", time_used);
	
		

	}
	for (i = 0; i < count; i++) {
		free(file_name[i]);
	}
	free(file_name);
	free(file_size);
	return 0;
}
void print_files(char** file_name, int* file_size, int count) {
	int i;
	for (i = 0; i < count; i++) {
		printf("%s - %d bytes\n", file_name[i], file_size[i]);
	}
}

void simple_sort(char** file_name, int* file_size, int count, int direction) {
	int i = 0, j = 0;
	for (i; i < count; i++) {
		for (j = i + 1; j < count; j++) {
			if (direction == 1) {
				if (file_size[i] > file_size[j]) {
					int tmp1 = file_size[i];
					char* tmp2 = file_name[i];
					file_size[i] = file_size[j];
					file_size[j] = tmp1;
					file_name[i] = file_name[j];
					file_name[j] = tmp2;
				}
			}
			else {
				if (file_size[i] < file_size[j]) {
					int tmp1 = file_size[i];
					char* tmp2 = file_name[i];
					file_size[i] = file_size[j];
					file_size[j] = tmp1;
					file_name[i] = file_name[j];
					file_name[j] = tmp2;
				}
			}
		}
	}
}
void selection_sort(char** file_name, int* file_size, int count, int direction) {
	int i = 0, j = 0;
	for (i; i < count; i++) {
		int minmax = file_size[i], idx = i;
		for (j = i + 1; j < count; j++) {
			if (direction == 1) {
				if (minmax > file_size[j]) {
					minmax = file_size[j];
					idx = j;
				}
			}
			else {
				if (minmax < file_size[j]) {
					minmax = file_size[j];
					idx = j;
				}
			}
		}
		if (idx != i) {
			char* tmp = file_name[idx];
			file_size[idx] = file_size[i];
			file_size[i] = minmax;
			file_name[i] = file_name[idx];
			file_name[idx] = tmp;
		}
	}
}

void insertion_sort(char** file_name, int* file_size, int count, int direction) {
	int i;
	for (i = 1; i < count; i++) {
		int j = i - 1;
		int tmp1 = file_size[i];
		char* tmp2 = file_name[i];
		if (direction == 1) {
			while (j >= 0 && file_size[j] > tmp1) {
				file_size[j + 1] = file_size[j];
				file_name[j + 1] = file_name[j];
				j -= 1;
			}
		}
		else {
			while (j >= 0 && file_size[j] < tmp1) {
				file_size[j + 1] = file_size[j];
				file_name[j + 1] = file_name[j];
				j -= 1;
			}
		}
		file_size[j + 1] = tmp1;
		file_name[j + 1] = tmp2;
	}
}

void bubble_sort(char** file_name, int* file_size, int count, int direction) {
	int i, j;;
	for (i = 0; i < count; i++) {
		for (j = 0; j < count - i - 1; j++) {
			if (direction == 1) {  
				if (file_size[j] > file_size[j + 1]) {
					int tmp1 = file_size[j];
					file_size[j] = file_size[j + 1];
					file_size[j + 1] = tmp1;
					
					char* tmp2 = file_name[j];
					file_name[j] = file_name[j + 1];
					file_name[j + 1] = tmp2;
				}
			}
			else {  
				if (file_size[j] < file_size[j + 1]) {
					int tmp1 = file_size[j];
					file_size[j] = file_size[j + 1];
					file_size[j + 1] = tmp1;

					char* tmp2 = file_name[j];
					file_name[j] = file_name[j + 1];
					file_name[j + 1] = tmp2;
				}
			}
		}
	}
}

void quick_sort(char** file_name, int* file_size, int count, int direction) {
	if (count > 1)
		quick_sort_recursive(file_name, file_size, 0, count - 1, direction);
}

void quick_sort_recursive(char** file_name, int* file_size, int l, int r, int direction) {
	if (l < r) {
		int pivot_index = partition(file_name, file_size, l, r, direction);
		quick_sort_recursive(file_name, file_size, l, pivot_index - 1, direction);
		quick_sort_recursive(file_name, file_size, pivot_index + 1, r, direction);
	}
}

int partition(char** file_name, int* file_size, int l, int r, int direction) {
	int pivot_value = file_size[r];
	int i = l - 1;

	for (int j = l; j < r; j++) {
		if ((direction && file_size[j] < pivot_value) || (!direction && file_size[j] > pivot_value)) {
			i++;

			int tmp1 = file_size[i];
			file_size[i] = file_size[j];
			file_size[j] = tmp1;

			char* tmp2 = file_name[i];
			file_name[i] = file_name[j];
			file_name[j] = tmp2;
		}
	}

	int tmp1 = file_size[i + 1];
	file_size[i + 1] = file_size[r];
	file_size[r] = tmp1;

	char* tmp2 = file_name[i + 1];
	file_name[i + 1] = file_name[r];
	file_name[r] = tmp2;

	return i + 1;
}

void merge_sort(char** file_name, int* file_size, int count, int direction, int l, int r) {
	int m;
	if (l >= r)
		return;
	m = l + (r - l) / 2;
	merge_sort(file_name, file_size, count, direction, l, m);
	merge_sort(file_name, file_size, count, direction, m + 1, r);
	merge(file_name, file_size, direction, l, m, r);
}

void merge(char** file_name, int* file_size, int direction, int l, int r, int m) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int i, j, k;
	
	int* left_size = (int*)malloc(n1 * sizeof(int));
	int* right_size = (int*)malloc(n2 * sizeof(int));
	char** left_name = (char**)malloc(n1 * sizeof(char*));
	char** right_name = (char**)malloc(n2 * sizeof(char*));

	for (i = 0; i < n1; i++) {
		left_size[i] = file_size[l + i];
		left_name[i] = file_name[l + i];
	}
	for (j = 0; j < n2; j++) {
		right_size[j] = file_size[m + 1 + j];
		right_name[j] = file_name[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (direction == 1) {
			if (left_size[i] <= right_size[j]) {
				file_size[k] = left_size[i];
				file_name[k] = left_name[i];
				i++;
			}
			else {
				file_size[k] = right_size[j];
				file_name[k] = right_name[j];
				j++;
			}
		}
		else {
			if (left_size[i] >= right_size[j]) {
				file_size[k] = left_size[i];
				file_name[k] = left_name[i];
				i++;
			}
			else {
				file_size[k] = right_size[j];
				file_name[k] = right_name[j];
				j++;
			}
		}
		k++;
	}

	while (i < n1) {
		file_size[k] = left_size[i];
		file_name[k] = left_name[i];
		i++;
		k++;
	}

	while (j < n2) {
		file_size[k] = right_size[j];
		file_name[k] = right_name[j];
		j++;
		k++;
	}

	free(left_size);
	free(right_size);
	free(left_name);
	free(right_name);
}


