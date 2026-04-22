#ifndef STRUCU_H
#define STRUCU_H
#include <string>

struct polinom {
	int* coef;
	int deg;
	polinom(int);
	polinom(const polinom&);
	polinom(const string, int);
	~polinom();
	polinom operator +(const polinom&);
	polinom operator -(const polinom&);
	polinom operator -();
	polinom operator *(const polinom&);
	int pznach(double  x);
	polinom pdif();
	const polinom& operator =(const polinom&);
	friend std::ostream& operator << (std::ostream& out, const polinom&);
	friend std::istream& operator >> (std::istream& in, const polinom&);

	//int degpol(const char* fname, int num);
	//polinom pcreate(const char* fname, int deg, int num); будет внутри чтения с файла?
};

#endif
