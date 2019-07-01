#include "Matrix.h"
#include "Exception.h"
#include "iostream"
#include <ctime>
using namespace std;

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    srand(time(0));
    elements = new int[rows * cols];
    for (int i = 0; i < (rows * cols); i++)
        elements[i] = rand() % 10;
}

Matrix::Matrix(const Matrix& M1)
{
    rows = M1.rows;
    cols = M1.cols;
    elements = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++)
        elements[i] = M1.elements[i];
}

Matrix::Matrix(int* _elements, int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    elements = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++)
        elements[i] = _elements[i];
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

void Matrix::operator=(Matrix& tmp)
{
    rows = tmp.rows;
    cols = tmp.cols;
    for (int i = 0; i < rows * cols; i++)
        elements[i] = tmp.elements[i];
}

Matrix Matrix::operator+(const Matrix& M1)
{
    if ((rows != M1.rows) || (cols != M1.cols))
        throw Exception("Sizes don't fit");
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
        throw Exception("Sizes don't fit");
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
        throw Exception("Sizes don't fit");
    Matrix tmp(rows, M1.cols);
    for (int i = 0; i < rows * M1.cols; i++)
        tmp.elements[i] = 0;
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

const int* Matrix::operator[](int _ind) const
{
    if ((_ind < 0) || (_ind > rows))
        throw Exception("Index don't fit");
    return(elements + cols * _ind);
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
