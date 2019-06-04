using namespace std;
#include <iostream>
class Vector
{
private:
	int n;
	int* elements;
public:
	Vector(int);
	Vector(int, int*);
	Vector(const Vector &);
	~Vector();
	double Length(const Vector&);
	int Scayler(const Vector&, const Vector&);
	const Vector& operator=(const Vector&);
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector operator*(int);
	Vector operator+(int);
	Vector operator-(int);
	int& operator[](int);
	const int& operator[](int) const;
	bool operator==(const Vector&);
	bool operator!=(const Vector&);
	bool operator>(const Vector&);
	bool operator<(const Vector&);
	void* operator new(size_t);
	void operator delete[](void*);
	friend ostream& operator<< (ostream&, const Vector&);
	friend istream& operator>> (istream&, const Vector&);
};

