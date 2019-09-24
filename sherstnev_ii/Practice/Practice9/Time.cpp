#include "Time.h"
#include <iostream>
#include <string>

Time::Time() {
	hours = 0;
	minutes = 0;
}

Time::Time(int h, int m){
	if (h < 0 || h > 23 || m < 0 || m > 60) throw (std::string)"Incorrect time";
	hours = h;
	minutes = m;
}

bool Time::operator==(const Time &m)
{
	if (hours == m.hours && minutes == m.minutes) return true;
	else return false;
}

int Time::getHours() { return hours; }
int Time::getMinutes() { return minutes; }
