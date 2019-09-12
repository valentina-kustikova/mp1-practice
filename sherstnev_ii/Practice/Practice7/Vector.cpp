#include "Vector.h"
#include <iostream>
#include <math.h>
#include <string>

#define M_PI       3.14159265358979323846

using namespace std;

Vector::Vector()
{
	size = 0;
}

Vector::Vector(Vector& x)
{
	size = x.size;
	elements = new double[size];
	for (int i = 0; i < size; i++)
		elements[i] = x.elements[i];
}

Vector::Vector(int s)
{
	size = s;
	elements = new double[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}


Vector::Vector(int s, double *arr)
{
	if (arr == NULL)
		return;
	size = s;
	elements = new double[size];
	for (int i = 0; i < size; i++)
		elements[i] = arr[i];
}

Vector::~Vector()
{
	size = 0;
	delete[]elements;
}

void Vector::PrintVector(int n)
{
	cout << "Vector " << n << ": ";
	for (int i = 0; i < size; i++) {
		cout << ((double)((int)(elements[i] * 100.0))) / 100.0 << " ";
	}
	cout << endl;
}

double Vector::Length()
{
	if (size == 0) throw (string)"Empty vector";
	int i;
	double res = 0.0;
	for (i = 0; i < size; i++)
	{
		res += elements[i] * elements[i];
	}
	return sqrt(res);
}

double Vector::Angle(Vector& V)
{
	if (size != V.size)
	{
		throw (string)"Different dimension";
	}
	double l1, l2, sc;
	l1 = Length();
	l2 = V.Length();
	sc = *this * V;
	return acos(sc / (l1 * l2)) * 180 / M_PI;
}

void Vector::Gen()
{
	double min = 1.0, max = 30.0;
	static const double fr = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	for (int i = 0; i < size; i++)
	{
		elements[i] = static_cast<double>(rand() * fr * (max - min + 1) + min);
	}
}

//Перегрузки

Vector Vector::operator + (const Vector& V)
{
	if (size != V.size)
	{
		throw (string)"Different dimension";
	}
	Vector v123(size);
	for (int i = 0; i < size; i++)
	{
		v123.elements[i] = elements[i] + V.elements[i];
	}
	return v123;
}

Vector Vector::operator - (const Vector& V)
{
	if (size != V.size)
	{
		throw (string)"Different dimension";
	}
	Vector v123(size);
	for (int i = 0; i < size; i++)
	{
		v123.elements[i] = elements[i] - V.elements[i];
	}
	return v123;
}

Vector Vector::operator * (double n)
{
	if (size == 0) throw (string)"Empty vector";
	Vector v123(size);
	for (int i = 0; i < v123.size; i++) {
		v123.elements[i] = elements[i] * n;
	}
	return v123;
}

double Vector::operator * (const Vector& V)
{
	if (size != V.size)
	{
		throw (string)"Different dimension";
	}
	double sum = 0.0;
	Vector v123(size);
	for (int i = 0; i < size; i++) {
		sum += elements[i] * V.elements[i];
	}
	return sum;
}

double Vector::operator [] (int n)
{
	if ((n < 0) || (n >= size))
	{
		throw (string)"Wrong element";
	}
	return elements[n];
}

Vector Vector::operator = (const Vector& V)
{
	if (size != V.size)
	{
		throw (string)"Different dimension";
	}
	for (int i = 0; i < size; i++) {
		elements[i] = V.elements[i];
	}
	return *this;
}

Vector& Vector::operator += (const Vector& V)
{
	*this = *this + V;
	return *this;
}

Vector& Vector::operator -= (const Vector& V)
{
	*this = *this - V;
	return *this;
}