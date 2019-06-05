#pragma once
#include <iostream>
using namespace std;
class Time
{
    unsigned int hour, minute;
public:
    Time();
    Time(unsigned int _h, unsigned int _m);
    ~Time();
    friend ostream& operator<< (ostream& out, const Time& a);
};