#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void) {
	int number1, number2, i;
	char str;
	i = 0;
	srand((unsigned int)time(0));
	scanf("%d", &number2);
	while (number2 > 1000 || number2 < 1) {
		printf("Error\n");
		scanf("%d\n", &number2);
	}
	number1 = 1 + rand() % 1000;
	while (number1 != number2) {
		printf("%d\n", &number1);
		scanf("%s\n", &str);
		if (str == ">") {
			number1 = 1 + rand() % number1;
		}
		else {
			number1 = number1 + rand() % (number2 - number1 + 1);

		}
		i = i + 1;
	}
	printf("You guessed right\n");
	printf("%d", &i);
	
	
	}

