#pragma once

typedef struct
{
    int n;
    double *x;
}Vector;

Vector* Cre(int _n);
void DeleteAll(Vector *v);
Vector* Sum(Vector *v1, Vector *v2);
Vector* Diff(Vector *v1, Vector *v2);
double Len(Vector *v);
double Skal(Vector *v1, Vector *v2);
double Angle(Vector *v1, Vector *v2);

void Print(Vector *v);
Vector* Fill(Vector *v);