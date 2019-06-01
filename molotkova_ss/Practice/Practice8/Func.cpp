#pragma once
#include <iostream>
#include "Header_Matrix.h"
using namespace std;

Matrix::Matrix()
{
	rows = 0; 
	cols = 0; 
	matrix = NULL;
}
Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	matrix = new double[rows*cols];
}
Matrix::Matrix(const Matrix& mtrx)
{
	rows = mtrx.rows;
	cols = mtrx.cols;
	matrix = new double [rows * cols];
	for (int i = 0; i < (rows * cols); i++)
		matrix[i] = mtrx.matrix[i];
}
Matrix::Matrix(double *mtrx, int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	matrix = new double [rows * cols];
	for (int i = 0; i < (rows * cols); i++)
		matrix[i] = mtrx[i];
}
//destructor
Matrix::~Matrix()
{
	delete[]matrix;
	rows = 0;
	cols = 0;
}
//fuctions
Matrix Matrix::operator+(const Matrix& mtrx) const
{
	if ((mtrx.rows != rows) || (mtrx.cols != cols))
		throw "Different dimension of matrixes";
	Matrix resMatrix(*this);
	for (int i = 0; i < (rows * cols); i++)
		resMatrix.matrix[i] += mtrx.matrix[i];
	return resMatrix;
}
Matrix Matrix::operator+(double a) const
{
	Matrix resMatrix(*this);
	for (int i = 0; i < (rows * cols); i++)
		resMatrix.matrix[i] += a;
	return resMatrix;
}

Matrix Matrix::operator-(const Matrix& mtrx) const
{
	if ((mtrx.rows != rows) || (mtrx.cols != cols))
		throw "Different dimension of matrixes";
	Matrix resMatrix(*this);
	for (int i = 0; i < (rows * cols); i++)
		resMatrix.matrix[i] -= mtrx.matrix[i];
	return resMatrix;
}
Matrix Matrix::operator-(double a) const
{
	Matrix resMatrix(*this);
	for (int i = 0; i < (rows * cols); i++)
		resMatrix.matrix[i] -= a;
	return resMatrix;
}

Matrix Matrix::operator*(const Matrix& mtrx) const
{
	if ( cols != mtrx.rows)
		throw "Inappropriate matrix sizes";
	Matrix resMatrix(rows, mtrx.cols);
	for(int i = 0; i < rows; i++)
		for (int j = 0; j < mtrx.cols; j++)
			for (int k = 0; k < cols; k++)
				resMatrix.matrix[i * mtrx.cols + j] += matrix[i * cols + k] * mtrx.matrix[k * mtrx.cols + i];
	return resMatrix;
}
Matrix Matrix::operator*(double a) const
{
	Matrix resMatrix(*this);
	for (int i = 0; i < (rows * cols); i++)
		resMatrix.matrix[i] *= a;
	return resMatrix;
}
double* Matrix::operator[](int number_of_row) const
{
	if ((number_of_row < 0) || (number_of_row >= rows))
		throw "That row doesn't exist";
	return &(matrix[number_of_row * cols]);

}
Matrix& Matrix::operator=(const Matrix& mtrx)
{
	if (*this == mtrx)
		return *this;
	this->cols = mtrx.cols;
	this->rows = mtrx.rows;
	for (int i = 0; i < (rows * cols); i++)
		this->matrix[i] = mtrx.matrix[i];
	return *this;
}
bool Matrix::operator==(const Matrix& mtrx)const
{
	if ((cols != mtrx.cols) || (rows != mtrx.rows))
		return false;
	for(int i = 0; i < (rows * cols); i++)
		if (this->matrix[i] != mtrx.matrix[i])
		{return false;}
	return true;			
}
void Matrix::Output()const
{
	if ((cols == 0) || (rows == 0))
		throw "Matrix is empty";
	for(int i = 0; i < (rows * cols); i++)
	{
			cout << matrix[i] << " ";
			if ( i%rows == 0)
				cout << endl;
	}
}
void Matrix :: Input()const
{
	for (int i = 0; i < (cols * rows); i++)
        cin >> matrix[i];
}