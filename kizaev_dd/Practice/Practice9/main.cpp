#include "timetable.h"
#include "mistakes.h"

#include <string>
#include <iostream>

using namespace std;

bool exit()
{
    timetable t;
    string s;

	cout << "enter filename" << endl;
	cin >> s;
	cout << endl;

	try 
	{
		t.read(s);
	}
	catch (mistakes& error)
	{
		switch (error.ecode())
		{
			case 1:
			{
				error.edrop();
				return false;
			}
			break;
			default:
			{
				error.edrop();
				return true;
			}
		}
	}

	int y, m, d;
	cout << "Date: " << endl << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
	cout << endl;

	date note = date(y, m, d);
	t.print(note);
	t.counttasks (note);
	return false;
}

int main ()
{
	while (!exit());

	system ("pause");
	return 0;
}