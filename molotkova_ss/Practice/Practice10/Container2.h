#pragma once
#include <iostream>
using namespace std;

template <typename T, int maxsize>
class Container
{
private:
    T** arr;
    int count;
public:
    Container();//по умолчанию
    Container(int x);
    Container(const Container& temp);//конструктор копирования
    ~Container();

    bool IsFull()const;//проверки
    bool IsEmpty()const;//проверки

    int Find(T a)const;// поиск
    void Add(T a);//вставка
    void Remove(T a);//удаление
    T* operator[](int i);

    void Print()const;
    void Fill();
};

template <typename T, int maxsize>
Container<T, maxsize>::Container()
{
    count = 0;
    arr = new T*[maxsize];
}

template <typename T, int maxsize>
Container<T, maxsize>::Container(int count)
{
    this-> count = count;
    arr = new T*[maxsize];
    for (int i = 0; i < count; i++)
    {
        arr[i] = new T;
    }
}

template <typename T, int maxsize>
Container<T, maxsize>::Container(const Container& temp)
{
    this->count = temp.count;
    arr = new T*[maxsize];
    for (int i = 0; i < count; i++)
    {
        arr[i] = new T;
        (*arr[i]) = temp.*arr[i];
    }
}

template <typename T, int maxsize>
Container<T, maxsize>::~Container()
{
    for (int i = 0; i < count; i++)
    {
        delete arr[i];
    }
    delete arr;
    count = 0;
}

template <typename T, int maxsize>
bool Container<T, maxsize>::IsFull()const
{
    return (count == maxsize);
}

template <typename T, int maxsize>
bool Container<T, maxsize>::IsEmpty()const
{
    return (count == 0);
}

template <typename T, int maxsize>
int Container<T, maxsize>::Find(T a)const
{
    for (int i = 0; i < count; i++)
        if (*(arr[i]) == a)
            return i;
    return -1;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Add(T a)
{
        if (this->IsFull())
            throw "Container is full";
        count++;
        arr[count - 1] = new T;
        *arr[count - 1] = a;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Remove(T a)
{
   
        if (this->IsEmpty())
            throw "Container is empty";
        int j = Find(a);
        if (j == -1)
            throw "Element does not exist";
        *arr[j] = *arr[count - 1];
        delete arr[count - 1];
        count--;
}

template <typename T, int maxsize>
T* Container<T, maxsize>::operator[](int i)
{
	if ((i < 0) || (i >= count))
       throw "Element does not exist";
    return arr[i];
}

template <typename T, int maxsize>
void Container<T, maxsize>::Print()const
{
	if (this->IsEmpty())
		throw "Container is empty";
    for (int i = 0; i < count; i++)
    {
        cout << *(arr[i]) << " ";
    }
	cout << endl;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Fill()
{
	if (this->IsEmpty())
            throw "Container is empty";
        for (int i = 0; i < count; i++)
        {
            cin >> *(arr[i]);
        }
}
