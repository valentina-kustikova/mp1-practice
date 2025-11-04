#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main() {
	unsigned n, c_b;
	setlocale(LC_ALL, "RU");
	printf("Игра \"Быки и коровы\"\nЗагадайте длину числа от 2 до 5: \n");

	do {
		scanf_s("%u", &n);
		if (n < 2 || n > 5) printf("Введена неправильная длина числа\n");
	} while (n < 2 || n > 5);

	srand(time(NULL));
	c_b = rand() % 9 + 1;//гарантирует, что 1-ая цифра не 0

	for (int i = 1; i < n; i++) {
		int new_c;
		int temp = c_b;
		int dupl_c;

		do {
			dupl_c = 0;
			new_c = rand() % 10;

			temp = c_b;
			while (temp > 0) {
				if (temp % 10 == new_c) {
					dupl_c = 1;
					break;
				}
				temp /= 10;//уничтожаем последнюю цифру-дубликат из общего числа
			}
		} while (dupl_c);//проверяем повторение новой цифры с прошлыми и повторяем, если нашли дубликат цифры

		c_b = c_b * 10 + new_c;
	}


	unsigned corov = 0, buk = 0, d;
	printf_s("Я задумал число длины %u из цифр от 1 до 9 - угадайте его(%u): ", n, c_b);

	do {
		scanf_s("%u", &d);
		int d1, d2, d3, d4, d5;
		int c1, c2, c3, c4, c5;

		if (n == 2) {
			d1 = d / 10; d2 = d % 10;
			c1 = c_b / 10; c2 = c_b % 10;
			d3 = d4 = d5 = c3 = c4 = c5 = -1; // заполнил "мусором" лишние переменные
		}
		else if (n == 3) {
			d1 = d / 100; d2 = (d % 100) / 10; d3 = d % 10;
			c1 = c_b / 100; c2 = (c_b % 100) / 10; c3 = c_b % 10;
			d4 = d5 = c4 = c5 = -1;
		}
		else if (n == 4) {
			d1 = d / 1000; d2 = (d % 1000) / 100; d3 = (d % 100) / 10; d4 = d % 10;
			c1 = c_b / 1000; c2 = (c_b % 1000) / 100; c3 = (c_b % 100) / 10; c4 = c_b % 10;
			d5 = c5 = -1;
		}
		else if (n == 5) {
			d1 = d / 10000; d2 = (d % 10000) / 1000; d3 = (d % 1000) / 100;
			d4 = (d % 100) / 10; d5 = d % 10;
			c1 = c_b / 10000; c2 = (c_b % 10000) / 1000; c3 = (c_b % 1000) / 100;
			c4 = (c_b % 100) / 10; c5 = c_b % 10;
		}

		if (n >= 1 && d1 == c1) buk++;
		if (n >= 2 && d2 == c2) buk++;
		if (n >= 3 && d3 == c3) buk++;
		if (n >= 4 && d4 == c4) buk++;
		if (n >= 5 && d5 == c5) buk++;

		if (n >= 1 && d1 != c1) {
			if (n >= 2 && d1 == c2) corov++;
			if (n >= 3 && d1 == c3) corov++;
			if (n >= 4 && d1 == c4) corov++;
			if (n >= 5 && d1 == c5) corov++;
		}

		if (n >= 2 && d2 != c2) {
			if (n >= 1 && d2 == c1) corov++;
			if (n >= 3 && d2 == c3) corov++;
			if (n >= 4 && d2 == c4) corov++;
			if (n >= 5 && d2 == c5) corov++;
		}

		if (n >= 3 && d3 != c3) {
			if (n >= 1 && d3 == c1) corov++;
			if (n >= 2 && d3 == c2) corov++;
			if (n >= 4 && d3 == c4) corov++;
			if (n >= 5 && d3 == c5) corov++;
		}

		if (n >= 4 && d4 != c4) {
			if (n >= 1 && d4 == c1) corov++;
			if (n >= 2 && d4 == c2) corov++;
			if (n >= 3 && d4 == c3) corov++;
			if (n >= 5 && d4 == c5) corov++;
		}

		if (n >= 5 && d5 != c5) {
			if (n >= 1 && d5 == c1) corov++;
			if (n >= 2 && d5 == c2) corov++;
			if (n >= 3 && d5 == c3) corov++;
			if (n >= 4 && d5 == c4) corov++;
		}

		printf("Угадано коров %u, угадано быков %u\n", corov, buk);
		if (buk == n) break;
		corov = 0;
		buk = 0;
	} while (1);

	return 0;
}