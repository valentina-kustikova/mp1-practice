#include <iostream>
#pragma once
template <typename T, int maxsize>
class Container {
	int count;
	T*arr;
public:
	Container();
	Container(const Container<T, maxsize>& a);
	~Container();

	bool IsFull() const;
	bool IsEmpty() const;
	int Find(T a) const;
	void Add(T a);
	void Delete(T a);
	int getcount();
	T& operator [](int index);
	const T& operator [] (int index) const;
	void print();
};
template<typename T, int maxsize>
inline Container<T, maxsize>::Container()
{
	count = 0;
	arr = new T[maxsize];
}
template<typename T, int maxsize>
Container <T, maxsize>::Container(const Container<T, maxsize> &a)
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
template<typename T, int maxsize>
inline Container<T, maxsize>::~Container()
{
	delete[]arr;
	count = 0;
}

template<typename T, int maxsize>
inline bool Container<T, maxsize>::IsFull() const
{
	return (count == maxsize) ? true : false;
}
template<typename T, int maxsize>
inline bool Container<T, maxsize>::IsEmpty() const
{
	return (count == 0) ? true : false;
}

template<typename T, int maxsize>
inline int Container<T, maxsize>::Find(T a) const
{
	for (int i = 0; i < count; i++)
	{
		if (arr[i] == a)
			return i;
	}
	std::cout << "takogo elementa net" << std::endl;
	return -1;
}
template<typename T, int maxsize>
inline void Container<T, maxsize>::Add(T a)
{
	if (IsFull())
		throw "massiv polon";
	if (IsEmpty())
	{
		count++;
		delete[] arr;
		arr = new T[count];
		arr[0] = a;
		return;
	}
	arr[count] = a;
	count++;

}
template<typename T, int maxsize>
inline void Container<T, maxsize>::Delete(T a)
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

template<typename T, int maxsize>
inline int Container<T, maxsize>::getcount()
{
	return count;
}

template<typename T, int maxsize>
inline T & Container<T, maxsize>::operator[](int index)
{
	if ((index < 0) || (index >= count))
		throw "ne tot index";
	return arr[index];
}

template<typename T, int maxsize>
inline const T & Container<T, maxsize>::operator[](int index) const
{
	if ((index < 0) || (index >= count))
		throw "ne tot index";
	return arr[index];
}
template<typename T, int maxsize>
inline void Container<T, maxsize>::print()
{
	for (int i = 0; i < count; i++)
	{
		system("color 5");
		std::cout << arr[i] << std::endl;
	}
}
template <typename T, int maxsize>
class Container <T*, maxsize>
{
	int count;
	T**arr;
public:
	Container();
	Container(const Container<T*, maxsize>& a);
	~Container();

	bool IsFull() const;
	bool IsEmpty() const;
	int Find(T* a) const;
	void Add(T* a);
	void Delete(T* a);
	int getcount();
	T* operator [](int index);
	T* const operator[] (int index) const;
	void print();
};
template<typename T, int maxsize>
Container<T*, maxsize>::Container()
{
	count = 0;
	arr = new T*[maxsize];
};
template<typename T, int maxsize>
Container<T*, maxsize>::~Container()
{
	for (int i = 0; i < count; i++)
		delete arr[i];
	delete arr;
	count = 0;
};
template<typename T, int maxsize>
inline int Container<T*, maxsize>::Find(T * a) const
{
	for (int i = 0; i < count; i++)
		if (*arr[i] == *a)
			return i;
	return -1;
}
template<typename T, int maxsize>
inline void Container<T*, maxsize>::Add(T * a)
{
	if (IsFull())
	{
		std::cout << "massiv polon" << std::endl;
		return;
	}
	arr[count] = new T;
	*arr[count++] = *a;



}
template<typename T, int maxsize>
inline void Container<T*, maxsize>::Delete(T * a)
{
	if (IsEmpty())
		throw "nechego udalat";
	*arr[Find(a)] = *arr[count - 1];
	delete arr[--count];
}

template<typename T, int maxsize>
void Container<T*, maxsize>::print()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << *arr[i] << std::endl;
	}
}
template<typename T, int maxsize>
bool Container<T*, maxsize>::IsEmpty() const
{
	return (count == 0) ? true : false;
}
template<typename T, int maxsize>
bool Container<T*, maxsize>::IsFull() const
{
	return (count == maxsize) ? true : false;
}
template<typename T, int maxsize>
T* Container<T*, maxsize>::operator[](int index)
{
	if ((index < 0) || (index >= count))
		throw "ne tot index";
	return arr[index];
}

template<typename T, int maxsize>
T* const Container<T*, maxsize>::operator[](int index) const
{
	if ((index < 0) || (index >= count))
		throw "ne tot index";
	return arr[index];
}