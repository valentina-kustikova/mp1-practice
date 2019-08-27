#ifndef _TO_DO_LIST_H_
#define _TO_DO_LIST_H_
#include <string>
#include "date.h"
#include "task.h"

using namespace std;

class todolist
{
	task **tasks;
	int count;
public:
	todolist();
	~todolist();
	void read();
	void print(date dat);
};
#endif