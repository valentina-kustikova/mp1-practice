#include "../Headers/Task_Day.h"

task_day::task_day() 
{

}

task_day::task_day(const task_day& temp)
{
    task_date = temp.task_date;
}

task_day::~task_day()
{

}

time task_day::getTime()
{
    return time(1440);
}

void task_day::input()
{
    cout << "Input task date ";
    task_date.input();
    getchar();
    cout << "Input task description" << endl;
    getline(cin, description);
}

bool task_day::isStd()
{
    return false;
}

void task_day::print()
{
    cout << description;
}

void task_day::fwrite(ofstream& file)
{
    file << task_date.getDay() << ' ' << task_date.getMonth() << ' ' << task_date.getYear() << ' ' << description;
}

void task_day::fread(ifstream& file)
{
    unsigned _day, _month, _year;
    file >> _day >> _month >> _year;
    task_date = date(_day, _month, _year);
    getline(file, description, '\n');
}