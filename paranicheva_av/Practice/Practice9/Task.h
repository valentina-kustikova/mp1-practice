#ifndef TASK_H
#define TASK_H
#include <string>
#include "Date.h"
#include "Time.h"
class Task
{
public:
	Date date;
	std::string description;
	Task();
	virtual ~Task();
	virtual void Print() = 0;
};

class Type1 : public Task
{
public:
	Type1();
	Type1(Date _date, std::string _description);
	~Type1();
	void Print();
};

class Type2 : public Task
{
private:
	int duration; 
	Time time;
public:
	Type2();
	Type2(Date _date, std::string _description, int _duration, Time _time);
	~Type2();

	void Print();
};

#endif