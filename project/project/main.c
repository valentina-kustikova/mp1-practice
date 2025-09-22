#include <stdio.h>
int main() {
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	printf("S = %d", a * (b + c));
	return 0;
} 