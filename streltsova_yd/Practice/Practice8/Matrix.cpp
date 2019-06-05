#include "Matrix.h"
#include <iostream>
#include <cstring>
using namespace std;
Matrix::Matrix(int _rows, int _columns)
{
    rows = _rows;
    columns = _columns;
    m = new double[rows * columns];
    memset(m, 0, sizeof(double) * rows * columns);
};
Matrix::Matrix(double* _m, int _rows, int _columns)
{
    rows = _rows;
    columns = _columns;
    m = new double[rows * columns];
    memcpy(m, _m, sizeof(double) * rows * columns);
};
Matrix::Matrix(const Matrix & a)
{
    rows = a.rows;
    columns = a.columns;
    m = new double[rows * columns];
    memcpy(m, a.m, sizeof(double) * rows * columns);
};
Matrix :: ~Matrix()
{
    delete[] m;
    rows = 0;
    columns = 0;
};
Matrix Matrix ::operator+(const Matrix & a) const
{
    if ((rows != a.rows) || (columns != a.columns))
        throw "Error: different dimension of matrices";
    Matrix b(rows, columns);
    for (int i = 0; i < rows * columns; i++)
        b.m[i] = m[i] + a.m[i];
    return b;
};
Matrix Matrix :: operator-(const Matrix & a) const
{
    if ((rows != a.rows) || (columns != a.columns))
        throw "Error: different dimension of matrices";
    Matrix b(rows, columns);
    for (int i = 0; i < rows * columns; i++)
        b.m[i] = m[i] - a.m[i];
    return b;
};
Matrix Matrix :: operator*(const Matrix & a) const
{
    if (columns != a.rows)
        throw "Error: different dimension of matrices";
    Matrix b(rows, a.columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < a.columns; j++)
            for (int k = 0; k < columns; k++)
                b.m[i * a.columns + j] += m[i * columns + k] * a.m[k * a.columns + j];
    return b;
};
Matrix Matrix :: operator+(double a) const
{
    Matrix b(rows, columns);
    for (int i = 0; i < rows * columns; i++)
        b.m[i] = m[i] + a;
    return b;
};
Matrix Matrix :: operator-(double a) const
{
    Matrix b(rows, columns);
    for (int i = 0; i < rows * columns; i++)
        b.m[i] = m[i] - a;
    return b;
};
Matrix Matrix :: operator*(double a) const
{
    Matrix b(rows, columns);
    for (int i = 0; i < rows * columns; i++)
        b.m[i] = m[i] * a;
    return b;
};
const double* Matrix :: operator[](int i) const
{
    if ((i < 0) || (i >= rows))
        throw "Error: no row";
    return &(m[i * columns]);
};
const Matrix& Matrix :: operator=(const Matrix & a)
{
    if (this == &a)
    {
        return *this;
    }
    delete[] m;
    rows = a.rows;
    columns = a.columns;
    m = new double[rows * columns];
    memcpy(m, a.m, sizeof(double) * rows * columns);
    return *this;
};
ostream& operator<< (ostream& out, const Matrix& a)
{
    if ((a.rows == 0) || (a.columns == 0))
        throw "Error: empty matrix";
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.columns; j++)
            out << a.m[i * a.columns + j] << " ";
        cout << endl;
    }
    cout << endl;
};
istream& operator>> (istream& in, Matrix& a)
{
    if ((a.rows == 0) || (a.columns == 0))
        throw "Error: empty matrix";
    for (int i = 0; i < a.rows * a.columns; i++)
        in >> a.m[i];
    cout << endl;
};