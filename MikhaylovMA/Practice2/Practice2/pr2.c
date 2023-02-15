#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char mode;
	do {
		printf("Choose game mode: \n1 - you guess number\n2 - you choose number \n");
		scanf("%c", &mode);
	} while (mode != '1' && mode != '2');

	if (mode == '1') {
		short try_count = 1, answer, cur_ans;
		srand((unsigned int)time(NULL));
		answer = rand() % 1000;

		printf("I chose the number. Try to guess it! (type '1001' for answer) \n");

		while (1) {
			do {
				printf("What's your guess? \n");
				scanf("%hd", &cur_ans);
			} while (cur_ans < 0 || cur_ans > 1001);

			if (cur_ans == 1001) {
				printf("%hd \n", answer);
			}
			else if (cur_ans < answer) {
				printf("This number < than my number. Try again. (Tries: %hd) \n", try_count);
				try_count++;
			}
			else if (cur_ans > answer) {
				printf("This number > than my number. Try again. (Tries: %hd) \n", try_count);
				try_count++;
			}
			else if (cur_ans == answer) {
				printf("You're right! You've guessed my number in %hd tries. \n", try_count);
				return 0;
			}
		}

	}
	if (mode == '2') {
		short try_count = 1, cur_ans = 500, step = 250;
		char reply;

		printf("I'm going to guess your number. \n");

		while (1) {
			do {
				printf("Is it %hd? \n", cur_ans);
				scanf("%c", &reply);
			} while (reply != '<' && reply != '=' && reply != '>');

			if (reply == '=') {
				printf("Woohoo! I've guessed your number in %hd tries \n", try_count);
				return 0;
			}
			else if (reply == '<') {
				cur_ans += step;
			}
			else if (reply == '>') {
				cur_ans -= step;
			}
			step = (step + 1) / 2;
			if (step == 0) step = 1;
			try_count++;
		}
	}
	return 0;
}