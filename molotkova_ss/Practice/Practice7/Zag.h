#pragma once
#include <iostream>
using namespace std;


	class Vector
{
private:
	int n;
	double *x;

public:
	Vector();
	Vector(int n);
	Vector(const Vector& v);
	~Vector();
	Vector operator- (const Vector& v) const;
	Vector operator+ (const Vector& v) const;
	double operator* (const Vector& v) const;
	Vector operator+ (double a) const;
	Vector operator- (double a) const;
	Vector operator* (double a) const;
	Vector operator= (const Vector& v);
	double* operator[] (int ind) const;
	double Length();
	Vector operator+= (const Vector& v);
	Vector operator-= (const Vector& v);
	Vector operator+= (double a);
	Vector operator-= (double a);
	Vector operator*= (double a);
	void Output();
	void Input();
};