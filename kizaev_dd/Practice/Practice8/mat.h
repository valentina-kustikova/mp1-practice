#pragma once
#include "iostream"

using namespace std;

class mat
{
    private:
        int dx, dy;
        double* mp;
    public:
        mat ();
        mat (int _dx, int _dy);
        mat (const mat& m);
        ~mat();

    mat operator+ (const mat& m) const;
    mat operator- (const mat& m) const;
    mat operator* (const mat& m) const;
    
    mat operator+ (double d) const;
    mat operator- (double d) const;
    mat operator* (double d) const;

    double* operator[] (int i);
    const double* operator[] (int i) const;  
    //
    const mat& operator=(const mat& m);
    bool operator== (const mat& m) const;

    mat& operator+= (const mat& m);
    mat& operator-= (const mat& m);
    mat& operator+= (double d);
    mat& operator-= (double d);

    mat& operator*= (double d);

    friend istream& operator>> (istream& stream, mat& m);
    friend ostream& operator<< (ostream& stream, const mat& m); 
};    