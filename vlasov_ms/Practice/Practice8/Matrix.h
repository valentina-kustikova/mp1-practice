#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>

class Matrix
{
	unsigned rows;
	unsigned cols;
	double *m;
public:
	Matrix();
	Matrix(const Matrix&);
	Matrix(unsigned, unsigned);
	Matrix(double*, unsigned, unsigned);
	~Matrix();

	void output();
	void input();

	const Matrix& operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator+(double);
	Matrix operator-(const Matrix&);
	Matrix operator-(double);
	Matrix operator*(const Matrix&);
	Matrix operator*(double);
	
	double& operator[](int);
	const double& operator[](int) const;
};

class MatrixUnequalSizes {};
class MatrixProductionUndefined {};

#endif