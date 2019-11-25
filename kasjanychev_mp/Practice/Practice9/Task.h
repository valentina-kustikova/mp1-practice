#pragma once
#include "Date.h"
#include "Time.h"
#include <string>
using namespace std;

class Task
{
protected:
	string des;
	Date date;
public:
	Task();
	virtual ~Task();
	virtual void Print() const = 0;
	Date GetDate()const;
};

class Type1 :public Task
{
public:
	Type1();
	Type1(string _des, Date dat);
	~Type1();
	void Print()const;
	const Type1& operator= (const Type1& temp);
};

class Type2 :public Task
{
private:
	Time time;
	int dur;
public:
	Type2();
	Type2(string _des, Date dat, Time t, int d);
	~Type2();
	void Print()const;
	const Type2& operator= (const Type2& temp);
};