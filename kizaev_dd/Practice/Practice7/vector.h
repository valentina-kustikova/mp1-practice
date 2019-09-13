#pragma once
#include <iostream>
using namespace std;

class vect
{
    private:
        int dim;
        double* coord;
    public:
        vect ();
        vect(int dim0);
        vect(const vect& v0);
        ~vect();

    vect operator+ (const vect& v) const;
    vect operator- (const vect& v) const;
    double operator* (const vect& v) const;

    vect operator+ (double d) const;
    vect operator- (double d) const;
    vect operator* (double d) const;

    const vect& operator= (const vect & v);

    double& operator[] (int i);
	const double& operator[] (int i) const;

    double vect_len() const;

    vect& operator+= (const vect & v);
    vect& operator-= (const vect & v);
    vect& operator+= (double d);
    vect& operator-= (double d);

    vect& operator*= (double d);

    void vect_print () const;
    void vect_read ();

    int operator==(const vect & v) const;

    friend istream& operator>> (istream& stream, vect& v);
    friend ostream& operator<< (ostream& stream, const vect& v);
};    