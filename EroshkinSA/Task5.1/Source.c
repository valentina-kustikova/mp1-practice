#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


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
		if(sz[i] != sz[j]) swap(&sz[i], &num[i], &sz[j], &num[j]);
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

int fcount(char dir[], int* pmx) {
	int k = 0;
	WIN32_FIND_DATA data;
	HANDLE hFind = FindFirstFileA(dir, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes != 32) continue;
			if (strlen(data.cFileName) > *pmx) *pmx = strlen(data.cFileName);
			k++;
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
	else {
		printf("Несуществующая директория!\n");
		return -1;
	}
	return k;
}

void read(char dir[], char flag, char** name, int* sz, int* num) {
	WIN32_FIND_DATAA data;
	HANDLE hFind = FindFirstFileA(dir, &data);
	int i = 0;
	hFind = FindFirstFileA(dir, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes != 32) continue;
			if(flag) printf("Прочитан файл %s размером %d байтов\n", data.cFileName, data.nFileSizeLow);
			strcpy(name[i], data.cFileName);
			sz[i] = data.nFileSizeLow;
			num[i] = i;
			i++;
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
}


char fsort(char method[], int k, int* sz, int* num) {
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
		int* temp = (int*)malloc(sizeof(int) * k);
		int* tempnum = (int*)malloc(sizeof(int) * k);
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

int main() {
	system("chcp 1251");
	char method[50], dir[1000] = "";
	int i, k = -1, type = -1, f, cnt = 0, mx = 0;
	int* sz; int* num; char** name;
	printf("Введите путь до директории:\n");
	while (k == -1) {
		scanf("%s", dir);
		strcat(dir, "\\*\0");
		k = fcount(dir, &mx);
	}
	sz = (int*)malloc(k * sizeof(int));
	num = (int*)malloc(k * sizeof(int));
	name = (char**)malloc(k * sizeof(char*));
	for (int i = 0; i < k; i++) {
		name[i] = (char*)malloc((mx + 5) * sizeof(char));
	}
	read(dir, 1, name, sz, num);
	printf("Выберите метод сортировки: classic - Классическая Сортировка\nbubble - Пузырьковая Сортировка\ninsert - Сортировка Вставками\nchoice - Сортировка Выбором\nmerge - Сортировка Слиянием\nquick - Быстрая/Сортировка Хоара\nВведите exit для выхода\n");
	while (1) {
		scanf("%s", method);
		if (strcmp(method, "exit") == 0) break;
		LARGE_INTEGER st, end, freq;
		double t;
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&st);
		f = fsort(method, k, sz, num);
		QueryPerformanceCounter(&end);
		t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
		if (f) {
			for (i = 0; i < k; i++) printf("%d) %s -> %d\n", i + 1, name[num[i]], sz[i]);
			printf("Время: %.3f мс\n", t);
		}
		//for (i = 0; i < k; i++) num[i] = i;
		read(dir, 0, name, sz, num); // Обратная перестановка массива
	}
	free(sz);
	free(num);
	for (i = 0; i < k; i++) {
		free(name[i]);
	}
	free(name);
	return 0;
}
