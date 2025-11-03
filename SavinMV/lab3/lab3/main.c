#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int dl, bik = 0, kor = 0, i = 0, k = 0,j=0;
	int pc_num[5] = { 0 };
	int d[10] = { 0 };
	int chp[5] = { 0 };
	int c = 0, l = 0;
	int ch;
	srand((unsigned int)time(0));
	do {
		printf("Vvedi dlinu ot 2 do 5: ");
		scanf_s("%d", &dl);
	} while (dl < 2 || dl>5);


	for (i; i < dl; i++) {
		do {
			if (i == 0) pc_num[i] = rand() % 9 + 1;
			else pc_num[i] = rand() % 10;
		} while (d[pc_num[i]] == 1);
		d[pc_num[i]] = 1;
	}
	l = dl;
	printf("Poprobuy vvesti chislo dlinoy %d: ", dl);
	

	do {
		bik = 0;
		kor = 0;
		scanf_s("%d", &ch);
		while (ch != 0) {
			c = ch % 10;
			chp[dl - 1] = c;
			ch /= 10;
			dl -= 1;
		}
		for (i = 0; i < l; i++) {
			printf("%d\n", chp[i]);
		}
		dl=l;
		for (i = 0; i < l; i++) {
			if (pc_num[i] == chp[i]) bik += 1;

		}

		for (k = 0; k < l; k++) {
			for (j = 0; j < l; j++) {
				
				if (pc_num[k] == chp[j] && k != j) kor += 1;				
			}
		}
		printf("%d bik and %d kor\n", bik, kor);
		if (bik != l) printf("ne ygadal, poprobui eshe\n");
	} while (bik != l);

	printf("ygadal");

	return 0;
}