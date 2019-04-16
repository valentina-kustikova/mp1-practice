#include "../headers/App.h"

bool TodoList::app::open(std::string& filename)
{
	reset();
	std::ifstream fin(filename.c_str());
	if (!fin.is_open())
		return false;
	else
		this->filename = filename;
	while (!fin.eof())
	{
		std::string line;  // 0 02032019 123 456 Text
		std::getline(fin, line, '\n');
		task::type ttype = task::type::t_std;
		ctask* next_task = nullptr;
		if (line[0] == '1') // task::type::day
		{
			ttype = task::type::t_day;
			next_task = new task::day();
		}
		else // task::type::std
		{
			ttype = task::type::t_std;
			next_task = new task::std();
		}
		unsigned long full_date = std::stoul(line.substr(2, 8));
		next_task->start(unsigned(full_date / 1000000UL), unsigned((full_date / 10000UL) % 100UL), unsigned(full_date % 10000UL));
		line = line.substr(11);
		if (ttype = task::t_std)
		{
			size_t space_pos = line.find_first_of(' ');
			unsigned long t_start = std::stoul(line.substr(0, space_pos));
			line = line.substr(space_pos + 1);
			space_pos = line.find_first_of(' ');
			unsigned long t_end = std::stoul(line.substr(0, space_pos));
			line = line.substr(space_pos + 1);
			next_task->set_start(time(unsigned(t_start)));
			next_task->set_end(time(unsigned(t_end)));
		}
		next_task->title = line;
		tasks.push_back(next_task);
		tcount++;
	}
	return true;
}

bool TodoList::app::create(std::string& filename)
{
	reset();
	filename += ".todo";
	std::ofstream fout(filename.c_str());
	bool result = fout.is_open();
	if (result)
	{
		fout.close();
		this->filename = filename;
	}
	tcount = 0;
	return result;
}

bool TodoList::app::save()
{
	std::ofstream fout(filename.c_str());
	if (!fout.is_open())
		return false;
	for (std::list<ctask*>::iterator i = tasks.begin(); i != tasks.end(); ++i)
	{
		task::type ttype = (*i)->get_type();
		fout << ttype << ' ';
		fout << (*i)->start;
		if (ttype == task::type::t_std)
			fout << (*i)->get_start() << ' ' << (*i)->get_end() << ' ';
		fout << (*i)->title << '\n';
	}
	fout.close();
	return true;
}

TodoList::app::app()
{
	tcount = 0;
	filename = "";
}

TodoList::app::~app()
{
	reset();
}

bool TodoList::app::add(std::string& title, task::type ttype, date start)
{
	ctask* next_task;
	if(ttype == task::type::t_std)
		next_task = new task::std(title, start);
	else
		next_task = new task::day(title, start);
	tasks.push_back(next_task);
	tcount++;
	return true;
}

bool TodoList::app::add(std::string& title, date start, time t_start, time t_end)
{
	ctask* next_task = new task::day(title, start);
	tasks.push_back(next_task);
	tcount++;
	return true;
}

bool TodoList::app::add(std::string& title, date start)
{
	ctask* next_task = new task::day(title, start);
	tasks.push_back(next_task);
	tcount++;
	return true;
}

bool TodoList::app::remove(ctask* t)
{
	return remove(t->get_uid());
}

bool TodoList::app::remove(unsigned uid)
{
	for (std::list<ctask*>::iterator i = tasks.begin(); i != tasks.end(); ++i)
	{
		if ((*i)->get_uid() == uid)
		{
			i = tasks.erase(i);
			tcount--;
			return true;
		}
	}
	return false;
}

void TodoList::app::print()
{
	for (std::list<ctask*>::iterator i = tasks.begin(); i != tasks.end(); ++i)
	{
		(*i)->print();
		std::cout << '\n';
	}
}

void TodoList::app::print(date d)
{

}

void TodoList::app::print(unsigned uid)
{

}

void TodoList::app::start()
{
	std::cout << "GOOGLE CALENDAR\n";
	std::cout << "1. Open list from file\n2. Create new list file\n";
	int action = 1;
	do
	{
		if ((action < 1) || (action > 2))
			std::cout << "Wrong code. Try again: ";
		else
			std::cout << "Enter code of action: ";
		std::cin >> action;
	} while ((action < 1) || (action > 2));

	std::string tmp;
	int attempts = 0;
	switch (action)
	{
	case 1:
		do
		{
			if (attempts > 0)
				std::cout << "Incorrect file. Try again: ";
			else
				std::cout << "Enter path to file: ";
			//std::getline(std::cin, tmp);
			std::cin >> tmp;
			attempts++;
		} while (!open(tmp));
		break;
	case 2:
		do
		{
			if (attempts > 0)
				std::cout << "Incorrect name. Try again: ";
			else
				std::cout << "Enter list name (filename will be <your_name>.todo): ";
			//std::getline(std::cin, tmp);
			std::cin >> tmp;
			attempts++;
		} while (!create(tmp));
		break;
	}

	system("cls");
	std::cout << "GOOGLE CALENDAR :: " << this->filename << '\n';
	while (1)
	{
		std::cout << "1. Show tasks     2. Search tasks by date\n";
		std::cout << "3. Add new task   4. Delete task            5. Save & exit\n";
		action = 1;
		do
		{
			if ((action < 1) || (action > 4))
				std::cout << "Wrong code. Try again: ";
			else
				std::cout << "Enter code of action: ";
			std::cin >> action;
		} while ((action < 1) || (action > 4));

		switch (action)
		{
		case 1:
			print();
			break;
		case 2:
			unsigned d, m, y;
			std::cout << "Enter day, month, year (separating with spaces): ";
			std::cin >> d >> m >> y;
			print(date(d, m, y));
			break;
		case 3:
			// add...
			break;
		case 4:
			unsigned uid;
			std::cout << "Enter uid of task you want to delete: ";
			std::cin >> uid;
			if (remove(uid))
				std::cout << "Task successfully deleted.\n";
			else
				std::cout << "Something went wrong.\n";
			break;
		case 5:
			if (save())
			{
				std::cout << "All changes saved. Have a nice day!\n";
				return;
			}
			else
				std::cout << "Something went wrong.\n";
			break;
		}
	}
}

void TodoList::app::reset()
{
	if (tcount > 0)
	{
		for (std::list<ctask*>::iterator i = tasks.begin(); i != tasks.end(); ++i)
			delete *i;
		tasks = std::list<ctask*>();
	}
	if (!filename.empty())
		filename = "";
	tcount = 0;
}
