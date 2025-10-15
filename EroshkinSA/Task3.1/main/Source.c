#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand((unsigned int)time(0));
	int n, b = 0, k = 0, mistery[5], i, cnt[10] = {0}, number[5], j;
	char c;
	do {
		scanf_s("%d", &n);
	} while (n < 2 || n > 5);
	printf("chosed length equal %d\n", n);
	for (i = 0; i < n; i++) {
		do {
			mistery[i] = rand() % 10;
		} while (cnt[mistery[i]] || (i == 0 && mistery[i] == 0));
		cnt[mistery[i]]++;
		printf("%d", mistery[i]);
	}
	printf("\n");
	scanf_s("%*c");
	do {
		b = 0;
		k = 0;
		for (i = 0; i < n; i++) {
			if (i == 0) {
				do {
					scanf_s("%c", &c);
					number[i] = c - '0';
				} while (number[i] == 0);
			}
			else {
				scanf_s("%c", &c);
				number[i] = c - '0';
			}

			for (j = 0; j < n; j++) {
				if (mistery[j] == number[i]) {
					if (i == j) b++;
					else k++;
				}
			}
		}
		if (b != n) printf("b = %d  k = %d\n", b, k);
		else printf("You win!!!");
		scanf_s("%*c");
	} while (b != n);
	return 0;
}