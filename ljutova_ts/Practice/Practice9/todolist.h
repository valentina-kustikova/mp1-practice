#ifndef _TODOLIST_H_
#define _TODOLIST_H_
#include <string>
#include "Date.h"
#include "Task.h"

using namespace std;

class Todolist
{
    Task **task;
    int n;
public:
    Todolist();
    ~Todolist();
    void read(const string);
    void print(Date);
};

class T1 : std::exception
{
    const std::string what_str = "File is not open";
public:
    const char* what() const;
};

class T2 : std::exception
{
    const std::string what_str = "You type is not correct";
public:
    const char* what() const;
};

class T3 : std::exception
{
    const std::string what_str = "You haven`t got tasks on this day";
public:
    const char* what() const;
};
#endif