#include "time.h"
Time::Time()
{
	minutes = 10;
	hours = 9;
}
Time::Time(int m, int h)
{
	minutes = m;
	hours = h;
}
Time::Time(const Time& _time)
{
	minutes = _time.minutes;
	hours = _time.hours;
}
Time::~Time()
{
	minutes = 0;
	hours = 0;
}
istream& operator>>(istream& in, Time& _time)
{
	char a;
	in >> _time.minutes >> a >> _time.hours;
	return in;
}
ostream& operator<<(ostream& out, const Time& _time)
{
	out << _time.minutes << ":" << _time.hours;
	return out;
}