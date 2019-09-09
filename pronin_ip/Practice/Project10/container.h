#pragma once
#include <iostream>
using namespace std;
template <typename T, int maxsize>
class Container
{
private:
	T* arr;
	int count;
	const static int sizestap = 10;
public:
	Container(int, T*);
	Container();
	Container(const Container &);
	~Container();
	bool IsFull() const;
	bool IsEmpty() const;
	int Find(T) const;
	void Add(T);
	void Deletebyidx(int);
	void Delete(T);
	void AddSize(int);
	T& operator[](int);
	const T& operator[](int) const;
	friend ostream& operator<<(ostream& o, const Container& container)
	{
		for (int i = 0; i < container.count; i++)
			o << container.arr[i] << " ";
		return o;
	}
	friend istream&  operator>>(istream& in, Container& container)
	{

		for (int i = 0; i < container.count; i++)
			in >> container.arr[i];
		return in;
	}
};



template <typename T, int maxsize>
Container <T, maxsize> ::Container()
{
	cout = 5;
	arr = new T[maxsize];
}
template <typename T, int maxsize>
Container <T, maxsize> ::Container(int a, T* b)
{
	count = a;
	arr = new T[maxsize];
	for (int i = 0; i < count; i++)
		arr[i] = b[i];
}
template <typename T, int maxsize>
Container <T, maxsize> ::Container(const Container <T, maxsize> &a)
{
	count = a.count;
	arr = new T[count];
	for (int i = 0; i < count; i++)
		arr[i] = a.arr[i];
}
template <typename T, int maxsize>
Container <T, maxsize> ::~Container()
{
	count = 0;
	delete[] arr;
	arr = NULL;
}
template <typename T, int maxsize>
bool Container <T, maxsize>::IsFull() const
{
	return (count == maxsize);
}
template <typename T, int maxsize>
bool Container <T, maxsize>::IsEmpty() const
{
	return (count == 0);
}
template <typename T, int maxsize>
int Container <T, maxsize>::Find(T a) const
{
	int flag = -1;
	for (int i = 0; i < count; i++)
		if (arr[i] == a)
			flag = i;
	return flag;
}
template <typename T, int maxsize>
void Container <T, maxsize>::Add(T a)
{
	if (Find(a) == -1)
	{
		if (IsFull())
		{
			AddSize(0);
			cout << "maxsize was increased" << endl;
		}
		arr[count] = a;
		count++;
		cout << "element" << " " << a << " " << "was added successfully" << endl;
	}
	else
		//cout << "element" << " " << a << " " << "already exists" << endl;
		throw "element already exists";
}
template <typename T, int maxsize>
void Container <T, maxsize>::Deletebyidx(int idx)
{
	if (IsEmpty() || idx < 0 || idx > count)
		//cout << "element cant be deleted" << endl;
		throw "element cant be deleted";
	else
	{
		cout << "element" << " " << arr[idx] << " " << "was deleted successfully" << endl;
		arr[idx] = arr[count - 1];
		count--;
		
	}
}
template <typename T, int maxsize>
void Container <T, maxsize>::Delete(T a)
{
	if (Find(a) == -1)
		throw "element is not found";
	else
	{
		Deletebyidx(Find(a));
	}
}
template <typename T, int maxsize>
void Container <T, maxsize>::AddSize(int a)
{
	if (a == 0) a = sizestap;
	int max = maxsize;
	max += a;
	T* tmp = new T[max];
	for (int i = 0; i < count; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp; 
}
template <typename T, int maxsize>
T& Container <T, maxsize>::operator[](int a)
{
	return arr[a];
}
template <typename T, int maxsize>
const T& Container <T, maxsize>::operator[](int a) const
{
	return arr[a];
}

