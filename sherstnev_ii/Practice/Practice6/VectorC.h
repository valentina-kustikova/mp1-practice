#pragma once

typedef struct Vector {
	int size;
	double *elements;
}Vector;

void Create(int n, Vector *v);
void Delete(Vector *v);
int Sum(Vector *v1, Vector *v2, Vector *vres);
int Sub(Vector *v1, Vector *v2, Vector *vres);
int Scalar(Vector *v1, Vector *v2, double *s);
int Angle(Vector *v1, Vector *v2, double *s);
double Length(Vector *v);
void Input(Vector *v);
void Output(Vector *v);