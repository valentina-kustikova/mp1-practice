#pragma once
#include "Task.h"
class Task_list
{
    unsigned int n;
    Task** tasks;
public:
    Task_list();
    ~Task_list();
    void Read(const char* path);
    void Print(Date _a);
};