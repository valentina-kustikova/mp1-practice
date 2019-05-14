#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include "Exception.h"
using namespace std;

template <typename T, int maxsize>
class Container
{
private:
    T* Arr;
    int count;
public:
    Container();
    Container(int);
    Container(const Container&);
    ~Container();

    bool IsFull() const;
    bool IsEmpty() const;
    int Find(T) const;
    void Add(T);
    void Delete(T);
    void Print() const;
    int GetCount() const;
    T operator[](int) const;
    T& operator[](int);
};

template <typename T, int maxsize>
Container<T, maxsize>::Container()
{
    count = 0;
    Arr = new T[maxsize];
}

template <typename T, int maxsize>
Container<T, maxsize>::Container(int _count)
{
    Arr = new T[maxsize];
    count = _count;
    for (int i = 0; i < count; i++)
        Arr[i] = i;
}

template <typename T, int maxsize>
Container<T, maxsize>::Container(const Container<T, maxsize>& tmp)
{
    count = tmp.count;
    Arr = new T[count];
    for (int i = 0; i < count; i++)
        Arr[i] = tmp.Arr[i];
}

template <typename T, int maxsize>
Container<T, maxsize>::~Container()
{
    count = 0;
    delete[]Arr;
}

template <typename T, int maxsize>
bool Container<T, maxsize>::IsFull() const
{
    return (count == maxsize);
}

template <typename T, int maxsize>
bool Container<T, maxsize>::IsEmpty() const
{
    return (count == 0);
}

template <typename T, int maxsize>
int Container<T, maxsize>::Find(T tmp) const
{
    for (int i = 0; i < count; i++)
        if (Arr[i] == tmp)
            return i;
    return -1;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Add(T tmp)
{
    if (!IsFull())
    {
        Arr[count++] = tmp;
    }
    else throw Exception("Container is full! MaxSize = 10");
}

template <typename T, int maxsize>
void Container<T, maxsize>::Delete(T tmp)
{
    if (IsEmpty())
        throw Exception("Container is empty!");

    int ind = Find(tmp);

    if (ind == -1)
        throw Exception("  Element didn't find!");

    Arr[ind] = Arr[--count];
}

template <typename T, int maxsize>
void Container<T, maxsize>::Print() const
{
    cout << "\n  ";
    for (int i = 0; i < count; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

template <typename T, int maxsize>
int Container<T, maxsize>::GetCount() const
{
    return count;
}

template <typename T, int maxsize>
T Container<T, maxsize>::operator[](int ind) const
{
    if ((ind < 0) || (ind > count))
        throw Exception("  Index isn't correct");
    return Arr[ind];
}

template <typename T, int maxsize>
T& Container<T, maxsize>::operator[](int ind)
{
    if ((ind < 0) || (ind > maxsize))
        throw Exception("Index don't fit");
    return Arr[ind];
}

#endif 