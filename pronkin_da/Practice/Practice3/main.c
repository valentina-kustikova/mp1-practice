#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	srand((unsigned int)time(0));
	int a = 1, b = 1000, x, p, i = 0;
	char c;
	do {
		printf("Viberite rezim igri, otgadat chislo (1), zagadat chislo (2)\n");
		scanf("%d", &i);
	} while (i < 0 || i > 2);
	if (i == 1) {
		x = rand()*(b - a) / RAND_MAX + a;
		while (1) {
			printf("Vvedite chislo \n");
			scanf("%d", &p);
			if (p > x) printf("Zagadannoe chislo menshe\n");
			if (p < x) printf("Zagadannoe chislo bolshe\n");
			if (p == x) {
				printf("Ugadali\n");
				return;
			}
		}
	}
	if (i == 2) {
		printf("Zagadaite chislo \n");
		scanf("%d", &p);
		while (1) {
			x = (rand() * (b - a)) / RAND_MAX + a;
			printf("%d\n", x);
			do {
				printf("Vvedite bolshe, menshe ili ravno vvidennoe computerom chislo \n");
				scanf("%s", &c);
			} while (c != '>' && c != '<' && c != '=');
			i++;
			if (c == '<') b = x - 1;
			if (c == '>') a = x + 1;
			if (c == '=') {
				printf("%d", i);
				return;
			}
		}
	}
}