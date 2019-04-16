#include "../headers/TaskDay.h"

// code here...

TodoList::task::day::day() : ctask()
{

}

TodoList::task::day::day(::std::string& title, date start) : ctask(title, start)
{

}

TodoList::task::day::day(const day& t) : ctask(t)
{

}

TodoList::task::day::~day()
{

}

TodoList::time TodoList::task::day::get_start()
{
	return time();
}

TodoList::time TodoList::task::day::get_end()
{
	return time();
}

void TodoList::task::day::print()
{
	::std::cout << '[' << get_uid() << '] ' << start << ' ' << title << '\n';
}

void TodoList::task::day::print(::std::ofstream& fout)
{
	fout << get_uid() << ' ' << start << ' ' << title << '\n';
}
