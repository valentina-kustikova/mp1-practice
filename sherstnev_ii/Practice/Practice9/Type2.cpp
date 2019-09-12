#include "Type2.h"
#include <string>

using namespace std;

Type2::Type2(Date d, string s, Time t) {
	((Task*)this)->date = d;
	((Task*)this)->description = s;
	Duration = t;
}

string Type2::getDescription()
{
	return description;
}

void Type2::Print()
{
	cout << getDescription() << " during " << Duration.getHours() << " hours and " << Duration.getMinutes() << " minutes " << endl;
}
