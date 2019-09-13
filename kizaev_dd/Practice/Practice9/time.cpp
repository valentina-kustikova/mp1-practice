#include "time.h"

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

time::time (const time& t) // ะสั
{
    hour = t.hour;
    min = t.min;
}

time::~time()
{
    hour = 0;
    min = 0;
}

void time::print() const // สฬ
{
    cout << hour << ":" << min << " ";
}

bool time::operator== (const time& t) const // สฬ; ะสั
{
    if ((hour == t.hour) && (min == t.min))
        return true;
    return false;
}

const time& time::operator= (const time& t) // ยสั
{
    if (*this == t)
        return *this;
    hour = t.hour;
    min = t.min;
    return *this;
}