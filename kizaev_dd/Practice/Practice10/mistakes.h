#pragma once

#include <string>
#include <iostream>

using namespace std;

class mistakes
{
private:
	int code;
	string message;
public:
	mistakes ();
	mistakes (int i);

	string emesg () const;
	int ecode () const;
	void edrop () const;
};