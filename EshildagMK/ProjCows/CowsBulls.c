#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int formNum(int n);

int main() {
	int gnum = 0, plnum, i = 0, j = 0, ncount, numi, numj, ic = 0, ib = 0, temp, kansw = 0;
	int cows[5] = { 11,11,11,11,11 };
	int bulls[5] = { 11,11,11,11,11 };
	int pl_digit[5] = { 11,11,11,11,11 };
	int gm_digit[5] = { 11,11,11,11,11 };

	printf("Enter ammount of numbers:\n");
	scanf_s("%d", &ncount);
	gnum = formNum(ncount);
	printf("%d \n", gnum);
	while (kansw != ncount) {
		kansw = 0; ic = 0; ib = 0; i = 0;
		for (i = 0; i < 5; i++) {
			cows[i] = 11;
			bulls[i] = 11;
			pl_digit[i] = 11;
			gm_digit[i] = 11;
		}
		i = 0;
		printf("Enter your number:\n");
		scanf_s("%d", &plnum);

		temp = plnum;
		while (temp > 0) {
			pl_digit[i] = temp % 10;
			temp /= 10;
			i++;
		}
		temp = gnum;
		i = 0;

		while (temp > 0) {
			gm_digit[i] = temp % 10;
			temp /= 10;
			i++;
		}
		i = 0;

		for (i = 0; i < ncount; i++) {
			if (pl_digit[i] == gm_digit[i]) {
				bulls[ib++] = pl_digit[i];
				kansw++;
			}
			else {
				for (j = 0; j < ncount; j++) {
					if (pl_digit[i] == gm_digit[j]) {
						cows[ic++] = pl_digit[i];
					}
				}
			}
		}

		printf("Cows: ");
		for (i = 0; i < ncount; i++) {
			if (cows[i] < 10) {
				printf("%d ", cows[i]);
			}
			else continue;
		}
		printf("\nBulls: ");
		for (i = 0; i < ncount; i++) {
			if (bulls[i] < 10) {
				printf("%d ", bulls[i]);
			}
			else continue;
		}
		printf("\n");
	}
	printf("YOU WON!");
}

int formNum(int n) {
	int i = 0, rnum, s = 0;
	srand(time(NULL));
	int UsedNums[10] = { 0 };
	while (i < n) {
		rnum = rand() % 10;
		if (UsedNums[rnum] == 1 || (i == 0 && rnum == 0)) {
			continue;
		}
		UsedNums[rnum] = 1;
		s *= 10;
		s += rnum;
		i++;
	}
	return s;
}