#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define eof 27

void main() {
	start:
	srand(time(NULL));
	int i, n, k, cows = 0, bulls = 0, try = 1, secret[N], answer[N];

	printf("\t Welcome to the game <Bulls and Cows>\n\tEnter the number of digits (you should enter number from 2 to 5)\n");
	do scanf_s("%d", &n); while ((n < 2) || (n > 5));

	for (i = 0; i < n; i++) {
		secret[i] = rand() % 9;
ProgrammMistake:
		for (k = 0; k < i; k++) {
			if (secret[i] == secret[k]) 
				goto ProgrammMistake;
			
		}
	}

UserMistake:	
	printf("\n\n\nEnter the expected number (one digit at a time, numbers cannot be repeated)\n");
	for (i = 0; i < n; i++) {
			scanf_s("%d", &answer[i]); 
			while ((answer[i] < 0) || (answer[i] > 9)) {
				printf("\n>>> You must enter number from 0 to 9! <<<\n");
				scanf_s("%d", &answer[i]);
			}
		for (k = 0; k < i; k++) {
			if (answer[k] == answer[i]) {
				printf("wrong enter, try again");
				goto UserMistake;
			}
		}
	}

	printf("You guessed that number\n");
	for (i = 0; i < n; i++) printf("%d\t", answer[i]);
	printf("\n");

	for (i = 0; i < n; i++) {
		for (k = 0; k < n; k++) {
			if ((secret[i] == answer[k]) && (secret[i] != answer[i])) cows++;			
		}
	}
	printf("Cows:%d\t", cows);

	for (i = 0; i < n; i++) {
		if (secret[i] == answer[i]) bulls++;	
	}
	printf("\nBulls:%d\t", bulls);

	if (bulls == n) printf("\n\nYou win!\nHow many attempts have there been? - %d\n", try);
	else {
		bulls = 0;
		cows = 0;
		try++;
		goto UserMistake;
	}

	system("pause");
}