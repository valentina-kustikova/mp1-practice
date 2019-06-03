#include "Vector.h"
#include <cstring>
using namespace std;

//Выделение памяти
Vector::Vector(int n)
{

	size = n;
	elements = new double[size];
    memset(elements, 0, size * sizeof(double));
}

//Копирование 
Vector::Vector(const Vector& x)
{
	size = x.size;
	elements = new double[size];
    memcpy(elements, x.elements, size * sizeof(double));
}

//Деструктор
Vector::~Vector()
{
	size = 0;
	if (elements != nullptr)
		delete[] elements;
}

bool Vector::operator==(const Vector& x) const
{
	if (size != x.size)
		return false;
	for (int i = 0; i < size; i++)
		if (elements[i] != x.elements[i])
			return false;
	return true;
}

Vector Vector::operator+(const Vector& x)
{
	if (size != x.size)
		throw Vector1();

	Vector x1(size);
	for (int i = 0; i < size; i++)
		x1.elements[i] = x.elements[i] + elements[i];
	return x1;
}

Vector Vector::operator-(const Vector& x)
{
	if (size != x.size)
		throw Vector1();

	Vector x1(size);
	for (int i = 0; i < size; i++)
		x1.elements[i] = elements[i] - x.elements[i];
	return x1;
}

const Vector& Vector::operator=(const Vector& x)
{
	if (*this == x)
		return x;
	if (size != x.size)
	{
		delete[] elements;
		size = x.size;
		elements = new double[size];
	}
    memcpy(elements, x.elements, size * sizeof(double));
	return *this;
}

ostream & operator<<(ostream & o, const Vector & x)
{
	for (int i = 0; i < x.size; i++)
		o << x.elements[i] << " " ;
	return o;
};

istream & operator>>(istream & o, const Vector & x)
{
    for (int i = 0; i < x.size; i++)
        o >> x.elements[i];
    return o;
};

Vector Vector::operator+(double a)
{
	Vector x1(*this);
	for (int i = 0; i < size; i++)
		x1.elements[i] += a;
	return x1;
}

Vector Vector::operator-(double a)
{
	Vector x1(*this);
	for (int i = 0; i < size; i++)
		x1.elements[i] -= a;
	return x1;
}

Vector Vector::operator*(double a)
{
	Vector x1(size);
	for (int i = 0; i < size; i++)
		x1.elements[i] = elements[i] * a;
	return x1;
}

double Vector :: operator*(const Vector & x) const
{
    if (size != x.size)
        throw Vector1();
    double Sc = 0;
    for (int i = 0; i < size; i++)
        Sc += (elements[i] * x.elements[i]);
    return Sc;
};

double& Vector::operator[](int a)
{
	if ((a < 0) || (a > size))
		throw Vector2();
	else
		return elements[a];
}

const double& Vector::operator[](int a) const
{
    if ((a < 0) || (a > size))
        throw Vector2();
    else
        return elements[a];
}

Vector& Vector::operator+=(const double a)
{
	*this = *this + a;
	return *this;
}

Vector& Vector::operator-=(const double a)
{
	*this = *this - a;
	return *this;
}

Vector& Vector::operator+=(const Vector & x)
{
	*this = *this + x;
	return *this;
}

Vector& Vector::operator-=(const Vector & x)
{
	*this = *this - x;
	return *this;
}

double Vector::Lenght(const Vector & x) const
{
	float l = 0;
	int i;
	for (i = 0; i < x.size; i++)
		l += (x.elements[i] * x.elements[i]);
	l = sqrt(l);
	return l;
}

const char* Vector1::what() const
{
    return what_str.c_str();
}

const char* Vector2::what() const
{
    return what_str.c_str();
}