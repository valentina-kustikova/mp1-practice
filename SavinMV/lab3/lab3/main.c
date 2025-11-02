#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int dl, bik = 0, kor = 0, i = 0, k = 0,j=0;
	int pc_num[5] = { 0 };
	int d[10] = { 0 };
	int ch_pol[5] = { 0 };
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
	if (dl == 2) printf("chislo kompa: %d%d\n", pc_num[0], pc_num[1]);
	if (dl == 3) printf("chislo kompa: %d%d%d\n", pc_num[0], pc_num[1], pc_num[2]);
	if (dl == 4) printf("chislo kompa: %d%d%d%d\n", pc_num[0], pc_num[1], pc_num[2], pc_num[3]);
	if (dl == 5) printf("chislo kompa: %d%d%d%d%d\n", pc_num[0], pc_num[1], pc_num[2], pc_num[3], pc_num[4]);
	
	printf("Poprobuy vvesti chislo dlinoy %d: ", dl);


	do {
		bik = 0;
		kor = 0;
		for (i = 0; i < dl; i++) {
			scanf_s("%1d", &ch_pol[i]);
		}
		for (k = 0; k < dl; k++) {
			for (j = 0; j < dl; j++) {
				if (pc_num[k] == ch_pol[j] && k == j) bik += 1;
				if (pc_num[k] == ch_pol[j] && k != j) kor += 1;				
			}
		}
		printf("%d bik and %d kor\n", bik, kor);
		if (bik != dl) printf("ne ygadal, poprobui eshe\n");
	} while (bik != dl);

	printf("ygadal");

	return 0;
}