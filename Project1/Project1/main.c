#include <stdio.h>
int main() {
	float V1, V2, S, T;
	scanf_s("%f %f %f %f", &V1, &V2, &S, &T);
	printf("S = %f", S + T * (V1 + V2));
	return 0;
}