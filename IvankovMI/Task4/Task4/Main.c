#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <string.h>

int unique(int a[5], int n, int i);
void get_int_arr_lenth_n(int a[5],int n);
int main() {
	int n, sl[5] = {-1}, mysl[5] = {0}, i, j, cows = 0, bulls = 0;  //на всякий случай инициализирую массивы, пока не знаю, зачем

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	printf("Введите длину загадываемого числа (2, 3, 4 или 5)\n");
	scanf_s("%d", &n);
	sl[0] = rand() % 10;
	for (i = 1; i < n; i++) {
		while (! unique(sl, n, i))               //(sl[i] == sl[i - 1]) || (sl[i] == sl[abs(i - 2)])     (for (j = i; j > 0; j--) sl[i] == sl[j])
			sl[i] = rand() % 10;
	}
	
	printf("\nOk'эй, я загадал число из %d цифр. Вводите свою отгадку, \nа я отвечу, сколько в ней коров (цифра есть, но не на своем месте) \nи быков (цифра и её положение угаданы верно).\n", n);
	get_int_arr_lenth_n(mysl, n);
	for (i = 0; i < n; i++) {
		int t = mysl[i];

	}
}

int unique(int a[5], int n, int i) {
	//ф-я проверяет уникальность i-того элемента в срезе массива от 0 до i
	int j = 0;
	for (; j < i; j++)
		if (a[j] == a[i])
			return 0;
	return 1;
}

void get_int_arr_lenth_n(int a[5], int n) {
	char inp[100];
	int i = 0, l;
	fscanf_s("%s", inp);
	while ((l = (strlen(inp)) != n) || (!arr_is_digit(inp, l))) {
		printf("Введите ЧИСЛО из %d цифр\n", n);
		fscanf_s("%s", inp);
	}
	for (; i < n; i++)
		a[i] = ((int)(inp[i]));
}

int arr_is_digit(char a[100], int n) {
	char digits[10] = "0123456789";
	int i = 0, j = 0, ok;
	for (; i < n; i++) {
		ok = 0;
		for (; j < 10; j++)
			if (a[i] == digits[j])
				ok = 1;
		if (ok == 0)
			return 0;
	}
	return 1;
}




//Просто полезные функции, которые пригодятся позже

void get_str_didg_arr_lenth_n(int a[5], int n) {
	char inp[100];
	int i = 0, l;
	fscanf_s("%s", inp);
	while ((l = (strlen(inp)) != n) || (!arr_is_digit(inp, l))) {
		printf("Введите ЧИСЛО из %d цифр\n", n);
		fscanf_s("%s", inp);
	}
	for (; i < n; i++)
		a[i] = ((int)(inp[i]));
}

void get_int_arr_in_range(int a[5], int n) {
	char inp[100];
	fscanf_s("%s", inp);
	if ((strlen(inp) < 2) || (strlen(inp) > n))
		printf("Введите число от ");
}