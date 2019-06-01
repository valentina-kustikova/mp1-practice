#pragma once
#include <iostream>
using namespace std;

template <typename T, int maxsize>
class Container1
{
private:
    T* arr;
    int count;//real number of elemnts
public:
    Container1();
    Container1(int count);
    Container1(const mContainer& tmp);
    ~Container1();

    bool IsFull()const;
    bool IsEmpty()const;

    int Find(T a)const;
    void Add(T a);
    void Delete(T a);
    T* operator[](int i);

    void Print()const;
    void Fill();
};

template <typename T, int maxsize>
Container1<T, maxsize>::Container1()
{
    count = 0;
    arr = new T[maxsize];
}

template <typename T, int maxsize>
Container1<T, maxsize>::Container1(int count)
{
    this->count = count;
    arr = new T[maxsize];
}

template <typename T, int maxsize>
Container1<T, maxsize>::Container1(const Container1& tmp)
{
    count = tmp.count;
    arr = new T[maxsize];
    for (int i = 0; i < count; i++)
    {
        arr[i] = tmp.arr[i];
    }
}

template <typename T, int maxsize>
Container1<T, maxsize>::~Container1()
{
    delete arr;
    count = 0;
}

template <typename T, int maxsize>
bool Container1<T, maxsize>::IsFull()const
{
    if (count == maxsize) 
	{
		cout<<"Full"<<endl;
		return true;
	}
	else 
	{
		cout <<"Is not full"<<endl;
		return false;
	}
}

template <typename T, int maxsize>
bool Container1<T, maxsize>::IsEmpty()const
{
    if (count == 0)
	{
		cout << "Empty" << endl;
		return true;
	}
	else 
		return false;
}

template <typename T, int maxsize>
int Container1<T, maxsize>::Find(T a)const
{
    for (int i = 0; i < count; i++)
	{
        if (arr[i] == a)
		{ 
			cout << "Index of element is "<< i <<endl;
			return i;
		}
		else
		{
			cout << "Element does not exist"<<endl;
			return -1;
		}	
	}
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Add(T a)
{
   if (this->IsFull())
       throw "Container is full";
   count++;
   arr[count - 1] = a;
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Remove(T a)
{
        if (this->IsEmpty())
            throw "Container is empty";
        int j = Find(a);
        if (j == -1)
            throw "Element does not exist" ;
        arr[j] = arr[count - 1];
        count--;
}

template <typename T, int maxsize>
T* Container1<T, maxsize>::operator[](int i)
{
	if ((i < 0) || (i >= count))
		throw "Element does not exist";
	return &(arr[i]);
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Print()const
{
   
        if (this->IsEmpty())
            throw "Container is empty";
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
   
   
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Fill()
{
        if (this->IsEmpty())
            throw "Container is empty";
        for (int i = 0; i < count; i++)
        {
            cin >> arr[i];
        } 
}
