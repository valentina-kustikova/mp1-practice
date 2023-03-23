#include <iostream>
#include <fstream> 
#include "polynom.h"
using namespace std;

TPolynom::TPolynom(void) {  // По умолчанию
	degree = 0;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = 0;
}
TPolynom::TPolynom(const TPolynom& p) { // Копирование
	degree = p.degree;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = p.coeff[i];
}
TPolynom::TPolynom(int _degree) { // Преобразование типа
	degree = _degree;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = 0;
}
TPolynom::TPolynom(int _degree, float _coeff) { // Инициализатор, все coeff = _coeff
	degree = _degree;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = _coeff;
}
TPolynom::~TPolynom(void) { // Деконструктор
	if (degree + 1)
		delete[] coeff;
	degree = 0;
}


bool TPolynom::operator==(const TPolynom& p) const {
	if (degree != p.degree) return false;
	for (int i = degree; i >= 0; i--)
		if (coeff[i] != p.coeff[i])
			return false;
	return true;
}
bool TPolynom::operator!=(const TPolynom& p) const {
	return !(*this == p);
}
const TPolynom& TPolynom::operator=(const TPolynom& p) {
	if (this != &p) {
		if (degree != p.degree) {
			delete[] coeff;
			degree = p.degree;
			coeff = new float[degree + 1];
		}
		for (int i = degree; i >= 0; i--)
			coeff[i] = p.coeff[i];
	}

	return (*this);
}

TPolynom TPolynom::operator+(const TPolynom& p) {
	TPolynom res(max_d(degree, p.degree));

	if (degree >= p.degree) {
		for (int i = degree; i >= 0; i--)
			res.coeff[i] = coeff[i];
		for (int i = p.degree; i >= 0; i--)
			res.coeff[i] += p.coeff[i];
	}
	else {
		for (int i = p.degree; i >= 0; i--)
			res.coeff[i] = p.coeff[i];
		for (int i = degree; i >= 0; i--)
			res.coeff[i] += coeff[i];
	}
	if (res.coeff[res.degree] == 0)
		res.Rebuffer();

	return res;
}
TPolynom TPolynom::operator-(const TPolynom& p) {
	TPolynom res(max_d(degree, p.degree));

	for (int i = res.degree; i >= 0; i--)
		res.coeff[i] = 0.f;

	for (int i = degree; i >= 0; i--)
		res.coeff[i] = coeff[i];
	for (int i = p.degree; i >= 0; i--)
		res.coeff[i] -= p.coeff[i];

	if (res.coeff[res.degree] == 0)
		res.Rebuffer();
	return res;
}
TPolynom TPolynom::operator*(const TPolynom& p) {
	TPolynom res(degree + p.degree);

	for (int i = degree; i >= 0; i--)
		for (int j = p.degree; j >= 0; j--)
			res.coeff[i + j] += coeff[i] * p.coeff[j];

	return res;
}
float TPolynom::operator()(float _x) {
	float res = 0.0f, x = 1.0f;
	for (int i = degree; i >= 0; i--) {
		res += coeff[i] * x;
		x *= _x;
	}
	return res;
}

TPolynom& TPolynom::operator+=(const TPolynom& p) {
	if (p.degree > degree)
		this->Resize(p.degree);

	for (int i = p.degree; i >= 0; i--)
		coeff[i] += p.coeff[i];

	if (coeff[degree] == 0)
		this->Rebuffer();
	return *this;
}
TPolynom& TPolynom::operator-=(const TPolynom& p) {
	if (p.degree > degree)
		this->Resize(p.degree);

	for (int i = p.degree; i >= 0; i--)
		coeff[i] -= p.coeff[i];

	if (coeff[degree] == 0)
		this->Rebuffer();
	return *this;
}
TPolynom& TPolynom::operator*=(const TPolynom& p) {
	int tmp_d = degree + p.degree;
	TPolynom tmp(tmp_d);

	for (int i = degree; i >= 0; i--)
		for (int j = p.degree; j >= 0; j--)
			tmp.coeff[i + j] += coeff[i] * p.coeff[j];

	this->Rebuffer(tmp_d);
	for (int i = tmp_d; i >= 0; i--)
		coeff[i] = tmp.coeff[i];

	return *this;
}

void read_file(TPolynom*& p, int& n) {
	/*
	Чтение происходит из файла "data.txt"
	-В первой строке - количество полиномов
	-В второй строке перечисленны степени каждого полинома
	-В последующих строках перечисленны коэффициенты полиномов

	!!!Предполагается, что введенные данные верны!!!
	*/

	int dgr;
	ifstream file;

	string f;
	cout << "Введите имя файла с данными: ";
	cin >> f;

	file.open(f);
	if (!file.is_open())
		throw "Файл данных не открыт";

	file >> n;
	p = new TPolynom[n];
	for (int i = 0; i < n; i++) {
		file >> dgr;
		p[i].Rebuffer(dgr);
	}
	for (int i = 0; i < n; i++) {
		for (int j = p[i].Degree(); j >= 0; j--)
			file >> p[i].Coeff(j);
		if (!p[i].Coeff(p[i].Degree()))
			p[i].Rebuffer();
	}

	file.close();
}

int& TPolynom::Degree() {
	return degree;
}
float& TPolynom::Coeff(int ind) {
	return coeff[ind];
}

void TPolynom::Fill_hand() {
	for (int i = degree; i >= 0; i--) {
		cout << "x^" << i << " = ";
		cin >> coeff[i];
	}
	cout << endl;
}
void TPolynom::Copy(const TPolynom& p) {
	this->Rebuffer(p.degree);
	for (int i = degree; i >= 0; i--)
		coeff[i] = p.coeff[i];
}


TPolynom TPolynom::Diff(const TPolynom& p) {
	this->Rebuffer(0);

	if (p.degree) {
		this->Rebuffer(p.degree - 1);
		for (int i = p.degree - 1; i >= 0; i--)
			coeff[i] = p.coeff[i + 1] * (i + 1);
	}

	return *this;
}

TPolynom& TPolynom::DiffEq() {
	int tmp_d = degree - 1;
	TPolynom tmp(tmp_d);

	if (degree == 0)
		return *this;
	else {
		for (int i = tmp_d; i >= 0; i--)
			tmp.coeff[i] = coeff[i + 1] * (i + 1);
	}

	this->Rebuffer(tmp_d);
	for (int i = tmp_d; i >= 0; i--)
		coeff[i] = tmp.coeff[i];

	return *this;
}


void TPolynom::Rebuffer(int newDegree) { // Изменяет кол-во коэф-ов и зануляет их
	if (degree + 1)
		delete[] coeff;
	degree = newDegree;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = 0.f;
}
void TPolynom::Rebuffer() { // Проверяет, есть ли у высоких степеней коэф 0. Если да, то уменьшается степень с копированием коэф-ов


	int tmp_dgr = degree;
	for (int i = degree; i >= 0; i--)
		if (coeff[i]) {
			tmp_dgr = i;
			break;
		}

	if (tmp_dgr != degree) {
		float* tmp = new float[degree + 1];
		_coeffcopy(tmp, coeff);

		if (degree + 1)
			delete[] coeff;
		degree = tmp_dgr;
		coeff = new float[degree + 1];
		for (int i = tmp_dgr; i >= 0; i--)
			coeff[i] = tmp[i];

		delete[] tmp;
	}
}
void TPolynom::Resize(int newDegree) {
	int tmp_degree = degree;
	float* tmp = new float[tmp_degree];
	_coeffcopy(tmp, coeff);

	if (degree + 1)
		delete[] coeff;
	degree = newDegree;
	coeff = new float[degree + 1];
	for (int i = degree; i > tmp_degree; i--)
		coeff[i] = 0.f;
	for (int i = tmp_degree; i >= 0; i--)
		coeff[i] = tmp[i];
	delete[] tmp;
}
void TPolynom::_coeffcopy(float* copy, float* from) {
	for (int i = degree; i >= 0; i--)
		copy[i] = from[i];
}

float power(float x, int n) {
	float res = 1.f;
	for (int i = 0; i < n; i++)
		res *= x;
	return res;
}
