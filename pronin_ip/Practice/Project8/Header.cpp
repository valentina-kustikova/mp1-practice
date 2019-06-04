#include "Header.h"
#include <cstring>
Matrix::Matrix(int _rows, int _cols)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows*cols];
	memset(m, 0, rows * cols * sizeof(double));
}
Matrix::Matrix(int _rows, int _cols, double* a)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows*cols];
	memcpy(m, a, rows * cols * sizeof(double));
}
Matrix::Matrix(const Matrix& a)
{
	rows = a.rows;
	cols = a.cols;
	m = new double[rows*cols];
	memcpy(m, a.m, rows * cols * sizeof(double));
}
Matrix::~Matrix()
{
	delete(m);
}
const Matrix& Matrix::operator=(const Matrix& a)
{
	if ((rows != a.rows) || (cols != a.cols))
		throw "different size of matrix";
	if ( *this == a)
		throw "error";
	rows = a.rows;
	cols = a.cols;
	for (int i = 0; i < rows*cols; i++)
		m[i] = a.m[i];
	return *this;
}
bool Matrix::operator==(const Matrix& a)
{
	int flag = 0;
	for (int i = 0; i < rows * cols; i++)
		if (m[i] != a.m[i])
			flag = 1;
	if ((flag == 0) && (rows == a.rows) && (cols == a.cols))
		return 1;
	else return 0;
}
Matrix Matrix::operator+(double a)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows*cols; i++)
		result.m[i] = m[i] + a;
	return result;
}
Matrix Matrix::operator+(const Matrix& a)
{
	if ((rows != a.rows) || (cols != a.cols))
		throw "different size of matrix";
	Matrix result(rows, cols);
	for (int i = 0; i < rows*cols; i++)
		result.m[i] = m[i] + a.m[i];
	return result;
}
Matrix Matrix::operator-(double a)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows*cols; i++)
		result.m[i] = m[i] - a;
	return result;
}
Matrix Matrix::operator-(const Matrix& a)
{
	if ((rows != a.rows) || (cols != a.cols))
		throw "different size of matrix";
	Matrix result(a.rows, a.cols);
	for (int i = 0; i < rows*cols; i++)
		result.m[i] = m[i] - a.m[i];
	return result;
}
Matrix Matrix::operator*(double a)
{
	Matrix result(rows,cols);
	for (int i = 0; i < rows*cols; i++)
		result.m[i] = m[i] * a;
	return result;
}
Matrix Matrix::operator*(const Matrix& a)
{
	if ((rows != a.rows) || (cols != a.cols))
		throw "different size of matrix";
	Matrix result(a.rows, a.cols);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < cols; k++)
				result.m[i*rows + j] += m[i*rows + k] * a.m[k*rows + j];
		}
	}
	return result;
}
ostream& operator<<(ostream& o, const Matrix& a)
{
	for (int i = 0; i < a.rows*a.cols; i++)
	{
		if (i % a.cols == 0)
			cout << endl;
		o << " " << a.m[i];
	}
	return o;
}
istream& operator>>(istream& in, const Matrix& a)
{
	for (int i = 0; i < a.rows*a.cols; i++)
		in >> a.m[i];
	return in;
}
double* Matrix::operator[](int index)
{
	return (m + index * cols);
}