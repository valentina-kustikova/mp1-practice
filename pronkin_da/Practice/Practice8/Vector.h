#pragma once
#include <iostream>
using namespace std;

class Vector {
	int n;
	double* x;
public:
	Vector(int);
	Vector(int, double*);
	Vector(const Vector&);
	~Vector();
	double Vlength();
	Vector& operator+(const Vector&);
	Vector& operator-(const Vector&);
	double operator*(const Vector&);
	const Vector& operator=(const Vector&);
	void operator+=(const Vector&);
	void operator-=(const Vector&);
	double& operator[](int);
	Vector& operator*(double);
	void* operator new(size_t);
	void operator delete(void*);
};
