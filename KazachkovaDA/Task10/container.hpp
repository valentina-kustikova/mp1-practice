#ifndef _CONTAINER_H
#define _CONTAINER_H

template<typename T>
class Container {
private:
	int size, capacity, step;
	T* elem;
public:
	Container(int);
	Container(int,  const T&);
	Container(const Container<T>&);
	Container(Container<T>&&);
	void push(T&);
	void remove(T&);
	T& operator[](int);
	const T& operator[](int) const;
	~Container();
	int find(T&);
};

#endif