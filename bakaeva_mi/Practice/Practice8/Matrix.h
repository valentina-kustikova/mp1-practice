#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "iostream"
using namespace std;
class Matrix
{
private:
    int *elements;
    int rows, cols;
public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix&);
    Matrix(int*, int, int);
    ~Matrix();

    void Output();
    void operator=(Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator+(int);
    Matrix operator-(const Matrix&);
    Matrix operator-(int);
    Matrix operator*(const Matrix&);
    Matrix operator*(int);
    const int* operator[](int) const;

    friend ostream& operator<<(ostream &, const Matrix &);
};
#endif