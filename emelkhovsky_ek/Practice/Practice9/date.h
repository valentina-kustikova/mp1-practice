#ifndef _DATE_H_
#define _DATE_H_
#include "iostream"
#include "locale.h"
using namespace std;
class date {
private:
	int y, m, d;
public:
	date();
	date(int y1,int m1,int d1);
	~date();
	bool operator==(date dat) const;
	const date& operator=(date& dat);
	friend ostream& operator<<(ostream& out, const date& dat);
	friend istream& operator>>(istream& put, date& dat);
};
#endif