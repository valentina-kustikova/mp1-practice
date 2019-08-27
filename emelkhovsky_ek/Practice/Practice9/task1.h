#ifndef _TASK1_H_
#define _TASK1_H_
#include "iostream"
#include "task.h"
using namespace std;
class task1:public task {
public:
	task1(string describe1, date dat);
	~task1();
	void print();
};
#endif