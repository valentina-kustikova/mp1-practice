#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP

#include <iostream>
#include <sys/types.h>

#ifndef ssize_t
#ifdef _WIN32
#include <BaseTsd.h>
#define ssize_t SSIZE_T
#else
#define ssize_t ptrdiff_t
#endif
#endif

template<typename T>
class container {
	size_t size, capacity, step;
	T* elems;
	void allocate(size_t);
	void reallocate(size_t);
public:
	container(size_t _capacity=0, size_t _step=10);
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

	ssize_t find(const T& elem) const;
	ssize_t find(T&& elem) const;

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
	ssize_t i = find(elem);
	if (i == static_cast<ssize_t>(-1))
		throw std::runtime_error("element not found");
	elems[i] = elems[--size];
}

template<typename T>
void container<T>::remove(T&& elem) {
	ssize_t i = find(elem);
	if (i == static_cast<ssize_t>(-1))
		throw std::runtime_error("element not found");
	elems[i] = elems[--size];
}

template<typename T>
ssize_t container<T>::find(const T& elem) const {
	for (size_t i = 0; i < size; i++)
		if (elems[i] == elem)
			return i;
	return static_cast<ssize_t>(-1);
}

template<typename T>
ssize_t container<T>::find(T&& elem) const {
	for (size_t i = 0; i < size; i++)
		if (elems[i] == elem)
			return i;
	return static_cast<ssize_t>(-1);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const container<T>& c) {
	os << "{ ";
	for (size_t i = 0; i < c.size; i++)
		os << c.elems[i] << " ";
	os << "}";
	return os;
}

#endif