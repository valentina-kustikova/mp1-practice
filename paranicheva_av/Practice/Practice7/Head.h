#ifndef HEAD_H
#define HEAD_H

class Vector
{
private:
	int n;
	double *x;

public:
	Vector(int nn);
	Vector(const Vector& z);
	~Vector();
	Vector operator+ (const Vector& z) const;
	Vector operator- (const Vector& z) const;
	double operator* (const Vector& z) const;
	Vector operator+ (double a) const;
	Vector operator- (double a) const;
	Vector operator* (double a) const;
	const Vector& operator= (const Vector& z);
	const double& operator[] (int ind) const;
	double& operator[] (int ind);
	double Length() const;
	Vector& operator+= (const Vector& z);
	Vector& operator-= (const Vector& z);
	Vector& operator+= (double a);
	Vector& operator-= (double a);
	Vector& operator*= (double a);
	void *operator new(size_t size);
	void operator delete(void *v);
	bool operator==(const Vector& z) const;
	friend istream& operator>> (istream& input, Vector& z);
    	friend ostream& operator<< (ostream& output, const Vector& z); 
};

#endif
