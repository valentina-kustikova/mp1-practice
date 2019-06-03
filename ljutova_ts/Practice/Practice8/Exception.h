#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <iostream>
#include <string>
using namespace std;

class Exception
{
private:
	string m;
public:
	Exception(string _m) : m(_m) {};
	void Print()
	{
		cout << " Error: " << m << endl;
	}
};

#endif
