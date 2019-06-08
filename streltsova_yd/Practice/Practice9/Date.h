#pragma once
#include <iostream>
using namespace std;
class Date
{
    unsigned int day, month, year;
public:
    Date();
    Date(unsigned int _d, unsigned int _m, unsigned int _y);
    ~Date();
    bool operator==(const Date& a) const;
    friend ostream& operator<< (ostream& out, const Date& a);
};