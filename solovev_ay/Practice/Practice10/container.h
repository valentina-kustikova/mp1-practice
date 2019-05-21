#include <iostream>
#pragma once
template <typename T>
class Container {
	int count;
	T*arr;
public:
	Container();
	Container(const Container<T>& a);
	~Container();

	bool IsEmpty() const;
	int Find(T a) const;
	void Add(T a);
	void Delete(T a);
	int getcount();
	T& operator [](int index);
	const T& operator [] (int index) const;
	void print();
};
template<typename T>
inline Container<T>::Container()
{
	count = 1;
	arr = new T[count];
}
template<typename T>
Container <T>::Container(const Container<T> &a)
{
	count = a.count;
	if (count == 0)
	{
		arr = nullptr;
	}
	else
	{

		arr = new T[count];
		for (int i = 0; i < count; i++)
		{
			arr[i] = a.arr[i];
		}
	}
}
template<typename T>
inline Container<T>::~Container()
{
	delete[]arr;
	count = 0;
}


template<typename T>
inline bool Container<T>::IsEmpty() const
{
	return (count == 0) ? true : false;
}

template<typename T>
inline int Container<T>::Find(T a) const
{
	for (int i = 0; i < count; i++)
	{
		if (arr[i] == a)
			return i;
	}
	std::cout << "takogo elementa net" << std::endl;
	return -1;
}
template<typename T>
inline void Container<T>::Add(T a)
{
	Container<T> tmp(*this);
	count++;
	arr = new T[count];
	for (int i = 0; i < count - 1; i++)
	{
		arr[i] = tmp[i];
	}
	arr[count - 1] = a;
}
template<typename T>
inline void Container<T>::Delete(T a)
{
	if (IsEmpty())
		throw "nechego udalat";
	int index = Find(a);

	if (count == 1)
	{
		count--;
		delete[] arr;
		arr = nullptr;
		return;
	}

	T* tmp = new T[count];
	for (int i = 0; i < count; i++)
		tmp[i] = arr[i];


	count--;
	arr = new T[count];
	for (int i = 0; i < count; i++)
		arr[i] = tmp[i >= index ? i + 1 : i];
	delete[] tmp;
}

template<typename T>
inline int Container<T>::getcount()
{
	return count;
}

template<typename T>
inline T & Container<T>::operator[](int index)
{
	if ((index < 0) || (index >= count))
		throw "ne tot index";
	return arr[index];
}

template<typename T>
inline const T & Container<T>::operator[](int index) const
{
	if ((index < 0) || (index >= count))
		throw "ne tot index";
	return arr[index];
}
template<typename T>
inline void Container<T>::print()
{
	for (int i = 0; i < count; i++)
	{
		system("color 5");
		std::cout << arr[i] << std::endl;
	}
}
template <typename T>
class Container <T*>
{
	int count;
	T**arr;
public:
	Container();
	Container(const Container<T*>& a);
	~Container();


	bool IsEmpty() const;
	int Find(T* a) const;
	void Add(T* a);
	void Delete(T* a);
	int getcount();
	T* operator [](int index);
	T* const operator[] (int index) const;
	void print();
};
template<typename T>
Container<T*>::Container()
{
	count = 0;
	arr = new T*;
};
template<typename T>
Container<T*>::~Container()
{
	for (int i = 0; i < count; i++)
		delete arr[i];
	delete arr;
	count = 0;
};
template<typename T>
inline int Container<T*>::Find(T * a) const
{
	for (int i = 0; i < count; i++)
		if (*arr[i] == *a)
			return i;
	return -1;
}
template<typename T>
inline void Container<T*>::Add(T * a)
{

	arr[count] = new T;
	*arr[count++] = *a;



}
template<typename T>
inline void Container<T*>::Delete(T * a)
{
	if (IsEmpty())
		throw "nechego udalat";
	*arr[Find(a)] = *arr[count - 1];
	delete arr[--count];
}

template<typename T>
void Container<T*>::print()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << *arr[i] << std::endl;
	}
}
template<typename T>
bool Container<T*>::IsEmpty() const
{
	return (count == 0) ? true : false;
}

template<typename T>
T* Container<T*>::operator[](int index)
{
	if ((index < 0) || (index >= count))
		throw "ne tot index";
	return arr[index];
}

template<typename T>
T* const Container<T*>::operator[](int index) const
{
	if ((index < 0) || (index >= count))
		throw "ne tot index";
	return arr[index];
}