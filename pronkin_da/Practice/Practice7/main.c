#include "Vector.h"
#include <stdio.h>

void main(){
	int n1, n2, i;
	double sp, _angle, _len;
	double *a;
	double *b;
	Vector v1, v2, v3;
	scanf("%d %d", &n1, &n2);
	if (n1 != n2)return;
	v1 = create(n1);
	v2 = create(n2);
	a = (double*)malloc(sizeof(double) * n1);
	b = (double*)malloc(sizeof(double) * n2);
	for (i = 0; i < n1; i++) {
		a[i] = i;
		b[i] = i + i * 2;
	}
	filling(v1, a);
	filling(v2, b);
	v3 = create(n1);
	v3 = addition(v1, v2);
	out(v3);
	deleted(v3);
	v3 = create(n1);
	v3 = substraction(v1, v2);
	out(v3);
	sp = scalarproduct(v1, v2);
	printf("%lf", sp);
	_angle = 57 * angle(v1, v2);
	printf("%lf", _angle);
	_len = vectorlength(v3);
	printf("%lf", _len);
}