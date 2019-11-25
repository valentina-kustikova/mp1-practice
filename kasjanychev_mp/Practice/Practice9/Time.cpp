#include "Time.h"
#include <iostream>
using namespace std;
Time::Time()
{
	h = 0;
	min = 0;
}
Time::Time(int _h, int _min)
{
	h = _h;
	min = _min;
}
Time::Time(const Time& time)
{
	h = time.h;
	min = time.min;
}
Time::~Time()
{
	h = 0;
	min = 0;
}
void Time::Print() const
{
	cout << h << ":" << min;
}

const Time& Time::operator=(const Time& temp)
{
	if (this == &temp)
		return *this;
	h = temp.h;
	min = temp.min;
}