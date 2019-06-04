#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
{
	d = 0;
	m = 0;
	y = 0;
}
Date::Date(int _d, int _m, int _y)
{	
	this->d = _d;
	this->m = _m;
	this->y = _y;
}
Date::~Date()
{
	d = 0;
	m = 0;
	y = 0;
}

void Date::Print()
{
	cout << d << "/" << m << "/" << y << endl;
}
bool Date::operator==(const Date& tmp) const
{
	if ((d == tmp.d) && (m == tmp.m) && (y == tmp.y))
		return true;
	return false;
}
const Date& Date::operator=(const Date date)
{
	d = date.d;
	m = date.m;
	y = date.y;
	return *this;
}
