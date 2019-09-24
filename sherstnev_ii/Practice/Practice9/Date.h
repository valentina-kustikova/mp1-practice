#pragma once
#include <iostream>

using namespace std;

class Date {
public:
	int year;
	int month;
	int day;
	Date();
	Date(int, int, int);
	bool operator == (Date);
	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, Date&);
};