#include "timetable.h"
#include <iostream>
using namespace std;

void main()
{
    timetable t;
    string s;
	cout << "enter filename" << endl;
    cin >> s;
    try 
    {
        t.read(s);
    }
    catch (const char* exc)
    {
        cout << exc << endl;
    } 
    int y, m, d;
    cout << "Date: " << endl << "Day: ";
    cin >> d;
    cout << "Month: ";
    cin >> m;
    cout << "Year: ";
    cin >> y;
    date note = date(y, m, d);
    t.print(note);
	system ("pause");
}