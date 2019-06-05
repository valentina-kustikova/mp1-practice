#pragma once
enum exeption_type { Badparametrs, BadIndex };
class Matrix
{
public:
	double *m;
	int runs, colc;
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
	const double* operator[](int index_rows) const;
	void PrintMatrix();
	double* operator[](int index_rows);
	void Inputmatrix();
	friend istream& operator>> (istream&, Matrix&); // Ввод
	friend ostream& operator<< (ostream&, const Matrix&); // Вывод
};
struct exeption
{
	exeption_type exp_type;

	exeption(exeption_type type)
	{
		exp_type = type;
	}
};
