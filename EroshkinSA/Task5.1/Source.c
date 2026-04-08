#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main() {
	system("chcp 1251");
	char method[50], dir[1000] = "";
	int i, k = -1, type = -1, f, cnt = 0, mx = 0;
	int* sz; int* num; char** name; int* temp, * tempnum;
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
	temp = (int*)malloc(k * sizeof(int));
	tempnum = (int*)malloc(k * sizeof(int));
	read(dir, 1, name, sz, num);
	printf("Выберите метод сортировки: classic - Классическая Сортировка\nbubble - Пузырьковая Сортировка\ninsert - Сортировка Вставками\nchoice - Сортировка Выбором\nmerge - Сортировка Слиянием\nquick - Быстрая/Сортировка Хоара\nВведите exit для выхода\n");
	while (1) {
		scanf("%s", method);
		if (strcmp(method, "exit") == 0) break;
		LARGE_INTEGER st, end, freq;
		double t;
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&st);
		f = fsort(method, k, sz, num, temp, tempnum);
		QueryPerformanceCounter(&end);
		t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
		if (f) {
			for (i = 0; i < k; i++) printf("%d) %s -> %d\n", i + 1, name[num[i]], sz[i]);
			printf("Время: %.6f мс\n", t);
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
