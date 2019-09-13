#pragma once
#include "mistakes.h"
#include <iostream>
 
using namespace std;

template <class T>
class container
{
private:
	T* arr;
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
	void elem_add(T t);
	void elem_delete(T t);
	T& operator[](int i);
	const T& operator[](int i)const;

	friend istream& operator>>(istream& stream, container& c)
	{
		for (int i = 0; i < c.n; i++)
			stream >> c[i];
		return stream;
	}

	friend ostream& operator<<(ostream& stream, const container& c)
	{
		for (int i = 0; i < c.n; i++)
			stream << c[i] << " ";
		return stream;
	}
};

template <class T>
container <T>::container()
{
	n = 0;
	len = 0;
}

template <class T>
container<T>::container(int i)
{
	n = 0;
	len = i;
	arr = new T[len];
}

template <class T>
container<T>::container(const container& c)
{
	n = c.n;
	len = c.len;
	arr = new T[len];
	for (int i = 0; i < n; i++)
		arr[i] = c.arr[i];
}

template <class T>
container<T>::~container()
{
	delete arr;
	n = 0;
	len = 0;
}

template <class T>
bool container<T>::checkfull()const
{
	if (n == len)
		return true;
	else
		return false;
}

template <class T>
bool container<T>::checkempty()const
{
	if (n == 0)
		return true;
	else
		return false;
}

template <class T>
int container<T>::elem_find(T t)const
{
	for (int i = 0; i < n; i++)
		if (arr[i] == t)
			return i;
	throw mistakes(4);
	return -1;
}

template <class T>
void container<T>::elem_add(T t)
{
	if (this->checkfull())
		this->addspace(1);
	arr[n] = t;
	n++;
}

template <class T>
void container<T>::elem_delete (T t)
{
	if (this->checkempty())
		throw mistakes (1);
	int j = elem_find(t);
	if (j == -1)
		throw mistakes (2);
	n--;
	arr[j] = arr[n];
}

template <class T>
T& container<T>::operator[](int i)
{
	if ((i < 0) || (i >= n))
		throw mistakes (3);
	return arr[i];
}

template <class T>
const T& container<T>::operator[](int i)const
{
	if ((i < 0) || (i >= n))
		throw mistakes (3);
	return arr[i];
}

template <class T>
void container<T>::addspace(int i)
{
	len += i;
	T* t_new = new T[len];
	for (int i = 0; i < n; i++)
		t_new[i] = arr[i];
	arr = t_new;
}