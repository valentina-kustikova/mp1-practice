#include "Header.h"
#include <iostream>
using namespace std;
Vector::Vector(int _n)
{
	int i;
	n = _n;
	elements = new int[_n];
	for (i = 0; i < _n; i++)
		elements[i] = 0;
}
Vector::Vector(int _n, int* _elements)
{
	int i;
	n = _n;
	elements = new int[_n];
	for (i = 0; i < _n; i++)
	{
		elements[i] = _elements[i];
	}
}
Vector::Vector(const Vector &a)
{
	int i;
	n = a.n;
	elements = new int[a.n];
	for (i = 0; i < a.n; i++)
	{
		elements[i] = a.elements[i];
	}
}
Vector::~Vector()
{
	n = 0;
	delete(elements);
}
double Vector::Length(Vector a)
{
	double length, len = 0;
	for (int i = 0; i < a.n; i++)
		len += a.elements[i] * a.elements[i];
	length = sqrt(len);
	return length;
}
Vector& Vector::operator=(const Vector& a)
{
	n = a.n;
	elements = new int[n];
	for (int i = 0; i < n; i++)
		elements[i] = a.elements[i];
	return *this;
}
Vector Vector::operator+(const Vector & a)
{
	Vector b(a.n);
	for (int i = 0; i < a.n; i++)
		b.elements[i] = elements[i] + a.elements[i];
	return b;
};
Vector Vector::operator-(const Vector &a)
{
	Vector b(a.n);
	for (int i = 0; i < a.n; i++)
		b.elements[i] = elements[i] - a.elements[i];
	return b;
}
Vector Vector::operator*(int a)
{
	Vector b(n);
	for (int i = 0; i < n; i++)
		b.elements[i] = elements[i] * a;
	return b;
}
Vector Vector::operator+(int a)
{
	Vector b(n);
	for (int i = 0; i < n; i++)
		b.elements[i] = elements[i] + a;
	return b;
}
Vector Vector::operator-(int a)
{
	Vector b(n);
	for (int i = 0; i < n; i++)
		b.elements[i] = elements[i] - a;
	return b;
}
bool Vector::operator==(const Vector& a)
{
	for (int i = 0; i < n; i++)
		if ((elements[i] == a.elements[i]) && (n == a.n))
			return true;
		else
			return false;
}
bool Vector::operator!=(const Vector& a)
{
	for (int i = 0; i < n; i++)
		if ((elements[i] == a.elements[i]) && (n == a.n))
			return false;
		else
			return true;
}
bool Vector::operator>(const Vector& a)
{
	return(Length(*this) > Length(a));
}
bool Vector::operator<(const Vector& a)
{
	return(Length(*this) < Length(a));
}
void* Vector::operatornew(size_t n)
{
	void* tmp = malloc(n);
	return tmp;
}
void Vector::operatordelete(void* n)
{
	free(n);
}
int& Vector::operator[](int size)
{
		return elements[size];
}
ostream& operator<< (ostream& o, const Vector& a)
{
	for (int i = 0; i < a.n; i++)
		o << a.elements[i];
	return o;
}