#include "Matrix.h"
Matrix::Matrix()
{
	cols = 0;
	rows = 0;
	m = nullptr;
	srand((unsigned int)time(0));
}
Matrix::Matrix(int _cols, int _rows)
{
	cols = _cols;
	rows = _rows;
	m = new double[rows * cols];
	for (int i = 0; i < (rows * cols); i++)
		m[i] = 0;
}
Matrix::Matrix(const Matrix& x)
{
	cols = x.cols;
	rows = x.rows;
	m = new double[rows * cols];
	for (int i = 0; i < (rows * cols); i++)
		m[i] = x.m[i];
}
Matrix::~Matrix()
{
	cols = 0;
	rows = 0;
	delete[] m;
}
Matrix Matrix::operator+(const Matrix& x)
{
	if ((cols != x.cols) || (rows != x.rows)) throw "Dimension mismatch in operation '+'!";
	Matrix res(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
		res.m[i] = m[i] + x.m[i];
	return res;
}
Matrix Matrix::operator+(double x)
{
	Matrix res(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
		res.m[i] = m[i] + x;
	return res;
}
Matrix Matrix::operator-(const Matrix& x)
{
	if ((cols != x.cols) || (rows != x.rows)) throw "Dimension mismatch in operation '-'!";
	Matrix res(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
		res.m[i] = m[i] - x.m[i];
	return res;
}
Matrix Matrix::operator-(double x)
{
	Matrix res(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
		res.m[i] = m[i] - x;
	return res;
}
Matrix Matrix::operator*(const Matrix& x)
{
	if (cols != x.rows) throw "Dimension mismatch in operation '*'!";
	Matrix res(x.cols, rows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			for (int k = 0; k < res.cols; k++)
				res.m[i * cols + j] += m[i * res.cols + k] * x.m[k * x.cols + j];
	return res;
}
Matrix Matrix::operator*(double x)
{
	Matrix res(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
		res.m[i] = m[i] * x;
	return res;
}
const double* Matrix::operator[](int x) const
{
	if (x > (rows - 1)) throw "Dimension mismatch in operation '[ ]'!";
	return (m + x * cols);
}

double* Matrix::operator[](int x)
{
	if (x > (rows - 1)) throw "Dimension mismatch in operation '[ ]'!";
	return (m + x * cols);
}
const Matrix& Matrix::operator=(const Matrix& x)
{
	cols = x.cols;
	rows = x.rows;
	delete[] m;
	m = new double[rows * cols];
	for (int i = 0; i < (rows * cols); i++)
	{
		m[i] = x.m[i];
	}
	return *this;
}
void Matrix::Output()
{
	std::cout << std::endl;
	for (int i = 0; i < rows; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < cols; j++)
			std::cout << m[i * cols + j] << " ";
		std::cout << "| " << std::endl;
	}
	std::cout << std::endl;
}
void Matrix::Input()
{
	for (int i = 0; i < (rows * cols); i++)
	{
		std::cout << "Enter element from row number " << i / rows << "and column number " << i - rows * (i / rows) << std::endl;
		std::cin >> m[i];
	}
}
void Matrix::RandomInput()
{
	double l = 1.0, r = 10.0;
	for (int i = 0; i < (rows * cols); i++)
		m[i] = l + ((double)rand() / RAND_MAX) * (r - l);
}