#ifndef TIME_H
#define TIME_H

class Time
{
public:
    	int min, h;
	Time();
	Time(int _min, int _h);
   	Time(const Time& t);
	~Time();

	void Print();
	const Time& operator=(const Time time);
   	bool operator == (const Time& t) const;
};
#endif
