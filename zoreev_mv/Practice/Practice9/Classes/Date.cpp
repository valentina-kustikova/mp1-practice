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
    do
    {
        cin >> day >> month >> year;
    } while ((year < 1970) || (day > 31) || (month > 12));
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