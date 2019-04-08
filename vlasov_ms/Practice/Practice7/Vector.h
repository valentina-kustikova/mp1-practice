#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <math.h>

struct Vector
{
	double *v;
	size_t size;

	Vector();
	explicit Vector(size_t);
	Vector(size_t, double*);
	Vector(size_t, double);
	Vector(const Vector&);
	~Vector();

	void print(const char* = "") const;
	void input()                 const;

	bool   nil()                const;
	size_t dim()                const;
	double angle(const Vector&) const;
	double len()                const;

	const Vector& operator=  (const Vector&);
	Vector operator+  (const Vector&);
	Vector operator-  (const Vector&);
	Vector operator+  (double);
	Vector operator-  (double);
	Vector operator*  (double);
	Vector operator/  (double);
	double operator*  (const Vector&) const;
	bool   operator== (const Vector&) const;
	bool   operator!= (const Vector&) const;

	bool   operator> (const Vector&) const;
	bool   operator>= (const Vector&) const;
	bool   operator< (const Vector&) const;
	bool   operator<= (const Vector&) const;

	Vector& operator+=  (Vector&);
	Vector& operator-=  (Vector&);
	Vector& operator*=  (double);
	Vector& operator/=  (double);

	Vector operator+ ();
	Vector operator- ();

	double& operator[](size_t index);
	const double& operator[](size_t index) const;

	/*void* operator new(size_t);
	void  operator delete(void*);
	void* operator new[](size_t, int);
	void  operator delete[](void*);*/
};

Vector operator*(double, const Vector&);

struct VectorBadIndexException {};
struct VectorDivizionByZero {};
struct VectorUnequalDimensionException {};

#endif