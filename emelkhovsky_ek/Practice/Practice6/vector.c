#include "stdio.h"
#include "vector.h"
#include "stdlib.h"
#include "locale.h"
#include "math.h"
#define PI 3.14159265
vector create() {
	vector c;
	int i;
	printf("¬ведите размерность вектора: ");
	scanf("%d", &c.n);
	c.x = (float*)malloc(sizeof(float) * c.n);
	printf("¬ведите координаты этого вектора:\n");
	for (i = 0; i < c.n; i++)
		scanf("%f", &(c.x[i]));
	return c;
}

void del(vector c) {
	free(c.x);
}

void output(vector c) {
	int i;
	for (i = 0; i < c.n; i++)
		printf("_%.2f_", c.x[i]);
}

vector sum(vector a, vector b) {
	vector c;
	int i;
	c.n = a.n;
	c.x = (float*)malloc(sizeof(float) * c.n);
	for (i = 0; i < a.n; i++)
		c.x[i] = a.x[i] + b.x[i];
	return c;
}


vector dif(vector a, vector b) {
	vector c;
	int i;
	c.n = a.n;
	c.x = (float*)malloc(sizeof(float) * c.n);
	for (i = 0; i < a.n; i++)
		c.x[i] = a.x[i] - b.x[i];
	return c;
}

double length(vector a) {
	int i;
	double l = 0;
	for (i = 0; i < a.n; i++)
		l = l + a.x[i] * a.x[i];
	l = sqrt(l);
	return l;
}

float scalar(vector a, vector b) {
	int i;
	float s = 0;
	for (i = 0; i < a.n; i++)
		s = s + a.x[i] * b.x[i];
	return s;
}

double angle(vector a, vector b) {
	float s;
	double an, k1, k2;
	k1 = length(a);
	k2 = length(b);
	s = scalar(a, b);
	an = acos(s / (k1 * k2)) * 180 / PI;
	return an;
}

