#ifndef STRUCU_H
#define STRUCU_H
#include <string>

struct polinom {
	int* coef;
	int deg;
	polinom(const string, int);
	polinom(const polinom&);
	polinom(int);
	~polinom();
	polinom operator +(const polinom&);
	polinom operator -(const polinom&);
	polinom operator -();
	polinom operator *(const polinom&);
	double pznach(double  x);
	polinom pdif();
	const polinom& operator =(const polinom&);
	friend std::ostream& operator << (std::ostream& out, const polinom&);
	friend std::istream& operator >> (std::istream& in, const polinom&);
};

#endif
