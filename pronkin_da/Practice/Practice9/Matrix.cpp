#include "Matrix.h"

Matrix::Matrix() {
	rows = cols = 1;
	m = new double[rows*cols];
}

Matrix::Matrix(int _rows, int _cols) {
	rows = _rows;
	cols = _cols;
	m = new double[rows*cols];
}

Matrix::Matrix(double *_m, int _rows, int _cols) {
	rows = _rows;
	cols = _cols;
	m = new double[rows*cols];
	for (int i = 0; i < rows*cols; i++) m[i] = _m[i];
}

Matrix::Matrix(const Matrix &_matrix) {
	rows = _matrix.rows;
	cols = _matrix.cols;
	m = new double[rows*cols];
	for (int i = 0; i < rows*cols; i++) m[i] = _matrix.m[i];
}

Matrix::~Matrix() {
	rows = cols = 0;
	delete(m);
}

Matrix Matrix::operator+(const Matrix &_matrix) {
	if (rows != _matrix.rows | cols != _matrix.cols) throw "Matrices have different sizes";
	Matrix result(rows, cols);
	for (int i = 0; i < rows*cols; i++) result.m[i] = m[i] + _matrix.m[i];
	return result;
}

Matrix Matrix::operator+(double s) {
	Matrix result(rows, cols);
	for (int i = 0; i < rows*cols; i++) result.m[i] = m[i] + s;
	return result;
}

Matrix Matrix::operator-(const Matrix &_matrix) {
	if (rows != _matrix.rows | cols != _matrix.cols) throw "Matrices have different sizes";
	Matrix result(rows, cols);
	for (int i = 0; i < rows*cols; i++) result.m[i] = m[i] - _matrix.m[i];
	return result;
}

Matrix Matrix::operator-(double s) {
	Matrix result(rows, cols);
	for (int i = 0; i < rows*cols; i++) result.m[i] = m[i] - s;
	return result;
}

Matrix Matrix::operator*(const Matrix &_matrix) {
	if (rows != _matrix.cols)throw "Matrices have different sizes";
	Matrix result(rows, _matrix.cols);
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < _matrix.cols; j++) {
			result.m[i * _matrix.cols + j] = 0;
			for (int k = 0; k < cols; k++) result.m[i * _matrix.cols + j] += m[i * cols + k] * _matrix.m[k * _matrix.cols + i];
		}
	return result;
}

Matrix Matrix::operator*(double p) {
	Matrix result(rows, cols);
	for (int i = 0; i < rows * cols; i++) result.m[i] = m[i] * p;
	return result;
}

const double* Matrix::operator[](int _i) const {
	if (_i > rows) throw "There is no such line";
	return (m + _i * cols);
}

const Matrix Matrix::operator=(const Matrix &_matrix) {
	rows = _matrix.rows;
	cols = _matrix.cols;
	m = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++) m[i] = _matrix.m[i];
	return *this;
}

ostream& operator<<(ostream &out, const Matrix &_matrix) {
	for (int i = 0, j = 0; i < _matrix.rows; i++) {
		while (j < _matrix.cols * (i + 1)) {
			out << _matrix.m[j] << " ";
			j++;
		}
		if (j == _matrix.cols) out << " " << endl;
	}
	return out;
}