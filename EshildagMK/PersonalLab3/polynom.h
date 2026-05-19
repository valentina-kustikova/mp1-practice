#ifndef STRUCT_H
#define STRUCT_H
#include<string>
#include <fstream>

class polynom {
private:
		int power;
		int* coefs;
public:
	//конструкторы:
	polynom();
	polynom(int deg);
	polynom(std::ifstream& file);
	//констр. коп.
	polynom(const polynom& other);

	//операторы:
	polynom& operator=(const polynom& other);

	polynom operator+(const polynom& other) const;
	polynom operator-(const polynom& other) const;
	polynom operator*(const polynom& other) const;
	double operator()(double x)const;

	//methods:
	polynom diff() const;
	void print_pnom() const;

	//destr.
	~polynom();
};

#endif
