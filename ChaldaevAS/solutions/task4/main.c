#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int n = 1, i;
	int digits[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int pc_num[5];

	srand(time(NULL));

	printf("Write number (2-5): ");
	while (1) {
		scanf_s("%d", &n);
		if (1 < n && n < 6) {
			break;
		}
		else {
			printf("Error: Number must be between 2 and 5!\n");
		}
	}
	for (i = 0; i < n; i++) {
		int number = rand() % 10;
		if (i == 0 && number == 0) {
			number = 1 + rand() % 9;
		}
		while (digits[number] != 0) {
			int number = rand() % 10;
		}
		digits[number] = 1;
		pc_num[i] = number;
	}

	while (1) {
		int player_num;
		int player_digits[5];
		int temp;
		int len = 0;
		int bulls = 0, cows = 0;

		printf("\nWrite your number (length %d): ", n);
		scanf_s("%d", &player_num);

		if (player_num <= 0) {
			printf("Error: Number must be positive!\n");
			continue;
		}
		temp = player_num;
		while (temp > 0) {
			if (len >= n) {
				break;
			}
			temp = temp / 10;
			len++;
		}

		if (len != n) {
			printf("Error: Number must have exactly %d digits!\n", n);
			continue;
		}

		temp = player_num;
		for (i = 0; i < n; i++) {
			player_digits[n - i - 1] = temp % 10;
			temp /= 10;
		}

		for (i = 0; i < n; i++) {
			if (player_digits[i] == pc_num[i]) {
				bulls += 1;
			}
			if (digits[player_digits[i]] == 1) {
				cows += 1;
			}
		}
		cows -= bulls;
		if (bulls == n) {
			printf("You win");
			break;
		}
		else {
			printf("%d - bulls, %d - cows", bulls, cows);
		}
	}
}