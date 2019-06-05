#pragma once
#include <iostream>
using namespace std;
enum exeption_type { BadLength, BadIndex };

class Vector {
	int size;
	double* elements;
public:
	Vector();//po umolch
	void Input();//vvod
	Vector(Vector& tmp);//copy
	Vector(int _size);
	Vector(int n, double*array);
	~Vector();//destr
	Vector operator=(const Vector&x);
	Vector operator+(double k);
	double & operator[](int index);
	Vector operator*(double k);
	Vector operator*(const Vector&x);//umnozheniye peregr
	Vector operator+(const Vector&x);//peregruzhen +
	Vector operator=(double k);
	bool operator>(Vector&x);
	bool operator>(double k);
	bool operator<(Vector & x);
	bool operator<(double k);
	bool operator>=(double k);
	bool operator>=(Vector & x);
	bool operator<=(double k);
	bool operator<=(Vector& x);
	Vector operator-(double k);//peregruzhen -
	Vector operator-(const Vector & x);
	void PrintVector();
	double Skalyar(Vector b);
	double Length();//length
	void operator+=(int k);
	void operator-=(int k);
	void operator*=(int k);
	void operator*=(Vector a);
	void Delete();
	friend istream& operator>> (istream&, Vector&); // Ввод
	friend ostream& operator<< (ostream&, const Vector&); // Вывод
	const double& operator[](int) const;
};

struct exeption
{
	exeption_type exp_type;

	exeption(exeption_type type)
	{
		exp_type = type;
	}
};
