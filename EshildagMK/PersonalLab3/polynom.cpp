#include"polynom.h"
#include <algorithm>
#include<iostream>
#include <iomanip>

polynom::polynom() : power(0), coefs(new int [1] {0}) {}
polynom::polynom(int deg) : power(deg), coefs(new int[deg + 1]()) {}
polynom::polynom(std::ifstream& file) {
	file >> this->power;
	coefs = new int[this->power + 1];

	for (int i = 0; i <= this->power; i++) {
		file >> this->coefs[i];
	}
}
//констр. коп.
polynom::polynom(const polynom& other) {
	this->power = other.power;
	this->coefs = new int[this->power + 1];
	for (int i = 0; i <= this->power; i++) {
		this->coefs[i] = other.coefs[i];
	}
}

//операторы:
polynom& polynom::operator=(const polynom& other) {
	if (this != &other) {
		delete[] coefs;
		power = other.power;
		coefs = new int[power + 1];
		for (int i = 0; i <= power; i++) {
			coefs[i] = other.coefs[i];
		}
	}
	return *this;
}

polynom polynom::operator+(const polynom& other) const {

	int max_deg = std::max(this->power, other.power);
	polynom result(max_deg);

	for (int i = 0; i < max_deg + 1; i++) {
		int c1 = (i <= this->power) ? this->coefs[i] : 0;
		int c2 = (i <= other.power) ? other.coefs[i] : 0;
		result.coefs[i] = c1 + c2;
	}
	while (result.power > 0 && result.coefs[result.power] == 0) {
		result.power--;
	}
	return result;
}
polynom polynom::operator-(const polynom& other) const {

	int max_deg = std::max(this->power, other.power);
	polynom result(max_deg);

	polynom copied_pnom(other);

	for (int i = 0; i < copied_pnom.power + 1; i++) {
		copied_pnom.coefs[i] *= -1;
	}

	result = *this + copied_pnom;
	return result;
}
polynom polynom::operator*(const polynom& other) const {
	int new_deg = this->power + other.power;
	polynom result(new_deg);
	for (int i = 0; i <= this->power; i++) {
		for (int j = 0; j <= other.power; j++) {
			result.coefs[i + j] += this->coefs[i] * other.coefs[j];
		}
	}
	while (result.power > 0 && result.coefs[result.power] == 0) {
		result.power--;
	}
	return result;
}
double polynom::operator()(double x)const {
	double result = coefs[0];
	double pow_x = x;
	for (int i = 1; i <= power; i++) {
		result += coefs[i] * pow_x;
		pow_x *= x;
	}
	return result;
}

//methods:
polynom polynom::diff() const {
	if (!power) {
		return polynom();
	}
	int deg = power - 1;
	polynom result(deg);

	for (int i = 0; i <= deg; i++) {
		result.coefs[i] = coefs[i + 1] * (i + 1);
	}
	return result;
}
void polynom::print_pnom() const {
	bool first = true;
	for (int i = power; i > 0; i--) {
		if (coefs[i] == 0) continue;

		if (first) {
			std::cout << coefs[i] << "*x^" << i;
			first = false;
		}
		else {
			std::cout << " ";
			if (coefs[i] > 0) std::cout << "+";
			std::cout << coefs[i] << "*x^" << i;
		}
	}

	if (first) {
		std::cout << coefs[0] << std::endl;
	}
	else {
		std::cout << " ";
		if (coefs[0] > 0) std::cout << "+";
		std::cout << coefs[0] << std::endl;
	}
}

//destr.
polynom::~polynom() {
	delete[] coefs;
}
