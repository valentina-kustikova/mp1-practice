#include "Vector.h"
#include "stdio.h"
#include "math.h"

vector* Create(int r)
{
	vector* a = (vector*)malloc(sizeof(vector));
	a->n = r;
	a->x = (float*)malloc(sizeof(float)* r);
	return a;
}
void Delete(vector* v)
{
	free((*v).x);
	(*v).n = 0;
}
vector* Sum(vector* a, vector* b)
{
	if ((*a).n != (*b).n)
		return;
	vector* res = (vector*)malloc(sizeof(vector));
	(*res).n = (*a).n;
	int i;
	for (i = 0; i < (*res).n; i++)
		(*res).x[i] = (*a).x[i] + (*b).x[i];
	return res;
}
vector* Diff(vector* a, vector* b)
{
	if ((*a).n != (*b).n)
		return;
	vector* res;
	res = Create((*a).n);
	int i;
	for (i = 0; i < (*res).n; i++)
		(*res).x[i] = (*a).x[i] - (*b).x[i];
	return res;
}
double Scal(vector* a, vector* b)
{
	if ((*a).n != (*b).n)
		return;
	int i;
	double scal = 0;
	for (i = 0; i < (*a).n; i++)
		scal += (*a).x[i] * (*b).x[i];
	return scal;
}
double Angl(vector* a, vector*b)
{
	double _a = Scal(a, b);
	double _b = Lenghs(a) * Lenghs(b);
	if (_b == 0)
		return;
	double _c = _a / _b;
	double cosInRadians = acos(_c);
	double angle = cosInRadians * (180 / 3.14);
	return angle;
}
double Lenghs(vector* a)
{
	int i;
	double lenghts = 0;
	for (i = 0; i < (*a).n; i++)
		lenghts += (*a).x[i] * (*a).x[i];
	lenghts = sqrt(lenghts);
	return lenghts;
}

void Output(vector* a)
{
	int i;
	for (i = 0; i < (*a).n; i++)
		printf("%lf ", ((*a).x[i]));
}
void Input(vector* a)
{
	int i;
	for (i = 0; i < (*a).n; i++)
		scanf("%lf", &((*a).x[i]));
}