#include "../headers/App.h"

bool TodoList::app::open(std::string& filename)
{
	reset();
	bool successful = true;
	std::ifstream fin(filename.c_str());
	if (!fin.is_open())
	{
		fin.open((filename + ".todo").c_str());
		if (!fin.is_open())
		{
			throw app_exception::file_open(filename);
			return false;
		}
		else
			this->filename = filename + ".todo";
	}
	else
		this->filename = filename;
	while (!fin.eof())
	{
		std::string line;  // 0 02032019 123 456 Text
		std::getline(fin, line, '\n');
		if (line.empty())
			continue;
		task::type ttype = task::type::t_std;
		ctask* next_task = nullptr;
		try
		{
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
			if (ttype == task::t_std)
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
		}
		catch (std::out_of_range)
		{
			throw app_exception::parsing(filename);
			successful = false;
			return false;
		}
		tasks.push_back(next_task);
		tcount++;
	}
	return successful;
}

bool TodoList::app::create(std::string& filename)
{
	reset();
	filename += ".todo";
	std::ofstream fout(filename.c_str());
	tcount = 0;
	bool result = fout.is_open();
	if (!result)
	{
		throw app_exception::file_write(filename);
	}
	else
	{
		fout.close();
		this->filename = filename;
	}
	return result;
}

bool TodoList::app::save()
{
	std::ofstream fout(filename.c_str());
	if (!fout.is_open())
	{
		throw app_exception::file_write(filename);
		return false;
	}
	for (std::list<ctask*>::iterator i = tasks.begin(); i != tasks.end(); ++i)
	{
		(*i)->print(fout);
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
	ctask* next_task = new task::std(title, start, t_start, t_end);
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
	throw app_exception::bad_uid(uid);
	return false;
}

void TodoList::app::print()
{
	if (!tcount)
	{
		std::cout << "There is no tasks in this list.\n";
		return;
	}
	std::cout << "---------------------------------------------------------\n";
	for (std::list<ctask*>::iterator i = tasks.begin(); i != tasks.end(); ++i)
	{
		(*i)->print();
	}
	std::cout << "---------------------------------------------------------\n";
}

void TodoList::app::print(date d)
{
	std::cout << "---------------------------------------------------------\n";
	int k = 0;
	for (std::list<ctask*>::iterator i = tasks.begin(); i != tasks.end(); ++i)
	{
		if ((*i)->start == d)
		{
			(*i)->print();
			k++;
		}
	}
	if (!k)
		std::cout << "There is no tasks on this date.\n";
	std::cout << "---------------------------------------------------------\n";
}

void TodoList::app::print(unsigned uid)
{
	for (std::list<ctask*>::iterator i = tasks.begin(); i != tasks.end(); ++i)
	{
		if ((*i)->get_uid() == uid)
		{
			(*i)->print();
			return;
		}
	}
	throw app_exception::bad_uid(uid);
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
f1inp:	try
		{
			do
			{
				if (attempts > 0)
					std::cout << " Try again: ";
				else
					std::cout << "Enter path to file: ";
				std::cin >> tmp;
				attempts++;
			} while (!open(tmp));
		}
		catch (app_exception::file_open e)
		{
			std::cout << "[ERROR] " << e.what();
			goto f1inp;
		}
		break;
	case 2:
f2inp:  try
		{
			do
			{
				if (attempts > 0)
					std::cout << " Try again: ";
				else
					std::cout << "Enter list name (filename will be <your_name>.todo): ";
				std::cin >> tmp;
				attempts++;
			} while (!create(tmp));
		}
		catch (app_exception::file_write e)
		{
			std::cout << "[ERROR] " << e.what() << '\n';
			goto f2inp;
		}
		catch (app_exception::parsing e)
		{
			std::cout << "[ERROR] " << e.what() << '\n';
			goto f2inp;
		}
		break;
	}

	system("cls");
	std::cout << "GOOGLE CALENDAR :: " << this->filename << '\n';
	unsigned d, m, y, h;
	while (1)
	{
		std::cout << "1. Show tasks     2. Search tasks by date\n";
		std::cout << "3. Add new task   4. Delete task            5. Save & exit\n";
		action = 1;
		do
		{
			if ((action < 1) || (action > 5))
				std::cout << "Wrong code. Try again: ";
			else
				std::cout << "Enter code of action: ";
			std::cin >> action;
		} while ((action < 1) || (action > 5));

		date t_date;
		time t_start, t_end;
		std::string title;
		switch (action)
		{
		case 1:
			print();
			break;
		case 2:
			std::cout << "Enter day, month, year (separating with spaces): ";
d2inp:		std::cin >> d >> m >> y;
			try
			{
				print(date(d, m, y));
			}
			catch (date_exception::bad_day e)
			{
				std::cout << "[ERROR] " << e.what() << " Try again: ";
				goto d2inp;
			}
			catch (date_exception::bad_month e)
			{
				std::cout << "[ERROR] " << e.what() << " Try again: ";
				goto d2inp;
			}
			catch (date_exception::bad_year e)
			{
				std::cout << "[ERROR] " << e.what() << " Try again: ";
				goto d2inp;
			}
			break;
		case 3:
			int type;
			type = 1;
			do
			{
				if ((type < 0) || (type > 1))
					std::cout << "Wrong type. Try again: ";
				else
					std::cout << "Enter type of task (0 - with start and end time, 1 - for whole day): ";
				std::cin >> type;
			} while ((type < 0) || (type > 1));
			std::cout << "Enter day, month, year (separating with spaces): ";
d3inp:		std::cin >> d >> m >> y;
			try
			{
				t_date(d, m, y);
			}
			catch (date_exception::bad_day e)
			{
				std::cout << "[ERROR] " << e.what() << " Try again: ";
				goto d3inp;
			}
			catch (date_exception::bad_month e)
			{
				std::cout << "[ERROR] " << e.what() << " Try again: ";
				goto d3inp;
			}
			catch (date_exception::bad_year e)
			{
				std::cout << "[ERROR] " << e.what() << " Try again: ";
				goto d3inp;
			}
			if (type == 0)
			{
				std::cout << "Enter hour, min of start (separating with spaces): ";
t3_sinp: 		std::cin >> h >> m;
				try
				{
					t_start(h, m);
				}
				catch (time_exception::bad_hour e)
				{
					std::cout << "[ERROR] " << e.what() << " Try again: ";
					goto t3_sinp;
				}
				catch (time_exception::bad_min e)
				{
					std::cout << "[ERROR] " << e.what() << " Try again: ";
					goto t3_sinp;
				}
				std::cout << "Enter hour, min of end (separating with spaces): ";
t3_einp: 		std::cin >> h >> m;
				try
				{
					t_end(h, m);
				}
				catch (time_exception::bad_hour e)
				{
					std::cout << "[ERROR] " << e.what() << " Try again: ";
					goto t3_einp;
				}
				catch (time_exception::bad_min e)
				{
					std::cout << "[ERROR] " << e.what() << " Try again: ";
					goto t3_einp;
				}
			}
			std::cout << "Enter title or description of task: ";
			getchar();
			getline(std::cin, title);
			if (type == 0)
				add(title, t_date, t_start, t_end);
			else
				add(title, t_date);
			std::cout << "Task added successfully.\n";
			break;
		case 4:
			unsigned uid;
			std::cout << "Enter uid of task you want to delete: ";
i_inp:		std::cin >> uid;
			try
			{
				if (remove(uid))
					std::cout << "Task successfully deleted.\n";
			}
			catch (app_exception::bad_uid e)
			{
				std::cout << "[ERROR] " << e.what() << " Try again: ";
				goto i_inp;
			}
			break;
		case 5:
			try
			{
				save();
			}
			catch (app_exception::file_write e)
			{
				std::cout << "[ERROR] " << e.what() << '\n';
				goto s_brk;
			}
			std::cout << "All changes saved. Have a nice day!\n";
			return;
s_brk:		break;
		}
		std::cout << '\n';
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

TodoList::app_exception::parsing::parsing()
{
	value = "";
}

TodoList::app_exception::parsing::parsing(std::string value)
{
	this->value = value;
}

const char* TodoList::app_exception::parsing::what() const
{
	return what_str.c_str();
}

TodoList::app_exception::file_open::file_open()
{
	value = "";
}

TodoList::app_exception::file_open::file_open(std::string value)
{
	this->value = value;
}

const char* TodoList::app_exception::file_open::what() const
{
	return what_str.c_str();
}

TodoList::app_exception::file_write::file_write()
{
	value = "";
}

TodoList::app_exception::file_write::file_write(std::string value)
{
	this->value = value;
}

const char* TodoList::app_exception::file_write::what() const
{
	return what_str.c_str();
}

TodoList::app_exception::bad_uid::bad_uid()
{
	value = 0U;
}

TodoList::app_exception::bad_uid::bad_uid(unsigned value)
{
	this->value = value;
}

const char* TodoList::app_exception::bad_uid::what() const
{
	return what_str.c_str();
}