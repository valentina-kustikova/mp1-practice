#pragma once

class Vector
{
	int size;
	double* elements;
public:
	Vector();
	Vector(Vector&);
	Vector(int);
	Vector(int, double*);
	~Vector();
	void PrintVector(int);
	double Length();
	double Angle(Vector&);
	void Gen();

	//Перегрузки
	Vector operator + (const Vector&);
	Vector operator - (const Vector&);
	Vector operator * (double);
	double operator * (const Vector&);
	Vector operator = (const Vector&);
	double operator [] (int);
	Vector& operator += (const Vector&);
	Vector& operator -= (const Vector&);
};
