#include "Type1.h"
#include <iostream>
#include <string>

using namespace std;

Type1::Type1(Date d, string s) {
	((Task*)this)->date = d;
	((Task*)this)->description = s;
}

string Type1::getDescription()
{
	return description;
}

void Type1::Print() {
	cout << getDescription() << endl;
}