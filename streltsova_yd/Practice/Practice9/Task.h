#pragma once
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;
class Task
{
public:
    string description;
    Date a;
    Task();
    virtual ~Task();
    virtual void Print() = 0;
};