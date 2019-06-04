#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int n, p, bull, cow, k, z, s = 0, x, i = 0;
	int m[10];
	bull = 0;
	cow = 0;
	srand((unsigned int)time(0));
	do {
		printf("Vvedite n, ot 1 do 9 ");
		scanf("%d", &n);
	} while (n <= 0 || n > 10);
	//Proverka s na 0
	while (i == 0) {
		if (s == 0)
			s = rand() % 10;
		else
			i = 1;
	}
	i = 0;
	//Generation chisla
	while (i < n - 1) {
		k = s;
		x = rand() % 10;
		while (k != 0) {
			if (k % 10 == x)
				break;
			else {
				k /= 10;
			}
		}
		if (k == 0) {
			s = s*10 + x;
			i++;
		}		
	}
	do {
		printf("Vvedite x ");
		scanf("%d", &x);
		i = 0;
		k = x;
		z = 0;
		for (i; i < n; i++) {
			m[i] = k % 10;
			k /= 10;
		}
		i = 0;
		for (p = 0; p < n; p++) {
			for (i = p + 1; i < n; i++) {
				if (m[p] == m[i]) z++;
			}
		}
	} while (z != 0);
	k = s;
	z = x;
	for (i = 0; i < n; i++) {
		m[i] = k % 10;
		k /= 10;
	} 
	p = 0;
	for (i = 0; i < n; i++) {
		while (z != 0) {
			if (p == i && m[i] == z % 10)
				bull++;
			if (m[i] == z % 10 && p != i)
				cow++;
			z /= 10;
			p++;
		}
		z = x;
		p = 0;
	}
	printf("Cow = %d\nBull = %d\n", cow, bull);
}
