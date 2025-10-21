#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define L 10
int main() {
	printf("The game 'Bulls and Cows'\n");
	int n, cn, hn;
	int cow = 0, bull = 0;
	srand(time(0));
	printf("Choose the length of mystery numbers(2-5): ");
	do {
		scanf_s("%d", &n);
	} while (n < 2 || n>5);
	int mcn[L];
	int i, j;
	int l = 1, r = 9;
	for (i = 1; i < n; i++) {
		l *= 10;
	}
	for (i = 1; i < n; i++) {
		r *= 10;
		r += 9;
	}
	int fl1 = 0;
	do {
		fl1 = 1;
		cn = rand() % (r - l + 1) + l;
		int p[L] = { 0 };
		int s = 0;
		int g1;
		g1 = cn;
		while (g1) {
			mcn[s] = g1 % 10;
			g1 /= 10;
			s++;
		}
		for (i = 0; i < n; i++) {
			p[mcn[i]]++;
		}
		for (i = 0; i < L; i++) {
			if (p[i] > 1) {
				fl1 = 0;
			}
		}
	} while (fl1 == 0);
	printf("Come up with and enter a number of the selected lenght: ");
	int fl2 = 0, cf = 0;
	int mhn[L];
	while (cf != 1) {
		do {
			fl2 = 1;
			do {
				scanf_s("%d", &hn);
			} while (hn<l || hn>r);
			int pp[L] = { 0 };
			int u = 0;
			int g2;
			g2 = hn;
			while (g2) {
				mhn[u] = g2 % 10;
				g2 /= 10;
				u++;
			}
			for (i = 0; i < n; i++) {
				pp[mhn[i]]++;
			}
			for (i = 0; i < L; i++) {
				if (pp[i] > 1) {
					fl2 = 0;
				}
			}
		} while (fl2 == 0);
		cow = 0;
		bull = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (mcn[i] == mhn[j] && i != j) {
					cow++;
				}
				if (mcn[i] == mhn[j] && i == j) {
					bull++;
				}
			}
		}
		if (bull == n) {
			cf = 1;
			printf("You are the winner, the hidden number - %d!", hn);
		}
		else {
			printf("cuws - %d, bulls - %d\n", cow, bull);
		}
	}
	return 0;
}