#include "Matrix.h"

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	m = nullptr;
}

Matrix::Matrix(const Matrix& _m)
{
	rows = _m.rows;
	cols = _m.cols;
	m = new double[rows * cols];
	for (unsigned i = 0; i < _m.rows * _m.cols; i++)
		m[i] = _m.m[i];
}

Matrix::Matrix(unsigned _rows, unsigned _cols)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows * cols];
	for (unsigned i = 0; i < _rows * _cols; i++)
		m[i] = 0;
}

Matrix::Matrix(double* _m, unsigned _rows, unsigned _cols)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows * cols];
	for (unsigned i = 0; i < _rows * _cols; i++)
		m[i] = _m[i];
}

Matrix::~Matrix()
{
	rows = 0;
	cols = 0;
	delete[] m;
}

void Matrix::output()
{
	for (unsigned i = 0; i < rows; i++)
	{
		std::cout << "> ";
		for (unsigned j = 0; j < cols; j++)
			std::cout << m[i * cols + j] << " ";
		std::cout << '\n';
	}
}

void Matrix::input()
{
	std::cout << "Enter number of rows: ";
	std::cin >> rows;
	std::cout << "Enter number of cols: ";
	std::cin >> cols;
	*this = Matrix(rows, cols);
	std::cout << "Enter values by rows (separating with space): ";
	for (unsigned i = 0; i < rows * cols; i++)
	{
		std::cin >> m[i];
	}
}

Matrix Matrix::operator+(const Matrix& _m)
{
	if ((rows != _m.rows) || (cols != _m.cols))
		throw MatrixUnequalSizes();
	Matrix result(rows, cols);
	for (unsigned i = 0; i < rows * cols; i++)
		result.m[i] = m[i] + _m.m[i];
	return result;
}

Matrix Matrix::operator+(double d)
{
	if ((rows == 0) || (cols == 0))
		return Matrix();
	Matrix result(rows, cols);
	for (unsigned i = 0; i < rows * cols; i++)
		result.m[i] = m[i] + d;
	return result;
}

Matrix Matrix::operator-(const Matrix& _m)
{
	if ((rows != _m.rows) || (cols != _m.cols))
		throw MatrixUnequalSizes();
	Matrix result(rows, cols);
	for (unsigned i = 0; i < rows * cols; i++)
		result.m[i] = m[i] - _m.m[i];
	return result;
}

Matrix Matrix::operator-(double d)
{
	if ((rows == 0) || (cols == 0))
		return Matrix();
	Matrix result(rows, cols);
	for (unsigned i = 0; i < rows * cols; i++)
		result.m[i] = m[i] - d;
	return result;
}

Matrix Matrix::operator*(const Matrix& _m)
{
	if ((rows != _m.cols) || (cols != _m.rows))
		throw MatrixProductionUndefined();
	Matrix result(rows, _m.cols);
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			for (unsigned k = 0; k < result.cols; k++)
				result.m[i * cols + j] += m[i * result.cols + k] * _m.m[k * _m.cols + j];
	return result;
}

Matrix Matrix::operator*(double d)
{
	if ((rows == 0) || (cols == 0))
		return Matrix();
	Matrix result(rows, cols);
	for (unsigned i = 0; i < rows * cols; i++)
		result.m[i] = m[i] * d;
	return result;
}

const Matrix& Matrix::operator=(const Matrix& _m)
{
	if ((rows == _m.rows) && (cols == _m.cols) && (m == _m.m))
		return *this;
	if (rows ^ _m.rows ^ cols ^ _m.cols) // сравним все хором
		delete[] m;
	rows = _m.rows;
	cols = _m.cols;
	m = new double[_m.rows * _m.cols];
	for (unsigned i = 0; i < rows * cols; i++)
		m[i] = _m.m[i];
	return *this;
}

double& Matrix::operator[](int index)
{
	return m[index * cols + 1];
}

const double& Matrix::operator[](int index) const
{
	return m[index * cols + 1];
}