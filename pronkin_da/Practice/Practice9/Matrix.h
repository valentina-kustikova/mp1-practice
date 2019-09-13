#pragma once
#include <iostream>

using namespace std;

class Matrix {
	double *m;
	int rows, cols;
public:
	Matrix();
	Matrix(int, int);
	Matrix(double*, int, int);
	Matrix(const Matrix&);
	~Matrix();
	Matrix operator+(const Matrix&);
	Matrix operator+(double);
	Matrix operator-(const Matrix&);
	Matrix operator-(double);
	Matrix operator*(const Matrix&);
	Matrix operator*(double);
	const Matrix operator=(const Matrix&);
	const double* operator[](int) const;
	friend ostream& operator<<(ostream&, const Matrix&);
};
