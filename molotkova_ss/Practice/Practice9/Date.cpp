#pragma once
#include <iostream>
#include "Date.h"
#include <fstream>
using namespace std;
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
Date ::~Date()
{
	day = 0;
	month = 0;
	year = 0;
}
bool Date ::operator == (const Date &date1)const
{
	if ((day == date1.day) && (month == date1.month) && (year == date1.year))
		return true;
	else
		return false;
}
void Date::PrintDate()const
{
	cout << "Date is: " << day << "." << month << "." << year << endl;
}
const Date& Date::operator=(const Date & t)
{
	if (*this == t)
		return *this;
	day = t.day;
	month = t.month;
	year = t.year;
	return *this;
}