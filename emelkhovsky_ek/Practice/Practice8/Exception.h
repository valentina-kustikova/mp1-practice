#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <iostream>
#include <string>
using namespace std;

class Exception
{
private:
	string e;
public:
	Exception(string _e) : e(_e) {};
	void Print()
	{
		cout << " Error: " << e << endl;
	}
};
#endif