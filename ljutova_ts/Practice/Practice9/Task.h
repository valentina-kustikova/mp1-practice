#ifndef _TASK_H_
#define _TASK_H_
#include <string>
#include "Date.h"
#include "Time.h"

using namespace std;

class Task
{
public:
	string description;
	Date date;
	Task();
	Task(string, Date);
	virtual ~Task();
	Date GetDate();
	virtual void Print() = 0;
};

#endif
