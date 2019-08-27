#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <iostream>
#include <string>
using namespace std;

class Exception
{
private:
	string er;
public:
	Exception(string e) : er(e) {};
	void Print()
	{
		cout << " Error: " << er << endl;
	}
};

#endif
