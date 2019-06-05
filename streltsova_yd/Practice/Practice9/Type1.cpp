#include "Type1.h"
#include <string>
#include <iostream>
using namespace std;
Type1::Type1()
{
    Date a;
    description = "";
};
Type1::Type1(Date _a, string _des)
{
    a = _a;
    description = _des;
};
Type1::~Type1()
{
    description.clear();
};
void Type1::Print()
{
    cout << description << endl;
};
