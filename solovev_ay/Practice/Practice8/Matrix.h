#pragma once
enum exeption_type { Badparametrs, BadIndex };
class Matrix
{
	double *m;
	int runs, colc;
public:
	Matrix();
	Matrix(const Matrix&);
	Matrix(int a, int b);
	Matrix(double*am, int a, int b);
	~Matrix();
	Matrix operator+(const Matrix&a);
	Matrix operator+(double k);
	Matrix operator-(const Matrix&a);
	Matrix operator-(double);
	Matrix operator*(const Matrix&a);
	const Matrix& operator=(const Matrix&a);
	Matrix operator*(double);
	const double operator[](int) const;
	void PrintMatrix();
	double & operator[](unsigned index);
	void Inputmatrix();
};
struct exeption
{
	exeption_type exp_type;

	exeption(exeption_type type)
	{
		exp_type = type;
	}
};