#include "Date.h"
#include "Exception.h"
#include <iostream>
using namespace std;
Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
};
Date::~Date()
{
    day = 0;
    month = 0;
    year = 0;
};
Date::Date(unsigned int _d, unsigned int _m, unsigned int _y)
{
    bool f = false;
    if (((_y % 4 == 0) && (_y % 100 != 0)) || (_y % 400 == 0))
        f = true;
    if (_y < 0)
        throw Exception("incorrect year entry\n");
    if ((_m < 0) || (_m > 12))
        throw Exception("incorrect month entry\n");
    if ((_d < 0) || (_d > 31))
        throw Exception("incorrect day entry\n");
    if ((_d > 28) && (_m == 2) && (f == false))
        throw Exception("in February cann't be more than 28 days\n");
    if ((_d > 29) && (_m == 2) && (f == true))
        throw Exception("in a leap year in February cann't be more than 29 days\n");
    if ((_d > 30) && ((_m == 4) || (_m == 6) || (_m == 9) || (_m == 11)))
        throw Exception("in this month cann't be more than 30 days\n");
    day = _d;
    month = _m;
    year = _y;
};
bool Date :: operator==(const Date & a) const
{
    if ((day != a.day) || (month != a.month) || (year != a.year))
        return false;
    return true;
};
ostream& operator<< (ostream& out, const Date& a)
{
    out << a.day << "." << a.month << "." << a.year << endl;
    return out;
};