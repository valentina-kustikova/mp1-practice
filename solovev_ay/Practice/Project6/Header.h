#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct
{
	int n;
	int* elements; // float
} VECTOR;
void Output(VECTOR a);
VECTOR  input(int _n);
void sum(VECTOR a, VECTOR b);
void roflan(VECTOR a, VECTOR b);
void skalyar(VECTOR a, VECTOR b);
void length(VECTOR a);
void corner(VECTOR a, VECTOR b);
int Delete(VECTOR a);
