#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
#include <math.h>
typedef struct vector {
	int n;//кол-во векторов
	double *x;//компоненты вектора
	vector();
	vector(int n);
	vector(vector& cop);
	~vector();
	vector& vector::operator=(const vector& t);
	vector vector::operator+(const vector& t);
	vector vector::operator-(const vector& t);
	vector vector::operator*(const vector& t);
	vector vector::operator+(double con);
	vector vector::operator-(double con);
	vector vector::operator*(double con);
	vector vector::operator+=(const vector& t);
	vector vector::operator-=(const vector& t);
	vector vector::operator*=(const vector& t);
	vector vector::operator+=(double con);
	vector vector::operator-=(double con);
	vector vector::operator*=(double con);
	double vector::lenght();
	void vector::Output();
	void vector::Input();
	double& vector::operator[](int i);
};
#endif