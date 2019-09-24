#pragma once

class Matrix {
	int rows, cols;
	double *elements;

public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix(int, int, double*);
	~Matrix();

	void Gen();
	void Print();

	Matrix operator +(const Matrix&);
	Matrix operator +(double);
	Matrix operator -(const Matrix&);
	Matrix operator -(double);
	Matrix operator *(const Matrix&);
	Matrix operator *(double);
	Matrix operator =(const Matrix&);
	double* operator [](int);
};