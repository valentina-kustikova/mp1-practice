#include <stdio.h>
#define N 4

int main() {
	int pokup, i, j, k, match, temp, obshtsena = 0;
	float obshskidki = 0.0;
	int shtrixpok[N];

	int shtrix[N][4] = {{1,0,0,1}, {2,0,0,2}, {3,0,0,3}, {4,0,0,4}};
	int tsena[N] = { 89, 35, 50, 149 };
	int skidka[N] = { 10, 5, 15, 20 };
	char nazvan[N][7] = {"Moloko", "Voda", "Sok", "Chipsi"};
	int kol[N] = { 0 };

	do {
		printf("Vvedite shtrix kod, esli pokupki zakonchilis, vvedite 0\n");
		scanf_s("%d", &pokup);

		temp = pokup;

		for (i = N; i > 0; i--) {
			shtrixpok[i - 1] = pokup % 10;
			pokup = pokup / 10;
		}

		for (i = 0; i < N; i++) {
			match = 1;
			for (j = 0; j < N; j++) {
				if (shtrixpok[j] != shtrix[i][j]) {
					match = 0;
					break;
				}
			}
			if (match == 1) {
				kol[i] += 1;
				printf("Shtrix kod - %d, Nazvanie - %s, Tsena - %d, Skidka - %d%%\n",
					temp, nazvan[i], tsena[i], skidka[i]);
				break;
			}
		}
	} while (temp != 0);
	
	printf("Check:\n");
	for (i = 0; i < N; i++) {
		if (kol[i] != 0) {
			printf("Nazvanie - %s, tsena - %d, kolichstvo - %d, obshaya tsena - %d\n",
				nazvan[i], tsena[i], kol[i], kol[i] * tsena[i]);
			obshtsena += kol[i] * tsena[i];
			obshskidki += kol[i] * (tsena[i] * (skidka[i] / 100.0));
		}
	}
	printf("\nObshaya tsena bez skidki - %d, Summarnaya skidka - %f, Itogovaya summa - %f\n", obshtsena, obshskidki, obshtsena - obshskidki);
	return 0;
}
