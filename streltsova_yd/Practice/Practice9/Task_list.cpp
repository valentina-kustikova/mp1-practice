#include "Task_list.h"
#include "Time.h"
#include "Task.h"
#include "Type1.h"
#include "Type2.h"
#include "Exception.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
Task_list::Task_list()
{
    n = 0;
    tasks = NULL;
};
Task_list::~Task_list()
{
    for (int i = 0; i < n; i++)
        delete[] tasks[i];
    delete[] tasks;
    n = 0;
};
void Task_list::Read(const char* path)
{
    ifstream file(path);
    if (!file.is_open())
        throw Exception("invalid file path\n");
    file >> n;
    tasks = new Task * [n];
    int i = 0;
    bool f = false;
    while (i < n + 1)
    {
        string s, _s;
        getline(file, s);
        if (s == "*")
            f = true;
        if (s != "*")
        {
            int _d, _m, _y;
            int pos = s.find(".");
            _s = s.substr(0, pos);
            _d = atoi(_s.c_str());
            s.erase(0, pos + 1);
            pos = s.find(".");
            _s = s.substr(0, pos);
            _m = atoi(_s.c_str());
            s.erase(0, pos + 1);
            pos = s.find(" ");
            _s = s.substr(0, pos);
            _y = atoi(_s.c_str());
            s.erase(0, pos + 1);
            Date a(_d, _m, _y);
            if (f == true)
            {
                int _h, _m;
                pos = s.find(":");
                _s = s.substr(0, pos);
                _h = atoi(_s.c_str());
                s.erase(0, pos + 1);
                pos = s.find("-");
                _s = s.substr(0, pos);
                _m = atoi(_s.c_str());
                s.erase(0, pos + 1);
                Time _t1(_h, _m);
                pos = s.find(":");
                _s = s.substr(0, pos);
                _h = atoi(_s.c_str());
                s.erase(0, pos + 1);
                pos = s.find(" ");
                _s = s.substr(0, pos);
                _m = atoi(_s.c_str());
                s.erase(0, pos + 1);
                Time _t2(_h, _m);
                tasks[i++] = new Type2(a, _t1, _t2, s);
            }
            else
                tasks[i++] = new Type1(a, s);
        }
    }
    file.close();
};
void Task_list::Print(Date _a)
{
    bool f = true;
    for (int i = 0; i < n + 1; i++)
        if (tasks[i]->a == _a)
        {
            tasks[i]->Print();
            f = false;
        }
    if (f == true)
        throw Exception("No plans for this day\n");
    return;
};