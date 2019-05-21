﻿#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include <exception>

template<typename T>
class Container 
{
	T* arr;
	int count, max_size;

	void malloc();
public:
	Container();
	Container(const Container&);
	~Container();
	bool is_full() const;
	bool is_empty() const;
	int find_elem(const T) const;
	void add_elem(const T);
	void delete_elem(const T);
	T& operator[](int) const;
	void print() const;
};

template<typename T>
Container<T>::Container()
{
	count = max_size = 0;
	arr = nullptr;
}

template<typename T>
void Container<T>::malloc()
{
	max_size += 10;
	T* new_arr = new T[max_size];
	for (int i = 0; i < count; i++)
		new_arr[i] = arr[i];
	if (arr)
		delete[] arr;
	arr = new_arr;

}

template<typename T>
Container<T>::Container(const Container& x)
{
	count = x.count;
	max_size = x.max_size;
	arr = new T[max_size];
	for (int i = 0; i < count; i++)
		arr[i] = x.arr[i];
}

template<typename T>
Container<T>::~Container()
{
	delete[] arr;
}

template<typename T>
bool Container<T>::is_full() const
{
	return (count == max_size) ? 1 : 0;
}

template<typename T>
bool Container<T>::is_empty() const
{
	return (count == 0) ? 1 : 0;
}

template<typename T>
T& Container<T>::operator[](int idx) const
{
	if (idx >= count)
		throw std::out_of_range("Выход за границы.\n");
	return arr[idx];
}

template<typename T>
int Container<T>::find_elem(const T x) const
{
	for (int i = 0; i < count; i++)
		if (x == arr[i])
			return i;
	return -1;
}

template<typename T>
void Container<T>::add_elem(const T x)
{
	if (is_full())
		malloc();
	arr[count] = x;
	count++;
}

template<typename T>
void Container<T>::delete_elem(const T x)
{
	int idx = find_elem(x);
	if (idx == -1)
	{
		throw "Элемент не найден \n";
	}
	T tmp = arr[idx];
	arr[idx] = arr[count - 1];
	arr[count - 1] = tmp;
	count--;
}

template<typename T>
void Container<T>::print() const
{
	for (int i = 0; i < count; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}










///////////////////////////////////////////////////////////////////////////////

template<typename T>
class Container<T*>
{
	T** arr;
	int count, max_size;

	void malloc();
public:
	Container<T*>();
	Container<T*>(const Container&);
	~Container<T*>();
	bool is_full() const;
	bool is_empty() const;
	int find_elem(const T) const;
	void add_elem(const T);
	void delete_elem(const T);
	T*& operator[](int) const;
	void print() const;
};

template<typename T>
Container<T*>::Container()
{
	count = max_size = 0;
	arr = nullptr;
}

template<typename T>
void Container<T*>::malloc()
{
	max_size += 10;
	T** new_arr = new T*[max_size];
	for (int i = 0; i < count; i++)
		new_arr[i] = new T(**(arr + i));
	if (arr)
		delete[] arr;
	arr = new_arr;
}

template<typename T>
void Container<T*>::add_elem(const T x)
{
	if (is_full())
		malloc();
	arr[count] = new T(x);
	count++;
}

template<typename T>
Container<T*>::Container(const Container& x)
{
	count = x.count;
	max_size = x.max_size;
	arr = new T*[x.max_size];
	for (int i = 0; i < count; i++)
	{
		arr[i] = new T(**(x.arr + i));
	}
}

template<typename T>
Container<T*>::~Container()
{
	for (int i = 0; i < count; i++)
		delete arr[i];
	delete arr;
}

template<typename T>
bool Container<T*>::is_full() const
{
	return (count == max_size) ? 1 : 0;
}

template<typename T>
bool Container<T*>::is_empty() const
{
	return (count == 0) ? 1 : 0;
}

template<typename T>
T*& Container<T*>::operator[](int idx) const
{
	if (idx >= count)
		throw std::out_of_range("Выход за границы.\n");
	return arr[idx];
}

template<typename T>
int Container<T*>::find_elem(const T x) const
{
	for (int i = 0; i < count; i++)
		if (x == **(arr + i))
			return i;
	return -1;
}

template<typename T>
void Container<T*>::delete_elem(const T x)
{
	int idx = find_elem(x);
	if (idx == -1)
	{
		throw "Элемент не найден. \n";
	}
	delete arr[idx];
	arr[idx] = arr[count - 1];
	count--;

}

template<typename T>
void Container<T*>::print() const
{
	for (int i = 0; i < count; i++)
		std::cout << *(arr[i]) << " ";
	std::cout << "\n";
}

#endif 