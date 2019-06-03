#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>

class Matrix 
{
	int *m;
	int rows, cols; //строки, столбцы
public:
	Matrix(int, int);
	Matrix(double*, int, int);
	~Matrix();
	Matrix(const Matrix&);
	Matrix operator+ (const Matrix&);
	Matrix operator- (const Matrix&);
	Matrix operator* (const Matrix&);
	Matrix operator+ (int);
	Matrix operator- (int);
	Matrix operator* (int);
	bool operator==(const Matrix& x) const;
	const int* operator[](int _i) const;
	void Output();
	void Input();
	friend std::ostream& operator<<(std::ostream &, const Matrix&);
};
#endif