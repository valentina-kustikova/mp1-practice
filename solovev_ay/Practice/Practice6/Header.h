#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct
{
	int n;
	float* elements;
} VECTOR;
void Output(VECTOR a);
VECTOR  input(int _n);
VECTOR Sum(VECTOR a, VECTOR b);
VECTOR roflan(VECTOR a, VECTOR b);//-
int skalyar(VECTOR a, VECTOR b);
float length(VECTOR a);
float corner(VECTOR a, VECTOR b);
int Delete(VECTOR a);
