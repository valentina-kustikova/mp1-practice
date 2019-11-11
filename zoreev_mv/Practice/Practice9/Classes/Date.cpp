#include "../Headers/Date.h"

date::date()
{
    day = 1;
    month = 1;
    year = 1970;
}

date::date(const date& temp)
{
    day = temp.day;
    month = temp.month;
    year = temp.year;
}

date::date(unsigned _day, unsigned _month, unsigned _year)
{
    day = _day;
    month = _month;
    year = _year;
}

date& date::operator=(const date& temp)
{
    day = temp.day;
    month = temp.month;
    year = temp.year;
    return *this;
}

bool date::operator<(const date& temp)
{
    if (year < temp.year) return true;
    if (year > temp.year) return false;
    if (month < temp.month) return true;
    if (month > temp.month) return false;
    if (day < temp.day) return true;
    if (day > temp.day) return false;
    return false;
}

bool date::operator>(const date& temp)
{
    if (year > temp.year) return true;
    if (year < temp.year) return false;
    if (month > temp.month) return true;
    if (month < temp.month) return false;
    if (day > temp.day) return true;
    if (day < temp.day) return false;
    return false;
}
bool date::operator==(const date& temp)
{
    if ((year == temp.year) && (month == temp.month) && (day == temp.day)) return true;
    return false;
}

unsigned date::getDay()
{
    return day;
}

unsigned date::getMonth()
{
    return month;
}

unsigned date::getYear()
{
    return year;
}

void date::input()
{
	bool attemt = false;
	do
	{
		if (attemt) cout << "Wrong date, try again" << endl;
		cin >> day >> month >> year;
		attemt = true;
	} while (
		(year > 2099) ||(year < 1970) || (month > 12) || (month < 1) || (day < 1)
		||
		((day > 31) && ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)))
		||
		((day > 30) && ((month == 2) || (month == 4) || (month == 6) || (month == 9) || (month == 11)))
		||
		((year % 4 == 0) && ((month == 2) && (day > 29)))
		||
		((year % 4 != 0) && ((month == 2) && (day > 28)))
		);
		
}

void date::setDay(unsigned _day)
{
    day = _day;
}
void date::setMonth(unsigned _month)
{
    month = _month;
}

void date::setYear(unsigned _year)
{
    year = _year;
}