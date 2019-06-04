#pragma once
class Matrix
{
private:
	int cols, rows;
	double* arr;
public:
	Matrix();
	Matrix(int x, int y);
	Matrix(const Matrix& mat);
	~Matrix();

	Matrix operator+(const Matrix& mat) const;
	Matrix operator-(const Matrix& mat) const;
	Matrix operator*(const Matrix& mat) const;
	Matrix& operator+ (double x);
	Matrix& operator- (double x);
	Matrix& operator* (double x);

	double* operator[] (int i) const;
	const Matrix& operator=(const Matrix& mat);
	void ScMat();
	void PrMat();
};