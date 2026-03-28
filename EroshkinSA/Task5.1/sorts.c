#include "sorts.h"
#include <stdio.h>

void swap(int* a, int* ai, int* b, int* bi) {
	int tmp = *b, tmpi = *bi;
	*b = *a;
	*bi = *ai;
	*a = tmp;
	*ai = tmpi;
}

void BubbleSort(int n, int* sz, int* num) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (sz[j] > sz[j + 1]) swap(&sz[j], &num[j], &sz[j + 1], &num[j + 1]);
		}
	}
}

void ClassicSort(int n, int* sz, int* num) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (sz[j] < sz[i]) swap(&sz[i], &num[i], &sz[j], &num[j]);
		}
	}
}

void ChoiceSort(int n, int* sz, int* num) {
	int i, j;
	for (i = 0; i < n; i++) {
		int min = sz[num[i]], idx = i;
		for (j = i + 1; j < n; j++) {
			if (sz[num[j]] < min) {
				min = sz[num[j]];
				idx = j;
			}
		}
		swap(&sz[i], &num[i], &sz[idx], &num[idx]);
	}
}

void InsertSort(int n, int* sz, int* num) {
	int i;
	for (i = 0; i < n; i++) {
		int j = i - 1, tmp = sz[num[i]];
		while (j >= 0 && sz[num[j]] > tmp) {
			sz[j + 1] = sz[j];
			num[j + 1] = num[j];
			j--;
		}
		sz[j + 1] = tmp;
		num[j + 1] = i;
	}
}

void Merge(int l, int c, int r, int* sz, int* num, int* temp, int* tempnum) {
	int i = l, j = c + 1, k = 0;
	while (i <= c && j <= r) {
		if (sz[i] <= sz[j]) {
			temp[k] = sz[i];
			tempnum[k] = num[i];
			k++; i++;
		}
		else {
			temp[k] = sz[j];
			tempnum[k] = num[j];
			k++; j++;
		}
	}
	while (i <= c) {
		temp[k] = sz[i];
		tempnum[k] = num[i];
		k++; i++;
	}
	while (j <= r) {
		temp[k] = sz[j];
		tempnum[k] = num[j];
		k++; j++;
	}
	for (i = 0; i < r - l + 1; i++) {
		sz[l + i] = temp[i];
		num[l + i] = tempnum[i];
	}
}


void MergeSort(int l, int r, int* sz, int* num, int* temp, int* tempnum) {
	if (l + 1 > r) return;
	int c = l + (r - l) / 2;
	MergeSort(l, c, sz, num, temp, tempnum);
	MergeSort(c + 1, r, sz, num, temp, tempnum);
	Merge(l, c, r, sz, num, temp, tempnum);
}

int parse(int* sz, int* num, int l, int r) {
	int pivot = sz[l + (r - l) / 2], i = l, j = r - 1;
	while (i <= j) {
		while (sz[i] < pivot) i++;
		while (sz[j] > pivot) j--;
		if (i > j) break;
		if (sz[i] != sz[j]) swap(&sz[i], &num[i], &sz[j], &num[j]);
		i++; j--;
	}
	return j + 1;
}

void QuickSort(int l, int r, int* sz, int* num) {
	if (r - l <= 1) return;
	int c = parse(sz, num, l, r);
	QuickSort(l, c, sz, num);
	QuickSort(c, r, sz, num);
}

char fsort(char method[], int k, int* sz, int* num, int* temp, int* tempnum) {
	if (strcmp(method, "classic") == 0) {
		ClassicSort(k, sz, num); return 1;
	}
	if (strcmp(method, "insert") == 0) {
		InsertSort(k, sz, num); return 1;
	}
	if (strcmp(method, "choice") == 0) {
		ChoiceSort(k, sz, num); return 1;
	}
	if (strcmp(method, "bubble") == 0) {
		BubbleSort(k, sz, num); return 1;
	}
	if (strcmp(method, "merge") == 0) {
		MergeSort(0, k - 1, sz, num, temp, tempnum); return 1;
		free(temp);
		free(tempnum);
	}
	if (strcmp(method, "quick") == 0) {
		QuickSort(0, k, sz, num); return 1;
	}
	printf("Недопустимый метод сортировки\n");
	return 0;
}