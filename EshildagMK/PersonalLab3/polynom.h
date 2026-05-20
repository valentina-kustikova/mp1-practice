#ifndef STRUCT_H
#define STRUCT_H
#include<string>
#include <fstream>
#include<iostream>

class polynom {
private:
	int power;
	int* coefs;
public:
	//constr
	polynom();
	polynom(int deg);
	polynom(std::ifstream& file);
	//copy constr.
	polynom(const polynom& other);

	//operators:
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
