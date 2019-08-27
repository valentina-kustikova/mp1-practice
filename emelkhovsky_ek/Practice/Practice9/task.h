#ifndef _TASK_H_
#define _TASK_H_
#include "date.h"
#include "time.h"
#include <string>
#include "locale.h"
using namespace std;
class task {
public:
	string describe;
	date date_m;
	task();
	virtual ~task();
	task(string describe1, date dat);
	virtual void print() = 0;
	date receipt();
};
#endif
