#include<stdio.h>
#include<math.h>

void main()
{
	float x1, x2, y1, y2, r1, r2, d;
	printf("Enter first circle characteristics: ");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Enter second circle characteristics: ");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (d == r1 + r2){
		printf("Circles touch externally");
		return 0;
	}
	if (d > r1 + r2) {
		printf("Circles don't have common points");
		return 0;
	}
	if ((d + r1 == r2) || (d + r2 == r1)) {
		printf("Circle is inside circle with a touch");
		return 0;
	}
	if (abs(x1-x2) < r1 || abs(x1-x2) < r2) {
		printf("One circle inside another");
		return 0;
	}
	if ((r1 == r2) && (y1 == y2) && (r1 == r2)) {
		printf("Circles are equal");
		return 0;
	}
	printf("Circles have two points in common");
	return 0;

}