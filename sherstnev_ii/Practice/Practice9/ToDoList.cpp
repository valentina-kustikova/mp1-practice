#include "ToDoList.h"
#include "Type1.h"
#include "Type2.h"
#include <iostream>
#include <string>

using namespace std;

ToDoList::ToDoList(int k) {
	count = k;
	tasks = new Task*[k];
}

void ToDoList::Print(int k) {
	if (k < 0 || k >= count) throw (string)"Wrong number";
	tasks[k]->Print();
}

void ToDoList::Print(Date d) {
	for (int i = 0; i < count; i++) {
		cout << "Tasks for " << &d << endl;
		if (tasks[i]->getDate() == d) {
			tasks[i]->Print();
		}
	}
}

void ToDoList::Read(string &s, int k) {
	if (s[6] == '1') {
		int day = (int)s[9] * 10 + (int)s[10];
		int month = (int)s[12] * 10 + (int)s[13];
		int year = (int)s[15] * 1000 + (int)s[16] * 100 + (int)s[17] * 10 + (int)s[18];
		string descr = s.erase(23, s.length() - 1);
		Date d(day, month, year);
		Task* t = new Type1(d, descr);
		tasks[k] = t;
	}
	else {
		int day = (int)s[9] * 10 + (int)s[10];
		int month = (int)s[12] * 10 + (int)s[13];
		int year = (int)s[15] * 1000 + (int)s[16] * 100 + (int)s[17] * 10 + (int)s[18];
		int hours = (int)s[22] * 10 + (int)s[23];
		int minutes = (int)s[25] * 10 + (int)s[26];
		string descr = s.erase(31, s.length() - 1);
		Date d(day, month, year);
		Time time(hours, minutes);
		Task* t = new Type2(d, descr, time);
		tasks[k] = t;
	}
}

int ToDoList::GetCount() { return count; }