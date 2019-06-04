#include <iostream>
#include <string>
#include "Task.h"
#include "Date.h"
#include "Time.h"
#include "ToDoList.h"
using namespace std;

void main()
{
	Todolist List;
	try
	{
    		std::string path;
    		cout << "Enter the path to the folder" << endl;
    		cin >> path; //C:/Temp/Text.txt"
		List.Read(path);
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	List.Print();
}
