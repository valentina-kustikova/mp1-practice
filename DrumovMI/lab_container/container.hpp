#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP

#include <iostream>
#include <string>
#include <sys/types.h>

template<typename T>
class container {
	size_t size, capacity;
	size_t step;
	T* elems;
	void allocate(size_t);
	void reallocate(size_t);
public:
	container(size_t _capacity = 0, size_t _step = 10);
	container(size_t _capacity, size_t _step, const T& elem);
	container(const container<T>& c);
	container(container<T>&& c);
	~container();

	const container<T>& operator=(const container<T>& c);

	T& operator[](size_t i);
	const T& operator[](size_t i) const;

	void push_back(const T& elem);
	void pop_back();
	void remove(const T& elem);
	void remove(T&& elem);

	size_t find(const T& elem) const;
	size_t find(T&& elem) const;

	bool operator==(const container<T>& c);

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const container<U>& c);
};

template<typename T>
void container<T>::allocate(size_t _capacity) {
	capacity = _capacity;
	elems = new T[capacity];
}

template<typename T>
void container<T>::reallocate(size_t _capacity) {
	if (capacity >= _capacity) {
		if (size > _capacity)
			throw std::range_error("bad new capacity");
		capacity = _capacity;
		return;
	}
	capacity = _capacity;
	T* elems1 = new T[capacity];
	for (size_t i = 0; i < size; i++)
		elems1[i] = elems[i];
	delete[] elems;
	elems = elems1;
}

template<typename T>
container<T>::container(size_t _capacity, size_t _step) {
	allocate(_capacity);
	size = 0;
	step = _step;
}

template<typename T>
container<T>::container(size_t _capacity, size_t _step, const T& elem) {
	allocate(_capacity);
	size = _capacity;
	step = _step;
	for (size_t i = 0; i < size; i++)
		elems[i] = elem;
}

template<typename T>
container<T>::container(const container<T>& c) {
	allocate(c.capacity);
	size = c.size;
	step = c.step;
	for (size_t i = 0; i < size; i++)
		elems[i] = c.elems[i];
}

template<typename T>
container<T>::container(container<T>&& c) {
	elems = c.elems;
	c.elems = nullptr;
	capacity = c.capacity;
	size = c.size;
	step = c.step;
}

template<typename T>
container<T>::~container() {
	delete[] elems;
}

template<typename T>
const container<T>& container<T>::operator=(const container<T>& c) {
	if (this == &c)
		return *this;
	if (capacity < c.capacity) {
		delete[] elems;
		allocate(c.capacity);
	}
	size = c.size;
	for (size_t i = 0; i < size; i++)
		elems[i] = c.elems[i];
	step = c.step;
	return *this;
}

template<typename T>
T& container<T>::operator[](size_t i) {
	if (i >= size)
		throw std::out_of_range("out-of-range");
	return elems[i];
}

template<typename T>
const T& container<T>::operator[](size_t i) const {
	if (i >= size)
		throw std::out_of_range("out-of-range");
	return elems[i];
}

template<typename T>
void container<T>::push_back(const T& elem) {
	if (size == capacity)
		reallocate(capacity + step);
	elems[size++] = elem;
}

template<typename T>
void container<T>::pop_back() {
	if (size > 0)
		size--;
}

template<typename T>
void container<T>::remove(const T& elem) {
	size_t i = find(elem);
	if (i == std::string::npos)
		throw std::runtime_error("element not found");
	elems[i] = elems[--size];
}

template<typename T>
void container<T>::remove(T&& elem) {
	size_t i = find(elem);
	if (i == std::string::npos)
		throw std::runtime_error("element not found");
	elems[i] = elems[--size];
}

template<typename T>
size_t container<T>::find(const T& elem) const {
	for (size_t i = 0; i < size; i++)
		if (elems[i] == elem)
			return i;
	return std::string::npos;
}

template<typename T>
size_t container<T>::find(T&& elem) const {
	for (size_t i = 0; i < size; i++)
		if (elems[i] == elem)
			return i;
	return std::string::npos;
}

template<typename T>
bool container<T>::operator==(const container<T>& c) {
	if (this == &c)
		return true;
	if (size != c.size)
		return false;
	for (size_t i = 0; i < size; i++)
		if (elems[i] != c.elems[i])
			return false;
	return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const container<T>& c) {
	os << "{ ";
	for (size_t i = 0; i < c.size; i++)
		os << c.elems[i] << " ";
	os << "}";
	return os;
}

// -------------------------------------------
// -------------- container<T*> --------------
// -------------------------------------------

template<typename T>
class container<T*> {
	size_t size, capacity;
	size_t step;
	T** elems;
	void allocate(size_t);
	void reallocate(size_t);
	void free();
public:
	container(size_t _capacity = 0, size_t _step = 10);
	container(size_t _capacity, size_t _step, const T& elem);
	container(const container<T*>& c);
	container(container<T*>&& c);
	~container();

	const container<T*>& operator=(const container<T*>& c);

	T*& operator[](size_t i);
	const T*& operator[](size_t i) const;

	void push_back(const T*& elem);
	void pop_back();
	void remove(const T*& elem);
	void remove(T*&& elem);

	size_t find(const T& elem) const;
	size_t find(T&& elem) const;

	bool operator==(const container<T*>& c);

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const container<U*>& c);
};

template<typename T>
void container<T*>::allocate(size_t _capacity) {
	capacity = _capacity;
	elems = new T * [capacity] {};
}

template<typename T>
void container<T*>::reallocate(size_t _capacity) {
	if (capacity >= _capacity) {
		if (size > _capacity)
			throw std::range_error("bad new capacity");
		capacity = _capacity;
		return;
	}
	capacity = _capacity;
	T** elems1 = new T * [capacity] {};
	for (size_t i = 0; i < size; i++)
		elems1[i] = elems[i];
	delete[] elems;
	elems = elems1;
}

template<typename T>
void container<T*>::free() {
	for (size_t i = 0; i < size; i++)
		delete elems[i];
	delete elems;
}

template<typename T>
container<T*>::container(size_t _capacity, size_t _step) {
	allocate(_capacity);
	size = 0;
	step = _step;
}

template<typename T>
container<T*>::container(size_t _capacity, size_t _step, const T& elem) {
	allocate(_capacity);
	size = _capacity;
	step = _step;
	for (size_t i = 0; i < size; i++)
		elems[i] = new T(elem);
}

template<typename T>
container<T*>::container(const container<T*>& c) {
	allocate(c.capacity);
	size = c.size;
	step = c.step;
	for (size_t i = 0; i < size; i++)
		elems[i] = new T(*c.elems[i]);
}

template<typename T>
container<T*>::container(container<T*>&& c) {
	elems = c.elems;
	c.elems = nullptr;
	capacity = c.capacity;
	size = c.size;
	step = c.step;
	c.size = c.capacity = 0;
}

template<typename T>
container<T*>::~container() {
	free();
}

template<typename T>
const container<T*>& container<T*>::operator=(const container<T*>& c) {
	if (this == &c)
		return *this;
	if (capacity < c.capacity) {
		free();
		allocate(c.capacity);
	}
	size = c.size;
	for (size_t i = 0; i < size; i++)
		elems[i] = new T(*c.elems[i]);
	step = c.step;
	return *this;
}

template<typename T>
T*& container<T*>::operator[](size_t i) {
	if (i >= size)
		throw std::out_of_range("out-of-range");
	return elems[i];
}

template<typename T>
const T*& container<T*>::operator[](size_t i) const {
	if (i >= size)
		throw std::out_of_range("out-of-range");
	return elems[i];
}

template<typename T>
void container<T*>::push_back(const T*& elem) {
	if (size == capacity)
		reallocate(capacity + step);
	elems[size++] = new T(*elem);
}

template<typename T>
void container<T*>::pop_back() {
	if (size > 0) {
		delete elems[--size];
		elems[size] = nullptr;
	}
}

template<typename T>
void container<T*>::remove(const T*& elem) {
	size_t i = find(*elem);
	if (i == std::string::npos)
		throw std::runtime_error("element not found");
	delete elems[i];
	elems[i] = elems[--size];
	elems[size] = nullptr;
}

template<typename T>
void container<T*>::remove(T*&& elem) {
	size_t i = find(*elem);
	if (i == std::string::npos)
		throw std::runtime_error("element not found");
	delete elems[i];
	elems[i] = elems[--size];
	elems[size] = nullptr;
}

template<typename T>
size_t container<T*>::find(const T& elem) const {
	for (size_t i = 0; i < size; i++)
		if (*elems[i] == elem)
			return i;
	return std::string::npos;
}

template<typename T>
size_t container<T*>::find(T&& elem) const {
	for (size_t i = 0; i < size; i++)
		if (*elems[i] == elem)
			return i;
	return std::string::npos;
}

template<typename T>
bool container<T*>::operator==(const container<T*>& c) {
	if (this == &c)
		return true;
	if (size != c.size)
		return false;
	for (size_t i = 0; i < size; i++)
		if (*elems[i] != *c.elems[i])
			return false;
	return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const container<T*>& c) {
	os << "{ ";
	for (size_t i = 0; i < c.size; i++)
		os << *c.elems[i] << " ";
	os << "}";
	return os;
}

#endif