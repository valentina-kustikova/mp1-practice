#include "ToDoList.h"

ToDoList::ToDoList() {
	n = 1;
	task = new Task*[n];
}

void ToDoList::read(string filename) {
	ifstream F;
	F.open(filename);
	string nstr; 
	getline(F, nstr);
	n = atoi(nstr.c_str());
	task = new Task*[n];
	for (int j = 0; j < n; j++) {
		string s, type;
		int i;
		getline(F, s);
		for (i = 0; i < 5; i++) {
			type += s[i];
		}
		if (type == "Type1") {
			i++;
			string name, tmp;
			char d, m, y;
			while (s[i] != ';') {
				name += s[i];
				i++;
			}
			i++;
			tmp += s[i];
			i++;
			tmp += s[i];
			d = atoi(tmp.c_str());
			i += 2;
			tmp = "";
			tmp += s[i];
			i++;
			tmp += s[i];
			m = atoi(tmp.c_str());
			i += 2;
			tmp = "";
			tmp += s[i];
			i++;
			tmp += s[i];
			y = atoi(tmp.c_str());
			try {
				Date date(d, m, y);
				task[j] = new Allday(name, date);
			}
			catch(char* str){
				cout << str << endl;
			}
		}
		else {
			i++;
			string name, tmp;
			char d, m, y, h, min;
			while (s[i] != ';') {
				name += s[i];
				i++;
			}
			i++;
			tmp += s[i];
			i++;
			tmp += s[i];
			d = atoi(tmp.c_str());
			i += 2;
			tmp = "";
			tmp += s[i];
			i++;
			tmp += s[i];
			m = atoi(tmp.c_str());
			i += 2;
			tmp = "";
			tmp += s[i];
			i++;
			tmp += s[i];
			y = atoi(tmp.c_str());
			i += 2;
			tmp = "";
			tmp += s[i];
			i++;
			tmp += s[i];
			h = atoi(tmp.c_str());
			i += 2;
			tmp = "";
			tmp += s[i];
			i++;
			tmp += s[i];
			min = atoi(tmp.c_str());
			try {
				Date date(d, m, y);
				Time time(h, min);
				task[j] = new Timeinterval(name, date, time);
			}
			catch(char* str){
				cout << str << endl;
			}
		}
	}
}

void ToDoList::write(Date _date) {
	for (int i = 0; i < n; i++)
		if (task[i]->rdate() == _date) task[i]->print();
}

ToDoList::~ToDoList() {
	delete[]task;
}