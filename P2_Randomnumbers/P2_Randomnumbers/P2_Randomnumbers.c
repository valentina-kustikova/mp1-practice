#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void main() {
	srand(time(NULL));
	int gamemode, try, x = 0, y = 1000, answer, guess, result;
	char sign;

	printf("\t\t\tHello, player!\n");

	do {
		printf("Choose gamemode (1 - bot guess the number, 2 - user guess the number)\n");
		scanf_s("%d", &gamemode);
	} while ((gamemode != 1) && (gamemode != 2));

	switch (gamemode) {
	case 1:
		result = 0; try = 0;
		answer = rand() % 1000;
		printf("Enter the value\n");

		do {
			getchar();
			scanf_s("%d", &guess);
			try++;
			while ((guess > 1000) || (guess < 0)) {
				printf("\n>>> You entered wrong value! <<<\n");
				scanf_s("%d", &guess);
			}
			if (guess == answer) {
				printf("You found the number!!!\n");
				result = 1;
				break;
			}
			else if (guess < answer) {
				printf("Your value less of answer. Try again!\t");
			}
			else {
				printf("Your value more of answer. Try again!\t");
			}

		} while (result != 1);

		break;




	case 2:
		result = 0; try = 0;
		
			printf("Enter the value, which you want to guess\t");
			getchar();
			scanf_s("%d", &answer);
			while ((answer < 0) || (answer > 1000)) {
				printf("\n>>> You entered wrong value! <<<\n");
				getchar();
				scanf_s("%d", &answer);
			}
		guess = rand() % 1000;
ent:	do {
			printf("Its %d? (y, >, <)\n", guess);
			getchar();
			do {
				scanf_s("%c", &sign);
			} while ((sign != '<') && (sign != 'y') && (sign != '>'));
			switch (sign) {
			case 'y':
				printf("I FOUND VALUE\n");
				result = 1;

				break;
			case '>':
				printf("Okey, i will try again ");
				y = guess - 1;
				guess = x + rand() % (y - x + 1);

				break;
			case '<':
				printf("Okey, i will try again ");
				x = guess + 1;
				guess = x + rand() % (y - x + 1);

				break;
			default:
				printf("you entered wrong sign!");
				goto ent;

				break;
			}

			try++;

		} while (result != 1);


		break;
	}



	printf("nubmer of attempts is %d\n", try);

	system("pause");
}
