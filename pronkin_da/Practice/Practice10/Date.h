#pragma once
#include <iostream>

using namespace std;

class Date {
protected:
	int y, m, d;
public:
	Date();
	Date(int, int, int);
	bool operator==(const Date) const;
	void out();
};
