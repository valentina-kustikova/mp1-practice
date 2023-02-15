#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <malloc.h>
#define N 5

int l;


void unique_number_pc(int* p1)
{
	int i=0, n = 0, digit, g=0, count = 0;
	printf("Input length of riddled number: \n");
	do {
		scanf("%d", &l);
	} while (l < 2 || l > 5);
	for (i = 0; i < l; i++) {
		digit = 0 + rand() % (9 - 0 + 1);		//generator sifr
		p1[i] = digit;
		for (g = 0; g < l; g++) {
			if (p1[i] == p1[g]) {
				count += 1;
			}
			if (count >= 2) {
				digit = 0 + rand() % (9 - 0 + 1);
				p1[i] = digit;
				count = 0;
				g = -1;
			}
		}
		count = 0;
	}
}
void unique_number_user(int *p2) {
	int status;
	int i, j;
	int k;
	int number;
	do {
		status = 1;
		printf("Enter a unique number of length %d: \n", l);
		scanf("%d", &number);
		i = 1;
		while (number > 0) {
			k = number % 10;
			p2[l - i] = k;
			number = number / 10;
			i++;
		}
		for (i = 0; i < l; i++) {
			for (j = i + 1; j < l; j++) {
				if (p2[j] == p2[i]) {
					status = 0;
					break;
				}
			}
			if (status == 0) {
				break;
			}
		}
		if (status == 0) {
			for (i = 0; i < l; i++) {
				p2[i] = -1;
			}
			i = 0;
		}
	} while (status == 0);
}


int main() {
	srand(time(NULL));
	int i, j;
	int cows=0, bulls=0;

	int arr_pc[N];
	unique_number_pc(arr_pc);

	do {
		int arr_user[N];
		unique_number_user(arr_user);

		for (i = 0; i < l; i++) {
			for (j = 0; j < l; j++) {
				if (arr_user[i] == arr_pc[j] && i == j) {
					bulls += 1;
				}
				else if(arr_user[i] == arr_pc[j] && j != i){
					cows += 1;
					}
				}
		}
		if (bulls != l) {
			printf("cows: %d\n", cows);
			printf("bulls: %d\n", bulls);
			cows = 0;
			bulls = 0;
		}
	} while (bulls != l);
	printf("My congratulations!You won!\n");

	return 0;
}



