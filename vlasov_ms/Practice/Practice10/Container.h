#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include <exception>

template <typename T>
class Container
{
	T** set;
	size_t size, buffer;
	static const size_t delta = 10;

	void alloc_for(size_t);
	void shrink_to_fit();
	size_t calc_buffer(size_t);
public:
	Container();
	Container(size_t);
	Container(const Container<T>&);
	~Container();

	size_t sz() const;
	bool empty() const;

	Container<T>& add(T);
	Container<T>& remove(T);
	Container<T>& remove(size_t);
	Container<T>& remove_if(bool(*callback)(T));
	Container<T>& remove_if(bool(*callback)(T*));
	Container<T>& remove_all();

	const Container<T>& operator=(const Container<T>&);
	T& operator[](size_t);
	const T& operator[](size_t) const;
};

template<typename T>
void Container<T>::alloc_for(size_t n)
{
	if (size + n <= buffer)
		return;
	buffer = calc_buffer(size + n);
	T** new_set = new T*[buffer];
	for (size_t i = 0; i < size; i++)
		new_set[i] = set[i];
	delete[] set;
	set = new_set;
}

template<typename T>
void Container<T>::shrink_to_fit()
{
	size_t empty = buffer - size;
	if (empty >= delta)
	{
		size_t d = calc_buffer(size);
		delete[](set + d);
		buffer = d;
	}
}

template<typename T>
size_t Container<T>::calc_buffer(size_t new_size)
{
	return new_size / delta * delta + delta;
}

template<typename T>
Container<T>::Container()
{
	size = 0;
	buffer = 0;
	set = nullptr;
}

template<typename T>
Container<T>::Container(size_t new_size)
{
	size = new_size;
	buffer = calc_buffer(new_size);
	set = new T*[buffer];
	for (size_t i = 0; i < size; i++)
		set[i] = new T;
}

template<typename T>
Container<T>::Container(const Container<T>& c)
{
	alloc_for(c.size);
	for (size_t i = 0; i < c.size; i++)
		**(set + i) = **(c.set + i);
	size = c.size;
}

template<typename T>
Container<T>::~Container()
{
	remove_all();
}

template<typename T>
size_t Container<T>::sz() const
{
	return size;
}

template<typename T>
bool Container<T>::empty() const
{
	return size == 0;
}

template<typename T>
Container<T>& Container<T>::add(T object)
{
	alloc_for(1);
	set[size] = new T(object);
	size += 1;
	return *this;
}

template<typename T>
Container<T>& Container<T>::remove(T object)
{
	for (size_t i = 0; i < size; i++)
		if ((*this)[i] == object)
			remove(i);
	return *this;
}

template<typename T>
Container<T>& Container<T>::remove(size_t index)
{
	if (index >= size)
		throw std::out_of_range("Container does not contain element with that index.");
	if (index == size - 1)
	{
		delete set[index];
		size -= 1;
		return *this;
	}
	delete set[index];
	size -= 1;
	set[index] = set[size];
	return *this;
}

template<typename T>
Container<T>& Container<T>::remove_if(bool(*callback)(T))
{
	for (size_t i = 0; i < size; i++)
		if ((*callback)((*this)[i]))
			remove(i);
	return *this;
}

template<typename T>
inline Container<T>& Container<T>::remove_if(bool(*callback)(T*))
{
	for (size_t i = 0; i < size; i++)
		if ((*callback)(set[i]))
			remove(i);
	return *this;
}

template<typename T>
Container<T>& Container<T>::remove_all()
{
	if (!size || !set)
		return *this;
	for (size_t i = 0; i < size; i++)
		delete set[i];
	delete[] set;
	set = nullptr;
	size = buffer = 0;
	return *this;
}

template<typename T>
const Container<T>& Container<T>::operator=(const Container<T>& c)
{
	remove_all();
	alloc_for(c.size);
	for (size_t i = 0; i < c.size; i++)
		**(set + i) = **(c.set + i);
	size = c.size;
	return *this;
}

template<typename T>
T& Container<T>::operator[](size_t index)
{
	if(index >= size)
		throw std::out_of_range("Container does not contain element with that index.");
	return **(set + index);
}

template<typename T>
const T& Container<T>::operator[](size_t index) const
{
	if (index >= size)
		throw std::out_of_range("Container does not contain element with that index.");
	return **(set + index);
}

#endif