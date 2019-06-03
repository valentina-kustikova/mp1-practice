#pragma once
#include <iostream>
#include <math.h>
struct Vector
{
	double* mas;
	int n;
	Vector();
	Vector(int _n);
	Vector(const Vector& x);
	~Vector();
	Vector operator+(const Vector& x);
	Vector operator-(const Vector& x);
	double operator*(const Vector& x);
	Vector operator+(double k);
	Vector operator-(double k);
	Vector operator*(double k);
	Vector& operator+=(const Vector& x);
	Vector& operator-=(const Vector& x);
	const Vector& operator=(const Vector& x);
	double operator[](int i);
	double Vector_Len();
	void Output();
};
