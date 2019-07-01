#ifndef _TODOLIST_H_
#define _TODOLIST_H_
#include "Task.h"
#include "Date.h"

class ToDoList
{
private:
    Task **tasks;
    int count;
public:
    ToDoList();
    ~ToDoList();
    void read();
    void print(Date);
};
#endif 
