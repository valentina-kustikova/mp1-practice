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
	} while (!instance.open(filename));
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
	} while (!instance.create(filename));
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
		instance.print(date(d, m, y));
		break;
	case 3:
		// add...
		break;
	case 4:
		unsigned uid;
		std::cout << "Enter uid of task you want to delete: ";
		std::cin >> uid;
		if (instance.remove(uid))
			std::cout << "Task successfully deleted.\n";
		else
			std::cout << "Something went wrong.\n";
		break;
	case 5:
		if (instance.save())
		{
			std::cout << "All changes saved. Have a nice day!\n";
			return;
		}
		else
			std::cout << "Something went wrong.\n";
		break;
	}
}