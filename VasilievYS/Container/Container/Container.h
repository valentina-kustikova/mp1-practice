#ifndef CNTNR
#define CNTNR 
#include<iostream>

template <typename T>
class Container
{
	std::size_t size;
	std::size_t capacity;
	const std::size_t step;
	T* elems;

	void reallocate();
public:
	Container() :
		size(0), capacity(0), elems(nullptr), step(20) {};
	Container(std::size_t s, const std::size_t st = 20);
	Container(std::size_t s, const T& elem, const std::size_t st = 20);
	Container(const Container<T>& C);
	Container(Container<T>&& C);
	~Container();
	void push_back(const T& elem);
	void remove(const T& elem);
	int find(const T& elem) const;
	T& operator[](std::size_t i);
	const T& operator[](std::size_t i) const;
	const Container<T>& operator = (const Container<T>& C);
	std::size_t getSize() const { return size; }
	std::size_t getCapacity() const { return capacity; }
};

template<typename T>
class Container<T*>
{
	std::size_t size;
	std::size_t capacity;
	const std::size_t step;
	T** elems;

	void reallocate();
public:
	Container() :
		size(0), capacity(0), elems(nullptr), step(20) {
	};
	Container(std::size_t s, const std::size_t st = 20);
	Container(std::size_t s, T* elem, const std::size_t st = 20);
	Container(const Container<T*>& C);
	Container(Container<T*>&& C);
	~Container();
	void push_back(T* elem);
	void remove(const T* elem);
	int find(const T* elem) const;
	T*& operator[](std::size_t i);
	const T* operator[](std::size_t i) const;
	const Container<T*>& operator = (const Container<T*>& C);
	std::size_t getSize() const { return size; }
	std::size_t getCapacity() const { return capacity; }
};

template <typename T>
Container<T>::Container(std::size_t s, const std::size_t st) :
	size(0), capacity(s), elems(new T[s]), step(st) {
}

template<typename T>
Container<T>::Container(std::size_t s, const T& elem, const std::size_t st) :
	size(s), capacity(s), elems(new T[s]), step(st)
{
	for (std::size_t i = 0; i < size; i++)
	{
		elems[i] = elem;
	}
}

template<typename T>
Container<T>::Container(const Container<T>& C):
	size(C.size), capacity(C.capacity), 
	elems(new T[C.capacity]), step(C.step)
{
	for (std::size_t i = 0; i < size; i++)
	{
		elems[i] = C.elems[i];
	}
}

template<typename T>
Container<T>::Container(Container<T>&& C):
	size(C.size), capacity(C.capacity),
	elems(C.elems), step(C.step)
{
	C.elems = nullptr;
	C.size = 0;
	C.capacity = 0;
}

template<typename T>
Container<T>::~Container()
{
	delete[]elems;
}

template<typename T>
void Container<T>::push_back(const T& elem)
{
	if (size >= capacity) { reallocate(); }
	elems[size] = elem;
	size++;
}

template<typename T>
void Container<T>::remove(const T& elem)
{
	int i = find(elem);
	if (i == -1) { throw std::exception("Not found"); }
	elems[i] = elems[size - 1];
	size--;
}

template<typename T>
int Container<T>::find(const T& elem) const
{
	for (int i = 0; i < size; i++)
	{
		if (elems[i] == elem) { return i; }
	}
	return -1;
}

template<typename T>
void Container<T>::reallocate()
{
	std::size_t new_capacity = step + capacity;
	T* new_elems = new T[new_capacity];
	for (std::size_t i = 0; i < size; i++)
	{
		new_elems[i] = elems[i];
	}
	delete[]elems;
	elems = new_elems;
	capacity = new_capacity;
}

template<typename T>
T& Container<T>::operator[](std::size_t i)
{
	if (i >= size) { throw std::exception("Out of range"); }
	return elems[i];
}

template<typename T>
const T& Container<T>::operator[](std::size_t i) const
{
	if (i >= size) { throw std::exception("Out of range"); }
	return elems[i];
}

template<typename T>
const Container<T>& Container<T>::operator=(const Container<T>& C)
{
	if (this != &C)
	{
		size = C.size;
		if (capacity != C.capacity)
		{
			capacity = C.capacity;
			delete[]elems;
			elems = new T[capacity];
		}		
		for (std::size_t i = 0; i < size; i++)
		{
			elems[i] = C.elems[i];
		}
	}
	return *this;
}

template <typename T>
Container<T*>::Container(std::size_t s, const std::size_t st) :
	size(0), capacity(s), elems(new T*[s]), step(st) {
}

template<typename T>
Container<T*>::Container(std::size_t s, T* elem, const std::size_t st) :
	size(s), capacity(s), elems(new T*[s]), step(st)
{
	for (std::size_t i = 0; i < size; i++)
	{
		elems[i] = new T(*elem );
	}
}

template<typename T>
Container<T*>::Container(const Container<T*>& C):
	size(C.size), capacity(C.capacity),
	elems(new T* [capacity]), step(C.step)
{
	for (std::size_t i = 0; i < size; i++)
	{
		elems[i] = new T(*(C.elems[i]));
	}
}

template<typename T>
Container<T*>::Container(Container<T*>&& C):
	size(C.size), capacity(C.capacity),
	elems(C.elems), step(C.step)
{
	C.elems = nullptr;
	C.size = 0;
	C.capacity = C.size;
}

template<typename T>
Container<T*>::~Container()
{
	for (int i = 0; i < size; i++)
	{
		delete elems[i];
	}
	delete[]elems;
}

template<typename T>
void Container<T*>::push_back(T* elem)
{
	if (size >= capacity) { reallocate(); }
	elems[size++] = new T(*elem);
}

template<typename T>
void Container<T*>::remove(const T* elem)
{
	int i = find(elem);
	if (i == -1) { throw std::exception("Not found"); }
	elems[i] = elems[--size];
}

template<typename T>
int Container<T*>::find(const T* elem) const
{
	for (int i = 0; i < size; i++)
	{
		if (*elems[i] == *elem) { return i; }
	}
	return -1;
}

template<typename T>
void Container<T*>::reallocate()
{
	std::size_t new_capacity = step + capacity;
	T** new_elems = new T*[new_capacity];
	for (std::size_t i = 0; i < size; i++)
	{
		new_elems[i] = elems[i];
	}
	delete[]elems;
	elems = new_elems;
	capacity = new_capacity;
}

template<typename T>
T*&  Container<T*>::operator[](std::size_t i)
{
	if (i >= size) { throw std::exception("Out of range"); }
	return elems[i];
}

template<typename T>
const T* Container<T*>::operator[](std::size_t i) const
{
	if (i >= size) { throw std::exception("Out of range"); }
	return elems[i];
}

template<typename T>
const Container<T*>& Container<T*>::operator=(const Container<T*>& C)
{
	if (this != &C)
	{
		size = C.size;
		if (capacity != C.capacity)
		{
			capacity = C.capacity;
			delete[]elems;
			elems = new T*[capacity];
		}
		for (std::size_t i = 0; i < size; i++)
		{
			elems[i] = new T(*(C.elems[i])); 
		}
	}
	return *this;
}
#endif 