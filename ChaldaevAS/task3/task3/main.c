#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int n = 1, i;
	int digits[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int pc_num[5] = {0, 0, 0, 0, 0};
	int number;


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

	number = 1 + rand() % 9;
	digits[number] = 1;
	pc_num[0] = number;
	for (i = 1; i < n; i++) {
		int number = rand() % 10;
		while (digits[number] != 0) {
			number = rand() % 10;
		}
		digits[number] = 1;
		pc_num[i] = number;
	}

	while (1) {
		int player_num;
		int player_digits[5];
		int player_digits_count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int is_incorrect = 0;
		int temp;
		int len = 0;
		int bulls = 0, cows = 0;

		printf("\nWrite your number (length %d): ", n);
		scanf_s("%d", &player_num); // проверить отсутствие повторений

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
			int digit = temp % 10;
			player_digits[n - i - 1] = digit;
			player_digits_count[digit] += 1;
			if (player_digits_count[digit] >= 2) {
				is_incorrect = 1;
				break;
			}
			temp /= 10;
		}
		if (is_incorrect) {
			printf("Error: Your number must not have any repeated digits!\n");
			continue;
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