#include <iostream>
#include "date.h"
#include "to_do_list.h"
#include "task1.h"
#include "task2.h"
#include "Exception.h"
#include <string>
#include <fstream>
using namespace std;

todolist::todolist(){
	count = 0;
}

todolist::~todolist()
{
	count = 0;
	delete[] * tasks;
}

void todolist::read() {
	string describe1;
	int n; //тип задания
	date dat;
	time start, finish;
	ifstream f("list_of_tasks.txt");
	if (!f.is_open())
		throw Exception("File is not open!");
	f >> count; //кол-во заданий
	tasks = new task*[count];
	for (int i = 0; i < count; i++){
		f >> n;
		if ((n!=1)&&(n!=2))
			throw Exception("Not correct type!");
		else if (n == 1){
			f >> dat;
			getline(f, describe1); 
			tasks[i] = new task1(describe1, dat);
		}
		else {
			f >> dat >> start >> finish;
			getline(f, describe1);
			tasks[i] = new task2(describe1, dat, start, finish);
		}
	}
	f.close();
}

void todolist::print(date dat)
{
	int f = -1;
	cout << endl << " Your plans on " << dat << ":"<< endl;
	for (int i = 0; i < count; i++){
		if (tasks[i]->receipt() == dat){
			tasks[i]->print();
			f = 1;
		}
	}
	if (f == -1)
		throw Exception("U don't have any plans on this day!");
};