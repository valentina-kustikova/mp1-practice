#pragma once

#include <iostream>

using namespace std;

class date
{
private:
    int year, month, day;
public:
    date();
    date(int y, int m, int d);
    date(const date& d);
    ~date();

    bool operator== (const date& d) const; // สฬ; ะสั;
    void print() const; // 
    const date& operator= (const date& d);
};
