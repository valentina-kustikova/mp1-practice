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
	int gethour();
	int getmin();
	friend ostream& operator<< (ostream& out, const time& a);
};
