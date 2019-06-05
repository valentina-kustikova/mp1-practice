#include "Task.h"
Task::Task()
{
    Date a;
    description = "";
};
Task:: ~Task()
{
    description.clear();
};