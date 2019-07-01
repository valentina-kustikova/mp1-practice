#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include <exception>
#include <iostream>
using namespace std;

template <typename T, int maxsize>
class Container
{
private:
    T* Arr;
    int count;
public:
    Container();
    Container(const Container&);
    ~Container();

    void Create(const T* _Arr, int _count);
    bool IsFull() const;
    bool IsEmpty() const;
    int Find(T) const;
    void Add(T);
    void Delete(T);
    void Print() const;
    int GetCount() const;
    T operator[](int) const;
    T& operator[](int);

    friend ostream& operator<<(ostream& os, const Container& _cont)
    {
        os << "( ";
        for (int i = 0; i < _cont.count; i++)
            os << _cont[i] << " ";
        os << ")";
        return os;
    }
};

template <typename T, int maxsize>
Container<T, maxsize>::Container()
{
    count = 0;
    Arr = new T[maxsize];
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
void Container<T, maxsize>::Create(const T* _Arr, int _count)
{
    count = _count;
    Arr = new T[maxsize];
    memcpy(Arr, _Arr, sizeof(T) * count);
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
    throw - 1;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Add(T tmp)
{
    if (IsFull())
        throw Exception_full("Container is full! MaxSize = 10");
    Arr[count++] = tmp;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Delete(T tmp)
{
    if (IsEmpty())
        throw Exception_emp("Container is empty!");

    int ind = Find(tmp);

    if (ind == -1)
        throw Exception_find("  Element didn't find!");

    Arr[ind] = Arr[--count];

    if (IsEmpty())
        throw Exception_emp("Container is empty!");
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
        throw Exception_ind("  Index isn't correct");
    return Arr[ind];
}

template <typename T, int maxsize>
T& Container<T, maxsize>::operator[](int ind)
{
    if ((ind < 0) || (ind > maxsize))
        throw Exception_ind("Index don't fit");
    return Arr[ind];
}

//Exceptions
class Exception_find : exception
{
private:
    const string mes;
public:
    Exception_find(string e)
        : mes(e)
    {
    }
    const char* what() const { return mes.c_str(); }
};

class Exception_ind : exception
{
private:
    const string mes;
public:
    Exception_ind(string e)
        : mes(e)
    {
    }
    const char* what() const { return mes.c_str(); }
};

class Exception_full : exception
{
private:
    const string mes;
public:
    Exception_full(string e)
        : mes(e)
    {
    }
    const char* what() const { return mes.c_str(); }
};

class Exception_emp : exception
{
private:
    const string mes;
public:
    Exception_emp(string e)
        : mes(e)
    {
    }
    const char* what() const { return mes.c_str(); }
};
#endif 