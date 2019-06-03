#include "Matrix.h"
#include <cstring>
using namespace std;

//Выделение памяти
Matrix::Matrix(int _rows, int _cols)
{

	rows = _rows;
	cols = _cols;
	m = new double[rows * cols];
    memset(m, 0, rows * cols * sizeof(double));
}

//Копирование 
Matrix::Matrix(const Matrix& x)
{
	rows = x.rows;
	cols = x.cols;
	m = new double[rows * cols];
    memcpy(m, x.m, rows * cols * sizeof(double));
}

//Деструктор
Matrix::~Matrix()
{
	rows = 0;
	cols = 0;
	if (m != nullptr)
		delete[] m;
}

Matrix Matrix::operator+(const Matrix&_m)
{
	if ((rows != _m.rows) || (cols != _m.cols))
	{
		throw Matrix1();
	}
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.m[i * cols + j] = m[i * cols + j] + _m.m[i * cols + j];
	return result;
}

Matrix Matrix::operator+(double x)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.m[i * cols + j] = m[i * cols + j] + x;
	return result;
}

Matrix Matrix::operator-(const Matrix&_m)
{
	if ((rows != _m.rows) || (cols != _m.cols))
	{
		throw Matrix1();
	}
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.m[i * cols + j] = m[i * cols + j] - _m.m[i * cols + j];
	return result;
}
Matrix Matrix::operator-(double x)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.m[i * cols + j] = m[i * cols + j] - x;
	return result;
}

Matrix Matrix::operator*(const Matrix&_m)
{
	if ((rows != _m.cols) || (cols != _m.rows))
        throw Matrix1();
	Matrix result(rows, _m.cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < _m.cols; j++)
			for (int k = 0; k < cols; k++)
			result.m[i * _m.cols + j] += m[i * cols + k] * _m.m[k * _m.cols + j];
	return result;
}

Matrix Matrix::operator*(double x)
{
	Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.m[i * cols + j] = m[i * cols + j] * x;
    return result;
}

const double* Matrix::operator[](int _i) const
{
	if ((_i < 0) || (_i > rows * cols))
		throw Matrix2();
	return(m + cols * _i);
}


bool Matrix::operator==(const Matrix& x) const
{
	if ((rows != x.rows) || (cols != x.cols))
		return false;
	for (int i = 0; i < rows * cols; i++)
		if (m[i] != x.m[i])
			return false;
	return true;
}

ostream & operator<<(ostream & o, const Matrix & x)
{
	for (int i = 0; i < x.rows; i++)
		for (int j = 0; j < x.cols; j++)
		o << x.m[i * x.cols + j] << " ";
	return o;
};

istream & operator>>(istream & o, const Matrix & x)
{
    for (int i = 0; i <x.rows * x.cols; i++)
        o >> x.m[i];
    return o;
};

const char* Matrix1::what() const
{
    return what_str.c_str();
}

const char* Matrix2::what() const
{
    return what_str.c_str();
}