#ifndef STRUCU_H
#define STRUCU_H

#include <string>

struct polinom {
	double* coef;
	int deg;

	polinom(const std::string&, int);
	polinom(const polinom&);
	polinom(int);
	polinom() { coef = nullptr; deg = 0; }
	~polinom();
	polinom operator +(const polinom&);
	polinom operator -(const polinom&);
	polinom operator -();
	polinom operator *(const polinom&);
	double operator()(double)const; 
	polinom pdif() const;
	const polinom& operator =(const polinom&);
	friend std::ostream& operator << (std::ostream& out, const polinom& p)
	{
		for (int i = p.deg; i >= 2; i--)
		{
			if (p.coef[i] == 1)
				out << "x^" << i << " + ";
			else
				out << p.coef[i] << "x^" << i << " + ";
		}
		out << p.coef[1] << "x + " << p.coef[0];
		return out;
	};
};

#endif
