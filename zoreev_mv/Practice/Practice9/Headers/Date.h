#pragma once
#include <iostream>

using namespace std;

class date
{
    unsigned day;
    unsigned month;
    unsigned year;

public:
    date();
    date(const date&);
    date(unsigned, unsigned, unsigned);

    date& operator=(const date&);
    bool operator<(const date&);
    bool operator>(const date&);
    bool operator==(const date&);

    unsigned getDay();
    unsigned getMonth();
    unsigned getYear();

    void input();
    void setDay(unsigned);
    void setMonth(unsigned);
    void setYear(unsigned);
};