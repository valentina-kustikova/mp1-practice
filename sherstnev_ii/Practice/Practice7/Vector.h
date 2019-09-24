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
	void PrintVector(int)const;
	double Length()const;
	double Angle(Vector&)const;
	void Gen();

	//Перегрузки
	Vector operator + (const Vector&);
	Vector operator - (const Vector&);
	Vector operator * (double);
	double operator * (const Vector&);
	const Vector& operator = (const Vector&);
	double operator [] (const int) const;
	double& operator [] (const int);
	Vector& operator += (const Vector&);
	Vector& operator -= (const Vector&);
	friend ostream& operator << (ostream&, const Vector&);
};
