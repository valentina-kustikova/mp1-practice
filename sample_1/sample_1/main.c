#include <stdio.h>
int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	if (a%b == 0) {
		printf("a делится на b");
		return 0;
	}
	printf("a не делится на b");
	return 1;
}