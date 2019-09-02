#include "Matrix.h"
#include "iostream"
using namespace std;

Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    elements = new float[rows * cols];
    memset(elements, 0, sizeof(int) * rows * cols);
}

Matrix::Matrix(const Matrix& M1)
{
    rows = M1.rows;
    cols = M1.cols;
    elements = new float[rows * cols];
    memcpy(elements, M1.elements, sizeof(float) * rows * cols);
}

Matrix::Matrix(float* _elements, int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    elements = new float[rows * cols];
    memcpy(elements, _elements, sizeof(float) * rows * cols);
}

Matrix::~Matrix()
{
    rows = 0;
    cols = 0;
    delete[] elements;
}

void Matrix::Output()
{
    for (int i = 0; i < rows; i++)
    {
        cout << "  |  ";
        for (int j = 0; j < cols; j++)
            cout << elements[i * cols + j] << " ";
        cout << " |\n";
    }
    cout << endl;
}

const Matrix& Matrix::operator=(Matrix& tmp)
{
    rows = tmp.rows;
    cols = tmp.cols;
    memcpy(elements, tmp.elements, sizeof(float) * rows * cols);
    return *this;
}

Matrix Matrix::operator+(const Matrix& M1)
{
    if ((rows != M1.rows) || (cols != M1.cols))
        throw Exception_sizes("Vector sizes are not equal!");
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            tmp.elements[i * cols + j] = elements[i * cols + j] + M1.elements[i * cols + j];
    return tmp;
}

Matrix Matrix::operator+(int _c)
{
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            tmp.elements[i * cols + j] = elements[i * cols + j] + _c;
    return tmp;
}

Matrix Matrix::operator-(const Matrix& M1)
{
    if ((rows != M1.rows) || (cols != M1.cols))
        throw Exception_sizes("Vector sizes are not equal!");
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            tmp.elements[i * cols + j] = elements[i * cols + j] - M1.elements[i * cols + j];
    return tmp;
}

Matrix Matrix::operator-(int _c)
{
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            tmp.elements[i * cols + j] = elements[i * cols + j] - _c;
    return tmp;
}

Matrix Matrix::operator*(const Matrix& M1)
{
    if ((rows != M1.cols) || (cols != M1.rows))
        throw Exception_sizes("Vector sizes are not equal!");
    Matrix tmp(rows, M1.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < M1.cols; j++)
            for (int k = 0; k < cols; k++)
                tmp.elements[i * M1.cols + j] +=
                (elements[i * cols + k] * M1.elements[k * M1.cols + j]);
    return tmp;
}

Matrix Matrix::operator*(int _c)
{
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            tmp.elements[i * cols + j] = elements[i * cols + j] * _c;
    return tmp;
}

const float*& Matrix::operator[](int _ind) const
{
    if ((_ind < 0) || (_ind > rows))
        throw Exception_ind("Not correct index!");
    return *(elements + cols * _ind);
}

ostream & operator<<(ostream &os, const Matrix & tmp)
{
    for (int i = 0; i < tmp.rows; i++)
    {
        cout << "  |  ";
        for (int j = 0; j < tmp.cols; j++)
            cout << tmp.elements[i * tmp.cols + j] << " ";
        cout << " |\n";
    }
    cout << endl;
    return os;
}
