#include <stdio.h>
#include "SORT.h"





//Простая сортировка
void sorto(unsigned long long int* a, int maxel) {
	unsigned long long int slide;
	for (int i = 0; i < maxel - 1; i++) {
		for (int j = i + 1; j < maxel; j++) {
			if (a[i] > a[j]) {
				slide = a[i];
				a[i] = a[j];
				a[j] = slide;
			}
		}
	}
}

//Пузырьком
void sortb(int* m, int n) {
	int slide, k;
	while (n > 1) {
		k = 0;
		for (int i = 1; i < n; ++i) {
			if (m[i] > m[i - 1]) {
				slide = m[i];
				m[i] = m[i - 1];
				m[i - 1] = slide;
				k = i;
			}
		}
		n = k;
	}

}

//Быстрая сортировка
void fastsort(unsigned long long  int* a, int size) {

	int i = 0, j = size - 1; //Правый и левый счетчики
	int mid = size / 2;//Опорный элемент, центральный

	//Создаем цикл
	do {

		//Если i-элемент меньше центрального, то пропускаем его
		while (a[i] < a[mid]) {
			i++;
		}
		//Если j-элемент больше центрального, то пропускаем его
		while (a[j] > a[mid]) {
			j--;
		}
		//Обмен + контроль положения i и j
		if (i <= j) {
			unsigned long long int exchange = a[i];
			a[i] = a[j];
			a[j] = exchange;
			i++;
			j--;
		}

	} while (i <= j);

	//Рекурсивная часть функции

	if (i < size) {
		fastsort(&a[i], size - i);
	}
	if (j > 0) {
		fastsort(a, j + 1);
	}
}

//Сортировка вставками
void insert_sort(unsigned long long  int* mas, int LIMIT) {
	for (int i = 1; i < LIMIT; i++) {
		int location = i, tmp;
		while ((mas[location] < mas[location - 1]) && (location > 0)) {
			tmp = mas[location];
			mas[location] = mas[location - 1];
			mas[location - 1] = tmp;
			location--;
		}
	}

}