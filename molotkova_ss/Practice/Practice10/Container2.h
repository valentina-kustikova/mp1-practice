#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Container1<T*>
{
private:
    T** arr;
    int count;
    int maxsize;
    void Adding(int add);
public:
    Container1();
    Container1(int x);
    Container1(const Container1& tmp);
    ~Container1();

    bool IsFull()const;
    bool IsEmpty()const;

    int Find(T a)const;
    void Add(T* a);
    void Delete(T a);
    T& operator[](int i);
    const T& operator[](int i)const;//reading

    /*void Print()const;
    void Fill(int count);*/
    
    friend istream& operator>>(istream&, Container1& tmp)
    {
        for (int i = 0; i < tmp.count; i++)
            input >> tmp[i];

        return input;
    };

    friend ostream& operator<<(ostream& out, const Container1& tmp)
        if (tmp.count == 0)
        {
            output << "The container is empty";
            return output;
        }

        output << "[ ";
        for (int i = 0; i < tmp.count; i++)
        {
            if (i != (tmp.count - 1))
                output << tmp[i] << ", ";
            else
                output << tmp[i] << "]";
        }

        return output;
    }
};

template <typename T>
Container1<T*>::Container1(int maxsize)
{
    this-> maxsize = maxsize;
    count = 0;
    arr = new T*[maxsize];
}

template <typename T>
Container1<T*>::Container1(const Container1& tmp)
{
    this->count = tmp.count;
	this->maxsize = tmp.maxsize;
    arr = new T*[maxsize];
    for (int i = 0; i < count; i++)
    {
		arr[i] = new T(*(tmp.arr[i]));
    }
}

template <typename T>
Container1<T*>::~Container1()
{
    for (int i = 0; i < count; i++)
    {
        delete arr[i];
    }
    delete arr;
    count = 0;
}

template <typename T>
bool Container1<T*>::IsFull()const
{
    return (count == maxsize);
}

template <typename T>
bool Container1<T*>::IsEmpty()const
{
    return (count == 0);
}

template <typename T>
int Container1<T*>::Find(T a)const
{
    for (int i = 0; i < count; i++)
        if (*arr[i] == a)
            return i;
    return -1;
}

template <typename T>
void Container1<T*>::Add(T* a)
{
	if (this->IsFull())
		this->Adding(1);
       arr[count++] = new T(*a);
}

template <typename T>
void Container1<T*>::Delete(T a)
{
   
        if (this->IsEmpty())
            throw "Container is empty";
        int j = Find(a);
        if (j == -1)
            throw "Element does not exist";
		delete arr[j];
        arr[j] = arr[count - 1];
		arr[--count] = 0;
}

template <typename T>
T& Container1<T*>::operator[](int i)
{
	if ((i < 0) || (i >= count))
       throw "Element does not exist";
    return *arr[i];
}

template <typename T>
const T& Container1<T*>::operator[](int i)const
{
	if ((i < 0) || (i >= count))
		throw "Element does not exist";
	return *arr[i];
}

/*template <typename T>
void Container1<T*>::Print()const
{
    for (int i = 0; i < count; i++)
    {
        cout << *(arr[i]) << " ";
    }
	cout << endl;
}

template <typename T>
void Container1<T*>::Fill(int count)
{
	this->count = count;
	if (this->IsEmpty())
            throw "Container is empty";
        for (int i = 0; i < count; i++)
        {
            cin >> *(arr[i]);
        }
}*/
