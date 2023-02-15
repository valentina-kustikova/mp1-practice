#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void first() {
	int n, count = 1, num;

	srand((unsigned int)time(NULL));
	n = rand() % 1000 + 1;

	printf("================================\n");
	printf("Guess the number\n");
	scanf("%d", &num);
	while (num != n) {
		if (num < 1 || num > 1000) {
			printf("The number belongs to the segment [1, 1000]\n");
			scanf("%d", &num);
			continue;
		}
		(num > n) ? printf("Less \n") : printf("More \n");
		scanf("%d", &num);
		count += 1;
	}

	printf("Number guessed \n");
	printf("Attempts are made: %d\n", count);
	printf("================================\n\n");
}

void second() {
	int left = 1, right = 1000, count = 0, mid;
	char sign;

	printf("================================\n");
	printf("Use '<' if hidden number less\n");
	printf("Use '>' if hidden number more\n");
	printf("Use '=' if hidden number equal\n");

	while (left <= right) {
		mid = (left + right) / 2;
		count += 1;
		printf("%d?\n", mid);
		do {
			scanf(" %c", &sign);
		} while (sign != '>' && sign != '<' && sign != '=');
		if (sign == '<') right = mid - 1;
		else if (sign == '>') left = mid + 1;
		else if (sign == '=') {
			printf("Attempts are made: %d\n", count);
			left = right + 1;
		}
	}
	printf("================================\n\n");
}

int main() {
	printf("Game modes: \n");
	printf("\t1. You guess the number guessed by the computer\n");
	printf("\t2. The computer guesses the number you guessed\n");
	printf("Enter '0' to end the game\n\n");
	
	int num;
	do {
		printf("Select game mode: ");
		scanf("%d", &num);
		printf("\n");
		if (num == 1) first();
		if (num == 2) second();
	} while (num != 0);

	return 0;
}