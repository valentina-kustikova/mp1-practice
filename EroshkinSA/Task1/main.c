#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand((unsigned int)time(0));
	int a = 1, b = 1000, n = rand() % (b - a + 1) + a, x, cnt = 0, mode, l = 0, r = 1000, c;
	char s = 't';
	printf("Enter mode of work: ");
	do {
		scanf_s("%d", &mode);
	} while (mode != 1 && mode != 2);
	if (mode == 1) {
		do {
			scanf_s("%d", &x);
			cnt++;
			if (x < n) printf("More\n");
			if (x > n) printf("Less\n");
		} while (x != n);
		printf("Number was guessed by %d questions!", cnt);
		return 0;
	}
	while (s != '=') {
		c = (l + r) / 2;
		printf("%d?", c);
		scanf_s("%c", &s);
		if (s == '=') {
			cnt++;
		}
		if (s == '<') {
			r = c - 1;
			cnt++;
		}
		if (s == '>') {
			l = c + 1;
			cnt++;
		}
	}
	printf("Number was guessed by %d questions!", cnt);
	return 0;
}