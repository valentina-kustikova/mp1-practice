#include <stdio.h>
#include <math.h>


void main() {
	float r1, r2, x1, x2, y1, y2, s;
	
	printf("\t Welcome to the program that analyzes the position of two circles relative to each other \n \t Enter the center coordinate and radius of circlys: \n");
	printf("\t X1 = ");
	scanf_s("%f", &x1);
	printf("\t Y1 = ");
	scanf_s("%f", &y1);
	printf("\t R1 = ");
	scanf_s("%f", &r1);
	while (r1 <= 0) {
		printf("You entered wrong value for R1 (R1 > 0)");
		printf("\t R1 = ");
		scanf_s("%f", &r1);
	}
	printf("\n \t X2 = ");
	scanf_s("%f", &x2);
	printf("\t Y2 = ");
	scanf_s("%f", &y2);
	printf("\t R2 = ");
	scanf_s("%f", &r2);
	while (r2 <= 0) {
		printf("You entered wrong value for R2 (R2 > 0)");
		printf("\t R2 = ");
		scanf_s("%f", &r2);
	}

	printf("The FIRST cyrcle >>> (x; y) = (%f: %f), R = %f\n", x1, y1, r1);
	printf("The SECOND cyrcle >>> (x; y) = (%f: %f), R = %f\n", x2, y2, r2);

	s = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

	printf("\nDistance from the first center to the second center = %f\n\n", s);

	printf("-------------------------------------------------\n\n");
	if (r1 == r2) {
		if ((x1 == x2) && (y1 == y2))
			printf("The circlys match!");
		else if (s < (r1 + r2))
			printf("Ñircles have 2 common points (R1 = R2)!");
		else if (s == (r1 + r2))
			printf("Ñircles have 1 common point (R1 = R2)!");
		else
			printf("Ñircles haven't any common points (R1 = R2)!");
	}

	if (r1 > r2) {
		if (((x1 == x2) && (y1 == y2)) || (r1 > (s + r2)))
			printf("The second circle is inside the first!");
		else if ((s == (r1 - r2)) || (s == (r1 + r2)))
			printf("Circles have 1 common point (R1 > R2)");
		else if (s < (r1 + r2))
			printf("Circles have 2 common points (R1 > R2)");
		else
			printf("Circles haven't any common points (R1 > R2)");
	}

	if (r1 < r2) {
		if ((x1 == x2) && (y1 == y2) || (r2 > (s + r1)))
			printf("The first circle is inside the second!");
		else if ((s == (r2 - r1)) || (s == (r1 + r2)))
			printf("Circles have 1 common point (R1 < R2)");
		else if (s < (r1 + r2))
			printf("Circles have 2 common points (R1 < R2)");
		else
			printf("Circles haven't any common points (R1 < R2)");
	}

	printf("\n");

	system("pause");
}