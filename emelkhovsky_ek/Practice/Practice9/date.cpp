#include "date.h"
#include "locale.h"
#include "Exception.h"
using namespace std;
date::date() {
	y = 0;
	m = 0;
	d = 0;
}
date::~date() {
	y = 0;
	m = 0;
	d = 0;
}
date::date(int y1, int m1, int d1) {
	y = y1;
	m = m1;
	d = d1;
}
bool date::operator==(date dat)const {
	return((y==dat.y)&&(m==dat.m)&&(d==dat.d));
}
const date& date::operator=(date& dat) {
	y = dat.y;
	m = dat.m;
	d = dat.d;
	return *this;
}
ostream& operator<<(ostream& out, const date& dat) {
	out << dat.d << "." << dat.m << "." << dat.y << endl;
	return out;
}
istream& operator>>(istream& put, date& dat) {
	cout << "Enter the date: year, month, day" << endl;
	put >> dat.y;
	put >> dat.m;
	put >> dat.d;
	if ((dat.m < 1)||(dat.m > 12)||(dat.d < 1)||(dat.m > 31))
		throw Exception("Not correct date!");
	return put;
}
