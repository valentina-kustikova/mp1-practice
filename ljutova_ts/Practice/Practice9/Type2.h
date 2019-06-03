#ifndef _TYPE2_H_
#define _TYPE2_H_
#include "Task.h"

class Type2 : public Task
{
	Time t1, t2;
public:
	Type2();
	Type2(string, Date, Time, Time);
	~Type2();

	void Print();
};

#endif
