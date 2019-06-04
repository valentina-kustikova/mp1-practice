#ifndef CONTAINERA_H
#define CONTAINERA_H

#include <iostream>
using namespace std;

template <typename T, int maxsize> 
class Container<T*, maxsize>
{
private:
	T** m;
	int s; 
public:
    Container(int _s);
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
        for (int i = 0; i < tmp.s; i++)
            fill >> tmp[i];
        return fill;
    };

    friend ostream& operator<<(ostream& print, const Container& tmp)
	{
        if (tmp.s == 0)
        {
            print << "The container is empty";
            return print;
        }
        for (int i = 0; i < tmp.s; i++)
        {
            if (i != (tmp.s - 1))
                print << tmp[i] << ", ";
            else
                print << tmp[i];
            cout << endl;
        }
        return print;
    };
};

template <typename T, int maxsize>
Container <T*, maxsize>::Container(int _s)
{
	s = _s;
	m = new T*[maxsize];
	for(int i = 0; i < s; i++)
	{
	m[i] = new T;
	}
}

template <typename T, int maxsize>
Container <T*, maxsize>::Container(const Container &c)
{
	s = c.s;
	m = new T*[maxsize];
	for (int i = 0; i < s; i++)
	{
		m = new T;
		m[i] = c->m[i];
	}
}

template <typename T, int maxsize>
Container <T*, maxsize>::~Container()
{
	for (int i = 0; i < s; i++)
		delete []m[i];
	delete []m;
	s = 0;
}

template <typename T, int maxsize>
bool Container <T*, maxsize>::IsFull() const
{
	if (s == maxsize)
		return true;
	return false;
}

template <typename T, int maxsize>
bool Container <T*, maxsize>::IsEmpty() const
{
	if (s == 0)
		return true;
	return false;
}

template <typename T, int maxsize>
int Container <T*, maxsize>::Find(T n) const
{
	for (int i = 0; i < s; i++)
        if (*m[i] == n)
            return -1;
    throw "Item not found";
}

template <typename T, int maxsize>
void Container <T*, maxsize>::Add(T n)
{
	if (IsFull())
		this->Resize(1);
	m[s] = new T;
	*m[s] = n;
	s++;
}

template <typename T, int maxsize>
void Container <T*, maxsize>::Delete(T n)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	int i;
	i = Find(n);
	*m[i] = *m[s - 1];
	delete m[s - 1];
	s--;
}

template <typename T, int maxsize>
T& Container <T*, maxsize>::operator[](int i)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= s))
		throw "Wrong index";
	return *m[s];
}

template <typename T, int maxsize>
const T& Container <T*, maxsize>::operator[](int i) const
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= s))
		throw "Wrong index";
	return *m[s];
}

template <typename T, int maxsize>
void Container <T*, maxsize>::Resize(int n = 1)
{
	T **tmp = new T*[s];
	for (int i = 0; i < s; i++)
		tmp[i] = m[i];
	delete m;
	m = new T*[s + n];
	for (int i = 0; i < s; i++)
		m[i] = tmp[i];
	delete []tmp;
}

#endif
