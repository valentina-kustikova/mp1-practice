#include "Header.h"
Matrix::Matrix()
{
	rows = 3;
	cols = 3;
	m = new double[rows*cols];
	for (int i = 0; i < rows*cols; i++)
		m[i] = 0;
}
Matrix::Matrix(int _rows, int _cols)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows*cols];
	for (int i = 0; i < rows*cols; i++)
		m[i] = 0;
}
Matrix::Matrix(int _rows, int _cols, double* a)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows*cols];
	for (int i = 0; i < rows*cols; i++)
		m[i] = a[i];
}
Matrix::Matrix(const Matrix& a)
{
	rows = a.rows;
	cols = a.cols;
	m = new double[rows*cols];
	for (int i = 0; i < rows*cols; i++)
		m[i] = a.m[i];
}
Matrix::~Matrix()
{
	delete(m);
}
Matrix& Matrix::operator=(const Matrix& a)
{
	if ((rows != a.rows) || (cols != a.cols))
		throw "different size of matrix";
	rows = a.rows;
	cols = a.cols;
	for (int i = 0; i < rows*cols; i++)
		m[i] = a.m[i];
	return *this;
}
Matrix Matrix::operator+(double a)
{
	Matrix result;
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
	Matrix result;
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
	Matrix result;
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
double* Matrix::operator[](int index)
{
	return (m + index * cols);
}