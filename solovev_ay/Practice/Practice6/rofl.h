#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct
{
	int n;
	int* elements;
} VECTOR;
void Output(VECTOR a);
VECTOR  input(int _n);
VECTOR Sum(VECTOR a, VECTOR b);
VECTOR roflan(VECTOR a, VECTOR b);//-
void skalyar(VECTOR a, VECTOR b);
void length(VECTOR a);
void corner(VECTOR a, VECTOR b);
int Delete(VECTOR a);