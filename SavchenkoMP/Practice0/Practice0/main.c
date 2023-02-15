#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
1) The circles are equal
2) They don't touch
3) External touch
4) Inner touch
5) One circle inside another
6) Сrossing at 2 points 
*/

void main() {
	
	setlocale(LC_ALL, "rus");
	float x1, y1, r1, x2, y2, r2, M, m, dl;
	printf("Circle 1 (x1, y1, r1) = ");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Circle 2 (x2, y2, r2) = ");
	scanf("%f %f %f", &x2, &y2, &r2);

	if (r1 > r2) {
		M = r1;
		m = r2;
	}
	else {
		M = r2;
		m = r1;
	}

	dl = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (x1 == x2 && y1 == y2 && r1 == r2)
		printf("1) The circles are equal");			// 1 1 1 1 1 1
	else {
		if (dl > (r1 + r2))
			printf("2) They don't touch");			// 1 1 1 4 1 1
		else if (dl == (r1 + r2))
			printf("3) External touch");			// 1 1 1 3 1 1
		else if (dl == (M - m))
			printf("4) Inner touch");				// 1 1 4 4 1 1
		else if (dl < (M - m))
			printf("5) One circle inside another"); // 1 1 4 2 1 1
		else
			printf("6) Crossing at 2 points ");		// 0 0 2 2 0 1
	}
}