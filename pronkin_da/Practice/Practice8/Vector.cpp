#include "Vector.h"
#include <math.h>

using namespace std;

Vector::Vector(int an) {
	if (an < 1)throw "Cannot create zero vector";
	n = an;
	x = new double[an];
}

Vector::Vector(int an, double* ax) {
	if (an < 1)throw "Cannot create zero vector";
	n = an;
	x = new double[an];
	for (int i = 0; i < n; i++)x[i] = ax[i];
}

Vector::Vector(const Vector &copyv) {
	n = copyv.n;
	x = new double[n];
	for (int i = 0; i < n; i++)x[i] = copyv.x[i];
}

Vector::~Vector() {
	n = 0;
	delete(x);
}

double Vector::Vlength() {
	if (n < 2) throw "It is impossible to calculate the length of the vector";
	double _leng = 0;
	for (int i = 0; i < n; i++)_leng += x[i] * x[i];
	return sqrt(_leng);
}

Vector& Vector::operator+(const Vector &av) {
	if (n != av.n) throw "Vectors have a different number of components";
	Vector *VR = new Vector(n);
	(*VR).x = new double[n];
	for (int i = 0; i < n; i++)(*VR).x[i] = x[i] + av.x[i];
	return *this;
}

Vector& Vector::operator+(const Vector &av) {
	if (n != av.n) throw "Vectors have a different number of components";
	Vector *VR = new Vector(n);
	(*VR).x = new double[n];
	for (int i = 0; i < n; i++)(*VR).x[i] = x[i] - av.x[i];
	return *this;
}

double Vector::operator*(const Vector &av) {
	if (n != av.n) throw "Vectors have a different number of components";
	double sp = 0;
	for (int i = 0; i < n; i++)sp = x[i] * av.x[i];
	return sp;
}

Vector& Vector::operator*(double m) {
	for (int i = 0; i < n; i++) x[i] *= m;
	return *this;
 }

const Vector& Vector::operator=(const Vector &av) {
	if (n != av.n) throw "Vectors have a different number of components";
	for (int i = 0; i < n; i++)x[i] = av.x[i];
	return *this;
}

void Vector::operator+=(const Vector &av) {
	if (n != av.n) throw "Vectors have a different number of components";
	for (int i = 0; i < n; i++)x[i] += av.x[i];
}

void Vector::operator-=(const Vector &av) {
	if (n != av.n) throw "Vectors have a different number of components";
	for (int i = 0; i < n; i++)x[i] -= av.x[i];
}

double& Vector::operator[](int an){
	if (an > n) throw "Out of vector space";
	return x[an];
}

void* Vector::operator new(size_t an) {
	void *vec = malloc(an);
	if (vec == NULL) throw "Cannot create zero vector";
	return vec;
}

void Vector::operator delete(void* v) {
	free(v);
}




