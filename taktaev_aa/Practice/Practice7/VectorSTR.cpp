#include "VectorSTR.h"
Vector::Vector()
{
	n = 0;
	mas = nullptr;
}
Vector::Vector(int _n)
{
	n = _n;
	mas = new double[_n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = 0;
	}
}
Vector::Vector(const Vector& x)
{
	n = x.n;
	mas = new double[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = x.mas[i];
	}
}
Vector::~Vector()
{
	delete[]mas;
}
Vector Vector::operator+(const Vector& x)
{
	if (n != x.n) throw "Dimension ERROR +";
	Vector rez(n);
	for (int i = 0; i < n; i++)
	{
		rez.mas[i] = mas[i] + x.mas[i];
	}
	return rez;
}
Vector Vector::operator-(const Vector& x)
{
	if (n != x.n) throw "Dimension ERROR -";
	Vector rez(n);
	for (int i = 0; i < n; i++)
	{
		rez.mas[i] = mas[i] - x.mas[i];
	}
	return rez;
}
double Vector::operator*(const Vector& x)
{
	if (n != x.n) throw "Dimension ERROR *";
	double rez = 0;
	for (int i = 0; i < n; i++)
	{
		rez = rez + mas[i] * x.mas[i];
	}
	return rez;
}
Vector Vector::operator+(double k)
{
	Vector rez(n);
	for (int i = 0; i < n; i++)
	{
		rez.mas[i] = mas[i] + k;
	}
	return rez;
}
Vector Vector::operator-(double k)
{
	Vector rez(n);
	for (int i = 0; i < n; i++)
	{
		rez.mas[i] = mas[i] - k;
	}
	return rez;
}
Vector Vector::operator*(double k) 
{
	Vector rez(n);
	for (int i = 0; i < n; i++)
	{
		rez.mas[i] = mas[i] * k;
	}
	return rez;
}
Vector& Vector::operator+=(const Vector& x)
{
	if (n != x.n) throw "Dimension ERROR +=";
	for (int i = 0; i < n; i++)
	{
		mas[i] = mas[i] + x.mas[i];
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& x)
{

	if (n != x.n) throw "Dimension ERROR -=";
	for (int i = 0; i < n; i++)
	{
		mas[i] = mas[i] - x.mas[i];
	}
	return *this;
}
const Vector& Vector::operator=(const Vector& x)
{
	n = x.n;
	delete[] mas;
	mas = new double[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = x.mas[i];
	}
	return *this;
}
double Vector::operator[](int i)
{
	if (!mas) throw "Index ERROR - out of array size";
	return mas[i];
}
double Vector::Vector_Len()
{
	return sqrt((*this) * (*this));
}
void Vector::Output()
{
	std::cout << "(";
    for (int i = 0; i < n - 1; i++)
        std::cout << mas[i] << ", ";
	std::cout << mas[n - 1] << ")" << std::endl;
}