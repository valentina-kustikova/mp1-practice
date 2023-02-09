#ifndef _VECTOR_H
#define _VECTOR_H

typedef struct
{
    float* x;
    int n;
} TVector;

void allocate_vector(TVector** vector, int n);
void free_vector(TVector** vector);

void fill_vector(TVector* vector);
void print_vector(TVector* vector);

TVector* add_vector(TVector* vector1, TVector* vector2);
TVector* add_const(TVector* vector, float c);
float multi_vector(TVector* vector1, TVector* vector2);
TVector* multi_const(TVector* vector, float c);

#endif
