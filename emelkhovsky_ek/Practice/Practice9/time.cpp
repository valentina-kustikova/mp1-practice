#include "iostream"
#include "time.h"
#include "Exception.h"
#include "locale.h"
using namespace std;
time::time() {
	h = 0;
	m = 0;
}
time::~time() {
	h = 0;
	m = 0;
}
time::time(int h1, int m1) {
	h = h1;
	m = m1;
}
ostream& operator<<(ostream& out, const time& t) {
	out << t.h << ":" << t.m << endl;
	return out;
}
istream& operator>>(istream& put, time& t) {
	put >> t.h;
	put >> t.m;
	if ((t.m < 0) || (t.m > 59) || (t.h < 0) || (t.h > 23))
		throw Exception("Not correct time!");
	return put;
}