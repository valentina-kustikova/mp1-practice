#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int mode;
	printf("Welcome to the game 'Guess the number' \n");
	printf("Select mode of the game ");
	srand(time(0));

	do {
		scanf_s("%d", &mode);
	} while (mode < 1 || mode > 2);
	if (mode == 1) {
		int k1 = 1, x, ans1;
		x = rand() % 1000 + 1;
		scanf_s("%d", &ans1);
		while (ans1) {
			if (ans1 > x) {
				printf("The number is less\n");
				scanf_s("%d", &ans1);
				k1++;
			}
			if (ans1 < x) {
				printf("The number is greater\n");
				scanf_s("%d", &ans1);
				k1++;
			}
			if (ans1 == x) {
				printf("You have won the number is correctly guessed\n");
				printf("Number of attempts = %d\n", k1);
				printf("The guessed number = %d ", ans1);
				break;
			}
		}
		return 0;
	}
	if (mode == 2) {
		int k2 = 1, num;
		char y;
		do {
			printf("Select the number ");
			scanf_s("%d", &num);
			y = getchar();
		} while (num < 1 || num > 1000);
		int ans2;
		ans2 = rand() % 1000 + 1;
		int min = 1, max = 1000;
		while (num) {
			printf("%d\n", ans2);
			char hunch;
			scanf_s("%c", &hunch);
			y = getchar();
			switch (hunch) {
			case '>':
				if (ans2 >= min) {
					min = ans2;
					ans2 = rand() % (max - min + 1) + min;
					k2++;
				}
				break;
			case '<':
				if (ans2 <= max) {
					max = ans2;
					ans2 = rand() % (max - min + 1) + min;
					k2++;
				}
				break;
			case '=':
				printf("The number is guessed\n");
				printf("Number of attempts = %d\n", k2);
				printf("The guessed number = %d ", ans2);


				return 0;

			default:
				printf("Incorrect data entry");
			}
		}
	}
	return 0;
}