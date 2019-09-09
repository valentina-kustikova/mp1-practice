#include "date.h"
#include<iostream>
using namespace std;

date::date()
{
    year = 0;
    month = 0;
    day = 0;
}

date::date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

date::date(const date& d)
{
    year = d.year;
    month = d.month;
    day = d.day;
}

date::~date()
{
    year = 0;
    month = 0;
    day = 0;
}

bool date::operator== (const date& d) const
{
    if ((year != d.year) || (month != d.month) || (day != d.day))
        return false;
    return true;
}

void date::print()const
{
    cout << day << "." << month << "." << year << endl;
}

const date& date::operator= (const date& d)
{
    if (*this == d)
        return *this;
    year = d.year;
    month = d.month;
    day = d.day;
    return *this;
}