#ifndef _CONTAINER_H
#define _CONTAINER_H

template<typename T>
class Container {
private:
	int size, capacity, step;
	T* elem;
	void reallocation();
public:
	Container();
	Container(int, int);
	Container(int, int, const T&);
	Container(const Container<T>&);
	void push_back(T&);
	void remove(T&);
	T& operator[](int);
	const Container <T>& operator = (const Container <T>&);
	~Container();
	int find(T&);
};

template<typename T>
class Container <T*>{
private:
	int size, capacity, step;
	T** elem;
	void reallocation();
public:
	Container();
	Container(int, int);
	Container(int, int, const T*&);
	Container(const Container<T*>&);
	void push_back(T*&);
	void remove(T*&);
	T*& operator[](int);
	const Container <T*>& operator = (const Container <T*>&);
	~Container();
	int find(T*&);
};
#include <iostream>
#include "container.hpp"


template <typename T>
Container <T>::Container() :
	size(0), capacity(0), step(1)
{
	elem = nullptr;
}

template <typename T>
void Container <T>::reallocation()
{
	if (size == capacity)
	{
		size += step;
		T* new_data = new T[size];
		for (int i = 0; i < capacity; i++)
			new_data[i] = elem[i];
		delete[] elem;
		elem = new_data;
	}
}


template <typename T>
Container <T>::Container(int size, int step) :
	size(size), capacity(0), step(step)
{
	elem = new T[size];
}

template <typename T>
Container <T>::Container(int size, int step, const T& element) :
	size(size), capacity(size), step(step)
{
	elem = new T[size];
	for (int i = 0; i < size; i++)
		elem[i] = element;
}

template <typename T>
Container <T>::Container(const Container& c1) :
	size(c1.size), capacity(c1.capacity), step(c1.step)
{
	elem = new T[size];
	for (int i = 0; i < capacity; i++)
		elem[i] = c1.elem[i];
}

template <typename T>
const Container <T>& Container <T>:: operator = (const Container <T>& c1)
{
	if (this == &c1)
		return *this;
	if (size != c1.size)
	{
		delete[] elem;
		size = c1.size;
		capacity = c1.capacity;
		elem = new T[size];
	}
	for (int i = 0; i < capacity; i++)
		elem[i] = c1.elem[i];

	return *this;
}

template <typename T>
Container <T>::~Container()
{
	delete [] elem;
}

template <typename T>
T& Container <T>::operator[](int i)
{
	if (i >= size)
		throw std::exception("out_of_range");
	return elem[i];
}

template <typename T>
void Container <T>::push_back(T& element)
{
	if (size == capacity)
		reallocation();
	elem[capacity++] = element;
}

template <typename T>
int Container<T>::find(T& element)
{
	for (int i = 0; i < capacity; i++)
		if (elem[i] == element)
			return i;
	return -1;
}

template <typename T>
void Container <T>::remove(T& element)
{
	int i = find(element);
	if (i == -1)
		throw std::exception("not_found");
	elem[i] = elem[--capacity];
}

///////////////////////////////////////////////////////////////////////
template <typename T>
Container <T*>::Container() :
	size(0), capacity(0), step(1)
{
	elem = nullptr;
}

template <typename T>
void Container <T*>::reallocation()
{
	if (size == capacity)
	{
		size += step;
		T** new_data = new T * [size];
		for (int i = 0; i < size; i++)
			new_data[i] = new T(*elem[i]);
		for (int i = 0; i < capacity; i++)
			delete elem[i];
		delete[]elem;
	}
}


template <typename T>
Container <T*>::Container(int size, int step) :
	size(size), capacity(0), step(step)
{
	elem = new T * [size];
	for (int i = 0; i < size; i++)
		elem[i] = nullptr;
}

template <typename T>
Container <T*>::Container(int size, int step, const T*& element) :
	size(size), capacity(size), step(step)
{
	elem = new T * [size];
	for (int i = 0; i < size; i++)
		elem[i] = new T(*element);
}

template <typename T>
Container <T*>::Container(const Container& c1) :
	size(c1.size), capacity(c1.capacity), step(c1.step)
{
	elem = new T * [size];
	for (int i = 0; i < capacity; i++)
		elem[i] = new T(*c1.elem[i]);
}

template <typename T>
const Container <T*>& Container <T*>:: operator = (const Container <T*>& c1)
{
	if (this == &c1)
		return *this;
	if (size != c1.size)
	{
		for (int i = 0; i < size; i++)
		{
			delete elem[i];
		}
		delete[] elem;

		size = c1.size;
		capacity = c1.capacity;
		step = c1.step;

		elem = new T * [size];

		for (int i = 0; i < size; i++)
			elem[i] = nullptr;

		for (int i = 0; i < capacity; i++)
			elem[i] = new T(*c1.elem[i]);
	}

	return *this;
}

template <typename T>
Container <T*>::~Container()
{
	for (int i = 0; i < size; i++)
	{
		delete elem[i];
	}
	delete[] elem;
}

template <typename T>
T*& Container <T*>::operator[](int i)
{
	if (i >= size)
		throw std::exception("out_of_range");
	return elem[i];
}

template <typename T>
void Container <T*>::push_back(T*& element)
{
	if (size == capacity)
		reallocation();
	elem[capacity++] = new T(*element);
}

template <typename T>
int Container<T*>::find(T*& element)
{
	for (int i = 0; i < capacity; i++)
		if (elem[i] == element)
			return i;
	return -1;
}

template <typename T>
void Container <T*>::remove(T*& element)
{
	int i = find(element);
	if (i == -1)
		throw std::exception("not_found");
	elem[i] = elem[--capacity];
}
#endif