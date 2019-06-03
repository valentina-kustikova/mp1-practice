#ifndef _TYPE1_H_
#define _TYPE1_H_
#include "Task.h"

class Type1 : public Task
{
public:
	Type1();
	Type1(string, Date);
	~Type1();

	void Print();
};

#endif
