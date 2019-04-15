#include "../headers/App.h"

bool TodoList::app::open(const char* filename)
{
	reset();
	fin.open(filename);
	if (!fin.is_open())
		return false;
	// some processing
	return true;
}

bool TodoList::app::create(const char* filename)
{
	reset();
	size_t len = 0;
	for (; filename[len]; len++);
	char* tmp = new char[len + 5 + 1]; // "<filename>.todo\0"
	for (size_t i = 0; tmp[i] = filename[i]; i++);
	tmp[len + 0] = '.';
	tmp[len + 1] = 't';
	tmp[len + 2] = 'o';
	tmp[len + 3] = 'd';
	tmp[len + 4] = 'o';
	tmp[len + 5] = '\0';
	this->filename = tmp;
	fin.open(this->filename);
	bool result = fin.is_open();
	if (fin.is_open())
		fin.close();
	return result;
}

bool TodoList::app::save()
{
	if (fin.is_open())
		fin.close();
	fout.open(filename);
	if (!fout.is_open())
		return false;
	for (size_t i = 0; i < tcount; i++)
	{
		task::type ttype = tasks[i]->get_type();
		fout << ttype << ' ';
		fout << tasks[i]->start;
		if (ttype == task::type::std)
			fout << tasks[i]->get_start() << ' ' << tasks[i]->get_end() << ' ';
		fout << tasks[i]->title << '\n';
	}
	fout.close();
	return true;
}

TodoList::app::app()
{
	uid_stream = 1;
	tcount = 0;
	tasks = nullptr;
	filename = nullptr;
}

TodoList::app::~app()
{
	reset();
}

void TodoList::app::start()
{
	/*std::cout << "GOOGLE CALENDAR\n";
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

	char* filename = new char[200];
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
			std::cin >> filename;
			attempts++;
		} while (!open(filename));
		break;
	case 2:
		do
		{
			if (attempts > 0)
				std::cout << "Incorrect name. Try again: ";
			else
				std::cout << "Enter list name (filename will be <your_name>.todo): ";
			std::cin >> filename;
			attempts++;
		} while (!create(filename));
		break;
	}

	system("cls");
	std::cout << "GOOGLE CALENDAR :: " << filename << (action == 1 ? "" : ".todo") << '\n';
	delete[] filename;
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
	}*/
}

void TodoList::app::reset()
{
	if (fin.is_open())
		fin.close();
	if (fout.is_open())
		fout.close();
	if (tcount > 0)
	{
		for (size_t i = 0; i < tcount; i++)
			delete tasks[i];
		delete[] tasks;
	}
	if (filename)
		delete[] filename;
	tasks = nullptr;
	tcount = 0;
	filename = nullptr;
	uid_stream = 1;
}
