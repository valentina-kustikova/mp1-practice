#include "Vector.h"

Vector create(int an) {
	Vector v;
	v.n = an;
	v.x = (double*)malloc(sizeof(double)*an);
	return v;
}

void deleted(Vector v) {
	v.n = 0;
	free(v.x);
}

Vector addition(Vector v1, Vector v2) {
	if (v1.n != v2.n){
		printf("Error: different dimension of vectors!");
		return;
	}
	Vector v3 = create(v1.n);
	int i = 0;
	for (i; i < v1.n; i++)v3.x[i] = v1.x[i] + v2.x[i];
	return v3;
}

Vector substraction(Vector v1, Vector v2) {
	if (v1.n != v2.n) {
		printf("Error: different dimension of vectors!");
		return;
	}
	Vector v3 = create(v1.n);
	int i = 0;
	for (i; i < v1.n; i++)v3.x[i] = v1.x[i] - v2.x[i];
	return v3;
}

double scalarproduct(Vector v1, Vector v2) {
	if (v1.n != v2.n) {
		printf("Error: different dimension of vectors!");
		return 0.0;
	}
	double p = 0;
	int i = 0;
	for (i; i < v1.n; i++)p += v1.x[i] * v2.x[i];
	return p;
}

double angle(Vector v1, Vector v2) {
	if (v1.n != v2.n) {
		printf("Error: different dimension of vectors!");
		return 0.0;
	}
	double co;
	co = (scalarproduct(v1, v2)) / (vectorlength(v1) * vectorlength(v2));
	return acos(co);
}

double vectorlength(Vector v) {
	int i;
	double leng = 0;
	for (i = 0; i < v.n; i++)leng += v.x[i] * v.x[i];
	return sqrt(leng);
}

void filling(Vector v, double *a) {
	int i;
	for (i = 0; i < v.n; i++)v.x[i] = a[i];
}

void out(Vector v) {
	int i;
	for (i = 0; i < v.n; i++)printf("%lf ", v.x[i]);
}

