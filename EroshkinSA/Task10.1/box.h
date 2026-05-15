#ifndef __BOX_H
#define __BOX_H

template<typename T>
class Box {
	size_t size, capacity, step;
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
	~Box();
};

template<typename T>
Box<T>::~Box() {
	delete[]elem;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Box<T>& b) {
	out << "size = " << b.size << " | capacity = " << b.capacity << " | step = " << b.step << "\n(";
	for (int i = 0; i < b.size; i++) {
		out << b.elem[i];
		if (i + 1 == b.size) break;
		out << " ";
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
	b.size = 0;
	b.capacity = 0;
}

template<typename T>
T& Box<T>::operator[](size_t ind) {
	if (ind > this->size) {
		std::cerr << "Out of range";
		throw std::exception("Out of range");
	}
	return this->elem[ind];
}

template<typename T>
const T& Box<T>::operator[](size_t ind) const {
	if (ind > this->size) {
		std::cerr << "Out of range";
		throw std::exception("Out of range");
	}
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
	if (pos == -1) {
		std::cerr << "Not found";
		throw std::exception("Not found");
	}
	this->elem[pos] = this->elem[--size];
}


template<typename T>
void Box<T>::remove(T&& el) {
	int pos = this->find(el);
	if (pos == -1) {
		std::cerr << "Not found";
		throw std::exception("Not found");
	}
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

//__________
//__________

template<typename T>
class Box<T*> {
	size_t size, capacity, step;
	T** elem;
	size_t* sizes;
public:
	Box(size_t, size_t);
	Box(size_t, size_t, T*&, size_t);
	Box(const Box<T*>&);
	Box(Box<T*>&&);
	T*& operator[](size_t);
	const T*& operator[](size_t) const;
	const Box& operator=(const Box&);
	int find(T*&, size_t);
	void push(T*&, size_t);
	void push(T*&&, size_t);
	void remove(T*&, size_t);
	void remove(T*&&, size_t);
	friend std::ostream& operator<< <T*>(std::ostream&, const Box<T*>&);
	~Box();
};

template<typename T>
Box<T*>::~Box() {
	for (int i = 0; i < size; i++) delete[]elem[i];
	delete[]sizes;
	delete[]elem;
}
template<typename T>
Box<T*>::Box(size_t cp, size_t st) : size(0), capacity(cp), step(st) {
	this->elem = new T * [capacity];
	this->sizes = new size_t[capacity];
}

template<typename T>
Box<T*>::Box(size_t cp, size_t st, T*& el, size_t len) : capacity(cp), step(st), size(cp) {
	this->elem = new T*[capacity];
	this->sizes = new size_t[capacity];
	for (int i = 0; i < size; i++) {
		elem[i] = el;
		sizes[i] = len;
	}
}

template<typename T>
T*& Box<T*>::operator[](size_t ind) {
	if (ind > this->size) {
		std::cerr << "Out of range";
		throw std::exception("Out of range");
	}
	return this->elem[ind];
}

template<typename T>
const T*& Box<T*>::operator[](size_t ind) const {
	if (ind > this->size) {
		std::cerr << "Out of range";
		throw std::exception("Out of range");
	}
	return this->elem[ind];
}

template<typename T>
int Box<T*>::find(T*& el, size_t len) {
	for (int i = 0; i < this->size; i++) {
		if (sizes[i] == len) {
			bool f = 1;
			for (int j = 0; j < sizes[i]; j++) {
				if (elem[i][j] != el[j]) {
					f = 0;
					break;
				}
			}
			if (f) return i;
		}
	}
	return -1;
}

template<typename T>
void Box<T*>::remove(T*& el, size_t len) {
	int pos = this->find(el, len);
	if (pos == -1) {
		std::cerr << "Not found";
		throw std::exception("Not found");
	}
	this->elem[pos] = this->elem[size];
	sizes[pos] = elem[--size];
}


template<typename T>
void Box<T*>::remove(T*&& el, size_t len) {
	int pos = this->find(el, len);
	if (pos == -1) {
		std::cerr << "Not found";
		throw std::exception("Not found");
	}
	this->elem[pos] = this->elem[size];
	sizes[pos] = elem[--size];
}

template<typename T>
void Box<T*>::push(T*& el, size_t len) {
	if (this->size == this->capacity) {
		this->capacity += this->step;
		T** buff = new T*[this->capacity];
		size_t* szbuff = new size_t[capacity];
		for (int i = 0; i < size; i++) {
			buff[i] = elem[i];
			szbuff[i] = sizes[i];
		}
		delete[]elem;
		delete[]sizes;
		elem = buff;
		sizes = szbuff;
	}
	elem[size] = el;
	sizes[size++] = len;
}

template<typename T>
void Box<T*>::push(T*&& el, size_t len) {
	if (this->size == this->capacity) {
		this->capacity += this->step;
		T** buff = new T * [this->capacity];
		size_t szbuff = new size_t[capacity];
		for (int i = 0; i < size; i++) {
			buff[i] = elem[i];
			szbuff[i] = sizes[i];
		}
		delete[]elem;
		delete[]sizes;
		elem = buff;
		sizes = szbuff;
	}
	elem[size] = el;
	sizes[size++] = len;
}

#endif