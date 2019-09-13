#include "Time.h"

#include <iostream>

using namespace std;

Time::Time() {
	h = m = duration = 0;
}

Time::Time(int _h, int _m) {
	if (_h < 0 || _m < 0 || _h > 24 || _m > 59) throw "Invalid time";
	h = _h;
	m = _m;
}

void Time::out() {
	cout << h << ":" << m << endl;
}

const Time Time::operator=(Time &_time) {
	h = _time.h;
	m = _time.m;
	return *this;
}