#ifndef _CONTAINER_POINTERS_H_
#define _CONTAINER_POINTERS_H_
#include "Container.h"
using namespace std;

template <typename T, int maxsize>
class Container<T*, maxsize>
{
private:
    T** Arr;
    int count;
public:
    Container();
    Container(T**, int);
    Container(const Container&);
    ~Container();

    bool IsFull() const;
    bool IsEmpty() const;
    int Find(T*) const;
    void Add(T*);
    void Delete(int);
    void Print() const;
    int GetCount() const;
    T operator[](int) const;
    T* operator[](int);
};

template <typename T, int maxsize>
Container<T*, maxsize>::Container()
{
    count = 0;
    Arr = new T*[maxsize];
};

template <typename T, int maxsize>
Container<T*, maxsize>::Container(T** _arr, int _count)
{
    count = _count;
    Arr = new T*[maxsize];
    for (int i = 0; i < count; i++)
    {
        Arr[i] = new T(*(_arr[i]));
    }
};

template <typename T, int maxsize>
Container<T*, maxsize>::Container(const Container<T*, maxsize>& tmp)
{
    count = tmp.count;
    Arr = new T*[maxsize];
    for (int i = 0; i < count; i++)
    {
        Arr[i] = new T(*(tmp.Arr[i]));
    }
};

template <typename T, int maxsize>
Container<T*, maxsize>::~Container()
{
    for (int i = 0; i < count; i++)
        delete Arr[i];
    delete[] Arr;
    count = 0;
};

template <typename T, int maxsize>
bool Container<T*, maxsize>::IsFull() const
{
    return (count == maxsize);
};

template <typename T, int maxsize>
bool Container<T*, maxsize>::IsEmpty() const
{
    return (count == 0);
};

template <typename T, int maxsize>
int Container<T*, maxsize>::Find(T* tmp) const
{
    for (int i = 0; i < count; i++)
        if (Arr[i] == tmp)
            return i;
    return -1;
};

template <typename T, int maxsize>
void Container<T*, maxsize>::Add(T* tmp)
{
    if (IsFull())
        throw Exception_full("  Container is full!");
    Arr[count++] = new T(*tmp);
};

template <typename T, int maxsize>
void Container<T*, maxsize>::Delete(int tmp)
{
    if (IsEmpty())
        throw Exception_emp("  Container is empty!");

    int ind = tmp;

    if (ind == -1)
        throw Exception_find("  Element didn't find!");

    delete Arr[ind];
    Arr[ind] = Arr[--count];
};

template <typename T, int maxsize>
void Container<T*, maxsize>::Print() const
{
    cout << "\n  ";
    for (int i = 0; i < count; i++)
        cout << Arr[i] << " ";
    cout << endl;
};

template <typename T, int maxsize>
int Container<T*, maxsize>::GetCount() const
{
    return count;
};

template <typename T, int maxsize>
T Container<T*, maxsize>::operator[](int ind) const
{
    if ((ind < 0) || (ind > count))
        throw Exception_ind("  Index isn't correct");
    return Arr[ind];
};

template <typename T, int maxsize>
T* Container<T*, maxsize>::operator[](int ind)
{
    if ((ind < 0) || (ind > maxsize))
        throw Exception_ind("Index don't fit");
    return Arr[ind];
}
#endif 