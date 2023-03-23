#ifndef _POLYNOM_H
#define _POLYNOM_H

#include <fstream> 

class TPolynom {
private:
	int degree;
	float* coeff;

public:
	TPolynom(void);				// По умолчанию
	TPolynom(const TPolynom& p);// Копирование
	TPolynom(int _degree);		// Инициализатор (Преобразование типа?)
	TPolynom(int _degree, float _coeff); // Инициализатор, все coeff = _coeff
	~TPolynom(void);			// Деконструктор

	bool operator==(const TPolynom& p) const;
	bool operator!=(const TPolynom& p) const;
	const TPolynom& operator=(const TPolynom& p);

	TPolynom operator+(const TPolynom& p);
	TPolynom operator-(const TPolynom& p);
	TPolynom operator*(const TPolynom& p);
	float operator()(float _x);

	//!!! WIP !!!
	TPolynom& operator+=(const TPolynom& p);
	TPolynom& operator-=(const TPolynom& p);
	TPolynom& operator*=(const TPolynom& p);

	int& Degree();
	float& Coeff(int ind);

	void Fill_hand();		// Заполнение от руки
	void Copy(const TPolynom& p);
	friend std::ostream& operator<<(std::ostream& out, const TPolynom& p) {
		out << p.coeff[p.degree];
		if (!p.coeff[p.degree]) {
			out << "x^0" << std::endl;
			return out;
		}

		out << "x^" << p.degree << " ";
		for (int i = p.degree - 1; i >= 0; i--) {
			if (p.coeff[i] > 0)
				out << "+ " << p.coeff[i] << "x^" << i << " ";
			else if (p.coeff[i] < 0)
				out << "- " << -p.coeff[i] << "x^" << i << " ";
		}
		out << std::endl;
		return out;
	}

	TPolynom Diff(const TPolynom& p);
	TPolynom& DiffEq();

	void Rebuffer(int newDegree);
	void Rebuffer();

private:
	void Resize(int newDegree);
	void _coeffcopy(float* c1, float* c2);
};

void read_file(TPolynom*& p, int& n);

inline int max_d(int a, int b) {
	return (a > b) ? a : b;
};

#endif