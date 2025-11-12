#include <stdio.h>
#include <locale.h>
#include <string.h>

#include <stdlib.h>
#include <time.h>


int main() {
	int n;
	srand(time(NULL));
	setlocale(LC_ALL, "");

	printf("¬ведите длину числа от 2 до 5: ");
	scanf_s("%d", &n);

	if (n < 2 || n>5) {
		printf("¬ведите длину числа от 2 до 5: ");
		return 0;
	}
	//компьютер загадывает число 
	int number[5];
	int used[10] = { 0 };
	number[0] = rand() % 9 + 1;
	used[number[0]] = 1;

	for (int i = 1; i < n; i++) {
		int d;
		do {
			d = rand() % 10;
		} while (used[d]);

		number[i] = d;
		used[d] = 1;
	}
	//игрок откадывает

	int attempts = 0;
	char guess[10];

	while (1) {
		printf("¬ведите загаданное число: ");
		scanf_s("%s", guess, (unsigned)_countof(guess));
		attempts++;

		if (strlen(guess) != n) {
			printf("ошибка");
			continue;
		}
		//счет быков и коров 

		int bulls = 0;
		int cows = 0;
		for (int i = 0; i < n; i++) {
			int g = guess[i] - '0';
			if (g == number[i]) {
				bulls++;
			}
			else {
				for (int j = 0; j < n; j++) {
					if (g == number[j]) {
						cows++;
						break;
					}
				}
			}
		}
		if (bulls == n) {
			printf("вы угадали за %d попыток\n", attempts);
			break;
		}
		else {
			printf("bulls: %d, cows: %d\n", bulls, cows);
		}
	}
	return 0;
}