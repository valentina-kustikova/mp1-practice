#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
int main() {
	srand((unsigned int)time(0));
	int i, j, number = 0, n, flag = 0, check, bulls = 0, cows = 0, guess, numcheck, guesscheck;
	int a[M];
	printf("Enter length of the number:\n");
	do {
		scanf_s("%d", &n);
	} while (n < 2 || n > 5);

	do {
		number = 0;
		for (i = 0; i < n; i++) {
			number = number * 10 + rand() % 10;
		}


		for (i = 0; i < M; i++) {
			a[i] = 0;
		}

		flag = 1;
		check = number;


		while (check > 0) {
			a[check % 10]++;
			check /= 10;
		}

		for (i = 0; i < M; i++) {
			if (a[i] > 1) {
				flag = 0;
			}
		}

	} while (flag == 0);


	while (bulls != 5) {
		bulls = 0;
		cows = 0;
		printf("Enter your guess:\n");
		scanf_s("%d", &guess);
		guesscheck = guess;
		for (i = 0; i < n; i++) {
			numcheck = number;
			for (j = 0; j < n; j++) {
				if (numcheck % 10 == guesscheck % 10) {
					if (i == j)
						bulls += 1;
					else
						cows += 1;
				}
				numcheck /= 10;
			}
			guesscheck /= 10;
		}
		printf("Amount of bulls: %d\n", bulls);
		printf("Amount of cows: %d\n", cows);
	}
	printf("You've guessed the number!");
	return 0;
}