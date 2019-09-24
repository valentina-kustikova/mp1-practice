#include "Date.h"
#include <iostream>
#include <string>

istream & operator>>(istream & s, Date &v)
{
	s >> v.day >> v.month >> v.year;
	return s;
}

ostream & operator<<(ostream & s, Date &v)
{
	s << v.day << v.month << v.year;
	return s;
}

Date::Date() 
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(int d, int m, int y)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d >= 1 && d <= 31) {
			day = d;
			month = m;
			year = y;
		}
		else {
			throw (string)"Incorrect date";
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d >= 1 && d <= 30) {
			day = d;
			month = m;
			year = y;
		}
		else {
			throw (string)"Incorrect date";
		}
	}
	else if (m == 2) {
		if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) {
			if (d >= 1 && d <= 29) {
				day = d;
				month = m;
				year = y;
			}
			else {
				throw (string)"Incorrect date";
			}
		}
		else {
			if (d >= 1 && d <= 28) {
				day = d;
				month = m;
				year = y;
			}
			else {
				throw (string)"Incorrect date";
			}
		}
	}
	else {
		throw (string)"Incorrect date";
	}
}

bool Date::operator==(Date k)
{
	if (day == k.day && month == k.month && year == k.year) return true;
	else return false;
}
