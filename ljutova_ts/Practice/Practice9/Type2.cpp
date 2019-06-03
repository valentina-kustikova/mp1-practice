#include "Type2.h" 
#include <iostream> 
#include "Task.h"
using namespace std;

Type2::Type2(string _des, Date _date, Time _t1, Time _t2)
{
	description = _des;
	date = _date;
	t1 = _t1;
	t2 = _t2;
}

Type2::~Type2()
{
	description = nullptr;
}

void Type2::Print()
{
	cout << date << " " << t1 << "  " << t2 << " " << description << endl;
}
