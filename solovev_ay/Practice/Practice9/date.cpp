#include "date.h"
#include <iostream>
using namespace std;

void date::input()
{
	int a, b, c;
	cout << "vvedi day month year" << endl;
	cin >> a >> b >> c;
	day = a;
	month = b;
	year = c;
}

int date::getday()
{
	return day;
}

int date::getmonth()
{
	return month;
}

int date::getyear()
{
	return year;
}

void date::setday(int a)
{
	day = a;
}

void date::setmonth(int a)
{
	month = a;
}

void date::setyear(int a)
{
	year = a;
}

bool date::operator==(const date &tmp)
{
	if ((this->day == tmp.day) && (this->month == tmp.month) && (this->year == tmp.year))
		return true;
	return false;
}

date::date()
{
	day = 1;
	month = 1;
	year = 1900;
}

date::date(const date & tmp)
{
	day = tmp.day;
	month = tmp.month;
	year = tmp.year;
}

date::~date()
{
	day = month = year = 0;
}

date::date(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
}

ostream & operator<<(ostream & out, const date & a)
{
	out << a.day << "." << a.month << "." << a.year << endl;
	return out;
}
