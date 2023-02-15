#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int isUnique(int number, int n) {
	int tmp[10], i = 0;
	while (number > 0) {
		tmp[i] = number % 10;
		number /= 10;
		i++;
	}
	for (i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (tmp[i] == tmp[j]) {
				return 1;
			}
		}
	}
	return 0;
}

int len(int number) {
	int l = 0;
	while (number > 0) {
		number /= 10;
		l++;
	}
	return l;
}

int main() {
	int a[] = { 0,1,2,3,4,5,6,7,8,9 }, r, n, i = 0, t, sup = 9;
	int mass[] = { 0,0,0,0,0,0,0 }, bulls = 0, cows = 0, userInput, userMass[] = { 0,0,0,0,0 };
	srand(time(NULL));

	do {
		printf("Enter the length of the number from 2 to 5\n");
		if (scanf("%d", &n) != 1) {
			printf("Enter only numbers...");
			return 1;
		}
	} while (n < 2 || n > 5);

	for (i; i < n; i++) {
		r = rand() % (sup + 1);
		t = rand() % 10;
		mass[i] = a[r];
		if (mass[0] == 0) {
			while (mass[0] == 0) {
				mass[0] = t;
			}
			for (int e = t; e < 10; ++e) {
				a[e] = a[e + 1];
			}
			--sup;
			continue;
		}
		for (int e = r; e < 10; ++e) {
			a[e] = a[e + 1];
		}
		--sup;
	}
	for (int g = 0; g < n; g++) {
		printf("%d", mass[g]);
	}
	printf(" ***A computer-generated number***\n");

	while (bulls != n) {
		bulls = cows = 0;

		do {
			printf("Enter your guess\n");
			if (scanf("%d", &userInput) != 1) {
				printf("Enter only numbers...");
				return 1;
			}
		} while ((isUnique(userInput, n) != 0) || len(userInput) != n);

		for (i = 1; n - i >= 0; i++) {
			userMass[n - i] = userInput % 10;
			userInput /= 10;
		}
		for (i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((userMass[i] == mass[j]) && (i != j)) {
					cows++;
				}
			}
		}
		for (i = 0; i < n; i++) {
			if (userMass[i] == mass[i]) {
				bulls++;
			}
		}
		printf("Cows: %d\n", cows);
		printf("Bulls: %d\n", bulls);
	}
	printf("Congratulations, you win!");
	return 0;
}