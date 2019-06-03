#include "Type1.h" 
#include <iostream> 
#include "Task.h"

using namespace std;

Type1::Type1()
{
}

Type1::Type1(string _des, Date _date)
{
	description = _des;
	date = _date;
}

Type1::~Type1()
{
	description = nullptr;
}

void Type1::Print()
{
	cout << date <<  "Your task is " <<  description << endl;
}



