#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Container
{
	T* arr;
	int realsize;
	int maxsize;
public:
	Container();
	Container(const Container& a);
	~Container();
	bool IsFull() const;
	bool IsEmpty() const;
	int Find(T a) const;
	void Add(T a);
	void Delete(T a);
	void resize();
	void print();
};

template<typename T>
Container<T>::Container()
{
	realsize = 0;
	maxsize = 10;
	arr = new T[maxsize];
}

template<typename T>
Container<T>::Container(const Container<T>& a)
{
	arr = new T[maxsize];
	realsize = a.realsize;
	for (int i = 0; i < realsize; i++)
		arr[i] = a.arr[i];
}

template<typename T>
Container<T>::~Container()
{
	delete[] arr;
}

template<typename T>
bool Container<T>::IsFull() const
{
	return (realsize == maxsize);
}

template<typename T>
bool Container<T>::IsEmpty() const
{
	return (realsize == 0);
}

template<typename T>
int Container<T>::Find(T a) const
{
	if (IsEmpty()) throw "Container is empty(nothing to find)";
	for (int i = 0; i < realsize; i++)
		if (arr[i] == a) return i;
	return -1;
}

template<typename T>
void Container<T>::Add(T a)
{
	if (IsFull()) resize();
	arr[realsize++] = a;
}

template<typename T>
void Container<T>::Delete(T a)
{
	if (IsEmpty()) throw "Container is empty(nothing to delete)";
	int idx = Find(a);
	if (idx == -1) throw "Cannot find an element";
	arr[idx] = arr[--realsize];
}

template <typename T>
void Container<T>::resize()
{
	T* tmparr = new T[realsize];
	for (int i = 0; i < realsize; i++)
		tmparr[i] = arr[i];
	delete[] arr;
	maxsize += 5;
	arr = new T[maxsize];
	for (int i = 0; i < realsize; i++)
		arr[i] = tmparr[i];
	delete[] tmparr;
}

template<typename T>
void Container<T>::print()
{
	if (IsEmpty()) throw "Container is empty(nothing to print)";
	for (int i = 0; i < realsize; i++)
		cout << "Element[" << i << "] = " << arr[i] << endl;
}

///////////////////////////////////////////////////////////////////////////////

template <typename T>
class Container<T*>
{
	T** arr;
	int realsize;
	int maxsize;
public:
	Container();
	Container(const Container<T*>& a);
	~Container();
	bool IsFull() const;
	bool IsEmpty() const;
	int Find(T a) const;
	void Add(T a);
	void Delete(T a);
	void print();
};

template<typename T>
Container<T*>::Container()
{
	realsize = 0;
	maxsize = 10;
	arr = new T*[maxsize];
}

template<typename T>
Container<T*>::Container(const Container<T*>& a)
{
	arr = new T*[maxsize];
	realsize = a.realsize;
	for (int i = 0; i < realsize; i++)
		arr[i] = new T(*(a.arr[i]));
}

template<typename T>
Container<T*>::~Container()
{
	for (int i = 0; i < realsize; i++)
		delete arr[i];
}

template<typename T>
bool Container<T*>::IsFull() const
{
	return (realsize == maxsize);
}

template<typename T>
bool Container<T*>::IsEmpty() const
{
	return (realsize == 0);
}

template<typename T>
int Container<T*>::Find(T a) const
{
	if (IsEmpty()) throw "Container is empty(nothing to find)*";
	for (int i = 0; i < realsize; i++)
		if (*(arr[i]) == a) return i;
	return -1;
}

template<typename T>
void Container<T*>::Add(T a)
{
	if (IsFull()) maxsize++;
	arr[realsize++] = new T(a);
}

template<typename T>
void Container<T*>::Delete(T a)
{
	if (IsEmpty()) throw "Container is empty(nothing to delete)*";
	int idx = Find(a);
	if (idx == -1) throw "Cannot find an element*";
	delete arr[idx];
	arr[idx] = arr[--realsize];
}

template<typename T>
void Container<T*>::print()
{
	if (IsEmpty()) throw "Container is empty(nothing to print)*";
	for (int i = 0; i < realsize; i++)
		cout << "Dereferenced element[" << i << "] = " << *(arr[i]) << endl;
}