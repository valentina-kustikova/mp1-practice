#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include <exception>
using namespace std;
class Matrix
{
private:
    float *elements;
    int rows, cols;
public:
    Matrix(int, int);
    Matrix(const Matrix&);
    Matrix(float*, int, int);
    ~Matrix();

    void Output();
    const Matrix& operator=(Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator+(int);
    Matrix operator-(const Matrix&);
    Matrix operator-(int);
    Matrix operator*(const Matrix&);
    Matrix operator*(int);
    const float*& operator[](int) const;

    friend ostream& operator<<(ostream &, const Matrix &);
};

//Exceptions
class Exception_sizes : exception
{
private:
    const string mes;
public:
    Exception_sizes(string e)
        : mes(e)
    {
    }
    const char* what() const { return mes.c_str(); }
};

class Exception_ind : exception
{
private:
    const string mes;
public:
    Exception_ind(string e)
        : mes(e)
    {
    }
    const char* what() const { return mes.c_str(); }
};
#endif