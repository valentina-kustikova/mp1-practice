#pragma once


class Time {
protected:
	int h, m, duration;
public:
	Time();
	Time(int, int);
	const Time operator=(Time&);
	void out();
};
