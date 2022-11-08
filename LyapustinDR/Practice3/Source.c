#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define M 10

void shuffle(int arr[]) {
	int i, temp, index;
	srand((unsigned int)time(NULL));
	for (i = M - 1; i > 0; i--) {
		index = rand() % (i + 1);
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

int numFromArray(int arr[]) {
	int i = 0, num = 0, pow = 1;
	while (arr[i] != -1) {
		num += pow * arr[i];
		pow *= 10;
		i++;
	}
	return num;
}

int getLength() {
	int length;
	do {
		printf("Enter number length (2-5): ");
		scanf("%d", &length);
	} while (length < 2 || length > 5);
	return length;
}

int getRandomNum(int length, int numArr[]) {
	int nums[M] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int i = 0, n = 0;
	shuffle(nums);
	if (nums[0] == 0) i = 1;
	while (n < length) {
		numArr[n] = nums[i];
		n++;
		i++;
	}
	return numFromArray(numArr);
}

void makeAttempt(int arr[], int num) {
	int cows = 0, bulls = 0, i = 0, target;
	while (num > 0) {
		target = num % 10;
		if (arr[i] == target) bulls++;
		else if (find(arr, target) != -1) cows++;
		num /= 10;
		i++;
	}
	printf(" Bulls: %d\n Cows: %d\n", bulls, cows);
}

int find(int arr[], int target) {
	int i;
	for (i = 0; i < N; i++) {
		if (arr[i] == target) return i;
	}
	return -1;
}

int main() {
	int length, num, answer, attempts = 0;
	int numArr[N] = { -1, -1, -1, -1, -1, -1 };

	length = getLength();
	num = getRandomNum(length, numArr);

	do {
		printf("Guess number: ");
		scanf("%d", &answer);
		makeAttempt(numArr, answer);
		attempts++;
	} while (answer != num);
	printf("Number is: %d\nAttempts made: %d", num, attempts);

	return 0;
}