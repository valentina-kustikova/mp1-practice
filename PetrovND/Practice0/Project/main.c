#include <stdio.h>
#include <math.h>

int main() {

	float x1, y1, x2, y2, r1, r2, d;

	printf("Enter x1: ");
	scanf("%f", &x1);
	printf("Enter y1: ");
	scanf("%f", &y1);
	printf("Enter x2: ");
	scanf("%f", &x2);
	printf("Enter y2: ");
	scanf("%f", &y2);
	printf("Enter r1: ");
	scanf("%f", &r1);
	printf("Enter r2: ");
	scanf("%f", &r2);

	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); // distance between the centers of circles

	if (r1 <= 0 || r2 <= 0) { //Input control
		printf("Data entered incorrectly...");
		return 1;
	}

	if (d > r1 + r2) {
		printf("Circles have no common points. \n");
		return 0;
	}

	if (x1 == x2 && y1 == y2 && r1 == r2) {
		printf("Circles is equals. \n");
		return 0;
	}

	if (d < (fmax(r1, r2)-fmin(r1,r2))) { // d < R - r
		printf("Circles have no common points(one circle inside another). \n");
		return 0;
	}

	if (d == r1 + r2) {
		printf("Circles have one common point (external touch). \n");
		return 0;
	}

	if (d == (fmax(r1, r2) - fmin(r1, r2))) { // d = R - r
		printf("Circles have one common point (inner touch). \n");
		return 0;
	}
	else
	{
		printf("Circles have two points in common (intersect). \n");
		return 0;
	}

	return 0;
}