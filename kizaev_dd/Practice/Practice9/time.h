#pragma once

#include <iostream>
using namespace std;

class time
{
private:
    unsigned hour, min;
public:
    time();
    time(unsigned _h, unsigned _m);
    time(const time& tmp);
    ~time();

    void print()const;
    bool operator== (const time& t) const;
    const time& operator= (const time& t);
};