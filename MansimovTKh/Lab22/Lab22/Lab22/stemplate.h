#ifndef STEMP_H
#define STEMP_H

#include <iostream>
#include "template.h"

using namespace std;

template <class T>
class Container <T*>{
private:
	T** elems;
	int size;
	int count;
	unsigned int step;
public:
	Container() : size(0), count(0), step(0), elems(nullptr) {};
	Container(int n, unsigned int step);
	Container(const Container <T*>&);
	~Container();

	void InsertElem(T* const& elem);
	void DeleteElem(T* const& elem);

	const Container <T*>& operator = (const Container <T*>&);
	T* operator [] (int);

	friend ostream& operator << (ostream& out, const Container <T*>& a) {
		for (int i = 0; i < a.count; i++) {
			out << a[i] << " ";
		}
		out << endl << "size: " << a.size << endl;
		out << "count: " << a.count << endl;
		out << "step: " << a.step << endl << endl;
		return out;
	}

};

template <class T>
Container <T*>::Container(int n, unsigned int step) {
	this->size = n;
	this->count = 0;
	this->step = step;
	this->elems = new T * [n];
}

template <class T>
Container <T*>::Container(const Container <T*>& cont) {
	this->size = cont.size;
	this->count = cont.count;
	this->step = cont.step;
	this->elem = new T * [this->size];
	for (int i = 0; i < this->count; i++) {
		this->elems[i] = new T(*cont.elems[i]);
	}
}

template <class T>
Container <T*>::~Container() {
	for (int i = 0; i < this->count; i++) {
		delete this->elems[i];
	}
	delete[] this->elems;
}

template <class T>
void Container <T*> :: InsertElem(T* const& elem) {
	if (this->count > size - 1) {
		this->size += this->step;
		Container<T*> buffer(this->size, this->step);
		buffer.count = this->count;
		for (int i = 0; i < this->count; i++) {
			buffer.elems[i] = new T(*this->elems[i]);
		}
		*this = buffer;
	}
	this->elems[this->count] = elem;
	this->count++;
}

template <class T>
void Container<T*>::DeleteElem(T* const& elem) {
	for (int i = 0; i < this->count; i++) {
		if (this->elems[i] == elem) {
			this->elems[i] = this->elems[count - 1];
			count--;
		}
	}
}

template <class T>
const Container <T*>& Container <T*>::operator = (const Container <T*>& cont) {
	if (this == &cont) {
		return *this;
	}
	for (int i = 0; i < this->count; i++) {
		delete this->elems[i];
	}
	delete[] this->elems;
	this->size = cont.size;
	this->elems = new T*[this->size];
	for (int i = 0; i < cont.count; i++) {
		this->elems[i] = new T(*cont.elems[i]);
	}
	this->count = cont.count;
	return *this;
}

template <class T>
T* Container<T*>::operator [] (int idx) {
	if (index < 0 || index > count - 1) {
		throw "wrong index\n";
	}
	return this->elems[idx];
}
#endif
