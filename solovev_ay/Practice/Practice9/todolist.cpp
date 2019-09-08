#include "tasktime.h"
#include "todolist.h"
#include "task.h"
#include "taskall.h"
using namespace std;
void list::add(ofstream& file)
{
	int a;
	this->lists = new task*[count];
	cin >> a;
	if (a == 1)
	{
		tasktime a;
		a.input();
		a.fwrite(file);
		count++;
	}
	else
	{
		taskall b;
		b.input();
		b.fwrite(file);
		count++;
	}
}
list::list()
{
	count = 0;
	lists = NULL;
	
}
list::list(int _count)
{
	if (_count < 1)
		throw "hmm, no tasks";

	count = _count;
	lists = new task*[count];
}

list::list(const list & _copy)
{
	delete[] * lists;

	count = _copy.count;
	lists = new task*[count];

	for (unsigned int i = 0; i < count; i++)
		lists[i] = _copy.lists[i];
}


list::~list()
{
	delete[]* lists;
	count = 0;
}
int list::read_number()
{
	char number_tasks[2];
	std::ifstream istm;
	istm.open("text.txt");
	if (!istm.is_open())
	{
		throw "file no";
	}
	istm >> number_tasks;
	number = atoi(number_tasks);
}
void list::read_tasks()
{
	read_number();
	std::string buff;
	std::ifstream istm;
	istm.open("text.txt");
	this->lists = new task*[number];
	getline(istm, buff);
	for (int i = 0; i < number; i++)
	{
		getline(istm, buff);
		char _type = (char)stoul(buff);
		unsigned long _day = stoul(buff.substr(2, 2));
		unsigned long _mon = stoul(buff.substr(5, 2));
		unsigned long _year = stoul(buff.substr(8, 4));
		date tmp(_day, _mon, _year);
		if (_type == 2)
		{
			task* Type1 = new taskall;
			Type1->Date = tmp;
			Type1->descrip = buff.substr(13);
			lists[i] = Type1;
		}
		if (_type == 1)
		{
			task* Type2 = new tasktime;
			Type2->Date = tmp;
			unsigned long _h_start = stoul(buff.substr(13, 2));
			unsigned long _m_start = stoul(buff.substr(16, 2));
			time _start(_h_start, _m_start);
			Type2->settime(_start);
			unsigned long _h_end = stoul(buff.substr(19, 2));
			unsigned long _m_end = stoul(buff.substr(22, 2));
			Type2->descrip = buff.substr(25);
			time _end(_h_end, _m_end);
			Type2->settimeend(_end);
			lists[i] = Type2;
		}
	}
	istm.close();
}
void list::print_tasks()
{
	cout << "All tasks: " << endl;
	for (int i = 0; i < number; i++)
		lists[i]->print();
}
void list::print_task_date(int a, int b, int c)
{
	date tmp;
	int _tmp;
	cout << "zadaci po konkretnoi date" << endl;
	cout << "vvedi den': ";
	cin >> _tmp;
	tmp.day=a;
	cout << "vvedi mesac: ";
	cin >> _tmp;
	tmp.month=b;
	cout << "vvedi god: ";
	cin >> _tmp;
	tmp.year=c;
	int flag = 0;
	for (int i = 0; i < number; i++)
	{
		if (tmp == lists[i]->Date)
		{
			lists[i]->print();
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "No tasks" << endl;
	}
}



