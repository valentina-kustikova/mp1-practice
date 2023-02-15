#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	float x1, x2, y1, y2, R1, R2, S;
	printf("Input x1 ");
	scanf("%f", &x1);
	printf("Input y1 ");
	scanf("%f", &y1);
	printf("Input R1 ");
	scanf("%f", &R1);
	printf("Input x2 ");
	scanf("%f", &x2);
	printf("Input y2 ");
	scanf("%f", &y2);
	printf("Input R2 ");
	scanf("%f", &R2);
	S = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (S > R1 + R2) {
		printf("The circle does not intersect ");
		return 0;
	}
	if (S == R1 + R2) {
		printf("External touch of circles ");
		return 0;
	}
	if ((S < R1 + R2) && (S > abs(R1 - R2))) {
		printf("The circles intersect ");
		return 0;
	}
	if ((S == abs(R1 - R2)) && (x1 != x2)) {
		printf("Inner touch of circles ");
		return 0;
	}
	if ((S == 0) && (R1 == R2)) {
		printf("The circles are equal ");
		return 0;
	}
	if (R1 > R2) printf("The second circle is inside the first one");
	else printf("The first circle is inside the second ");
	return 0;
}