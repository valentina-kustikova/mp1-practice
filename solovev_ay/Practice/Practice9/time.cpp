#include "time.h"
#include <iostream>
using namespace std;
time::time()
{
	hour = 10;
	min = 10;
}

time::~time()
{
	hour = min = 0;
}

time::time(const time & _time)
{
	hour = _time.hour;
	min = _time.min;
}

time::time(int a, int b)
{
	hour = a;
	min = b;
}

void time::inputtime()
{
	int a, b;
	cout << "vvedi hour and min" << endl;
	cin >> a >> b;
	hour = a;
	min = b;
}

void time::printtime()
{
	cout << hour << ":" << min << endl;
}

int time::gethour()
{
	return hour;
}

int time::getmin()
{
	return min;
}

ostream & operator<<(ostream & out, const time & a)
{
	out << a.hour << ":" << a.min << " ";
	return out;
}
