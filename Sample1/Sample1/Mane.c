#include <stdio.h>
int main() {
	int a, b, S, T;
	scanf_s("%d %d %d %d", &a, &b, &S, &T);
	printf("S = %d", S + (a + b)*T);
	return 0;
}