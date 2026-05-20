#ifndef STRUCU_H
#define STRUCU_H

#include <string>
#include <iostream>
#include "cstdlib"

using namespace std;

template <typename T>
class Container {
	int size, capacity;
	const int step;
	T* elems;
public:
	Container();
	Container(int size, const int step);
	Container(int size, const T& elem, const int step);
	Container(const Container <T>& c1);
	~Container();
	void push_back(T& elem);
	void remove(T& elem);
	const Container<T>& operator = (const Container <T>& c1);
	T& operator [] (int i);
	int find(T& elem);
};


template <typename T>
class Container<T*> {
	int size, capacity;
	const int step;
	T** elems;
public:
	Container();
	Container(int size, const int step);
	Container(int size, T* const& elem, const int step);
	Container(const Container <T*>& c1);
	~Container();
	void push_back(T* const& elem);
	void remove(T* const& elem);
	const Container<T*>& operator = (const Container <T*>& c1);
	T*& operator [] (int i);
	int find(T* const& elem);
};

//T
template <typename T>
Container<T>::Container()
	:step(1)
{
	size = capacity = 0;
	elems = nullptr;
}

template <typename T>
Container<T>::Container(int size, const int step)
	:size(size), step(step), capacity(0)
{
	elems = new T[size];
}
template <typename T>
Container<T>::Container(int size, const T& elem, const int step)
	: size(size), step(step), capacity(size)
{
	elems = new T[size];
	for (int i = 0; i < size; i++)
		elems[i] = elem;
}
template <typename T>
Container<T>::Container(const Container <T>& c1)
	:size(c1.size), step(c1.step), capacity(c1.capacity)
{
	elems = new T[size];
	for (int i = 0; i < capacity; i++)
		elems[i] = c1.elems[i];
}
template <typename T>
Container<T>::~Container()
{
	delete[] elems;
}
template <typename T>
void Container<T>::push_back(T& elem)
{
	if (size == capacity)
	{
		size = capacity + step;
		elems = (T*)realloc(elems, size * sizeof(T));
	}
	elems[capacity++] = elem;
}
template <typename T>
void Container<T>::remove(T& elem)
{
	int i = find(elem);
	if (i == -1)
		throw std::exception("not-found");
	elems[i] = elems[--capacity];
}
template <typename T>
const Container<T>& Container<T>::operator = (const Container <T>& c1)
{
	if (this == &c1)
		return *this;
	if (size != c1.size)
	{
		delete[] elems;
		size = c1.size;
		capacity = c1.capacity;
		elems = new T[size];
	}
	for (int i = 0; i < capacity; i++)
		elems[i] = c1.elems[i];
	return *this;
}
template <typename T>
T& Container<T>::operator [] (int i)
{
	if (i >= size)
		throw std::exception("out-of-range");
	return elems[i];
}
template <typename T>
int Container<T>::find(T& elem)
{
	for (int i = 0; i < capacity; i++)
		if (elems[i] == elem)
			return i;
	return -1;
}
//T*
template <typename T>
Container<T*>::Container()
	:step(1)
{
	size = capacity = 0;
	elems = nullptr;
}
template <typename T>
Container<T*>::Container(int size, const int step)
	:size(size), step(step), capacity(0)
{
	elems = new T*[size];
	for (int i = 0; i < size; i++)
		elems[i] = nullptr;
}
template <typename T>
Container<T*>::Container(int size, T* const& elem, const int step)
	: size(size), step(step), capacity(size)
{
	elems = new T*[size];
	for (int i = 0; i < size; i++)
		elems[i] = new T(*elem);
}
template <typename T>
Container<T*>::Container(const Container <T*>& c1)
	:size(c1.size), step(c1.step), capacity(c1.capacity)
{
	elems = new T*[size];
	for (int i = 0; i < capacity; i++)
		elems[i] = new T(*(c1.elems[i]));
}
template <typename T>
Container<T*>::~Container()
{
	for (int i = 0; i < capacity; i++)
	{
		delete elems[i];
	}
	delete[] elems;
}
template <typename T>
void Container<T*>::push_back(T* const& elem)
{
	if (size == capacity)
	{
		size = capacity + step;
		elems = (T**)realloc(elems, size * sizeof(T*));
	}
	elems[capacity++] = elem;
}
template <typename T>
void Container<T*>::remove(T* const& elem)
{
	int i = find(elem);
	if (i == -1)
		throw std::exception("not-found");
	delete elems[i];
	elems[i] = elems[--capacity];
}
template <typename T>
const Container<T*>& Container<T*>::operator = (const Container <T*>& c1)
{
	if (this == &c1)
		return *this;
	if (size != c1.size)
	{
		delete[] elems;
		size = c1.size;
		elems = new T*[size];
	}
	capacity = c1.capacity;
	for (int i = 0; i < capacity; i++)
		elems[i] = new T(*(c1.elems[i]));
	return *this;
}
template <typename T>
T*& Container<T*>::operator [] (int i)
{
	if (i >= size)
		throw std::exception("out-of-range");
	return elems[i];
}
template <typename T>
int Container<T*>::find(T* const& elem)
{
	for (int i = 0; i < capacity; i++)
		if (elems[i] == elem)
			return i;
	return -1;
}

#endif 

