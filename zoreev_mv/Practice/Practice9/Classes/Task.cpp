#include "../Headers/Task.h"

task::task()
{

}

task::~task()
{

}

task::task(const task& temp)
{
    task_date = temp.task_date;
    description = temp.description;
}

date task::getDate()
{
    return task_date;
}