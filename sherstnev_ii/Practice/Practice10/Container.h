#pragma once
#include <iostream>
#include <string>

using namespace std;

////////////////////

template <typename T, int maxsize>
class Container {
	T* arr;
	int count;
public:
	Container();
	Container(const Container<T, maxsize>&);
	~Container();

	T& operator [](int);

	bool IsFull() const;
	bool IsEmpty() const;
	void Print();

	int Find(T a) const;
	void Add(T a);
	void Delete(T a);
};

////////////////////

template <typename T, int maxsize>
Container<T, maxsize>::Container() {
	count = 0;
	arr = new T[maxsize];
}
template <typename T, int maxsize>
Container<T, maxsize>::Container(const Container<T, maxsize>& c) {
	count = c.count;
	arr = new T[maxsize];
	for (int i = 0; i < count; i++) arr[i] = c.arr[i];
}
template <typename T, int maxsize>
Container<T, maxsize>::~Container() {
	count = 0;
	delete[]arr;
}

template<typename T, int maxsize>
T& Container<T, maxsize>::operator[](int n)
{
	if (n >= count || n < 0) throw (string)"Element doesn`t exist";
	return arr[n];
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

template<typename T, int maxsize>
void Container<T, maxsize>::Print()
{
	if (IsEmpty()) throw (string)"Container is empty";
	cout << "Container: " << endl;
	for (int i = 0; i < count; i++) {
		cout << arr[i] << endl;
	}
}

template <typename T, int maxsize>
int Container<T, maxsize>::Find(T a) const {
	for (int i = 0; i < count; i++)
	if (arr[i] = a) return i;
	return -1;
}
template <typename T, int maxsize>
void Container<T, maxsize>::Add(T a) {
	if (IsFull()) throw (string)"Container is full";
	arr[count] = a;
	count++;
}
template <typename T, int maxsize>
void Container<T, maxsize>::Delete(T a) {
	if (IsEmpty()) throw (string)"Container is empty";
	int idx = Find(a);
	if (idx != -1) {
		count -= 1;
		for (int i = idx; i < count; i++) arr[i] = arr[i + 1];
	}
	else {
		throw (string)"Element doesn`t exist";
	}
}

////////////////////

template <typename P, int maxsize>
class Container<P*, maxsize> {
	P** arr;
	int count;
public:
	Container();
	Container(const Container<P*, maxsize>&);
	~Container();


	P& operator [](int);

	bool IsFull() const;
	bool IsEmpty() const;
	void Print();

	int Find(P a) const;
	void Add(P a);
	void Delete(P a);
};

///////////////////////////

template <typename P, int maxsize>
Container<P*, maxsize>::Container() {
	count = 0;
	arr = new P*[maxsize];
}
template <typename P, int maxsize>
Container<P*, maxsize>::Container(const Container<P*, maxsize>& c) {
	count = c.count;
	arr = new P*[maxsize];
	for (int i = 0; i < count; i++) {
		arr[i] = new P(*(c.arr[i]));
	}
}
template <typename P, int maxsize>
Container<P*, maxsize>::~Container() {
	for (int i = 0; i < count; i++) {
		delete arr[i];
	}
	delete[] arr;
	count = 0;
}

template<typename P, int maxsize>
P& Container<P*, maxsize>::operator[](int n)
{
	if (n >= count || n < 0) throw (string)"Element doesn`t exist";
	return *arr[n];
}

template<typename P, int maxsize>
bool Container<P*, maxsize>::IsFull() const
{
	return (count == maxsize);
}

template<typename P, int maxsize>
bool Container<P*, maxsize>::IsEmpty() const
{
	return (count == 0);
}

template<typename P, int maxsize>
void Container<P*, maxsize>::Print()
{
	if (IsEmpty()) throw (string)"Container is empty";
	cout << "Container: " << endl;
	for (int i = 0; i < count; i++) {
		cout << *arr[i] << endl;
	}
}

template<class P, int maxsize>
int Container<P*, maxsize>::Find(P a) const
{
	for (int i = 0; i < count; i++)
	if (*arr[i] = a) return i;
	return -1;
}

template<class P, int maxsize>
void Container<P*, maxsize>::Add(P a)
{
	if (IsFull()) throw (string)"Container is full";
	arr[count] = new P(a);
	count++;
}

template<class P, int maxsize>
void Container<P*, maxsize>::Delete(P a)
{
	if (IsEmpty()) throw (string)"Container is empty";
	int idx = Find(a);
	if (idx != -1) {
		count -= 1;
		delete arr[idx];
		for (int i = idx; i < count; i++) arr[i] = arr[i + 1];
	}
	else {
		throw (string)"Element doesn`t exist";
	}
}