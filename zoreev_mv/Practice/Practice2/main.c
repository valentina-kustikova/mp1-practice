#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void main() {
	int n, cow, bull, i, out, count = 0, temp = 0;
	int free[10] =  { 0 }, number[10] = { 0 }, input[10] = { 0 }, Cfree[10] = { 0 };
	long a;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));

	//Ввод
	
	do {
		printf("Input count of numbers ");
		scanf("%d", &n);
    } while ((n < 1) || (n > 10));

	//Генерация числа

	for (i = 0; i < n; i++) {
		/*Можно первую цифру генерировать отдельно, чтобы не проверять каждый
		раз на то что она не равна нулю, но тогда код читать сложнее...*/

		do {
			number[i] = rand() % 10;
		} while ((Cfree[number[i]] == 1) || (number[0] == 0));
		
		Cfree[number[i]] = 1; //Cfree[a]=1 значит что цифра a уже есть в числе

	}
	
	//Проверка совпадений

	do {
		
		do {
			out = 0;
            memset(free, 0, 10*sizeof(int));

			printf("Input number ");
			scanf("%ld", &a);

            temp = a;
            count = 0;
            while (temp > 0) {
                temp = temp / 10;
                count++;
            }

			if (count != n) {
				printf("Out of range\n");
				out = 1;
				continue;
			}

			for (i = n-1; i >= 0; i--) { //заполняется от младших к старшим
				if (free[(a % 10)] == 1) {
					out = 1;
					printf("repeating of nubers\n");
					break;
				}
				input[i] = a % 10;
				free[(a % 10)] = 1;
				a = a / 10;
			}

		} while ((out == 1));
		
		//Поиск совпадений

		bull = 0;
		cow = 0;

		for (i = 0; i < n; i++) {
			if (number[i] == input[i]) bull++;
		}
		for (i = 0; i < 10; i++) {
			if ((free[i] == 1) && (Cfree[i] == 1)) cow++;
		}
		cow = cow - bull;

		if (bull < n) {
			printf("Cows %d\nBulls %d\n", cow, bull);
		}
		else {
			printf("\nYou win!\n");
		}
	} while (bull < n);
}
