#include "date.h"
Date::Date()
{
	day = 9;
	month = 5;
	year = 1945;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
Date::Date(const Date& _date)
{
	day = _date.day;
	month = _date.month;
	year = _date.year;
}
Date::~Date()
{
	day = 0;
	month = 0;
	year = 0;
}
bool Date::operator==(const Date& _date)
{
	if (day == _date.day && month == _date.month && year == _date.year)
		return true;
	else
		return false;
}
istream& operator>>(istream& in, Date& _date)
{
	char a;
	in >> _date.day >> a >> _date.month >> a >> _date.year;
	return in;
}
ostream& operator<<(ostream& out, const Date& _date)
{
	out << _date.day << "." << _date.month << "." << _date.year;
	return out;
}