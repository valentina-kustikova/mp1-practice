#pragma once
#include <iostream>
using namespace std;
class Matrix
{
private:
	double* m;
	int rows, cols;
public:
	Matrix(int, int);
	Matrix(int, int, double*);
	Matrix(const Matrix&);
	~Matrix();
	const Matrix& operator=(const Matrix&);
	bool operator==(const Matrix&);
	Matrix operator+(double);
	Matrix operator+(const Matrix&);
	Matrix operator-(double);
	Matrix operator-(const Matrix&);
	Matrix operator*(double);
	Matrix operator*(const Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
	friend istream& operator>>(istream&, const Matrix&);
	double* operator[](int index);
};