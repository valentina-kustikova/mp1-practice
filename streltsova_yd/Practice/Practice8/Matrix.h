#pragma once
#include <iostream>
using namespace std;
class Matrix
{
    int rows, columns;
    double* m;
public:
    Matrix(int rows, int columns);
    Matrix(double* _m, int _rows, int _columns);
    Matrix(const Matrix& a);
    ~Matrix();
    Matrix operator+(const Matrix& a) const;
    Matrix operator-(const Matrix& a) const;
    Matrix operator*(const Matrix& a) const;
    Matrix operator+(double a) const;
    Matrix operator-(double a) const;
    Matrix operator*(double a) const;
    const double* operator[](int i) const;
    const Matrix& operator=(const Matrix& a);
    friend ostream& operator<< (ostream& out, const Matrix& a);
    friend istream& operator>> (istream& in, Matrix& a);
};