#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main() {
	int dlina, bulls, cows, pop = 0;
	int i = 1, j = 0, k = 0, m = 0;
	srand((unsigned int)time(0));

	printf("Vvedi dlinu ot 2 do 5\n");
	scanf_s("%d", &dlina);

	int a[N] = { 0 };
	int used[10] = { 0 };
	a[0] = rand() % 9 + 1;
	used[a[0]] = 1;


	for (i; i < dlina; i++) {
		do {
			a[i] = rand() % 10;
		} while (used[a[i]] == 1);
		used[a[i]] = 1;
	}

	printf("Poprobui vvesti chislo dlinoi %d\n", dlina);

	do {
		int b[N] = { 0 };
		bulls = 0;
		cows = 0;
		pop += 1;

		for (j = 0; j < dlina; j++) {
			scanf_s("%1d", &b[j]);
		}

		for (k = 0; k < dlina; k++) {
			for (m = 0; m < dlina; m++) {
				if (a[k] == b[m] && k == m) {
					bulls += 1;
				}
				if (a[k] == b[m] && k != m) {
					cows += 1;
				}
			}
		}

		printf("%d bulls and %d cows\n", bulls, cows);
		if (bulls != dlina) {
			printf("ne ugadal, poprobui eshe\n");
		}
	} while (bulls != dlina);

	printf("pobeda, %d popitok", pop);

	return 0;
}