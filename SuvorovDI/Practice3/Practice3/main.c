#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int an[5] = { -1, -1, -1, -1, -1 }, n = 0, len, i, gN, cDi = 0, endOfGame = 1;
	srand(time(NULL));

	printf("Let's play in Bull-n-cow game!\nChoose length of number (from 2 to 5) [2, 5]:\n");

	// ask the user the length of number
	do {
		scanf_s("%d", &len);
		if (len < 2 || len >5) {
			printf("Your choice is incorrect! Try again choose length only in [2, 5]\n");
		}
	} while (len < 2 || len >5);


	// generation random number
	i = 0;
	while (i < len) {
		int newN, flag = 1, j;
		newN = 1 + rand() % 9; // first digit can't be 0

		for (j = 0; j < len; j++) { // check that there are no repeat of digits
			if (an[j] == newN)
				flag = 0;
		}

		if (flag) { // if everything is OK -- save digit
			an[i] = newN;
			i++;
		}
	}

	printf("I choose some number with length %d\nTry to guess:\n", len);

	// основной цикл игры
	while (endOfGame) {
		int c_Bull = 0, c_Cow = 0, copy, cDi, gNarr[5], i, j, flag = 1;

		do {
			int c_of_dig[10] = { 0 }, i;
			cDi = 0;
			scanf_s("%d", &gN);
			copy = gN;
			while (copy > 0) {
				c_of_dig[copy % 10] += 1; // accumulating count of all digits
				cDi++;
				copy /= 10;
			}

			for (i = 0; i < 10; i++) {
				if (c_of_dig[i] > 1) {
					flag = 0;
				}
			}

			if (!flag) {
				printf("there are some repeating digits in your number! \n");
			}

			if (cDi != len) {
				printf("I have chosen some number, which length is  %d!!! You have entered number with some other length!\n", len);
			}

		} while (cDi != len || !flag);

		copy = gN;
		for (i = len - 1; i >= 0; i--) {
			gNarr[i] = copy % 10;
			copy /= 10;
		}

		//подсчёт коров
		for (i = 0; i < len; i++) {
			for (j = 0; j < len; j++) {
				if (gNarr[j] == an[i] && i != j) {
					c_Cow++;
				}
			}
		}

		//подсчёт быков:
		for (i = 0; i < len; i++) {
			if (an[i] == gNarr[i]) {
				c_Bull++;
			};
		}

		if (c_Bull == len) {
			endOfGame = 0;
			printf("You're WINNER! Congratulation!");
			break;
		}
		printf("Count of Bull: %d\nCount of Cow: %d\n", c_Bull, c_Cow);

	}

	return 0;
}