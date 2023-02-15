#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int HiddenNumberMas[5] = {0};
int HiddenNumber = 0;
int count_mas[2];

int check(int x, int y) {
	for (int i = 0; i < y; i++) {
		if (x == HiddenNumberMas[i]) return 1;
	}
	return 0;
}

int check_user_answer(int AnsMas[5], int n) {
	int mas[10] = { 0 };
	for (int i = 0; i < n; i++) {
		int num = AnsMas[i];
		if (mas[num] == 0) mas[num]++;
		else return 0;
	}
	return 1;
}

void random_num(int x) {
	srand((unsigned int)time(NULL));
	HiddenNumberMas[0] = rand() % 9 + 1;
	HiddenNumber = HiddenNumber * 10 + HiddenNumberMas[0];
	for (int i = 1; i < x; i++) {
		int num = rand() % 10;
		while (check(num, x) == 1)
			num = rand() % 10;
		HiddenNumberMas[i] = num;
		HiddenNumber = HiddenNumber * 10 + HiddenNumberMas[i];
	}
}

void counter(int AnsMas[5], int n) {
	int count_cows = 0, count_bulls = 0;
	for (int i = 0; i < n; i++) {
		if (AnsMas[i] != HiddenNumberMas[i]) {
			if (check(AnsMas[i], n) == 1) 
				count_cows += 1;
		}
		else
			count_bulls += 1;
	}
	count_mas[0] = count_bulls;
	count_mas[1] = count_cows;
}

int main() {
	int n, Answer;

	printf("Enter the number of digits of the guessed number (2 to 5)\n");
	do {
		scanf_s("%d", &n);
	} while (n < 2 || n > 5);
	random_num(n);
	printf("%d\n", HiddenNumber); // for tasting
	do {
		int AnswerMas[5] = {0};
		do {
			printf("Reminder! All digits of the hidden number are different\n");
			scanf_s("%d", &Answer);

			int num = Answer;
			for (int i = n - 1; i >= 0; i--) {
				AnswerMas[i] = num % 10;
				num /= 10;
			}
		} while (check_user_answer(AnswerMas, n) == 0);
		counter(AnswerMas, n);
		if (count_mas[0] == n) {
			printf("Numbre guessed");
			return 0;
		}
		printf("Count of bulls: %d\n", count_mas[0]);
		printf("Count of cows: %d\n\n", count_mas[1]);
		count_mas[0] = 0;
		count_mas[1] = 0;
	} while (Answer != HiddenNumber);
	return 0;
}