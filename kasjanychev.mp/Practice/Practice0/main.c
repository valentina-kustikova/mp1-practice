#include <stdio.h>
#include <math.h>
void main() {
	double a1, b1, a2, b2, r1, r2,d;
	printf("Vvedite a1,a2,b1,b2,r1,r2");
	scanf("%lf %lf %lf %lf %lf %lf", &a1, &a2, &b1, &b2, &r1, &r2);
	d = sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2));
	if ((a1 == a2) && (b1 == b2) && (r1 == r2)) {
		printf("Okruzhnosti sovpadayut");
		return;
	}
	if (d < (r1 + r2))&&(d>sqrt((r1-r2)*(r1-r2)){
		printf("Okruzhnosti peresekayutsya");
	return;
	}
	if ( d == (r1 + r2)) {
		printf("Okruzhnosti kasayutsya vneshne");
		return;
	}
	if (d > (r1 + r2)) {
		printf("Okruzhnosti ne peresekayutsya i ne lezhat drug v druge");
		return;
	}
	if (d<sqrt((r1-r2)*(r1-r2))
		printf("Okruzhnosti lezhat drug v druge i ne kasayutsya drug druga");
	return;
	if (d==sqrt((r1-r2)*(r1-r2))
		printf("Okruzhnosti kasayutsya vntutri");
	return;
    }
}