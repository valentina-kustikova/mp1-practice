#pragma once
#include <iostream>
using namespace std;
enum exeption_type { BadLength, BadIndex };

class Vector {
	int size;
	double* elements;
public:
	Vector();//po umolch
	Vector(Vector& tmp);//copy
	Vector(int _size);
	Vector(int n, double*array);
	~Vector();//destr
	const Vector& operator=(const Vector&x);
	Vector operator+(double k);
	double & operator[](int index);
	const Vector& operator*(double k);
	const Vector& operator*(const Vector&x);//umnozheniye peregr
	const Vector& operator+(const Vector&x);//peregruzhen +
	const Vector& operator=(double k);
	bool operator>(const Vector&x)const;
	bool operator>(const double k)const;
	bool operator<(const Vector & x)const;
	bool operator<(const double k)const;
	bool operator>=(const double k)const;
	bool operator>=(const Vector & x)const;
	bool operator<=(const double k)const;
	bool operator<=(const Vector& x)const;
	Vector operator-(double k);//peregruzhen -
	Vector operator-(const Vector & x);
	double Skalyar(const Vector& b);
	const double Length();//length
	void operator+=(double k);
	void operator-=(double k);
	void operator*=(int k);
	void operator*=(Vector& a);
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
