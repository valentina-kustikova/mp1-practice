#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#define N 5

void main()
{
	int size, comp[N], buff, num, prov, user[N], j = 0;
	int count = 0;
	int bulls = 0, cows = 0;
	setlocale(LC_ALL, "rus");
	srand((unsigned int)time(NULL));

	do {
		printf("введите количество цифр в числе от 2 до 5 :");//ввод количества разрядов числа контроль ввода
		scanf_s("%d", &size);
	} while ((size < 2) || (size > 5));

	//генерация числа
	int digits = 0, equal;
	comp[0] = 1 + rand() % 9;
	digits++;
	while (digits < size) {

		buff = rand() % 10;
		equal = digits;
		for (int i = 0; i < digits; i++)
			if (buff != comp[i])
				equal--;
		if (equal == 0) {
			comp[digits] = buff;
			digits++;
		}
		//		digits++;
	}
	for (int i = 0; i < size; i++)
		printf("%d", comp[i]);
	printf("\n");
	//пользователь угадывает число


	do {
		bulls = cows = j = 0;
		do {
			count = 0;
			printf("введите ваше число :");

			//			bulls = 0, cows = 0;
			scanf_s("%d", &num);

			prov = num;

			for (int i = size - 1; i >= 0; --i) {
				user[i] = num % 10;
				num /= 10;
			}

			//		for (int i = 0; i < size; i++) {
			//			printf("user[%d]=%d\n", i, user[i]);
			//		}
			do {
				prov /= 10;
				j++;
			} while (prov != 0);

			for (int i = 0; i < size; i++) {
				for (int l = i + 1; l < size; l++) {
					if (user[i] == user[l]) {
						count++;
						break;
					}
				}
			}
			if (count != 0)
				printf("неправильно введеные данные\n");
		} while ((count != 0));

		//		printf("j=%d, size=%d\n", j, size);

		if (j == size)
		{
			for (int i = 0; i < size; i++) {
				if (user[i] == comp[i]) bulls++;
				else {
					for (int l = 0; l < size; l++) {
						if (user[i] == comp[l]) cows++;
					}
				}
			}
			printf("bulls=%d, cows=%d\n", bulls, cows);
		}
		else printf("неверно введена длина числа\n");

	} while (bulls != size);
	printf("!!! You win !!!");
}