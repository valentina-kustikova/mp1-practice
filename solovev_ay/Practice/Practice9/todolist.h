#include "date.h"
#include "task.h"
class list
{
public:
	task** lists;
	int count = 0;
	int number = 0;
	void add(ofstream& file);
	list(int count);
	list(const list& _copy);
	list();
	~list();
	int read_number();
	void read_tasks();
	void print_tasks();
	void print_task_date();
};

