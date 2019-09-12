#pragma once
#include <iostream>
using namespace std;
class Matrix
{
private:
	double* m;
	int rows, cols;
public:
	Matrix();
	Matrix(int, int);
	Matrix(int, int, double*);
	Matrix(const Matrix&);
	~Matrix();
	Matrix& operator=(const Matrix&);
	Matrix operator+(double);
	Matrix operator+(const Matrix&);
	Matrix operator-(double);
	Matrix operator-(const Matrix&);
	Matrix operator*(double);
	Matrix operator*(const Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
	double* operator[](int index);
};