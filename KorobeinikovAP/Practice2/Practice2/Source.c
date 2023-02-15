#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int X_n = 1 + rand() % (1000), user_n;
	int min = 1, max = 1000, attempts = 0;
	char mode, ans;
	printf("Choose mode 1 or 2 ");
	scanf("%c", &mode);
	switch (mode) {
	case '1': 
		printf("The program made a number from 1 to 1000. Try to guess it : \n");
		do {
			printf("Input number from 1 to 1000 ");
			scanf ("%d", &user_n);
			while ((user_n > 1000) || (user_n < 1)) {
				printf("Incorrect data. Try again. ");
				scanf ("%d", &user_n); 
			}
			if (user_n == X_n)
				printf("Congratulations, you guessed the number in %d attempts!", attempts);
			else if (user_n < X_n) {
				printf("The hidden number is greater than your number. Try again: ");
				attempts++;
			}
			else {
				printf("The hidden number is less than your number. Try again: ");
				attempts++;
			}
		} while (user_n != X_n);
		break;
	case '2':
		printf("Enter a number from 1 to 1000. The program will try to guess it: ");
		do {
			scanf ("%d", &user_n);
			if (user_n > 1000 || user_n < 1) {
				printf("Incorrect data. Try again: ");
			}
		} while (user_n > 1000 || user_n < 1);
		while (user_n != X_n) {
			X_n = min + rand() % (max - min + 1);
			printf("Is this the number %d ? ", X_n);
			scanf ("%c", &ans);
			if (scanf("%c", &ans) != 1) {  // != 1 means scanf failed
				while ((ans = getchar()) != '\n' && ans != EOF) {
					;
				}
			}
			attempts++;
			switch (ans) {
			case '=':
				printf("The program guessed the number %d in %d attempts!", X_n, attempts);
				break;
			case '>':
				min = 1 + X_n;
				break;
			case '<':
				max = X_n - 1;
				break;
			default: 
				printf("Incorrect answer. Try again. Input '=' or '>' or '<' \n");			
			}		
		}
		break;
	default: printf("Incorrect data, try again");
	}
	return 0;
}