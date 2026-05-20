#ifndef _CONTAINER_H
#define _CONTAINER_H

template<typename T>
class Container {
private:
	size_t size, capacity, step;
	T* elem;
public:
	Container(size_t);
	Container(size_t,  const T&);
	Container(const Container<T>&);
	Container(Container<T>&&);
	void push(T&);
	void remove(T&);
	T& operator[](size_t);
	const T& operator[](size_t) const;
	~Container();
};

#endif