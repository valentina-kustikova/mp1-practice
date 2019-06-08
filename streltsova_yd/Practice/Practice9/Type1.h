#pragma once
#include "Task.h"
#include <string>
#include <iostream>
using namespace std;
class Type1 : public Task
{
public:
    Type1();
    Type1(Date _a, string _des);
    ~Type1();
    void Print();
};