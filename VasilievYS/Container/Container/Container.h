#ifndef CNTNR
#define CNTNR 
#include<iostream>
#include<cstdlib>
template <typename T>
class Container
{
	std::size_t size;
	std::size_t capacity;
	const std::size_t step = 10;
	T* elems;
public:
	Container() :
		size(0), capacity(0), elems(nullptr) {};
	Container(std::size_t s);
	Container(std::size_t s, const T& elem);
	Container(const Container<T>& C);
	Container(Container<T>&& C);
	~Container();
	void push_back(T& elem);
	void remove(T& elem);
	int find(const T& elem);
	void reallocate();
	T& operator[](std::size_t i);
	const T& operator[](std::size_t i) const;
	const Container<T>& operator = (const Container<T>& C);
};
//#include "Container.h"
//#include<iostream>
//#include<cstdlib>

template <typename T>
Container<T>::Container(std::size_t s) :
	size(s), capacity(s), elems(new T[s]) {
}

template<typename T>
Container<T>::Container(std::size_t s, const T& elem) :
	size(s), capacity(s), elems(new T[s])
{
	for (std::size_t i = 0; i < size; i++)
	{
		elems[i] = elem;
	}
}

template<typename T>
Container<T>::Container(const Container<T>& C)
{
	size = C.size;
	capacity = C.capacity;
	elems = new T[capacity];
	for (std::size_t i = 0; i < size; i++)
	{
		elems[i] = C.elems[i];
	}
}

template<typename T>
Container<T>::Container(Container<T>&& C)
{
	size = C.size;
	capacity = C.capacity;
	elems = C.elems;
	C.elems = nullptr;
	C.size = 0;
	C.capacity = 0;
}

template<typename T>
Container<T>::~Container()
{
	delete[]elems;
}

template<typename T>
void Container<T>::push_back(T& elem)
{
	if (size >= capacity) { reallocate(); }
	elems[size] = elem;
	size++;
}
//step в конструкторе
template<typename T>
void Container<T>::remove(T& elem)
{
	int i = find(elem);
	if (i == -1) { throw std::exception("Not found"); }
	elems[i] = elems[size - 1];
	//elems[size - 1].~T();
	size--;
}

template<typename T>
int Container<T>::find(const T& elem)
{
	for (int i = 0; i < size; i++)
	{
		if (elems[i] == elem) { return i; }
	}
	return -1;
}

template<typename T>
void Container<T>::reallocate()
{
	std::size_t new_capacity = step + capacity;
	T* new_elems = new T[new_capacity];
	for (std::size_t i = 0; i < size; i++)
	{
		new_elems[i] = elems[i];
	}
	delete[]elems;
	elems = new_elems;
	capacity = new_capacity;
}

template<typename T>
T& Container<T>::operator[](std::size_t i)
{
	if (i >= size) { throw std::exception("Out of range"); }
	return elems[i];
}

template<typename T>
const T& Container<T>::operator[](std::size_t i) const
{
	if (i >= size) { throw std::exception("Out of range"); }
	return elems[i];
}

template<typename T>
const Container<T>& Container<T>::operator=(const Container<T>& C)
{
	if (this != &C)
	{
		size = C.size;
		capacity = C.capacity;
		delete[]elems;
		elems = new T[capacity];
		for (std::size_t i = 0; i < size; i++)
		{
			elems[i] = C.elems[i];
		}
	}
	return *this;
}
#endif 