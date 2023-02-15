#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int a;
	printf("Game: guess the number. Which mode do you want to choose?(1 or 2) ");
	scanf("%d", &a);
	while ((a != 1) && (a != 2)) {
		printf("You can only choose mod number 1 or mod number 2");
		scanf("%d", &a);
	}
	if (a == 1) {
		mode1();
		return 0;
	}
	else {
		mode2();
		return 0;
	}
}

int mode1() {
	time_t t;
	int numb, guess, i = 1;
	srand((unsigned int)time(&t));
	numb = (int)(1000. / RAND_MAX * rand());
	printf("Are you ready?\n");
	system("pause");
	printf("Let's start the game. Try to guess what number the computer guessed: ");
	scanf("%d", &guess);
	while ((guess > 1000) || (guess < 0)) {
		printf("Maybe you forgot that the computer could guessed of a number in the range from 0 to 1000(Don't be upset, this attempt doesn't count.). Try again: ");
		scanf("%d", &guess);

	}
	if (numb == guess)
	{
		printf("Wow! From the first try! Congratulations:)");
		return 0;
	}
	else
	{
		while (numb != guess)
		{
			if (numb > guess) {
				printf("The hidden number is greater than the one you entered.Try again: ");
				scanf("%d", &guess);
				while ((guess > 1000) || (guess < 0)) {
					printf("Maybe you forgot that the computer could guessed of a number in the range from 0 to 1000(Don't be upset, this attempt doesn't count.). Try again: ");
					scanf("%d", &guess);
				}
			}
			else {
				printf("The hidden number is less than the one you entered.Try again: ");
				scanf("%d", &guess);
				while ((guess > 1000) || (guess < 0)) {
					printf("Maybe you forgot that the computer could guessed of a number in the range from 0 to 1000(Don't be upset, this attempt doesn't count.). Try again: ");
					scanf("%d", &guess);
				}
			}
			i++;
		}
		printf("Congratulations!You were able to guess from %d attempts", i);
	}
	return 0;
}

int mode2() {
	int point = 500;
	int correction = 500;
	int user_ans = -1;
	int i = 0;
	int choice = 0;
	printf("Are you ready?\n");
	system("pause");
	printf("Think of a number in the range from 0 to 1000, please.\n");
	while (user_ans != 0)
	{
		if ((point > 1000) || (point < 0))
		{
			printf("The number that you have in your mind doesn't belong to the specified range. Would you like to try again (if yes type 1)?\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				system("cls");
				mode2();
				return 0;
			}
			else
			{
				return 0;
			}
		}
		printf("The number is %d, isn't it? (if my number is greater than yours, type 2, if my number is less than yours, type 1, otherwise type 0)\n", point);
		i++;
		if (i >= 15)
		{
			printf("You LIAR!!!\n");
			system("pause");
			return 0;
		}
		scanf("%d", &user_ans);
		switch (user_ans)
		{
		case 2: point += correction;
			correction = correction / 2 + correction % 2;
			break;
		case 1: point -= correction;
			correction = correction / 2 + correction % 2;
			break;
		case 0: printf("I'm smart! It takes me %d attempts to accomplish this mission!\n", i);
			break;
		}
	}
	system("pause");
	return 0;
}