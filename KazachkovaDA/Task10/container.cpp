#include "container.hpp"

template <typename T>
Container <T>::Container (int size)
{
	this -> size = size;
	capasity = 0;
	elems = new T[size];
}

template <typename T>
Container <T>::Container(int size, const T& elem)
{
	this -> size = size;
	capasity = size;
	elems = new T[size];
	for (int i=0; i < size; i++)
		elems[i] = elem;
}

template <typename T>
Container <T>:: Container(const Container& c1)
{
	size = c1.size;
	capasity = c1.capasity;
	elems = new T[size];
	for (int i = 0; i < capasity; i++)
		elems[i] = c1.elems[i];
}

template <typename T>
const Container <T>&operator=(const Container <T>&c1)
{
	if (this == &c1)
		return;
	if (size != c1.size)
	{
		delete [] elems;
		size = c1.size;
		capasity = c1.capasity;
		elems = new T[size];
	}
	for (int i = 0; i < capasity; i++)
		elems[i] = c1.elems[i];
		
	return *this;
}

template <typename T>
Container <T>::~Container()
{
	delete [elems];
}

template <typename T>
T& Container::operator[](int i)
{
	if (i >= size)
		throw std::exception("out_of_range");
	return elems[i];
}

template <typename T>
void Container <T>::push_back(T& elem)
{
	if (size == capasity)
		throw std::exception("out_of_memory");
	elems[capasity++] = elem;
}

template <typename T>
sint Container<T>::find(T& elem)
{
	for (int i = 0; i < capasity; i++)
		if (elems[i] == elem)
			return i;
	return statis_cast <ssiz_t>(-1);
}

template <typename T>
void Container <T>:: remove(T& elem)
{
	sint i = find(elem);
	if (i == static_cast <sint>(-1))
		throw std::exception ("not_found");
	elems[i] = elems[--capacity];
}