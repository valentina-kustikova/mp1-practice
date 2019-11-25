#pragma once

class Time
{
private:
	int h, min;
public:
	Time();
	Time(int _h, int _min);
	Time(const Time& time);
	~Time();
	void Print() const;
	const Time& operator=(const Time& temp);
};