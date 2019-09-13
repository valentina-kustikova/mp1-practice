#include "Date.h"

Date::Date() {
	d = 1;
	m = 1;
	y = 1970;
}

Date::Date(int _d, int _m, int _y) {
	if (_d < 0 || _m < 0 || _y < 0 || _d > 31 || _m > 12) throw "Invalid date";
	d = _d;
	m = _m;
	y = _y;
}

void Date::out() {
	cout << d << "." << m << "." << y << " ";
} 

bool Date::operator==(const Date _date) const {
	if (d != _date.d || m != _date.m || y != _date.y) return false;
	return true;
}