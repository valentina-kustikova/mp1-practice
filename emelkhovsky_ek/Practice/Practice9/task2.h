#ifndef _TASK2_H_
#define _TASK2_H_
#include "iostream"
#include "time.h"
#include "task.h"
using namespace std;
class task2 :public task {
private:
	time start, finish;
public:
	task2(string describe1, date dat, time start1, time finish1);
	~task2();
	void print();
};
#endif
