#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
class Matrix
{
	int cols;
	int rows;
	double* m;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	Matrix operator+(const Matrix&);
	Matrix operator+(double);
	Matrix operator-(const Matrix&);
	Matrix operator-(double);
	Matrix operator*(const Matrix&);
	Matrix operator*(double);
	const double* operator[](int) const;
	double* operator[](int);
	const Matrix& operator=(const Matrix&);
	void Output();
	void Input();
	void RandomInput();
};