#ifndef STRUCU_H
#define STRUCU_H

#include <string>

class polinom {
private:
	double* coef;
	int deg;
public:
	polinom(const std::string&, int);
	polinom(const polinom&);
	polinom(int);
	polinom() { coef = nullptr; deg = 0; }
	~polinom();
	polinom operator +(const polinom&);
	polinom operator -(const polinom&);
	polinom operator -() const;
	polinom operator *(const polinom&);
	double operator()(double)const;
	polinom pdif() const;
	const polinom& operator =(const polinom&);
	friend std::ostream& operator << (std::ostream& out, const polinom& p)
	{
		out << p.coef[p.deg] << "x^" << p.deg << " ";
		for (int i = p.deg - 1; i >= 2; i--)
		{
			if (p.coef[i] != 0)
			{
				if (p.coef[i + 1] < 0)
					out << "- ";
				else
					out << "+ ";
				if (abs(p.coef[i]) == 1)
					out << "x^" << i << " ";
				else
					out << abs(p.coef[i]) << "x^" << i << " ";
			}
		}
		if (p.coef[1] < 0)
			out << "- " << -p.coef[1] << "x ";
		else if (p.coef[1] > 0)
			out << "+ " << p.coef[1] << "x ";
		if (p.coef[0] < 0)
			out << "- " << -p.coef[0];
		else if (p.coef[0] > 0)
			out << "+ " << p.coef[0];
		return out;
	};
};

#endif

