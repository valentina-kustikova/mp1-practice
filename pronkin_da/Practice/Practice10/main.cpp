#include "Task.h"
#include "Timeinterval.h"
#include "Allday.h"
#include <fstream>
#include <iostream>
#include <string>
#include "ToDoList.h"

void main() {
	ToDoList list;
	list.read("task.txt");
	Date date(10, 12, 07);
	list.write(date);
}