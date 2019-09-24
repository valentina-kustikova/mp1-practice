#include <iostream>
#include <fstream>
#include <string>
#include "ToDoList.h"

using namespace std;

void main() {
	int count = 0;
	string s;
	ifstream file("tasks.txt");
	if (!file.is_open()) {
		cout << "File couldn`t be opened" << endl;
	}
	cout << "Source file: " << endl;
	while (getline(file, s)) {
		cout << s << endl;
		if (s != "~") count++; // Завершающий символ
	}
	cout << "Number of tasks: " << count << endl;
	ToDoList list(count);
	count = 0;
	while (getline(file, s)) {
		list.Read(s, count);
		count++;
	}
	file.close();
	cout << "Typing all list: " << endl;
	for (int i = 0; i < list.GetCount(); i++) list.Print(i);
	int day = 1;
	int month = 1;
	int year = 2019;
	while (day != 0) {
		try{
			cout << "Type date to watch tasks or type 0 to exit" << endl;
			cin >> day;
			if (day == 0) return;
			cin >> month;
			cin >> year;
			Date d(day, month, year);
			list.Print(d);
		}
		catch (string q) {
			cout << q << endl;
		}
	}
}