#include "Vector.h"
#include "stdio.h"
#include "math.h"

void main()
{
	vector* v1 = Create(5);
	Input(v1);
	Output(v1);
	double leng = Lenghs(v1);
	printf("\n %lf", leng);
	vector* v2 = Create(5);
	Input(v2);
	Output(v2);
	vector* v3 = Sum(v1, v2);
	Output(v3);
	vector* v4 = Diff(v1, v2);
	Output(v4);
	double scal = Scal(v1, v2);
	printf("\n %lf", scal);
	double ang = Angl(v1, v2);
	printf("\n %lf", ang);
}
