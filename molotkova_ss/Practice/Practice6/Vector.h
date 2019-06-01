#pragma once

typedef struct
{
	int n;//размерность
	double *x;//координаты в массиве
}vector;

vector* Create(int n);
void Delete(vector* v);
vector* Sum(vector* a, vector* b);
vector* Diff(vector* a, vector* b);
double Scal(vector* a, vector* b);
double Angl(vector* a, vector*b);
double Lenghs(vector* a);

void Output(vector* a);
void Input(vector* a);