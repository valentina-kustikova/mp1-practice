#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	cols = 0;
	rows = 0;
	arr = NULL;
}
Matrix::Matrix(int x, int y)
{
	arr = new double[x * y];
	cols = x;
	rows = y;
}
Matrix::Matrix(const Matrix& mat)
{
	arr = new double[mat.cols * mat.rows];
	cols = mat.cols;
	rows = mat.rows;
	for (int i = 0; i < mat.cols * mat.rows; i++)
		arr[i] = mat.arr[i];
}
Matrix::~Matrix()
{
	delete arr;
	cols = 0;
	rows = 0;
}

Matrix Matrix::operator+(const Matrix& mat) const
{
	if ((cols != mat.cols) || (rows != mat.rows))
		throw "Size";
	Matrix rez = Matrix(*this);
	for (int i = 0; i < cols * rows; i++)
		rez.arr[i] += mat.arr[i];
	return rez;
}

Matrix Matrix::operator-(const Matrix& mat) const
{
	if ((cols != mat.cols) || (rows != mat.rows))
		throw "Size";
	Matrix rez = Matrix(*this);
	for (int i = 0; i < cols * rows; i++)
		rez.arr[i] -= mat.arr[i];
	return rez;
}

Matrix Matrix::operator*(const Matrix& mat) const
{
	if (cols != mat.rows)
		throw "Size";
	Matrix rez(rows, mat.cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < mat.cols; j++)
			for (int k = 0; k < cols; k++)
				rez.arr[i * mat.cols + j] += arr[i * cols + k] * mat.arr[k * mat.cols + j];
	return rez;
}

Matrix& Matrix::operator+ (double x)
{
	for (int i = 0; i < cols * rows; i++)
		arr[i] += x;
	return *this;
}
Matrix& Matrix::operator- (double x)
{
	for (int i = 0; i < cols * rows; i++)
		arr[i] -= x;
	return *this;
}

Matrix& Matrix::operator* (double x)
{
	for (int i = 0; i < cols * rows; i++)
		arr[i] *= x;
	return *this;
}

double* Matrix::operator[] (int i) const
{
	if ((i < 0) || (i > cols))
		throw "No Cols";
	return &(arr[rows * i]);
}

const Matrix& Matrix::operator=(const Matrix& mat)
{
	delete[] arr;
	rows = mat.rows;
	cols = mat.cols;
	arr = new double[mat.cols * mat.rows];
	for (int i = 0; i < cols * rows; i++)
		arr[i] = mat.arr[i];
	return *this;
}

void Matrix::ScMat()
{
	for (int i = 0; i < rows * cols; i++)
		cin >> arr[i];
}
void Matrix::PrMat()
{
	for (int i = 0; i < rows * cols; i++)
	{	
		if (i % rows == 0)
		cout << endl;
		cout << arr[i] << " ";
	}
}