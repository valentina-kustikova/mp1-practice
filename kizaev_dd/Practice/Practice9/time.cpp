#include "time.h"
#include<iostream>
using namespace std;

time::time()
{
    hour = 0;
    min = 0;
}

time::time(unsigned h, unsigned m)
{
    hour = h;
    min = m;
}

time::time(const time& t)
{
    hour = t.hour;
    min = t.min;
}

time::~time()
{
    hour = 0;
    min = 0;
}

void time::print() const
{
    cout << hour << ":" << min << " ";
}

bool time::operator== (const time& t) const
{
    if ((hour == t.hour) && (min == t.min))
        return true;
    return false;
}

const time& time::operator= (const time& t)
{
    if (*this == t)
        return *this;
    hour = t.hour;
    min = t.min;
    return *this;
}