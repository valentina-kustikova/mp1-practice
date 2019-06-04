#include "Header.h"
#include <iostream>
using namespace std;
Vector::Vector(int _n)
{
	n = _n;
	elements = new int[_n];
	memset(elements, 0, n * sizeof(int));
}
Vector::Vector(int _n, int* _elements)
{
	n = _n;
	elements = new int[_n];
	memcpy(elements, _elements, n * sizeof(int));
}
Vector::Vector(const Vector &a)
{
	n = a.n;
	elements = new int[a.n];
	memcpy(elements, a.elements, n * sizeof(int));
}
Vector::~Vector()
{
	n = 0;
	delete [] elements;
}
double Vector::Length(const Vector& a) 
{
	double len = 0;
	for (int i = 0; i < n; i++)
		len += a.elements[i] * a.elements[i];
	return sqrt(len);
}
int Vector::Scayler(const Vector& a, const Vector& b) 
{
	int x = 0;
	for (int i = 0; i < a.n; i++)
		x += a.elements[i] * b.elements[i];
	return x;
}
const Vector& Vector::operator=(const Vector& a)
{
	if (*this == a)
		throw "wrong operation";
	n = a.n;
	elements = new int[n];
	for (int i = 0; i < n; i++)
		elements[i] = a.elements[i];
	return *this;
}
Vector Vector::operator+(const Vector & a)
{
	if (n != a.n)
		throw "different size of vectors";
	Vector b(a.n);
	for (int i = 0; i < a.n; i++)
		b.elements[i] = elements[i] + a.elements[i];
	return b;
};
Vector Vector::operator-(const Vector &a)
{
	if (n != a.n)
		throw "different size of vectors";
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
void* Vector::operator new(size_t n)
{
	void* tmp = malloc(n);
	return tmp; 
}
void Vector::operator delete[](void* n)
{
	free(n);
}
int& Vector::operator[](int size)
{
		return elements[size];
}
const int& Vector::operator[](int size) const
{
	return elements[size];
}
ostream& operator<< (ostream& o, const Vector& a)
{
	for (int i = 0; i < a.n; i++)
		o << a.elements[i];
	return o;
}
istream& operator>> (istream& in, const Vector& a)
{
	for (int i = 0; i < a.n; i++)
		in >> a.elements[i];
	return in;
}