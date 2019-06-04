#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()
{
	d = 0;
	m = 0;
	y = 0;
}
Date::Date(int _d, int _m, int _y)
{
	d = _d;
	m = _m;
	y = _y;
}
Date::Date(const Date& dat)
{
	d = dat.d;
	m = dat.m;
	y = dat.y;
}
Date::~Date()
{
	d = 0;
	m = 0;
	y = 0;
}
void Date::Print() const
{
	cout << d << "." << m << "." << y;
}
bool Date::operator==(const Date dat) const
{
	if ((dat.d == d) && (dat.m == m) && (dat.y == y))
		return true;
	return false;
}
Date& Date::operator=(const Date& temp)
{
	if (this == &temp)
		return *this;
	d = temp.d;
	m = temp.m;
	y = temp.y;
}