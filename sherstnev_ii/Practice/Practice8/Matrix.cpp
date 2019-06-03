#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

Matrix::Matrix() 
{
	rows = 0;
	cols = 0;
	elements = nullptr;
}

Matrix::Matrix(int r, int c)
{
	rows = r;
	cols = c;
	elements = new double[r * c];
	for (int i = 0; i < r * c; i++) {
		elements[i] = 0.0;
	}
}

Matrix::Matrix(const Matrix& M)
{
	rows = M.rows;
	cols = M.cols;
	elements = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++) {
		elements[i] = M.elements[i];
	}
}

Matrix::Matrix(int r, int c, double* d)
{
	rows = r;
	cols = c;
	elements = new double[r * c];
	for (int i = 0; i < r * c; i++) {
		elements[i] = d[i];
	}
}

Matrix::~Matrix()
{
	rows = 0;
	cols = 0;
	delete[] elements;
}

void Matrix::Gen() 
{
	double min = 1.0, max = 30.0;
	static const double fr = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	for (int i = 0; i < rows * cols; i++)
	{
		elements[i] = static_cast<double>(rand() * fr * (max - min + 1) + min);
	}
}

void Matrix::Print() 
{
	if (rows == 0 || cols == 0) cout << "Matrix is empty" << endl;
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << (int)elements[i * rows + j] << " ";
			}
			cout << endl;
		}
	}
}

//Перегрузки

Matrix Matrix::operator +(const Matrix& M) {
	if (rows != M.rows || cols != M.cols) throw (string)"Different dimension";
	Matrix res(rows, cols);
	for (int i = 0; i < rows*cols; i++) {
		res.elements[i] = elements[i] + M.elements[i];
	}
	return res;
}

Matrix Matrix::operator +(double d) {
	if (rows == 0 || cols == 0) throw (string)"Emprty matrix";
	Matrix res(rows, cols);
	for (int i = 0; i < rows*cols; i++) {
		res.elements[i] = elements[i] + d;
	}
	return res;
}

Matrix Matrix::operator -(const Matrix& M) {
	if (rows != M.rows || cols != M.cols)
	{
		throw (string)"Different dimension";
	}
	Matrix res(rows, cols);
	for (int i = 0; i < rows*cols; i++) {
		res.elements[i] = elements[i] - M.elements[i];
	}
	return res;
}

Matrix Matrix::operator -(double d) {
	Matrix res(rows, cols);
	for (int i = 0; i < rows*cols; i++) {
		res.elements[i] = elements[i] - d;
	}
	return res;
}

Matrix Matrix::operator *(const Matrix& M) {
	if (cols != M.rows)
	{
		throw (string)"Matrixes are not available to multiply";
	}
	Matrix res(rows, M.cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			for (int k = 0; k < res.cols; k++)
				res.elements[i * cols + j] += elements[i * res.cols + k] * M.elements[k * M.cols + j];
	return res;
}

Matrix Matrix::operator *(double d) {
	Matrix res(rows, cols);
	for (int i = 0; i < rows*cols; i++) {
		res.elements[i] = elements[i] * d;
	}
	return res;
}

Matrix Matrix::operator =(const Matrix& M) {
	rows = M.rows;
	cols = M.cols;
	delete[]elements;
	elements = new double[rows * cols];
	for (int i = 0; i < rows*cols; i++) {
		elements[i] = M.elements[i];
	}
	return *this;
}

double* Matrix::operator [](int r) {
	if (r < 0 || r >= rows) {
		throw "Wrong element";
	}
	return &elements[r * cols];
}