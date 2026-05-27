#ifndef _TEMP_H
#define _TEMP_H

#include <iostream>

using namespace std;


template <typename T>
class Container {
private:
	T* elems;
	int size;
	int count;
	unsigned int step;
public:
	Container() : elems(nullptr), size(0), count(0), step(0) {};
	Container(int n, unsigned int step);
	Container(const Container <T>&);
	~Container();

	void InsertElem(const T& elem);
	void DeleteElem(const T& elem);

	const Container <T>& operator = (const Container <T>&);

	T operator[] (int);
	
	friend ostream& operator << (ostream& out, const Container <T>& a) {
		for (int i = 0; i < a.count; i++) {
			out << a.elems[i] << " ";
		}
		out << endl << "size: " << a.size << endl;
		out << "count: " << a.count << endl;
		out << "step: " << a.step << endl << endl;
		return out;
	}

};

template <typename T>
Container <T>::Container(int n, unsigned int step) {
	this->size = n;
	this->elems = new T[n];
	this->count = 0;
	this->step = step;
}

template <typename T>
Container <T>::Container(const Container <T>& a) {
	this->size = a.size;
	this->elems = new T[this->size];
	this->count = a.count;

	for (int i = 0; i < this->count; i++) {
		this->elems[i] = a.elems[i];
	}
}

template <typename T>
Container <T>::~Container() {
	delete[] elems;
}

template <typename T>
void Container <T>::InsertElem(const T& elem) {
	if (this->count > size - 1) {
		this->size += this->step;
		Container buffer(this->size, this->step);
		buffer.count = this->count;
		for (int i = 0; i < this->count; i++) {
			buffer.elems[i] = this->elems[i];
		}
		*this = buffer;
	}
	this->elems[this->count] = elem;
	this->count++;
}

template <typename T>
void Container <T>::DeleteElem(const T& elem) {
	for (int i = 0; i < this->count; i++) {
		if (this->elems[i] == elem) {
			this->elems[i] = this->elems[count-1];
			count--;
		}
	}
}

template <typename T>
const Container <T>& Container <T>::operator = (const Container <T>& cont) {
	if (this != &cont) {
		delete[] elems;
		this->size = cont.size;
		this->elems = new T[this->size];
		for (int i = 0; i < cont.count; i++) {
			this->elems[i] = cont.elems[i];
		}
		this->count = cont.count;
		return *this;
	}
}

template <typename T>
T Container <T>::operator [] (int idx) {
	if (index < 0 || index > count - 1) {
		throw "wrong index\n";
	}
	return this->elems[idx];
}
#endif
