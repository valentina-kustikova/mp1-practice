#ifndef STRUCU_H
#define STRUCU_H

typedef struct {
	int* coef;
	int deg;
}polinom;

polinom pcreate(int deg);
polinom pplus(polinom* p1, polinom* p2);
polinom pminus(polinom* p1, polinom* p2);
polinom pumn(polinom* p1, polinom* p2);
int pznach(polinom* p, double  x);
polinom pdif(polinom* p);

#endif