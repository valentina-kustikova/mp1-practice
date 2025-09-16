#include <stdio.h>

int main() {
	int x, p, ans = 1;
	scanf_s("%d %d", &x, &p);
	for (int i = 0; i < p; i++) {
		ans *= x;
	}
	printf("%d ^ %d = %d", x, p, ans);
	return 0;
}