#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int unique(int a[5], int n, int i);
int main() {
	int n, sl[5] = -1, i, j;

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	printf("¬ведите длину загадываемого числа (2, 3, 4 или 5)\n");
	scanf_s("%d", &n);
	sl[0] = rand() % 10;
	for (i = 1; i < n; i++) {
		while (unique(sl, n, i))               //(sl[i] == sl[i - 1]) || (sl[i] == sl[abs(i - 2)])     (for (j = i; j > 0; j--) sl[i] == sl[j])
			sl[i] = rand() % 10;
	}

}

int unique(int a[5], int n, int i) {
	int ok = 1, j = 0;
	for (; j < i; j++)
		if a[j]
}