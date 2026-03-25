#ifndef STRUCU_H
#define STRUCU_H
#define MAX_LEN 1000

typedef struct {
	int* coef;
	int deg;
}polinom;

int degpol(const char* fname, int num);
polinom pcreate(const char* fname, int deg, int num);
polinom pplus(polinom* p1, polinom* p2);
polinom pminus(polinom* p1, polinom* p2);
polinom pumn(polinom* p1, polinom* p2);
int pznach(polinom* p, double  x);
polinom pdif(polinom* p);

#endif

