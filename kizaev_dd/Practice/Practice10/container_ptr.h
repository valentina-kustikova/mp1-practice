#pragma once
#include <iostream>
#include "container.h"
using namespace std;

template <typename T>
class container<T*>
{
private:
	T** arr;
	int n;
	int len;
	void addspace(int i);
public:
	container();
	container(int i);
	container(const container& c);
	~container();

	bool checkfull()const;
	bool checkempty()const;

	int elem_find(T t)const;
	void elem_add(T* t);
	void elem_delete(T t);
	T& operator[](int i);
	const T& operator[](int i)const;

	friend istream& operator>>(istream& in, container& c)
	{
		for (int i = 0; i < c.n; i++)
			in >> c[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, const container& c)
	{
		for (int i = 0; i < c.n; i++)
			out << c[i] << " ";
		return out;
	}
};

template <typename T>
container<T*>::container()
{
	n = 0;
	len = 0;
}

template <typename T>
container<T*>::container(int i)
{
	len = i;
	n = 0;
	arr = new T*[len];
}

template <typename T>
container<T*>::container(const container& c)
{
	n = c.n;
	len = c.len;
	arr = new T*[len];
	for (int i = 0; i < n; i++)
		arr[i] = new T(*(c.arr[i]));
}

template <typename T>
container<T*>::~container()
{
	for (int i = 0; i < n; i++)
	{
		delete arr[i];
	}
	delete arr;
	n = 0;
}

template <typename T>
bool container<T*>::checkfull()const
{
	return (n == len);
}

template <typename T>
bool container<T*>::checkempty()const
{
	return (n == 0);
}

template <typename T>
int container<T*>::elem_find(T t)const
{
	for (int i = 0; i < n; i++)
		if (*arr[i] == t)
			return i;
	throw mistakes(4);
	return -1;
}

template <typename T>
void container<T*>::elem_add(T* t)
{
	if (this->checkfull())
		this->addspace(1);
	arr[n++] = new T(*t);
}

template <typename T>
void container<T*>::elem_delete(T t)
{
	if (this->checkempty())
		throw mistakes(1);
	int j = elem_find(t);
	if (j == -1)
		throw mistakes(2);
	delete arr[j];
	arr[j] = arr[n - 1];
	arr[--n] = 0;
}

template <typename T>
T& container<T*>::operator[](int i)
{
	if ((i < 0) || (i >= n))
		throw mistakes(3);;
	return *arr[i];
}

template <typename T>
const T& container<T*>::operator[](int i)const
{
	if ((i < 0) || (i >= n))
		throw mistakes(3);
	return *arr[i];
}

template <typename T>
void container<T*>::addspace(int i)
{
	len += i;
	T** tn = new T*[len];
	for (int i = 0; i < n; i++)
	{
		tn[i] = arr[i];
	}
	arr = tn;
}