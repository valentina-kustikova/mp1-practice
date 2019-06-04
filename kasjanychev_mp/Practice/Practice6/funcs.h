#pragma once

typedef struct 
{
    int a;//размерность вектора
    double* vec;
} Vector;

Vector* create(int n);
void del(Vector* v);
Vector* sum(Vector* v1, Vector* v2);
Vector* sub(Vector* v1, Vector* v2);
double length(Vector* v);
double multi(Vector* v1, Vector* v2);
double corner(Vector* v1, Vector* v2);

void vivod(Vector* v);
void vvod(Vector* v);