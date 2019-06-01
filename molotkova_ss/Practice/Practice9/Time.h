#pragma once
class Time
{
private:
	unsigned h;
	unsigned m;
public:
	Time();
	Time(unsigned h, unsigned m);
	Time(const Time& t);
	~Time();

	void PrintTime()const;
	bool operator == (const Time& t)const;
	Time& operator = (const Time& t);
};