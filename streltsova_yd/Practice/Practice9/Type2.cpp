#include "Type2.h"
#include <string>
#include <iostream>
using namespace std;
Type2::Type2()
{
    Date a;
    Time t1, t2;
    description = "";
};
Type2::Type2(Date _a, Time _t1, Time _t2, string _des)
{
    a = _a;
    t1 = _t1;
    t2 = _t2;
    description = _des;
};
Type2::~Type2()
{
    description.clear();
};
void Type2::Print()
{
    cout << t1 << "- " << t2 << description << endl;
};