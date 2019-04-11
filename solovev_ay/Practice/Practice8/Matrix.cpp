#include "Matrix.h"
#include <iostream>
using namespace std;
Matrix::Matrix()
{
	runs = 0;
	colc = 0;
	m = nullptr;
}
Matrix::Matrix(const Matrix &rofl)
{
	runs = rofl.runs;
	colc = rofl.colc;
	unsigned elements = runs * colc;
	m = new double[elements];
	for (unsigned i = 0; i < elements; i++)
		m[i] = rofl.m[i];
}
Matrix::Matrix(int a, int b)
{
	runs = a;
	colc = b;
	m = new double[runs*colc];
	for (int i = 0; i < (runs*colc); i++)
	{
		m[i] = 0;
	}
}
Matrix::Matrix(double * am, int a, int b)
{
	runs = a;
	colc = b;
	m = new double[runs*colc];
	for (int i = 0; i < (a*b); i++)
	{
		m[i] = am[i];
	}
}
Matrix::~Matrix()
{
	runs = 0;
	colc = 0;
	delete[] m;
}
Matrix  Matrix::operator+(const Matrix & a)
{
	if ((runs != a.runs) || (colc != a.colc))
		throw exeption(Badparametrs);
	Matrix result(runs, colc);
	unsigned elements = runs * colc;
	for (unsigned i = 0; i < elements; i++)
		result.m[i] = m[i] + a.m[i];
	return result;
}
Matrix Matrix::operator+(double k)
{
	if ((runs == 0) || (colc == 0))
		return Matrix();
	Matrix result(runs, colc);
	for (int i = 0; i < (runs*colc); i++)
	{
		result.m[i] = m[i] + k;
	}
	return result;
}
Matrix  Matrix::operator-(const Matrix & a)
{
	if ((runs != a.runs) || (colc != a.colc))
		throw exeption(Badparametrs);
	Matrix result(runs, colc);
	unsigned elements = runs * colc;
	for (unsigned i = 0; i < elements; i++)
		result.m[i] = m[i] - a.m[i];
	return result;
}
Matrix Matrix::operator-(double k)
{
	if (!runs || !colc)
		return Matrix();
	Matrix result(runs, colc);
	for (int i = 0; i < (runs*colc); i++)
	{
		result.m[i] = m[i] - k;
	}
	return result;
}
Matrix Matrix::operator*(const Matrix& _m)
{
	if ((runs != _m.colc) || (colc != _m.runs))
		throw exeption(Badparametrs);
	Matrix result(runs, _m.colc);
	for (unsigned i = 0; i < runs; i++)
		for (unsigned j = 0; j < colc; j++)
			for (unsigned k = 0; k < result.colc; k++)
				result.m[i * colc + j] += m[i * result.colc + k] * _m.m[k * _m.colc + j];
	return result;
}
const Matrix& Matrix::operator=(const Matrix& _m)
{
	if ((runs == _m.runs) && (colc == _m.colc) && (m == _m.m))
		return *this;
	if (runs ^ _m.runs ^ colc ^ _m.colc)
		delete[] m;
	runs = _m.runs;
	colc = _m.colc;
	int elements = runs * colc;
	m = new double[elements];
	for (unsigned i = 0; i < elements; i++)
		m[i] = _m.m[i];
	return *this;
}
Matrix Matrix::operator*(double k)
{
	if ((runs == 0) || (colc == 0))
		return Matrix();
	Matrix result(runs, colc);
	for (int i = 0; i < (runs*colc); i++)
	{
		result.m[i] = m[i] * k;
	}
	return result;
}
const double Matrix::operator[](int a) const
{
	if (a > (colc*runs))
		throw exeption(BadIndex);
	return m[a * colc + 1];
}
void Matrix::PrintMatrix()
{
	int kek = 0;
	double count=m[0];
	for (int i = 0; i < runs*colc; i++)
	{
		if (m[i] > count)
			count = m[i];
	}
	if (count < 10)
	{
		for (int i = 0; i < (runs*colc); i++)
		{
			cout << m[i] << " ";
			kek++;
			if (kek == runs)
			{
				cout << endl;
				kek = 0;
			}
		}
	}
	if ((count >10)&&(count<100))
	{
		for (int i = 0; i < (runs*colc); i++)
		{
			cout << m[i] << "  ";
			kek++;
			if (kek == runs)
			{
				cout << endl;
				kek = 0;
			}
		}
	}
	if ((count > 100) && (count < 1000))
	{
		for (int i = 0; i < (runs*colc); i++)
		{
			cout << m[i] << "   ";
			kek++;
			if (kek == runs)
			{
				cout << endl;
				kek = 0;
			}
		}
	}
}
double& Matrix::operator[](unsigned index)
{
	return m[index * colc + 1];
}
void Matrix::Inputmatrix()
{
	cout << "vvedi kolvo strok ";
	cin >> runs;
	cout << "vvedi kolvo stolbcov: ";
	cin >> colc;
	*this = Matrix(runs, colc);
	unsigned elements = runs * colc;
	cout << "vvedi elementi matrix ";
	for (unsigned i = 0; i < elements; i++)
	{
		cin >> m[i];
	}
}