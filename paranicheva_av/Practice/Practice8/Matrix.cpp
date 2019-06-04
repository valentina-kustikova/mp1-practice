#include <iostream>
#include "Head.h"
using namespace std;

Matrix::Matrix(int _rows, int _cols)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows * cols];
}
Matrix::Matrix(double* _m, int _rows, int _cols)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows * cols];
	m = _m;
}
Matrix::Matrix(const Matrix& M)
{
	rows = M.rows;
	cols = M.cols;
	m = new double[rows * cols];
	for(int i = 0; i < rows * cols; i++)
		memcpy(&m[i], &M.m[i], sizeof(m[i]));
}
Matrix::~Matrix()
{
	delete[]m;
	rows = 0;
	cols = 0;
}
const Matrix Matrix::operator= (const Matrix& M) 
{
	if (*this == M)
		return *this;
	delete[] m;
	rows = M.rows;
	cols = M.cols;
	m = new double[rows * cols];
	for(int i = 0; i < rows * cols; i++)
		memcpy(&m[i], &M.m[i], sizeof(m[i]));
	return *this;
}
Matrix Matrix::operator+ (const Matrix& M) const
{
	if(rows == M.rows && cols == M.cols)
	{
		Matrix res(rows, cols);
		for(int i = 0; i < rows * cols; i++)
			res.m[i] = m[i] + M.m[i];
		return res;
	}
	else
		throw "Error";
}
Matrix Matrix::operator- (const Matrix& M) const
{
	if(rows == M.rows && cols == M.cols)
	{
		Matrix res(rows, cols);
		for(int i = 0; i < rows * cols; i++)
			res.m[i] = m[i] - M.m[i];
		return res;
	}
	else
		throw "Error";
}
Matrix Matrix::operator* (const Matrix& M) const
{
	if (cols != M.rows)
		throw "Error";
	Matrix res(rows, M. cols);
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
        {
            res.m[i * M.cols + j] = 0.0;
			for(int k = 0; k < rows; k++)
				res.m[i * M.cols + j] += M.m[i * cols + k] * M.m[k * M.cols + j];
        }
}
Matrix Matrix::operator+ (double a) const
{
	Matrix res(*this);
	for (int i = 0; i < rows * cols; i++)
		res.m[i] += a;
	return res;
}
Matrix Matrix::operator- (double a) const
{
    Matrix res(*this);
	for (int i = 0; i < rows * cols; i++)
		m[i] -= a;
	return res;
}
Matrix Matrix::operator* (double a) const
{
    Matrix res(*this);
	for (int i = 0; i < rows * cols; i++)
		m[i] *= a;
	return res;
}
const double*& Matrix::operator[] (int ind) const
{
	if ((ind < 0) || (ind >= rows * cols))
		throw "Error";
	return m + cols * ind;
}
bool Matrix:: operator== (const Matrix& M) const
{
    if ((rows != M.rows) || (cols != M.cols)) return false;
    for (int i = 0; i < rows * cols; i++)
    {
        if (m[i] != M.m[i]) 
            return false;
    }
    return true;
}
 istream& operator>>(istream& input, Matrix& M)
{
    for (int i = 0; i < (M.rows * M.cols); i++)
        input >> M.m[i];
    return input;
}
ostream& operator<<(ostream &output, const Matrix& M)
{
    if ((M.rows * M.cols) == 0)
    {
        cout << "Empty matrix.";
        return output;
    }
    for (int i = 0; i < (M.rows * M.cols); i++)
    {
        if (i % M.cols == 0)
            output << "| ";
        output << M.m[i] << " ";
        if ((i + 1) % M.cols == 0)
            output << "|" << endl;
    }
    return output;
}
