#include "Task_list.h"
#include "Date.h"
#include "Exception.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    Task_list L;
    try
    {
        L.Read("Task list.txt");
    }
    catch (Exception& s)
    {
        cout << s.what() << endl;
    }
    unsigned int d, m, y;
    cout << "Enter day: ";
    cin >> d;
    cout << endl;
    cout << "Enter month: ";
    cin >> m;
    cout << endl;
    cout << "Enter year: ";
    cin >> y;
    cout << endl;
    try
    {
        Date a(d, m, y);
        cout << "Your plans for this day:" << endl;
        L.Print(a);
    }
    catch (Exception s)
    {
        cout << s.what() << endl;
    }
}