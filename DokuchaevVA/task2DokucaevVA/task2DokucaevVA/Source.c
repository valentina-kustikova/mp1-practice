#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define N 1000

int main() {
	int a[N]; int x; int chooese; int y; int l, r, c; char ans;
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	x = rand() % N;
	printf("%d\n", x);

	do {
		printf("Введите номер режима (1 или 2):");
		scanf_s("%d", &chooese);
	}
	while ((chooese <1 || chooese>2));

	if (chooese == 1)	{
		printf("Вы выбрали игру <Угадай число от 1 до 1000>\n");
		do {
			printf("Какое число я загадал?\n");
			scanf_s("%d", &y);
			if (x<y) {
				printf("Загаданное число меньше!\n");
			}
			else if (x>y){
				printf("Загаданное число больше!\n");
			}
		} while (y != x);
		printf("Победа!!!");
	}
	else {
		printf("Вы выбрали игру <Загадай число>. Напишите, пожалуйста, загадываемое число.\n");
		scanf_s("%d", &y);
		printf("Сейчас я буду угадывать число, а вы будете вводить знаки '>, <, ='. Играем!\n");
		l = 0;
		r = N;
		do {
			c = (l + r) / 2;
			printf("Ваше число %d?\n", c);
			scanf_s(" %c", &ans);
			switch (ans) {
			case '>': {
				l = c;
				break;
			}
			case  '<': {
				r = c;
				break;
			}
			case '=': {
				break;
			}
			default: printf("Ошибка\n");
			}
		} while (ans != '=');
		printf("Win");
	}

	return 0;
}