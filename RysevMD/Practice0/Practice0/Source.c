#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	float x1, y1, r1;
	float x2, y2, r2;
	float d;
	
	printf("Enter the coordinates of the center and the radius of the first circle: ");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Enter the coordinates of the center and the radius of the second circle: ");
	scanf("%f %f %f", &x2, &y2, &r2);
	
	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	if (d == 0) {
		if (r2 == r1) 
			printf("Circles match ");
		else 
			printf("One circle lies inside another ");
	}

	else if (d < abs(r1 - r2))
		printf("One circle lies inside another ");

	else if (d == abs(r1 - r2))
		printf("The circles touch each other from the inside ");

	else if (d > abs(r1 - r2) && d < r1 + r2)
		printf("Circles intersect ");

	else if (d == r1 + r2)
		printf("Circles touch each other on the outside ");

	else
		printf("The circles lie apart from each other ");

	return 0;
}
