#pragma once

class Time {
	int hours;
	int minutes;
public:
	Time();
	Time(int, int);
	bool operator ==(const Time&);
	int getHours();
	int getMinutes();
};