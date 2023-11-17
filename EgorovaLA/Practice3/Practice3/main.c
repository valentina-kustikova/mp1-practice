#include <stdio.h>
#include <locale.h>
#include<time.h>
#include<stdlib.h>

#define len 5

int length(int n) {
	int leng = 0;
	do {
		leng++;
		n /= 10;
	} while (n);
	return leng;
}

void main() {
	int const low_line = 2, up_line = 5;
	int n,i,j,number,pep_chiclo;
	int k = 0;
	int bull = 0, cow = 0;
	int chislok[len] = {0};
	int chislop[len] = {0};

	setlocale(LC_ALL, "rus");

	do {
		printf("Введите длину числа в диапазоне (2..5) ");
		scanf("%d", &n);
	} while ((n < low_line) || (n > up_line));

	srand((unsigned int)time(0));

	chislok[0] = 1 + rand() % (10 - 1);
	for (i = 1; i < n; i++) {
		do{
			k = 0;
			number = rand() % 10;
			for (j = 0; j < i; j++) {
				if (chislok[j] == number)
					break;
				k++;
			}
			if (k == i) {
				chislok[i] = number;
				break;
			}
		} while (1);
	}

	/*for (i = 0; i < n; i++) {
			printf("%d", chislok[i]);
		}//test
	printf("\n");*/

	do {
		bull = 0;
		cow = 0;

		do {
			printf("Введите свою отгадку (все цифры различны) ");
			scanf("%d", &pep_chiclo);
			if (length(pep_chiclo) != n)
				printf("Ваша отгадка не той длины\n");
			else break;
		} while (1);
	
		for (i = n-1; i >=0; i--) {
			chislop[i] = pep_chiclo % 10;
			pep_chiclo = pep_chiclo / 10;
		}

		for (i = 0; i < n; i++) { 
			for (j = 0; j<n; j++) { 
				if (chislop[i] == chislok[j]) {
					cow++;
					if (i == j) {
						bull++;
						cow--;
					}
					break;
				}
			}
		}
		if (bull != n)
			printf("В вашей отгадке: коров %d быков %d\n", cow, bull);
		else {
			printf("Вы угадали, поздравляю!");
			break;
		}
	} while (1);

	return;
}