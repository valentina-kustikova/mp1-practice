#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define DIRECTORY_LENGTH 5

void simple_sort(int a[], int n);
void choose_sort(int a[], int n);
void insert_sort(int a[], int n);
void bubble_sort(int a[], int n);
void merge_sort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);
void quick_sort(int a[], int n1, int n2);

int file_directory_1[DIRECTORY_LENGTH] = { 4, 3, 5, 2, 1 };
int sizelist_1[DIRECTORY_LENGTH] = { 75, 388, 289, 45, 203 };

int file_directory_2[DIRECTORY_LENGTH] = { 17, 45, 33, 65, 58 };
int sizelist_2[DIRECTORY_LENGTH] = { 790, 274, 28, 642, 45 };

int file_directory_3[DIRECTORY_LENGTH] = { 79, 57, 12, 87, 34 };
int sizelist_3[DIRECTORY_LENGTH] = { 638, 28, 976, 112, 784 };

int main() {
	clock_t start_time, end_time;
	double diff_time;
	int* temp_directory, * temp_sizelist;
	temp_directory = (int*)malloc(DIRECTORY_LENGTH * sizeof(int));
	temp_sizelist = (int*)malloc(DIRECTORY_LENGTH * sizeof(int));
	int directory_choise = 0, sort_choise = 0, i, j, l = 0, r = DIRECTORY_LENGTH, n1 = 0, n2 = DIRECTORY_LENGTH;

	printf("Choose a directory:\n\n1. Directory 1\n2. Directiry 2\n3. Directory 3\n\n");
	while (directory_choise < 1 || directory_choise > 3) {
		scanf_s("%d", &directory_choise);
		if (directory_choise < 1 || directory_choise > 3) {
			printf("Wrong input. Try again.\n");
		}
	}
	system("cls");
	printf("Directory choosed: %d\n\n", directory_choise);
	printf("Choose a sort type:\n\n1. Simple Sort\n2. Choose Sort\n3. Insert Sort\n4. Bubble Sort\n5. Merge Sort\n6. Qiuck Sort\n\n");
	while (sort_choise < 1 || sort_choise > 6) {
		scanf_s("%d", &sort_choise);
		if (sort_choise < 1 || sort_choise > 6) {
			printf("Wrong input. Try again.\n");
		}
	}
	system("cls");
	printf("Directory choosed: %d\n\n", directory_choise);
	printf("Sort type choosed: %d\n\n", sort_choise);

	switch (directory_choise) {
	case 1:
		for (i = 0; i < DIRECTORY_LENGTH; i++) temp_directory[i] = file_directory_1[i];
		break;
	case 2:
		for (i = 0; i < DIRECTORY_LENGTH; i++) temp_directory[i] = file_directory_2[i];
		break;
	case 3:
		for (i = 0; i < DIRECTORY_LENGTH; i++) temp_directory[i] = file_directory_3[i];
		break;
	}

	switch (sort_choise) {
	case 1:
		start_time = clock();
		simple_sort(temp_directory, DIRECTORY_LENGTH);
		end_time = clock();
		break;
	case 2:
		start_time = clock();
		choose_sort(temp_directory, DIRECTORY_LENGTH);
		end_time = clock();
		break;
	case 3:
		start_time = clock();
		insert_sort(temp_directory, DIRECTORY_LENGTH);
		end_time = clock();
		break;
	case 4:
		start_time = clock();
		bubble_sort(temp_directory, DIRECTORY_LENGTH);
		end_time = clock();
		break;
	case 5:
		start_time = clock();
		merge_sort(temp_directory, l, r);
		end_time = clock();
		break;
	case 6:
		start_time = clock();
		quick_sort(temp_directory, n1, n2);
		end_time = clock();
		break;
	}

	diff_time = (double)(end_time - start_time)/CLOCKS_PER_SEC; //почему время всегда 0

	switch (directory_choise) {
	case 1:
		for (i = 0; i < DIRECTORY_LENGTH; i++) {
			for (j = 0; j < DIRECTORY_LENGTH; j++) {
				if (temp_directory[i] == file_directory_1[j]) {
					temp_sizelist[i] = sizelist_1[j];
				}
			}
		}
		break;
	case 2:
		for (i = 0; i < DIRECTORY_LENGTH; i++) {
			for (j = 0; j < DIRECTORY_LENGTH; j++) {
				if (temp_directory[i] == file_directory_2[j]) {
					temp_sizelist[i] = sizelist_2[j];
				}
			}
		}
		break;
	case 3:
		for (i = 0; i < DIRECTORY_LENGTH; i++) {
			for (j = 0; j < DIRECTORY_LENGTH; j++) {
				if (temp_directory[i] == file_directory_3[j]) {
					temp_sizelist[i] = sizelist_3[j];
				} 
			}
		}
		break;
	}

	for (i = 0; i < DIRECTORY_LENGTH; i++) {
		printf("File %d ----------- Size: %d KB\n", temp_directory[i], temp_sizelist[i]);
	}

	printf("\nSort time: %.2f\n", diff_time);

	free(temp_directory);
	free(temp_sizelist);

	return 0;
}

void simple_sort(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

}

void choose_sort(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int min = a[i], ind = i;
		for (j = i + 1; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				ind = j;
			}
		}
		a[ind] = a[i];
		a[i] = min;
	}
}

void insert_sort(int a[], int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j = i - 1, tmp = a[i];
		while (j >= 0 && a[j] > tmp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}

void bubble_sort(int a[], int n){
	int i, j;
	for (i = 0; i < n; i++) { 
		for (j = 0; j < n - i - 1; j++) {
			if (a[j + 1] < a[j]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void merge_sort(int a[], int l, int r) {
	int m;
	if (l + 1 >= r) return;
	m = l + (r - l) / 2;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, m, r);
}

void merge(int a[], int l, int m, int r) {
	int* b;
	b = (int*)malloc((DIRECTORY_LENGTH) * sizeof(int)); //что делать с этим списком
	int it1 = 0, it2 = 0, i;
	while (it1 <= m && it2 < r) {
		if (a[l + it1] < a[m + it2 + 1]) {
			b[it1 + it2] = a[l + it1];
			it1++;
		}
		else {
			b[it1 + it2] = a[m + it2 + 1];
			it2++;
		}
	}
	while (it1 <= m - l) {
		b[it1 + it2] = a[it1 + l];
		it1++;
	}
	while (it2 < r - m) {
		b[it1 + it2] = a[m + it2 + 1];
		it2++;
	}
	for (i = 0; i < it1 + it2; i++) {
		a[l + i] = b[i];
	}
	free(b);
}

void quick_sort(int a[], int n1, int n2) {
	//что сюда писать
}