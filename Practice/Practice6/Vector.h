#pragma once

typedef struct
{
    int dim;      //размернось пространства, в котором задан вектор
    double *x;    //координаты вектора
} Vector;

void Create(int *d, Vector **v);
void Fill(Vector **v);
void Print(Vector *v);
void Delete(Vector *v);
Vector* Add(Vector *v1, Vector *v2);
Vector* Difference(Vector *v1, Vector *v2);
double ScalarProduct(Vector *v1, Vector *v2);
double Lenght(Vector *v);
double Аngle(Vector *v1, Vector *v2);
int Check(Vector *v1, Vector *v2);
