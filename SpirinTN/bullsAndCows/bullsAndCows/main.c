#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
	printf("(TEST) A number has been guessed: %d\n", hiddenNumber);
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

int isIdenticalDigits(int userNumber);
int counterBulls(int userNumber, int hiddenNumber, int lengthNumber);
int counterCows(int userNumber, int hiddenNumber, int lengthNumber);

void tryingGuessNumber(int hiddenNumber, int lengthNumber) {
	int userNumber = 0, rangeMultiplier = (int) pow(10, lengthNumber - 1), i;

	while (userNumber != hiddenNumber) {
		printf("Input number (all the digits are different, length number - %d digits): ", lengthNumber);
		scanf_s("%d", &userNumber);
		while (userNumber < rangeMultiplier || userNumber >= rangeMultiplier * 10 || isIdenticalDigits(userNumber)) {
			printf("Incorrect number. Input number (all the digits are different, length number - %d digits): ", lengthNumber);
			scanf_s("%d", &userNumber);
		}
		printf("Number of bulls: %d\n", counterBulls(userNumber, hiddenNumber, lengthNumber));
		printf("Number of cows: %d\n\n", counterCows(userNumber, hiddenNumber, lengthNumber));
	}
	printf("Congratulations! You guessed the number.\n");
}

int isIdenticalDigits(int userNumber) {
	int digits[10] = { 0 };
	while (userNumber > 0) {
		int currentDigit = userNumber % 10;
		if (digits[currentDigit] == 1) {
			return 1;
		}
		digits[currentDigit]++;
		userNumber /= 10;
	}
	return 0;
}

int counterBulls(int userNumber, int hiddenNumber, int lengthNumber) {
	int count = 0, i;
	for (i = 0; i < lengthNumber; i++) {
		if (hiddenNumber / (int)pow(10, i) % 10 == userNumber / (int)pow(10, i) % 10) {
			count++;
		}
	}
	return count;
}

int counterCows(int userNumber, int hiddenNumber, int lengthNumber) {
	int count = 0, i, j;
	for (i = 0; i < lengthNumber; i++) {
		for (j = 0; j < lengthNumber; j++) {
			if (j == i) {
				continue;
			}
			if (hiddenNumber / (int)pow(10, i) % 10 == userNumber / (int)pow(10, j) % 10) {
				count++;
			}
		}
	}
	return count;
}