#ifndef STRUCT_H
#define STRUCT_H
#include<string>
#include <fstream>
#include<iostream>

struct polynom {
	int power;
	int* coefs;
	
	//конструкторы:
	polynom();
	polynom(int deg);
	polynom(std::ifstream& file);
	//констр. коп.
	polynom(const polynom& other);

	//операторы:
	const polynom& operator=(const polynom& other);
	polynom operator+(const polynom& other) const;
	polynom operator-(const polynom& other) const;
	polynom operator-() const;
	polynom operator*(const polynom& other) const;
	friend std::ostream& operator << (std::ostream& os, const polynom& tmp);
	double operator()(double x)const;

	//methods:
	polynom diff() const;

	//destr.
	~polynom();
};

#endif
	

