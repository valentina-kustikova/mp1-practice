#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 5

void razb(int* try, int a, int n){  // разбиение числа на список цифр
	int i = 0;
	while (a > 0) {
		try[n - i - 1] = a % 10;
		a = a / 10;
		i++;
	}
}

int find(int* x, int n, int e) { // линейный поиск
	int i = 0, ind = -1;
	for (i = 0; i < n; i++) {
		if (x[i] == e) {
			ind = i;
			break;
		}
	}
	return ind;
}

int main() {
	int n, i, a, c = 1;
	int x[N], try[N];
	srand(time(NULL));
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		do {
			a = 1 + rand() % 9; // создание ключа
		} while (find(x, i, a) != -1);
		x[i] = a;
	};
	while (c != n) {
		printf("\n");
		scanf_s("%d", &a);
		c = 0;
		razb(try, a, n); //кладем в try ответ игрока
		int u = 0, k = 0, b = 0;
		for (u = 0; u < n; u++) {
			if (find(x, n, try[u]) == -1) {
				// no element
				continue;
			}
			else if (x[u] == try[u]) {
				b++;
				c++;
			}
			else {
				k++;
			}
		}
		printf("%d bulls and %d kows", b, k);
		if (c == n) {
			printf("\n you won!!!");
		}
	}
	return 0;
}