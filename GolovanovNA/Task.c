#include <stdio.h>
#include <math.h>

int main() {
	float x1, y1, r1, x2, y2, r2, d;
	scanf_s("%f%f%f%f%f%f", &x1, &y1, &r1, &x2, &y2, &r2);
	if (r1 <= 0 || r2 <= 0) {
		printf("vvodinormalno");
		return 0;
	}
	if (x1 == x2 && y1 == y2 && r1 == r2) {
		printf("oniodinakovie");
		return 0;
	}
	if (x1 == x2 && y1 == y2) {
		printf("oniconcentriceskie");
		return 0;
	}
	d = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (r1 + r2 < d) {
		printf("onidaleko");
		return 0;
	}
	if (r1 + r2 == d) {
		printf("onikasautsairiadom");
		return 0;
	};
	if (d < fabs(r1 - r2)) {
		printf("odnavdrugoi");
		return 0;
	};
	if (d == fabs(r1 - r2)) {
		printf("onikasautsaiodnavnutri");
		return 0;
	};
	printf("oniperesecautsa");
	return 0;
	
	return 0;
}
