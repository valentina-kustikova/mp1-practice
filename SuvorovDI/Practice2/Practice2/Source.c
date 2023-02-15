#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	char mode;
	int ch_num;
	srand((unsigned int)time(NULL));

	printf("Hello, let's play a guessing game! Please, choose a mode: 1 or 2\n");

	do {
		scanf_s("%c", &mode, 1);
	} while (mode != '1' && mode != '2');

	if (mode == '1') { // programm choose some number and user try to guess it
		int c = 0;

		int gnum;
		ch_num = rand() % 100;
		printf("I made a choice in [0, 100]! Please, guess!\n");

		while (1) {
			do {
				scanf_s("%d", &gnum);
			} while (gnum > 100 || gnum < 0);

			if (gnum < ch_num) {
				printf("No, my number is greater, Try again\n");
				c++;
			}
			else if (gnum > ch_num) {
				printf("No, my number is less, Try again\n");
				c++;
			}
			else {
				printf("YOU WIN!\n");
				printf("You have made %d attempts\n", c + 1);
				break;
			}
		}
		printf("The End");
	}
	else {
		int l = 0, r = 1000, try_num, c = 0;;
		printf("Choose some number in [0, 1000], I try to guess how faster how I can!\n ");

		while (1) {
			char ans;
			try_num = (l + r) / 2;

			if (r - l == 2) {
				printf("YAY, I'm a WINNER\nBecause your number is %d!\nI have made %d attemps\n", try_num, c);
				break;
			}

			printf("Your number is %d ?\n'y' - if this is your num\n'g' - if your num is greater\n'l' - if your num is less:\n", try_num);
			do {
				scanf_s("%c", &ans, 1);
			} while (ans != 'g' && ans != 'l' && ans != 'y');

			if (ans == 'g') {
				l = try_num;
				c++;
			}
			else if (ans == 'l') {
				r = try_num;
				c++;
			}
			else if (ans == 'y') {
				c++;
				printf("YAY, I'm a WINNER\nI have made %d attemps\n", c);
				break;
			}
		}
		printf("The End");
	}
	return 0;
}