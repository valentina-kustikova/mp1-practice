#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG

#define FRAME "\
|------------------------|\n\
|     Bulls and cows     |\n\
|------------------------|\n\n"

int setLengthNumber();
int generationNumber(int lengthNumber);
void tryingGuessNumber(int hiddenNumber, int lengthNumber);

int main() {
	srand((unsigned int)time(0));
	int hiddenNumber, lengthNumber;
	printf(FRAME);
	lengthNumber = setLengthNumber();
	hiddenNumber = generationNumber(lengthNumber);
#ifdef DEBUG
	printf("(TEST) A number has been guessed: %d", hiddenNumber);
#endif

	tryingGuessNumber(hiddenNumber, lengthNumber);
	return 0;
}

int setLengthNumber() {
	int length;
	printf("Input length Number (from 2 to 5): ");
	scanf_s("%d", &length);
	while (length > 5 || length < 2) {
		printf("Incorrect length. Input length Number (from 2 to 5): ");
		scanf_s("%d", &length);
	}
	return length;
}

int generationNumber(int lengthNumber) {
	int i, resultNumber;
	int digits[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int randPos = rand() % 9;
	resultNumber = digits[randPos];
	digits[randPos] = 0;
	for (i = 1; i < lengthNumber; i++) {
		int randPos = rand() % (10 - i);
		resultNumber = resultNumber * 10 + digits[randPos];
		digits[randPos] = digits[9 - i];
	}
	return resultNumber;
}

int counterBulls(int userNumber, int hiddenNumber, int lengthNumber);
int counterCows(int userNumber, int hiddenNumber, int lengthNumber);

void tryingGuessNumber(int hiddenNumber, int lengthNumber) {
	int userNumber = 0, rangeMultiplier = 1, i;
	for (i = 1; i < lengthNumber; i++) {
		rangeMultiplier *= 10;
	}
	while (userNumber != hiddenNumber) {
		printf("Input number (length number - %d digits): ");
		scanf_s("%d", &userNumber);
		while (userNumber < rangeMultiplier || userNumber >= rangeMultiplier * 10) {
			printf("Incorrect number. Input number (length number - %d digits): ");
			scanf_s("%d", &userNumber);
		}
		printf("Number of bulls: %d\n", counterBulls(userNumber, hiddenNumber, lengthNumber));
		printf("Number of cows: %d\n\n", counterCows(userNumber, hiddenNumber, lengthNumber));
	}
	printf("Congratulations! You guessed the number.");
}

int counterBulls(int userNumber, int hiddenNumber, int lengthNumber) {
	int count = 0, i;
	for (i = 0; i < lengthNumber; i++) {
		if (userNumber % 10 == hiddenNumber % 10) {
			count++;
		}
		userNumber /= 10;
		hiddenNumber /= 10;
	}
	return count;
}

int counterCows(int userNumber, int hiddenNumber, int lengthNumber) {
	int count = 0, i;

	return count;
}
