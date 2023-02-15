#include <stdio.h>
#include <stdlib.h>

int main() {

	int a;

	printf("select game mode 1 or 2\n");
	scanf_s("%d", &a);

	if (a == 1) {
		int num;
		int flag = 1;
		int counter = 0;
		int number_of_machine;

		srand(time(NULL));
		number_of_machine = 1 + rand() % 999;

		while (flag == 1) {
			printf("enter a number\n");
			scanf_s("%d", &num);

			if (num == number_of_machine) {
				printf("gg wp\n");
				printf("%d\n", num);
				printf("number of attempts:\n");
				printf("%d", counter);
				return 0;
			}

			if (num < number_of_machine) {
				printf("the number is bigger than what you wrote\n");
			}

			if (num > number_of_machine) {
				printf("the number is less then what you wrote\n");
			}

			counter++;
		}
	}

	else if (a == 2) {

		int start = 0, end = 1000;
		int count = 0;
		char ch;
		printf("write more(+) or less(-), if equal then(=)\n");
		do {
			printf("pc thinks it is: %d\n", (start + end) / 2);
			while (ch = getchar() != '\n');
			scanf_s("%c", &ch, 1);
			while (ch != '-' && ch != '+' && ch != '=') {
				while (ch = getchar() != '\n');
				printf("invalid input\n");
				scanf_s("%c", &ch, 1);
			}
			if (ch == '+')
				start = (start + end) / 2 + 1;
			else if (ch == '-')
				end = (start + end) / 2 - 1;
			else
				printf("gg wp! Number of attempts: %d", count);
			count++;
		} while (ch != '=');
	}

	else {
		printf("select game mode 1 or 2");
	}


	return 0;
}