#include "Matrix.h"
#include "Exception.h"
using namespace std;

//Выделение памяти
Matrix::Matrix(int _rows, int _cols)
{

	rows = _rows;
	cols = _cols;
	m = new int[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		m[i] = 0;
}

//Копирование 
Matrix::Matrix(const Matrix& x)
{
	rows = x.rows;
	cols = x.cols;
	m = new int[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		m[i] = x.m[i];
}

//Деструктор
Matrix::~Matrix()
{
	rows = 0;
	cols = 0;
	if (m != nullptr)
		delete[] m;
}

//Вывод
void Matrix::Output()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << m[i * cols + j] << " ";
		cout << endl;
	}

}

//Ввод
void Matrix::Input()
{
	for (int i = 0; i < rows * cols; i++)
		cin >> m[i];
}

Matrix Matrix::operator+(const Matrix&_m)
{
	if ((rows != _m.rows) || (cols != _m.cols))
	{
		throw Exception("Diferent size");
	}
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.m[i * cols + j] = m[i * cols + j] + _m.m[i * cols + j];
	return result;
}

Matrix Matrix::operator+(int x)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.m[i * cols + j] = m[i * cols + j] + x;
	return result;
}

Matrix Matrix::operator-(const Matrix&_m)
{
	if ((rows != _m.rows) || (cols != _m.cols))
	{
		throw Exception("Error. Different size");
	}
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.m[i * cols + j] = m[i * cols + j] - _m.m[i * cols + j];
	return result;
}
Matrix Matrix::operator-(int x)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			result.m[i * cols + j] = m[i * cols + j] - x;
	return result;
}

Matrix Matrix::operator*(const Matrix&_m)
{
	if ((rows != _m.cols) || (cols != _m.rows))
		throw Exception("Different size");
	Matrix result(rows, _m.cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < _m.cols; j++)
			for (int k = 0; k < cols; k++)
			result.m[i * _m.cols + j] += m[i * cols + k] * _m.m[k * _m.cols + j];
	return result;
}

Matrix Matrix::operator*(int x)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			for (int k = 0; k < cols; k++)
				result.m[i * cols + j] += m[i * cols + k] * x;
	return result;
}

const int* Matrix::operator[](int _i) const
{
	if ((_i < 0) || (_i > rows * cols))
		throw Exception("Index do not exist!");
	return(m + cols * _i);
}


bool Matrix::operator==(const Matrix& x) const
{
	if ((rows != x.rows) || (cols != x.cols))
		return false;
	for (int i = 0; i < rows * cols; i++)
		if (m[i] != x.m[i])
			return false;
	return true;
}

ostream & operator<<(ostream & o, const Matrix & x)
{
	for (int i = 0; i < x.rows; i++)
		for (int j = 0; j < x.cols; j++)
		o << x.m[i * x.cols + j] << " ";
	return o;
};