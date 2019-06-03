#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>

class Matrix 
{
	double *m;
	int rows, cols; //строки, столбцы
public:
	Matrix(int, int);
	Matrix(double*, int, int);
	~Matrix();
	Matrix(const Matrix&);
	Matrix operator+ (const Matrix&);
	Matrix operator- (const Matrix&);
	Matrix operator* (const Matrix&);
	Matrix operator+ (double);
	Matrix operator- (double);
	Matrix operator* (double);
	bool operator==(const Matrix& x) const;
	const double* operator[](int _i) const;

	friend std::ostream& operator<<(std::ostream &, const Matrix&);
    friend std::istream& operator>>(std::istream &, const Matrix&);
};
class Matrix1 : std::exception
{
    const std::string what_str = "Different size";
public:
    const char* what() const;
};

class Matrix2 : std::exception
{
    const std::string what_str = "Index do not exist!";
public:
    const char* what() const;
};

#endif