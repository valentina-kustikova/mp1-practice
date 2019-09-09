#include "timetable.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define MAX_LEN 100

timetable::timetable()
{
    todo = nullptr;
    count = 0;
}

timetable::timetable(unsigned n)
{
    count = n;
    todo = new task*[n];
}

timetable::~timetable()
{
    for (int i = 0; i < count; i++)
        delete[] todo[i];
    delete[] todo;
    count = 0;
}

void timetable::print(date d) const
{
    d.print();
    for (int i = 0; i < count; i++)
    {
        if (todo[i]->GetNote() == d)
        {
            todo[i]->print();
            cout << endl;
        }
    }

}

void timetable::read(const string s)
{
    ifstream fin(s);
    if (fin.is_open() == false)
        throw "error: file does not exist";
    fin >> count;

    todo = new task*[count];

    int type;
    int year, month, day;
    char* c = new char[MAX_LEN];
    unsigned min, hour, dur;

    string s1, s2;
    for (int i = 0; i < count; i++)
    {
        fin >> type;
        if (type == 1)
        {
            int pos1, pos2;
            fin.getline(c, MAX_LEN);
            s1 = string(c);

            pos1 = s1.find(".");
            pos2 = s1.rfind(" ", pos1);
            s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1));
            day = atoi(s2.c_str()); 
            s2 = "";

            pos2 = s1.find(".", pos1 + 1);
            s2 = s1.substr((pos1 + 1), (pos2 - pos1 - 1));
            month = atoi(s2.c_str()); 
            s2 = "";

            pos1 = s1.find(" ", pos2);
            s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1));
            year = atoi(s2.c_str()); 
            s2 = "";

            pos2 = s1.find("/0", pos1);
            s2 = s1.substr((pos1 + 1), (pos2 - pos1 - 1));
            s1 = s2; 
            s2 = "";

            date note = date(year, month, day);
            todo [i] = new task1(s1, note);
        }
        if (type == 2)
        {
            int pos1, pos2;
            fin.getline(c, MAX_LEN);
            s1 = string(c);
            pos1 = s1.find(".");
            pos2 = s2.rfind(" ", pos1);
            s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1));
            day = atoi(s2.c_str());
            s2 = "";

            pos2 = s1.find(".", pos1 + 1);
            s2 = s1.substr((pos1 + 1), (pos2 - pos1 - 1));
            month = atoi(s2.c_str());
            s2 = "";

            pos1 = s1.find(" ", pos2);
            s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1));
            year = atoi(s2.c_str());
            s2 = "";

            pos1 = s1.find(":");
            pos2 = s1.rfind(" ", pos1);
            s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1));
            hour = atoi(s2.c_str());
            s2 = "";

            pos2 = s1.find(" ", pos1);
            s2 = s1.substr((pos1 + 1), (pos2 - pos1 - 1));
            min = atoi(s2.c_str());
            s2 = "";

            pos1 = s1.find_first_of("1234567890", pos2);
            pos2 = s1.find(" ", pos1);
            s2 = s1.substr(pos1, (pos2 - pos1));
            dur = atoi(s2.c_str());
            s2 = "";

            pos1 = s1.find("/0", pos2);
            s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1));
            s1 = s2;
            s2 = "";

            date note = date(year, month, day);
            time clock = time(hour, min);
			todo [i] = new task2(s1, note, clock, dur);
        }
    }
    fin.close();
}