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
Matrix & Matrix::operator+(const Matrix & a)
{
	if ((runs != a.runs) || (colc != a.colc))
		throw exeption (Badparametrs);
	Matrix result(runs, colc);
	for (int i = 0; i < colc; i++)
	{
		for (int j = 0; j < colc; j++)
		{
			result.m[i*colc + j] = m[i*colc + j] + a.m[i*colc + j];
		}
	}
	return result;
}
Matrix Matrix::operator+(double k)
{
	Matrix result(runs, colc);
	for (int i = 0; i < (runs*colc); i++)
	{
		result.m[i] = m[i] + k;
	}
	return result;
}
Matrix & Matrix::operator-(const Matrix & a)
{
	if ((runs != a.runs) || (colc != a.colc))
		throw exeption(Badparametrs);
	Matrix result(runs, colc);
	for (int i = 0; i < colc; i++)
	{
		for (int j = 0; j < colc; j++)
		{
			result.m[i*colc + j] = m[i*colc + j] - a.m[i*colc + j];
		}
	}
	return result;
}
Matrix Matrix::operator-(double k)
{
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
Matrix Matrix::operator=(const Matrix & a)
{
	if ((runs != a.runs) || (colc != a.colc))
		throw exeption(Badparametrs);
	Matrix result(runs, colc);
	for (int i = 0; i < (runs*colc); i++)
	{
		result.m[i] = a.m[i];
	}
	return result;
}
Matrix Matrix::operator*(double k)
{
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
void Matrix::Inputmatrix()
{
	cout << "Enter number of rows: ";
	cin >> runs;
	cout << "Enter number of cols: ";
	cin >> colc;
	*this = Matrix(runs, colc);
	unsigned elements = runs * colc;
	cout << "Enter values by rows (separating with space): ";
	for (unsigned i = 0; i < elements; i++)
	{
		cin >>m[i];
	}
}
void Matrix::obratmatrix()
{
	double a = 0;
	a = m[0] * m[3] - m[1] * m[2];
	if (a != 0)
	{
		Matrix ab(2, 2);
		ab.m[0] = m[3];
		ab.m[1] = m[2];
		ab.m[2] = m[1];
		ab.m[3] = m[0];
		ab.PrintMatrix();
	}
}