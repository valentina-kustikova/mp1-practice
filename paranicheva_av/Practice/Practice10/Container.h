#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
using namespace std;

template <typename T, int maxsize> 
class Container
{
private:
	T* arr;
	int size; 
public:
    Container(int _size);
	Container(const Container& c);
	~Container();

	bool IsFull() const;
	bool IsEmpty() const;

	int Find(T n) const;
	void Add(T n);
	void Delete(T n);
	T& operator[](int i);
	const T& operator[](int i) const;
	void Resize(int n);

	friend istream& operator>>(istream& fill, Container& tmp)
    {
        for (int i = 0; i < tmp.size; i++)
            fill >> tmp[i];
        return fill;
    };

    friend ostream& operator<<(ostream& print, const Container& tmp)
	{
        if (tmp.size == 0)
        {
            print << "The container is empty";
            return print;
        }
        for (int i = 0; i < tmp.size; i++)
        {
            if (i != (tmp.size - 1))
                print << tmp[i] << ", ";
            else
                print << tmp[i];
            cout << endl;
        }
        return print;
    };
};

template <typename T, int maxsize>
Container <T, maxsize>::Container <T,maxsize>(int _size)
{
	size = _size;
	arr = new T[size];
}
template <typename T, int maxsize>
Container <T, maxsize>::Container < T, maxsize> (const Container &c)
{
	size = c.size;
	arr = new T[maxsize];
	for (int i = 0; i < size; i++)
		arr[i] = c.arr[i];
}

template <typename T, int maxsize>
Container <T, maxsize>::~Container <T,maxsize>()
{
	delete []arr;
	size = 0;
}

template <typename T, int maxsize>
bool Container <T, maxsize>::IsFull() const
{
	if (size == maxsize)
		return true;
	return false;
}

template <typename T, int maxsize>
bool Container <T, maxsize>::IsEmpty() const
{
	if (size == 0)
		return true;
	return false;
}

template <typename T, int maxsize>
int Container <T, maxsize>::Find(T n) const
{
	for (int i = 0; i < size; i++)
		if (arr[i] == n) 
		return -1;
	throw "Item not found";
}

template <typename T, int maxsize>
void Container <T, maxsize>::Add(T n)
{
	if (IsFull())
		this->Resize(1);
	arr[size] = n;
	size++;
}

template <typename T, int maxsize>
void Container <T, maxsize>::Delete(T n)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	int i;
	i = Find(n);
	arr[i] = arr[size - 1];
	size--;
}

template <typename T, int maxsize>
T& Container <T, maxsize>::operator[](int i)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= size))
		throw "Wrong index";
	return arr[i];
}

template <typename T, int maxsize>
const T& Container <T, maxsize>::operator[](int i) const
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= size))
		throw "Wrong index";
	return arr[i];
}

template <typename T, int maxsize>
void Container <T, maxsize>::Resize(int n = 1)
{
	T *tmp = new T[size];
	for (int i = 0; i < size; i++)
		tmp[i] = arr[i];
	delete []arr;
	arr = new T[size + n];
	for (int i = 0; i < size; i++)
		arr[i] = tmp[i];
}

#endif
