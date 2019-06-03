#include "VectorC.h"
#include <stdio.h>

void main() {
	double q;
	Vector v1, v2, v3, vRes;
	Create(3, &v1);
	Create(3, &v2);
	Create(2, &v3);
	Create(3, &vRes);
	Input(&v1);
	Input(&v2);
	Input(&v3);
	q = Length(&v3);
	printf("Length of 3rd vector %lf \n", q);
	printf("Vector 3 deleted and we`re trying to ouput it \n");
	Delete(&v3);
	Output(&v3);
	Sum(&v1, &v2, &vRes);
	printf("Sum of vector 1 and vector 2 ");
	Output(&vRes);
	Sub(&v1, &v2, &vRes);
	printf("Difference between vector 1 and vector 2 ");
	Output(&vRes);
	Scalar(&v1, &v2, &q);
	printf("Scalar product of vector 1 and vector 2 %lf \n", q);
	Angle(&v1, &v2, &q);
	printf("Angle between vector 1 and vector 2 %lf \n", q);
	scanf("%lf", &q);
}