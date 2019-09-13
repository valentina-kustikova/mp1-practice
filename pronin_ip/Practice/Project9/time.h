#pragma once
#include <iostream>
using namespace std;
class Time
{
private:
	int minutes;
	int hours;
public:
	Time();
	Time(int, int);
	Time(const Time&);
	~Time();
	friend istream& operator>>(istream&, Time&);
	friend ostream& operator<<(ostream&, const Time&);
};
