#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void main() {
	int randchislK, chisloP, mode, k = 0;
	int num = 1;
	int Range = 1000;
	char ans;

	setlocale(LC_ALL, "rus");
	
	do {
		printf("В какой режим сыграть? Загадывает компьютер(1) или вы (2) ");
		scanf("%d", &mode);
	} while (mode != 1 && mode != 2);

	if (mode == 1) {
		srand((unsigned int)time(0));
		randchislK = (rand() % Range) + num;
		do {
			k++;
			printf("Введите число (1,1000)");
			scanf("%d", &chisloP);
			if (chisloP == randchislK) {
				printf("Вы угадали!\n");
				printf("Колличество попыток %d", k);
				break;
			}
			else if (chisloP > randchislK)
				printf("Загаданное число меньше\n");
			else if (chisloP < randchislK)
				printf("Загаданное число больше\n");
		} while (1);
	}
	else {
		do {
			printf("Загадайте число (1,1000)");
			scanf("%d", &chisloP);			
		} while ((chisloP > Range) || (chisloP < 1));

		srand((unsigned int)time(0));

		do {			
			randchislK = num + rand() % (Range-num+1);
			printf("Я думаю это %d\n", randchislK);
			k++;
			printf("Я угадал? Введите (<, >, =), чтобы я понял ");
			scanf("%*c%c", &ans);			
			if (ans == '=') {
				printf("Я угадал за %d попыток", k);
				break;
			}
			else if (ans == '>') {
				num = randchislK + 1;
			}
			else if (ans == '<') {
				Range = randchislK - 1;
			}
		} while (1);
	}

	return;
}