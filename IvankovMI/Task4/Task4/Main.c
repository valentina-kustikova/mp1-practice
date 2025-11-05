#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <string.h>

int unique(int a[5], int n, int i);
void get_int_arr(int a[5],int n);
int main() {
	int n, sl[5] = {-1}, mysl[5] = {0}, i, j;  //на вс€кий случай инициализирую массивы, пока не знаю, зачем

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	printf("¬ведите длину загадываемого числа (2, 3, 4 или 5)\n");
	scanf_s("%d", &n);
	sl[0] = rand() % 10;
	for (i = 1; i < n; i++) {
		while (!unique(sl, n, i))               //(sl[i] == sl[i - 1]) || (sl[i] == sl[abs(i - 2)])     (for (j = i; j > 0; j--) sl[i] == sl[j])
			sl[i] = rand() % 10;
	}
	printf("\nOk'эй, € загадал число из %d цифр. ¬водите свою отгадку, \nа € отвечу, сколько в ней коров (цифра есть, но не на своем месте) \nи быков (цифра и еЄ положение угаданы верно).\n", n);
	get_int_arr(mysl, n);
}

int unique(int a[5], int n, int i) {
	//ф-€ провер€ет уникальность i-того элемента в срезе массива от 0 до i
	int j = 0;
	for (; j < i; j++)
		if (a[j] == a[i])
			return 0;
	return 1;
}

void get_int_arr(int a[5], int n); {
	char inp[100];
	fscanf_s("%s", inp);
	if ((strlen(inp) != n) || (strlen(inp) > n))
		printf("¬ведите число от ")
}

int arr_is_digit(char a[100]) {

}




void get_int_arr1(int a[5], int n); {
	char inp[100];
	fscanf_s("%s", inp);
	if ((strlen(inp) < 2) || (strlen(inp) > n))
		printf("¬ведите число от ")
}