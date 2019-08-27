#ifndef _TIME_H_
#define _TIME_H_
#include "iostream"
#include "locale.h"
using namespace std;
class time {
private:
	int h, m;
public:
	time();
	time(int h1, int m1);
	~time();
	friend ostream& operator<<(ostream& out, const time& t);
	friend istream& operator>>(istream& put,  time& t);
};
#endif