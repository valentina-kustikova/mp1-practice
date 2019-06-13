#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Time.h"

using namespace std;

class task
{
protected:
    date task_date;
    string description;

public:
    task();
    task(const task&);
    virtual ~task();

    date getDate();
    virtual time getTime() = 0;
    virtual void input() = 0;
    virtual bool isStd() = 0;
    virtual void print() = 0;
    virtual void fwrite(ofstream& file) = 0;
    virtual void fread(ifstream& file) = 0;
};