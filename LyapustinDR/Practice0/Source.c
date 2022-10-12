#include <stdio.h>
#include <math.h>

int main() {
	float x1, y1, r1, x2, y2, r2, d;

	printf("First circle center coordinates and radius: ");
	scanf_s("%f %f %f", &x1, &y1, &r1);

	printf("Second circle center coordinates and radius: ");
	scanf_s("%f %f %f", &x2, &y2, &r2);

	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	if (d == 0) {
		if (r1 == r2) {
			printf("Circles match");
		}
		else printf("One circle lies inside another");
	}
	else if (d < abs(r1 - r2)) printf("One circle lies inside another");
	else if (d == abs(r1 - r2)) printf("One circle touches other from the inside");
	else if (d > abs(r1 - r2) && d < r1 + r2) printf("Circles intersect");
	else if (d == r1 + r2) printf("One circle touches other from the outside");
	else printf("Circles lie apart from each other");

	return 0;
}