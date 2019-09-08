#pragma once

class time
{
public:
	int hour;
	int min;
	time();
	~time();
	time(const time&_time);
	time(int, int);
	void inputtime();
	void printtime();
	friend ostream& operator<< (ostream& out, const time& a);
};
