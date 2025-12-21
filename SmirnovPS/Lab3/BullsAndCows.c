#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
int main() {
	srand((unsigned int)time(0));
	int i, j, n, flag, check, bulls, cows, numguess;
	int guess[M], number[M];

	do {
		printf("Enter length (2 - 5) of the number:\n");
		scanf_s("%d", &n);
	} while (n < 2 || n > 5);


	do {
		flag = 1;

		for (i = 0; i < n; i++) {
			number[i] = rand() % 10;
		}


		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++)
				if (number[i] == number[j])
					flag = 0;
		}

		if (number[0] == 0) {
			flag = 0;
		}


	} while (flag == 0);


	bulls = 0;


	while (bulls != n) {
		bulls = 0;
		cows = 0;

		printf("Enter your guess:\n");
		scanf_s("%d", &numguess);

		for (i = n - 1; i >= 0; i--) {
			guess[i] = numguess % 10;
			numguess /= 10;
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (number[i] == guess[j])
					if (i == j)
						bulls++;
					else
						cows++;
			}
		}

		printf("Amount of bulls: %d\n", bulls);
		printf("Amount of cows: %d\n", cows);
	}

	printf("You've guessed the number!");
	return 0;
}