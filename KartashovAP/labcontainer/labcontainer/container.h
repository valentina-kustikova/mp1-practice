#ifndef __CONTAINER_H
#define __CONTAINER_H

#include <iostream>
#include <stdexcept>

template<typename T>
class container {
	size_t size, capacity, step;
	T* elem;
	void reallocate();
public:
	container(size_t, size_t);
	container(size_t, size_t, const T&);
	container(const container<T>&);
	container(container<T>&&);
	container() {};
	T& operator[](size_t);
	const T& operator[](size_t) const;
	const container& operator=(const container&);
	int find(T&) const;
	void push(T&);
	void push(T&&);
	void remove(T&);
	void remove(T&&);
	friend std::ostream& operator<<(std::ostream& out, const container<T>& b) {
		out << "size = " << b.size << " | capacity = " << b.capacity << " | step = " << b.step << "\n|";
		for (int i = 0; i < b.size; i++) {
			out << b.elem[i];
			if (i + 1 == b.size) break;
			out << " ";
		}
		out << "|";
		return out;
	}
	~container();
};

template<typename T>
container<T>::~container() {
	delete[]elem;
}

template<typename T>
container<T>::container(size_t cp, size_t st) : capacity(cp), size(0), step(st) {
	this->elem = new T[cp];
}

template<typename T>
container<T>::container(size_t cp, size_t st, const T& el) : capacity(cp), size(cp), step(st) {
	this->elem = new T[cp];
	for (int i = 0; i < cp; i++) this->elem[i] = el;
}

template<typename T>
container<T>::container(const container<T>& b) : size(b.size), capacity(b.capacity), step(b.step) {
	this->elem = new T[size];
	for (int i = 0; i < size; i++) elem[i] = b.elem[i];
}

template<typename T>
container<T>::container(container<T>&& b) : size(b.size), capacity(b.capacity), step(b.step) {
	this->elem = b.elem;
	b.elem = nullptr;
	b.size = 0;
	b.capacity = 0;
}

template<typename T>
T& container<T>::operator[](size_t ind) {
	if (ind > this->size) throw std::out_of_range("Out of range");
	return this->elem[ind];
}

template<typename T>
const T& container<T>::operator[](size_t ind) const {
	if (ind > this->size) throw std::out_of_range("Out of range");
	return this->elem[ind];
}

template<typename T>
const container<T>& container<T>::operator=(const container<T>& b) {
	if (this == &b) return *this;
	if (this->size != b.size) {
		delete[] this->elem;
		this->size = b.size;
		this->capacity = b.capacity;
	}
	for (int i = 0; i < size; i++) this->elem[i] = b.elem[i];
	return *this;
}

template<typename T>
int container<T>::find(T& el) const {
	for (int i = 0; i < this->size; i++)
		if (this->elem[i] == el)
			return i;
	return -1;
}

template<typename T>
void container<T>::remove(T& el) {
	int pos = this->find(el);
	if (pos == -1) throw std::runtime_error("Not found");
	this->elem[pos] = this->elem[--size];
}

template<typename T>
void container<T>::remove(T&& el) {
	int pos = this->find(el);
	if (pos == -1) throw std::runtime_error("Not found");
	this->elem[pos] = this->elem[--size];
}

template<typename T>
void container<T>::reallocate() {
	this->capacity += this->step;
	T* buff = new T[this->capacity];
	for (int i = 0; i < size; i++) buff[i] = elem[i];
	delete[]elem;
	elem = buff;
}

template<typename T>
void container<T>::push(T& el) {
	if (this->size == this->capacity) reallocate();
	elem[size++] = el;
}

template<typename T>
void container<T>::push(T&& el) {
	if (this->size == this->capacity) reallocate();
	elem[size++] = el;
}

template<typename T>
class container<T*> {
	size_t size, capacity, step;
	T** elem;
	void reallocate();
public:
	container(size_t, size_t);
	container(size_t, size_t, T*&);
	container(const container<T*>&);
	container(container<T*>&&);
	T*& operator[](size_t);
	const T*& operator[](size_t) const;
	const container& operator=(const container&);
	int find(T*&) const;
	void push(T*&);
	void push(T*&&);
	void remove(T*&);
	void remove(T*&&);
	friend std::ostream& operator<<(std::ostream& out, const container<T*>& b) {
		out << "size = " << b.size << " | capacity = " << b.capacity << " | step = " << b.step << "\n____________\n";
		for (int i = 0; i < b.size; i++) {
			out << *b.elem[i] << '\n';
		}
		out << "____________";
		return out;
	}
	~container();
};

template<typename T>
container<T*>::~container() {
	for (int i = 0; i < this->size; i++) delete elem[i];
	delete[]elem;
}

template<typename T>
container<T*>::container(size_t cp, size_t st) : size(0), capacity(cp), step(st) {
	this->elem = new T * [capacity];
}

template<typename T>
container<T*>::container(size_t cp, size_t st, T*& el) : capacity(cp), step(st), size(cp) {
	this->elem = new T * [capacity];
	for (int i = 0; i < size; i++) elem[i] = new T(*el);
}

template<typename T>
T*& container<T*>::operator[](size_t ind) {
	if (ind > this->size) throw std::out_of_range("Out of range");
	return this->elem[ind];
}

template<typename T>
const T*& container<T*>::operator[](size_t ind) const {
	if (ind > this->size) throw std::out_of_range("Out of range");
	return this->elem[ind];
}

template<typename T>
int container<T*>::find(T*& el) const {
	for (int i = 0; i < this->size; i++) {
		if (*elem[i] == *el) return i;
	}
	return -1;
}

template<typename T>
void container<T*>::remove(T*& el) {
	int pos = this->find(el);
	if (pos == -1) throw std::runtime_error("Not found");
	delete this->elem[pos];
	this->elem[pos] = this->elem[--size];
}

template<typename T>
void container<T*>::remove(T*&& el) {
	int pos = this->find(el);
	if (pos == -1) throw std::runtime_error("Not found");
	delete this->elem[pos];
	this->elem[pos] = this->elem[--size];
}

template<typename T>
void container<T*>::reallocate() {
	this->capacity += this->step;
	T** buff = new T * [this->capacity];
	for (int i = 0; i < size; i++) buff[i] = elem[i];
	delete[]elem;
	elem = buff;
}

template<typename T>
void container<T*>::push(T*& el) {
	if (this->size == this->capacity) reallocate();
	elem[size++] = new T(*el);
}

template<typename T>
void container<T*>::push(T*&& el) {
	if (this->size == this->capacity) reallocate();
	elem[size++] = new T(*el);
}

template<typename T>
container<T*>::container(const container<T*>& b) : size(b.size), capacity(b.capacity), step(b.step) {
	this->elem = new T * [size];
	for (int i = 0; i < size; i++) elem[i] = new T(*b.elem[i]);
}

template<typename T>
container<T*>::container(container<T*>&& b) : size(b.size), capacity(b.capacity), step(b.step) {
	this->elem = b.elem;
	b.elem = nullptr;
	b.size = 0;
	b.capacity = 0;
}

#endif