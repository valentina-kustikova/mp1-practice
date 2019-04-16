#include "../headers/Task.h"

namespace TodoList
{
	unsigned ctask::uid_stream = 0;
}

TodoList::ctask::ctask()
{
	uid = ++uid_stream;
	start(1U, 1U, 1970U);
}

TodoList::ctask::ctask(const ctask& t)
{
	uid = ++uid_stream;
	type = t.type;
	title = t.title;
	start = t.start;
}

TodoList::ctask::ctask(std::string& title)
{
	uid = ++uid_stream;
	start(1U, 1U, 1970U);
	this->title = title;
}

TodoList::ctask::ctask(std::string& title, date start)
{
	uid = ++uid_stream;
	this->start = start;
	this->title = title;
}

TodoList::ctask::~ctask()
{

}

unsigned TodoList::ctask::get_uid()
{
	return uid;
}

TodoList::task::type TodoList::ctask::get_type()
{
	return type;
}

TodoList::time TodoList::ctask::set_start(time t)
{
	return time();
}

TodoList::time TodoList::ctask::set_end(time t)
{
	return time();
}
