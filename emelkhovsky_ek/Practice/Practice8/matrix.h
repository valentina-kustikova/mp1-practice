#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "iostream"
using namespace std;
class matrix {
private:
	int *mat;
	int columns;
	int rows;
public:
	matrix();
	matrix(int c, int r);
	matrix(matrix& mat);
	~matrix();
	const matrix& operator=(const matrix& m);
	matrix operator+(const matrix& m);
	matrix operator-(const matrix& m);
	matrix operator*(const matrix& m);
	matrix operator+(int con);
	matrix operator-(int con);	
	matrix operator*(int con);
	matrix operator+=(const matrix& m);
	matrix operator-=(const matrix& m);
	matrix operator+=(int con);
	matrix operator-=(int con);
	matrix operator*=(int con);
	void matrix::output();
	void matrix::input();
	int* operator[](int index);
};
#endif