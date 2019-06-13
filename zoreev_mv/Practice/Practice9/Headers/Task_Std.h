#pragma once
#include "Task.h"
#include "Time.h"

class task_std : public task
{
    time beginning_time;
    time end_time;

public:
    task_std();
    task_std(const task_std&);
    ~task_std();

    time getTime();
    void input();
    bool isStd();
    void print();
    void fwrite(ofstream& file);
    void fread(ifstream& file);
};