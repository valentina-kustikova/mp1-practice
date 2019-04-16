#include "../headers/TaskStd.h"

// code here...

TodoList::task::std::std() : ctask()
{
	t_start = 00.00;
	t_end = 00.00;
}

TodoList::task::std::std(const std& t) : ctask(t)
{
	t_start = t.t_start;
	t_end = t.t_end;
}

TodoList::task::std::std(::std::string& title, date start) : ctask(title, start)
{

}

TodoList::task::std::std(::std::string& title, date start, time t_start, time t_end) : ctask(title, start)
{
	this->t_start = t_start;
	this->t_end = t_end;
}

TodoList::task::std::std(::std::string& title) : ctask(title)
{
	t_start = 00.00;
	t_end = 00.00;
}

TodoList::task::std::~std()
{

}

TodoList::time TodoList::task::std::get_start()
{
	return t_start;
}

TodoList::time TodoList::task::std::get_end()
{
	return t_end;
}

TodoList::time TodoList::task::std::set_start(time t)
{
	t_start = t;
	return t_start;
}

TodoList::time TodoList::task::std::set_end(time t)
{
	t_end = t;
	return t_end;
}

void TodoList::task::std::print()
{
	::std::cout << '[' << get_uid() << '] ' << start << ' ' << t_start.get_mins() << ' ' << t_end.get_mins() << ' ' << title << '\n';
}

void TodoList::task::std::print(::std::ofstream& fout)
{
	fout << get_uid() << ' ' << start << ' ' << t_start.get_mins() << ' ' << t_end.get_mins() << ' ' << title << '\n';
}