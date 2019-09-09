using namespace std;
#include <iostream>
struct Vector
{
private:
	int n;
	int* elements;
public:
	Vector(int);
	Vector(int, int*);
	Vector(const Vector &);
	~Vector();
	double Length(Vector);
	Vector& operator=(const Vector&);
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector operator*(int);
	Vector operator+(int);
	Vector operator-(int);
	int& operator[](int);
	bool operator==(const Vector&);
	bool operator!=(const Vector&);
	bool operator>(const Vector&);
	bool operator<(const Vector&);
	void* operatornew(size_t);
	void operatordelete(void*);
	friend ostream& operator<< (ostream&, const Vector&);
};
