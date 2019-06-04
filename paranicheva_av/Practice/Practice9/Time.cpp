#include <iostream>
#include "Time.h"
using namespace std;

Time::Time()
{
	min = 0;
	h = 0;
}
Time::Time(int _min, int _h)
{
	this->h = _h;
    this->min = _min;
}
Time::Time(const Time& t)
{
    h = t.h;
	min = t.min;
}
Time::~Time()
{
	min = 0;
	h = 0;
}

void Time::Print()
{
	cout << h << ":" << min << endl;
}
const Time& Time::operator=(const Time time)
{
	h = time.h;
	min = time.min;
	return *this;
}
bool Time::operator == (const Time& t) const
{
    if ((h == t.h) && (min == t.min))
		return true;
	return false;
}
