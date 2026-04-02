#include <stdio.h>
#include <math.h>
int main() {
	float x1, y1, r1, x2, y2, r2, d;
	printf("Cord and rad 1\n");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Cord and rad 2\n");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	if ((r1 < 0) || (r2 < 0)) {
		printf("negative radius");
		return 1;
	}
	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
		printf("Circ are same");
		return 0;
	}
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if ((abs(r1 - r2) > d) || ((r1 + r2) < d)) {
		printf("Circ do not intersect");
		return 0;
	}
	if (abs(r1 - r2) == d) {
		printf("Internal tanqency of circles");
		return 0;
	}
	if ((r1 + r2) == d) {
		printf("External tanqency of circles");
		return 0;
	}
	printf("Circles intersect each other");
	return 0;
}