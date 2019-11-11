#include "../Headers/Time.h"

time::time()
{
    minutes = 0;
}

time::time(const time& temp)
{
    minutes = temp.minutes;
}

time::time(unsigned _minutes)
{
    minutes = _minutes;
}

time::time(unsigned _hours, unsigned _minutes)
{
    minutes = _hours * 60 + _minutes;
}

time& time::operator=(const time& temp)
{
    minutes = temp.minutes;
    return *this;
}

time time::operator+(const time& temp)
{
    time out(minutes + temp.minutes);
    while (minutes > 1440) minutes -= 1440;
    return out;
}

bool time::operator<(const time& temp)
{
    if (minutes < temp.minutes) return true;
    return false;
}
bool time::operator>(const time& temp)

{
    if (minutes > temp.minutes) return true;
    return false;
}
bool time::operator==(const time& temp)
{
    if (minutes == temp.minutes) return true;
    return false;
}

unsigned time::getHours()
{
    return (minutes / 60);
}

unsigned time::getMinutes()
{
    return (minutes % 60);
}

unsigned time::getTime()
{
    return minutes;
}

void time::input()
{
	bool attemt = false;
    unsigned _hours, _minutes;
    do
    {
		if (attemt) cout << "Wrong time, try again" << endl;
        cin >> _hours >> _minutes;
		attemt++;
    } while ((_hours > 23) || (_minutes > 59));
    minutes = _hours * 60 + _minutes;
}

void time::setTime(unsigned _hours, unsigned _minutes)
{
    minutes = _hours * 60 + _minutes;
}