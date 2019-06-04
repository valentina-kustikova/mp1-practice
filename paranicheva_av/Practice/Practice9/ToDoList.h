#ifndef TODOLIST_H
#define TODOLIST_H

class Todolist
{
private:
    Task **tasks;
	int count;
public:
	Todolist();
	Todolist(int _count);
	~Todolist();

	void Read(std::string &path);
	void Print();
};

#endif
