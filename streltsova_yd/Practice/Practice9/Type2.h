#pragma once
#include "Task.h"
#include "Time.h"
#include <string>
#include <iostream>
using namespace std;
class Type2 : public Task
{
public:
    Time t1, t2;
    Type2();
    Type2(Date _a, Time _t1, Time _t2, string _des);
    ~Type2();
    void Print();
};