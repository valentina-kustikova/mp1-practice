#include "ToDoList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ToDoList::ToDoList()
{
	n = 0;
	list = NULL;
}
ToDoList::ToDoList(int _n)
{
	n = _n;
	list = new Task*[n];
}
ToDoList::~ToDoList()
{
	for (int i = 0; i < n; i++)
		delete list[i];
	delete list;
	n = 0;
}
void ToDoList::Read(char* adr)
{
	ifstream fin(adr);
	if (!fin.is_open())
		throw "No File";
	fin >> n;
	list = new Task*[n];
	int type;
	int y, m, d;
	int min, h, dur;
	char* c = new char[50];
	string des, ss;
	for (int i = 0; i < n; i++)
	{
		fin >> type;
		if (type == 1)
		{
			int start, finish;
			fin.getline(c, 50);
			des = string(c);

			finish = des.find("/");
			start = des.rfind(" ", finish);
			ss = des.substr((start + 1), (finish - start - 1));
			d = atoi(ss.c_str());
			ss = "";

			start = finish;
			finish = des.find(".", start + 1);
			ss = des.substr((start + 1), (finish - start - 1));
			m = atoi(ss.c_str());
			ss = "";

			start = finish;
			finish = des.find(" ", start);
			ss = des.substr((start + 1), (finish - start - 1));
			y = atoi(ss.c_str());
			ss = "";

			start = finish;
			finish = des.find("/0", start);
			ss = des.substr((start + 1), (finish - start - 1));
			des = ss;
			ss = "";

			Date date = Date(y, m, d);
			list[i] = new Type1(des, date);
		}
		if (type == 2)
		{
			int start, finish;
			fin.getline(c, 50);
			des = string(c);

			finish = des.find("/");
			start = des.rfind(" ", finish);
			ss = des.substr((start + 1), (finish - start - 1));
			d = atoi(ss.c_str());
			ss = "";

			start = finish;
			finish = des.find(".", start + 1);
			ss = des.substr((start + 1), (finish - start - 1));
			m = atoi(ss.c_str());
			ss = "";

			start = finish;
			finish = des.find(" ", start);
			ss = des.substr((start + 1), (finish - start - 1));
			y = atoi(ss.c_str());
			ss = "";

			finish = des.find(":");
			start = des.rfind(" ", finish);
			ss = des.substr((start + 1), (finish - start - 1));
			h = atoi(ss.c_str());
			ss = "";

			start = finish;
			finish = des.find(" ", start);
			ss = des.substr((start + 1), (finish - start - 1));
			min = atoi(ss.c_str());
			ss = "";

			start = des.find_first_of("1234567890", finish);
			finish = des.find(" ", start);
			ss = des.substr(start, (finish - start));
			dur = atoi(ss.c_str());
			ss = "";

			start = finish;
			finish = des.find("/0", start);
			ss = des.substr((start + 1), (finish - start - 1));
			des = ss;
			ss = "";

			Date date = Date(y, m, d);
			Time time = Time(h, min);
			list[i] = new Type2(des, date, time, dur);
		}
	}
	fin.close();
}
void ToDoList::Vivod(Date dat)
{
	for (int i = 0; i < n; i++)
		if (list[i]->GetDate() == dat)
			list[i]->Print();
}