#ifndef __BOX_H
#define __BOX_H

template<typename T>
class Box {
	size_t size, capacity, step = 1;
	T* elem;
public:
	Box(size_t, size_t);
	Box(size_t, size_t, const T&);
	Box(const Box<T>&);
	Box(Box<T>&&);
	T& operator[](size_t);
	const T& operator[](size_t) const;
	const Box& operator=(const Box&);
	int find(T&);
	void push(T&);
	void push(T&&);
	void remove(T&);
	void remove(T&&);
	friend std::ostream& operator<< <T>(std::ostream&, const Box<T>&);
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Box<T>& b) {
	out << "size = " << b.size << " | capacity = " << b.capacity << " | step = " << b.step << "\n(";
	for (int i = 0; i < b.size; i++) {
		out << b.elem[i];
		if (i + 1 != b.size) out << " ";
	}
	out << ")";
	return out;
}

template<typename T>
Box<T>::Box(size_t cp, size_t st) : capacity(cp), size(0), step(st) {
	this->elem = new T[cp];
}

template<typename T>
Box<T>::Box(size_t cp, size_t st, const T& el) : capacity(cp), size(cp), step(st) {
	this->elem = new T[cp];
	for (int i = 0; i < cp; i++) this->elem[i] = el;
}

template<typename T>
Box<T>::Box(const Box<T>& b) : size(b.size), capacity(b.capacity) {
	this->elem = new T[size];
	for (int i = 0; i < size; i++) elem[i] = b.elem[i];
}

template<typename T>
Box<T>::Box(Box<T>&& b) : size(b.size), capacity(b.capacity) {
	this->elem = b.elem;
	b.elem = nullptr;
}

template<typename T>
T& Box<T>::operator[](size_t ind) {
	if (ind > this->size) throw std::exception("Out of range");
	return this->elem[ind];
}

template<typename T>
const T& Box<T>::operator[](size_t ind) const {
	if (ind > this->size) throw std::exception("Out of range");
	return this->elem[ind];
}

template<typename T>
const Box<T>& Box<T>::operator=(const Box<T>& b) {
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
int Box<T>::find(T& el) {
	for (int i = 0; i < this->size; i++)
		if (this->elem[i] == el)
			return i;
	return -1;
}

template<typename T>
void Box<T>::remove(T& el) {
	int pos = this->find(el);
	if (pos == -1) throw std::exception("Not found");
	this->elem[pos] = this->elem[--size];
}


template<typename T>
void Box<T>::remove(T&& el) {
	int pos = this->find(el);
	if (pos == -1) throw std::exception("Not found");
	this->elem[pos] = this->elem[--size];
}

template<typename T>
void Box<T>::push(T& el) {
	if (this->size == this->capacity) {
		this->capacity += this->step;
		T* buff = new T[this->capacity];
		for (int i = 0; i < size; i++) buff[i] = elem[i];
		delete[]elem;
		elem = buff;
	}
	elem[size++] = el;
}

template<typename T>
void Box<T>::push(T&& el) {
	if (this->size == this->capacity) {
		this->capacity += this->step;
		T* buff = new T[this->capacity];
		for (int i = 0; i < size; i++) buff[i] = elem[i];
		delete[]elem;
		elem = buff;
	}
	elem[size++] = el;
}

#endif