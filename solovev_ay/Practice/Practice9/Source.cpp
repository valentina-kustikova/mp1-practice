#include <iostream>
#include "date.h"
#include "taskall.h"
#include "time.h"
#include "tasktime.h"
#include "todolist.h"
using namespace std;
int main()
{
	list to_do_list;
	std::ofstream out("text.txt", std::ios::app);
	cout << "dobavte novuyu zadacu" << endl;
	cout << "press 1 to time task, 2 to no time task" << endl;
	to_do_list.add(out);
	out.close();
	int n = 0;
	do {
		try
		{
			to_do_list.read_tasks();
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k << std::endl;
			system("pause");
			return 0;
		}
	} while (n != 1);

	do {
		try
		{
			to_do_list.print_tasks();
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k << std::endl;
		}
	} while (n != 1);

	do {
		try
		{
			to_do_list.print_task_date();
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k << std::endl;
		}
	} while (n != 1);
	cout << "prezhde cem zapisat zanovo, izmenite v task.txt 1 stroku na +1" << endl;
	system("pause");
}